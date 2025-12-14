from flask import Flask , request ,jsonify,json
from flask_sqlalchemy import SQLAlchemy 
from flask_jwt_extended import create_access_token , JWTManager , jwt_required, get_jwt_identity
from sqlalchemy import Enum
import enum

app = Flask(__name__)


app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///data.db'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
app.config["JWT_SECRET_KEY"] = "sachin"

db = SQLAlchemy(app)
jwt = JWTManager(app)

class QuestionType(enum.Enum):
    mcq = "mcq"
    tf = "tf"
    subjective = "subjective"

class User(db.Model):
    name = db.Column(db.String(50) , nullable = False)
    password = db.Column(db.String(10) , nullable = False)
    id = db.Column(db.Integer , primary_key = True)
    exams = db.relationship('Exam', backref='user', lazy=True)


class Exam(db.Model):
    name = db.Column(db.String(50) , nullable = False)
    ExamId = db.Column(db.Integer ,primary_key = True)

    user_id = db.Column(db.Integer, db.ForeignKey('user.id'), nullable=False)

class Question(db.Model):
    statement = db.Column(db.String(200) , nullable = False)
    QuestionID = db.Column(db.Integer , primary_key = True)
    user_id = db.Column(db.Integer, db.ForeignKey('user.id'), nullable=False)
    exam_id = db.Column(db.Integer, db.ForeignKey('exam.ExamId'), nullable=False)
    type = db.Column(
        db.Enum(QuestionType, native_enum=False),
        nullable=False
    )

class Option(db.Model):
    statement = db.Column(db.String(200) , nullable = False)
    option_id = db.Column(db.Integer , primary_key = True)
    ques_id = db.Column(db.Integer, db.ForeignKey('question.QuestionID'), nullable=False)
    user_id = db.Column(db.Integer, db.ForeignKey('user.id'), nullable=False)
    flag = db.Column(db.String(10) , nullable = False)

    

with app.app_context():
    db.create_all()

@app.route("/")
def hello():
    return "hello world"

@app.route("/check")
@jwt_required()
def check():
    userid = get_jwt_identity()
    user = User.query.get(userid)
    if not user:
        return jsonify({"error": "User not found"}), 404
    
    print(f"User logged in: {user.name} (id: {user.id})")

    return jsonify({
        "message": "valid token",
        "user": {
            "id": user.id,
            "name": user.name
        }
    })

@app.route("/login" , methods = ["POST"])
def login():
    data = request.get_json()
    
    if not data or "name" not in data or "password" not in data:
        return jsonify({"error" : "empty field"}) , 400
    
    user = User.query.filter_by(name = data["name"]).first()

    if not user:
        return jsonify({"error" : "user not exist"}) , 400
    
    if user.password != data["password"]:
        return jsonify({"error" : "password did not match"}) , 400
        
    token = create_access_token(identity=str(user.id))
    print(token)

    return token
    # return jsonify({
    #     "msg" : "login successful"
    #     ,"access_token" : token}) , 200
    

@app.route("/signup" , methods = ["POST"])
def signup():
    data = request.get_json()
    if not data or "name" not in data or "password" not in data:
        return jsonify({"error" : "empty field"}) , 400
    
    existing_user = User.query.filter_by(name=data["name"]).first()

    if existing_user:
        return jsonify({"error": "user already exists"}), 409

    # print(data["name"] , data["password"]);
    newUser = User(name = data["name"] , password = data["password"])

    
    db.session.add(newUser)
    db.session.commit()
    return "hello"

#create exam by that admin exam must be unique by only same name exam can be present the foreign key of exam is user
@app.route("/create/exam" , methods = ["POST"])
@jwt_required()
def createExam():
    data = request.get_json()
    if not data or "name" not in data:
        return jsonify({"error" : "empty field"})


    user_id = get_jwt_identity()
    
    exam = Exam(name = data["name"] , user_id = user_id)
    db.session.add(exam)
    db.session.commit()
    return "success"

@app.route("/getallexams")
def getallexams():
    Exams = Exam.query.all()
    result = []
    for exam in Exams:
        result.append({"name" : exam.name , "id" : exam.ExamId})
    
    return jsonify(result),200

@app.route("/getmyexams")
@jwt_required()
def getmyexams():
    user_id = get_jwt_identity()
    user = User.query.get(user_id)
    Exams = user.exams
    result = []
    for exam in Exams:
        result.append({"name" : exam.name , "id" : exam.ExamId})
    return jsonify(result),200



@app.route("/create/question", methods=["POST"])
@jwt_required()
def createquestion():
    user_id = get_jwt_identity()
    data = request.get_json()

    # Required fields check
    if not data or "statement" not in data or "exam_id" not in data or "type" not in data:
        return jsonify({"error": "statement, exam_id and type are required"}), 400

    # Enum validation without try/except    
    allowed_types = [t.value for t in QuestionType]
    if data["type"] not in allowed_types:
        return jsonify({
            "error": f"Invalid question type. Allowed: {allowed_types}"
        }), 400

    question = Question(
        statement=data["statement"],
        type=QuestionType(data["type"]),
        user_id=user_id,
        exam_id=data["exam_id"]
    )

    db.session.add(question)
    db.session.commit()

    return jsonify({
        "question_id": question.QuestionID,
        "type": question.type.value
    }), 201

    
@app.route("/get/questions")
@jwt_required()
def getquestions():
    user_id = get_jwt_identity()
    exam_id = request.args.get("exam_id", type=int)
    print(exam_id)
    if not exam_id:
        return jsonify({"erroro" : "something is missing"})
    
    ans = []
    questions = Question.query.filter_by(exam_id=exam_id , user_id=user_id).all()
    for ques in questions:
        ans.append({"question" : ques.statement , "question id" : ques.QuestionID , "user_id" : ques.user_id , "type" : ques.type.value})

    return jsonify(ans),200

@app.route("/create/options" , methods = ["POST"])
@jwt_required()
def createoptions():
    user_id = get_jwt_identity()
    data = request.get_json()
    if not data or "statement" not in data or "ques_id" not in data or "flag" not in data:
        return jsonify({"error": "statement, ques_id and flag are required"}), 400
    
    if(data["flag"] != "true" and data["flag"] != "false"):
        return "flag is not valid" , 400
    
    option = Option(statement = data["statement"] , ques_id = data["ques_id"] , user_id = user_id , flag = data["flag"])
    db.session.add(option)
    db.session.commit()

    return jsonify({
        "option" : option.statement,
        "flag" : option.flag,
        "optionID" : option.option_id
    }),200

@app.route("/get/options")
@jwt_required()
def getoptions():
    user_id = get_jwt_identity()
    ques_id = request.args.get("ques_id", type=int)
    if not ques_id:
        return jsonify({"erroro" : "something is missing"})
    
    ans = []
    options = Option.query.filter_by(ques_id=ques_id , user_id=user_id).all()
    for ops in options:
        ans.append({"statement" : ops.statement , "flag" : ops.flag})

    return jsonify(ans),200

if __name__ == "__main__":
    print("localhost:5000")
    app.run(debug=True)

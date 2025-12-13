from flask import Flask , request ,jsonify,json
from flask_sqlalchemy import SQLAlchemy
from flask_jwt_extended import create_access_token , JWTManager , jwt_required, get_jwt_identity
app = Flask(__name__)


app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///data.db'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
app.config["JWT_SECRET_KEY"] = "sachin"

db = SQLAlchemy(app)
jwt = JWTManager(app)
class User(db.Model):
    name = db.Column(db.String(50) , nullable = False)
    password = db.Column(db.String(10) , nullable = False)
    id = db.Column(db.Integer , primary_key = True)
    exams = db.relationship('Exam', backref='user', lazy=True)

class Exam(db.Model):
    name = db.Column(db.String(50) , nullable = False)
    ExamId = db.Column(db.Integer ,primary_key = True)

    user_id = db.Column(db.Integer, db.ForeignKey('user.id'), nullable=False)




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





if __name__ == "__main__":
    print("localhost:5000")
    app.run(debug=True)

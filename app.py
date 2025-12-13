from flask import Flask , redirect , url_for , jsonify , request
from flask_sqlalchemy import SQLAlchemy

app = Flask(__name__)


app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///data.db'
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False

db = SQLAlchemy(app)

class Name(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.String(50), nullable=False)

with app.app_context():
    db.create_all()

@app.route("/")
def hello():
    return "Hello World"

@app.route("/names", methods=["POST"])
def add_name():
    data = request.get_json()
    if not data or "name" not in data:
        return jsonify({"error": "Name is required"}), 400

    new_name = Name(name=data["name"])
    db.session.add(new_name)
    db.session.commit()

    return jsonify({"id": new_name.id, "name": new_name.name}), 201

@app.route("/names", methods=["GET"])
def get_names():
    all_names = Name.query.all()
    result = [{"id": n.id, "name": n.name} for n in all_names]
    return jsonify(result)

if __name__ == "__main__":
    print("http://localhost:5000/")
    app.run(debug=True)
#pip install flask
# pip install flask_sqlalchemy
# python -m vevn vevn
# vevn\Scripts\Activate
# python app.py




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



with app.app_context():
    db.create_all()

@app.route("/")
def hello():
    return "hello world"

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
        
    token = create_access_token(identity=user.id)
    print(token)

    
    return jsonify({
        "msg" : "login successful"
        ,"access_token" : token}) , 200
    

    
    


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


if __name__ == "__main__":
    print("localhost:5000")
    app.run(debug=True)

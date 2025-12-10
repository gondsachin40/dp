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

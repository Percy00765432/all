from flask import Flask, render_template
from models import create_table, insert_user

app = Flask(_name_)

create_table()

@app.route('/')
def home():
    insert_user('John Doe', 'johndoe@example.com', 30)
    return 'User inserted'

if _name_ == '_main_':
    app.run(debug=True)
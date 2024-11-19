from flask import Flask, render_template
from models import create_table, insert_user

app = Flask(__name__)

create_table()

@app.route('/')
def home():
    insert_user('John Doe', 'johndoe@example.com', 30)
    return 'User inserted'

if __name__ == '__main__':
    app.run(debug=True)
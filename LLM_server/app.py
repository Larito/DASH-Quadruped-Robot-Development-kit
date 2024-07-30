from flask import Flask, request, render_template
import ollama

app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/prompt', methods=['POST'])
def prompt():
    user_prompt = request.form['prompt']
    response = get_ollama_response(user_prompt)
    return response

def get_ollama_response(prompt):
    response = ollama.chat(model='llama3', messages=[
        {
            'role': 'user',
            'content': prompt,
        },
    ])
    return response['message']['content']


if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0', port=4000)


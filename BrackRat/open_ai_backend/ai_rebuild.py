import requests, json
from flask import Flask, request
import logging
from flask_cors import CORS
import openai

logging.basicConfig(filename='app.log', level=logging.INFO,encoding='utf-8')

app = Flask(__name__)
cors = CORS(app, origins=["http://localhost:5173"], headers=['Content-Type'],
            expose_headers=['Access-Control-Allow-Origin'], supports_credentials=True)
cors.init_app(app)


openai.api_key = "" # 你的KEY

def api_call(user_input):
    
    # 使用 `openai.Completion.create` 方法调用 OpenAI 的 API
    response = openai.Completion.create(
        engine="text-davinci-003",
        prompt=user_input,
        max_tokens=2048,
        
    )
    logging.info('prompt: %s, text: %s', user_input, response.choices[0].text)
    # 将 OpenAI 的 API 响应解析为字符串并返回
    return response.choices[0].text

@app.route('/process', methods=['GET'])
def process():
    # 获取参数
    prompt = request.args.get('prompt')
    text = api_call(prompt)
    return {
        'status': 200,
        'result': text.replace("\n","<br>")
    }

if __name__ == '__main__':
    app.run(
        host='127.0.0.1',
        port=5000
    )
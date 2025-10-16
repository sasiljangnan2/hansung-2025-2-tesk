from flask import Flask, render_template, request
app = Flask(__name__)
@app.route('/')
def index(): 
    return render_template('index.html')
@app.route('/store/', methods=['GET'])
def store():
    name = request.args.get('name')
    tel = request.args.get('tel')
    file = open('./data/phonebook.txt', 'a')
    data = "%s,%s\n" % (name, tel)
    file.write(data)
    file.close()
    return render_template('index.html', msg='저장되었습니다.')
if __name__ == '__main__':
    app.run(host='0.0.0.0', port=8080, debug=True)
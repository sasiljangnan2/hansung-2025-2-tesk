from flask import Flask, render_template, request
app = Flask(__name__)
@app.route('/')
def index(): 
    return render_template('index.html')
@app.route('/store/', methods=['GET']) # 전화번호 저장
def store():
    name = request.args.get('name') # 이름 받기
    tel = request.args.get('tel') # 전화번호 받기
    file = open('./data/phonebook.txt', 'a') # 추가 모드로 열기
    data = "%s,%s\n" % (name, tel) # data에 name,tel 형식으로 저장
    file.write(data) # 파일에 저장
    file.close()
    return render_template('index.html', msg='저장되었습니다.') # 저장 완료 메시지 출력
@app.route('/search', methods=['GET', 'POST']) # 전화번호 검색
def search():
    name = request.args.get('name') # 이름 받기
    phonebook = {} # 빈 딕셔너리 생성
    file = open('./data/phonebook.txt', 'r') # 읽기 모드로 열기
    for line in file.readlines(): # 한 줄씩 읽기
        data = line.strip().split(',') # , 기준으로 나누어서 data[0], data[1]에 저장
        phonebook[data[0]] = data[1] # 딕셔너리에 이름, 전화번호 저장
    file.close()
    if name in phonebook: # 이름이 딕셔너리에 있으면
        msg = "%s의 전화번호는 %s" % (name, phonebook[name])  # 메세지 생성
    else: # 이름이 딕셔너리에 없으면
        msg = "%s는 없음" % name # 메세지 생성
    return render_template('index.html', msg=msg) # 결과 메시지 출력
@app.route('/view', methods=['GET']) # 전화번호 전체 보기
def view():
    phonebook = {} # 빈 딕셔너리 생성
    file = open('./data/phonebook.txt', 'r') # 읽기 모드로 열기
    for line in file.readlines(): # 한 줄씩 읽기
        data = line.strip().split(',') # , 기준으로 나누어서 data[0], data[1]에 저장
        phonebook[data[0]] = data[1] # 딕셔너리에 이름, 전화번호 저장
    file.close()
    return render_template('view.html', phonebook=phonebook)
if __name__ == '__main__':
    app.run(host='0.0.0.0', port=8080, debug=True)


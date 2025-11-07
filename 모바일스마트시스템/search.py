dict = {} # 빈 딕셔너리 생성
file = open("bookwriter.txt", "r") # 읽기 모드로 열기
for line in file.readlines(): # 한 줄씩 읽기
    data = line.strip().split(",") # , 기준으로 나누어서 data[0], data[1]에 저장
    dict[data[0]] = data[1] # 딕셔너리에 이름, 전화번호 저장
while(1): # 무한 반복
   name = input("검색할 이름>>")
   if name == "exit": # 입력에 exit가 들어오면
      print("검색을 끝냅니다.")
      break # 종료pip install paho.mqttpip install paho.mqtt
   if name in dict: # 이름이 딕셔너리에 있으면
      print("%s의 전화번호는 %s" % (name, dict[name])) 
   else:  # 이름이 딕셔너리에 없으면
      print("%s는 없음" % name)
file.close() # 파일 닫기
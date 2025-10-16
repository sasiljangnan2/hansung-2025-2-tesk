file = open("bookwriter.txt", "w") # 쓰기 모드로 열기 파일이 없으면 새로 만들어서 쓰기
while (1): # 무한 반복
    name = input("name>>")
    if name == "exit": # 입력에 exit가 들어오면
        break # 종료
    phone = input("tel>>")
    line = "%s,%s\n" % (name, phone) # 이름,전화번호 형식으로 저장
    file.write(line) # 파일에 쓰기
file.close() # 파일 닫기
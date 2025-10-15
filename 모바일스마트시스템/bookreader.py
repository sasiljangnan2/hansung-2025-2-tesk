file = open("bookwriter.txt", "r") # 읽기 모드로 열기

for line in file.readlines(): # 한 줄씩 읽기
    data = line.strip().split(",") # , 기준으로 나누어서 data[0], data[1]에 저장
    print("이름은 %s, 전화번호는 %s " % (data[0], data[1]))
    print(type(line))
file.close() # 파일 닫기
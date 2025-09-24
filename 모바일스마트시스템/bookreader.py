file = open("bookwriter.txt", "r")
for line in file.readlines():
    print(line, end="")
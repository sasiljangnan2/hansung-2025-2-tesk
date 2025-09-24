file = open("bookwriter.txt", "w")
while (1):
    name = input("name>>")
    if name == "exit":
        break
    phone = input("tel>>")
    line = "%s.%s\n" % (name, phone)
    file.write(line)
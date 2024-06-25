f = open("test.txt", "w")
f.write("")
f.close()

f = open("test.txt", "a")
iter = 0
Txt = ''
if iter <= 2:
    if Txt != "QUIT":
        if iter == 0:
            Txt = 'Once upon the time'
            iter = iter + 1
            f.write(Txt)
        elif iter <= 1:
            Txt = 'In the west'
            iter = iter + 1
            f.write(Txt)
        else:
            Txt = "QUIT"

f.close()

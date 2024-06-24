import time as t
import random as r
def main():
    
    try:
        server()
    except:
        print("that wasn't ment to happen")
        

def server():
    rep = 0
    while rep < 60:
        rep = rep + 1
        rand = r.randrange(6)
        rand = rand + 1
        
        print(rand)
        if rand == 6:
            ErrorNumb = r.randrange(3)
            ErrorNumb = ErrorNumb + 1
            time = t.ctime()

            ErrorListener(ErrorNumb, time)
        
        t.sleep(2)

def ErrorListener(Errornumb, time):
    error = open('error_log.txt', 'a')

    error.write(f'Error Code {Errornumb} at Server on {time}\n')
    
    print("Error! Check the Error log!")

if __name__ == '__main__':
    main()

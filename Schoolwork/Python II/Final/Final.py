import time as t
import random as r
import sqlite3 
import re
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

    conn = sqlite3.connect('error_log.db')
    c = conn.cursor()
    c.execute('''CREATE TABLE IF NOT EXISTS error_messages (error_date VARCHAR(30) PRIMARY KEY NOT NULL, error_category INTEGER)''')

    time = str(time)
    Time = re.sub("[ ,]", "-", time)

    c.execute(f'''INSERT INTO error_messages (error_date, error_category) VALUES (?,?)''', (Time, Errornumb))

    conn.commit()
    conn.close()    

    
    print("Error! Check the Error log!")

if __name__ == '__main__':
    main()
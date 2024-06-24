import sqlite3

def main():
    conn = sqlite3.connect('ContactsDB.db')

    cur = conn.cursor()

    cur.execute('''CREATE TABLE Contacts(CustomerID INTEGER PRIMARY KEY NOT NULL, 
                FirstName VARCHAR(20) NOT NULL, LastName VARCHAR(20) NOT NULL, PhoneNumber VARCHAR(10) NOT NULL)''')

    cur.execute('''INSERT INTO Contacts(CustomerID, FirstName, LastName, PhoneNumber) 
                VALUES (1, "Jhon", "Smith", 8883967296), (2, "Jane", "Doe", 8883967494)''')

    conn.commit()
    conn.close()


if __name__ == '__main__':
    main()




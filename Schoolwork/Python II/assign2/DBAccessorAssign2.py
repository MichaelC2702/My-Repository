import sqlite3

def main():
    conn = sqlite3.connect('ContactsDB.db')#Contacts

    c = conn.cursor()

    mode = "Start"
    stopper = "continue"
    while stopper == "continue":
        try:
            print("----------------------------------------------------------------------------------------------------------------------")
            print('Please choose the method you wish to preform, type "Find" to find an entry by Name, Type "Add" to add a entry to the database, ')
            mode = str(input('Type "FindAll" to display all entries in the database, and type "Quit" to quit. '))

            if mode == "Find":
                FN = input("Enter the First Name of the entry you wish to find. ")
                LN = input("Enter the Last Name of the entry you wish to find. ")

                print(c.execute(f'SELECT PhoneNumber FROM Contacts WHERE FirstName = "{FN}" AND LastName = "{LN}"').fetchall())


            if mode =="Add":
                Id = input('Please enter a unique I.D. Optionally, Run the "FindAll" command to find the smallest avaiable I.D. ')
                First = str(input("Please enter the First Name of the new entry. "))
                Last = str(input("Please enter the Last Name of the new entry. "))
                Phone = input('Please enter the Phone Number of the new entry. ')

                c.execute(f'''INSERT INTO Contacts(CustomerID, FirstName, LastName, PhoneNumber) VALUES ({Id}, "{First}", "{Last}", {Phone})''')

            if mode == "FindAll":
                c.execute('SELECT CustomerID, FirstName, LastName, PhoneNumber FROM Contacts')

                records = c.fetchall()
                for I in records:
                    print(I)

            if mode == "Quit":
                stopper = "End"

        except:
            print("----------------------------------------------------------------------------------------------------------------------")
            print("Sorry, something seems to have gone wrong. Please try again, and remember everything is case sensitive.")

    conn.commit()
    conn.close()


if __name__ == '__main__':
    main()



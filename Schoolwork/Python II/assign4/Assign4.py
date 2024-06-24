import tkinter as tk
from tkinter import *
from tkinter import messagebox as mb
import sqlite3


class A4GUI():
    def __init__(self):
        self.mainWindow = tk.Tk
        self.root = Tk()
        self.topframe = Frame(self.root)

        self.IDlabel = Label(self.topframe, text= "ID Value")
        self.IDlabel.grid(row= 0, column= 0)
        self.IdEntry = Entry(self.topframe, width=20)
        self.IdEntry.grid(row= 0, column= 1)

        self.Firstlabel = Label(self.topframe, text= "First Name")
        self.Firstlabel.grid(row= 1, column= 0)
        self.FirstEntry = Entry(self.topframe, width=20)
        self.FirstEntry.grid(row= 1, column= 1)

        self.Lastlabel = Label(self.topframe, text= "Last Name")
        self.Lastlabel.grid(row= 2, column= 0)
        self.LastEntry = Entry(self.topframe, width=20)
        self.LastEntry.grid(row= 2, column= 1)

        self.Phonelabel = Label(self.topframe, text= "Phone Number")
        self.Phonelabel.grid(row= 3, column= 0)
        self.PhoneEntry = Entry(self.topframe, width=20)
        self.PhoneEntry.grid(row= 3, column= 1)

        self.SubButton = Button(self.topframe, text="Submit", command=self.Enter)
        self.SubButton.grid(row=4, column=1)


        self.topframe.pack()
        self.root.mainloop()

    def Enter(self):
        conn = sqlite3.connect('ContactsDB.db')#Contacts
        c = conn.cursor()


        id = (self.IdEntry.get())
        fn = (self.FirstEntry.get())
        ln = (self.LastEntry.get())
        phone = (self.PhoneEntry.get())

        Id = str(id)
        Fn = str(fn)
        Ln = str(ln)
        Phone = str(phone)
        try:
            c.execute('''INSERT INTO Contacts VALUES (?,?,?,?)''', (Id,Fn,Ln,Phone))
            conn.commit()
            conn.close()
            w = mb.showinfo("Success", 'Item added Succesfully')

        except:
            w = mb.showinfo("Error", "Sorry, Something must have gone wrong. If the ID is unique, Try entering just the numbers in the Phone number.")

if __name__ == '__main__':
    A4GUI()

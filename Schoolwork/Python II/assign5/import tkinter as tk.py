import tkinter as tk
from tkinter import *
from tkinter import messagebox as mb
import sqlite3


class A5GUI():
    def __init__(self):
        self.mainWindow = tk.Tk
        self.root = Tk()
        self.topframe = Frame(self.root)

        self.Firstlabel = Label(self.topframe, text= "First Name")
        self.Firstlabel.grid(row= 0, column= 0)
        self.FirstEntry = Entry(self.topframe, width=20)
        self.FirstEntry.grid(row= 0, column= 1)

        self.Lastlabel = Label(self.topframe, text= "Last Name")
        self.Lastlabel.grid(row= 0, column= 2)
        self.LastEntry = Entry(self.topframe, width=20)
        self.LastEntry.grid(row= 0, column= 3)

        
        self.SubButton = Button(self.topframe, text="Submit", command=self.Enter)
        self.SubButton.grid(row=1, column=0)

        self.Phonelabel = Label(self.topframe, text= "Phone Number -->")
        self.Phonelabel.grid(row= 1, column= 2)
        self.PhoneEntry = Entry(self.topframe, width=20)
        self.PhoneEntry.grid(row= 1, column= 3)

        self.topframe.pack()
        self.root.mainloop()

    def Enter(self):
        conn = sqlite3.connect('ContactsDB.db')#Contacts
        c = conn.cursor()

        fn = (self.FirstEntry.get())
        ln = (self.LastEntry.get())

        phone = c.execute("SELECT PhoneNumber WHERE FirstName = (?) AND LastName = (?) ", (fn,ln))
        self.PhoneEntry = phone
        
        self.PhoneEntry = "N/A"

if __name__ == '__main__':
    A5GUI()

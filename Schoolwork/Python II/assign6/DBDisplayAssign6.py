import tkinter as tk
from tkinter import *
from tkinter import messagebox as mb
import sqlite3


class A5GUI():
    def __init__(self):
        
        self.mainWindow = tk.Tk
        self.root = Tk()
        self.topframe = Frame(self.root)

        self.ProdLabel = tk.Label(text="Display all contents of the Products Table")
        self.ProdLabel.grid(row=0, column=0, padx= 5, pady= 2)
        self.Prodbutton = tk.Button(text="Products", command=self.ProdDisplay)
        self.Prodbutton.grid(row=0, column=1, padx= 5, pady= 2)

        self.ProdDetLabel = tk.Label(text="Display all contents of the Product Details Table")
        self.ProdDetLabel.grid(row=1, column=0, padx= 5, pady= 2)
        self.ProdDetbutton = tk.Button(text="Details", command=self.ProdDetDisplay)
        self.ProdDetbutton.grid(row=1, column=1, padx= 5, pady= 2)

        self.BothLabel = tk.Label(text="Display all contents of Both the Product table and the Product Details Table")
        self.BothLabel.grid(row=2, column=0, padx= 5, pady= 2)
        self.Bothbutton = tk.Button(text="Both", command=self.BothDisplay)
        self.Bothbutton.grid(row=2, column=1, padx= 5, pady= 2)


        self.root.mainloop()


    def ProdDisplay(self):
        conn = sqlite3.connect('Inventory.db')# Products and ProductDetails
        c = conn.cursor()

        a = c.execute('SELECT * FROM Products')
        a = c.fetchall()
        m = mb.showinfo("Data", f"{a}")

        conn.close()#We don't need to commit changes if we do not make any

    def ProdDetDisplay(self):
        conn = sqlite3.connect('Inventory.db')# Products and ProductDetails
        c = conn.cursor()

        a = c.execute('SELECT * FROM ProductDetails')
        a = c.fetchall()
        m = mb.showinfo("Data", f"{a}")

        conn.close()

    def BothDisplay(self):
        conn = sqlite3.connect('Inventory.db')# Products and ProductDetails
        c = conn.cursor()
        
        a = c.execute('''SELECT Products.PName, Products.InspectionCode, Products.ApprovedDate, ProductDetails.PManu, ProductDetails.Price
                        FROM Products INNER JOIN ProductDetails ON ProductDetails.ProductID = Products.ProductID''')

        a = c.fetchall()
        m = mb.showinfo("Data", f"{a}")
        
        conn.close()

if __name__ == '__main__':
    A5GUI()

            
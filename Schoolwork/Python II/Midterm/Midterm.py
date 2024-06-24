import tkinter as tk
from tkinter import *
from tkinter import messagebox as mb
import sqlite3


class MIDGUI():
    def __init__(self):
        self.mainWindow = tk.Tk
        self.root = Tk()
        self.leftframe = Frame(self.root)
        self.rightframe = Frame(self.root)

        
        self.IDlabel = Label(self.leftframe, text= "ID Number")
        self.IDlabel.grid(row= 0, column= 0)
        self.IDEntry = Entry(self.leftframe, width=25)
        self.IDEntry.config(state=NORMAL)
        self.IDEntry.grid(row= 0, column= 1)
        

        self.NameOutput = tk.StringVar()
        self.Namelabel = Label(self.leftframe, text= "Name")
        self.Namelabel.grid(row= 1, column= 0)
        self.NameEntry = Entry(self.leftframe, width=25,textvariable= self.NameOutput)
        self.NameEntry.grid(row= 1, column= 1)
        self.NameEntry.config(state=NORMAL)

        self.CatOutput = tk.StringVar()
        self.Catlabel = Label(self.leftframe, text= "Category")
        self.Catlabel.grid(row= 2, column= 0)
        self.CatEntry = Entry(self.leftframe, width=25, textvariable= self.CatOutput)
        self.CatEntry.grid(row= 2, column= 1)

        self.PriceOutput = tk.StringVar()
        self.Pricelabel = Label(self.leftframe, text= "Price")
        self.Pricelabel.grid(row= 3, column= 0)
        self.PriceEntry = Entry(self.leftframe, width=25, textvariable= self.PriceOutput)
        self.PriceEntry.grid(row= 3, column= 1)

        self.OHOutput = tk.StringVar()
        self.OHlabel = Label(self.leftframe, text= "OnHand")
        self.OHlabel.grid(row= 4, column= 0)
        self.OHEntry = Entry(self.leftframe, width=25,textvariable= self.OHOutput)
        self.OHEntry.grid(row= 4, column= 1)

        self.SaveButton = Button(self.leftframe, text="Save record", command=self.Save)
        self.SaveButton.grid(row=5, column=1)

        self.clearAButton = Button(self.leftframe, text="Clear Text", command = self.ClearA)
        self.clearAButton.grid(row=6, column=1)

        self.tx = Text(self.rightframe, height= 7, width= 40)
        self.tx.grid(row=0, columnspan= 2)
        self.tx.config(state=NORMAL)
        
        self.ProdOutput = tk.StringVar()
        self.ProdLabel = Label(self.rightframe, text= "Product Name")
        self.ProdLabel.grid (row=1, column= 0, padx=5)
        self.ProdEntry = Entry(self.rightframe, width= 20, textvariable= self.ProdOutput)
        self.ProdEntry.grid (row=1, column= 1, padx=5)

        self.displayButton = Button(self.rightframe, text= "Display Record", command= self.Display)
        self.displayButton.grid(row=3, column=0)

        self.clearBButton = Button(self.rightframe, text="Clear Text", command = self.ClearB)
        self.clearBButton.grid(row=3, column=1)


        self.leftframe.pack(side=LEFT)
        self.rightframe.pack(side=RIGHT)
        self.root.mainloop()

    def Save(self):
        conn = sqlite3.connect('products.db')#PRODUCTS
        c = conn.cursor()

        id = (self.IDEntry.get())
        Name = (self.NameEntry.get())
        cat = (self.CatEntry.get())
        price = (self.PriceEntry.get())
        oh =(self.OHEntry.get())

        Id = (id)
        Na = str(Name)
        Cat = str(cat)
        Price = (price)
        OnHand = (oh)

        try: 
            c.execute("INSERT INTO PRODUCTS VALUES (?,?,?,?,?)", (Id,Cat,Name,Price,OnHand))# Almost missed that Category and Name are swapped. Caused some issues.
            w = mb.showinfo("Success", 'Item added Succesfully')
            conn.commit()
            conn.close()

        except:
            w = mb.showinfo("error", "Sorry, There seems to have been an problem. Double check your inputs are correct and ID is unique.")

    def ClearA(self):
        
        self.IDEntry.get()
        self.IDEntry.delete(0, tk.END)
        self.IDEntry.insert(0, "") #Two methods are used because I thought both were broken due to an improper setup running all button commands at boot and not on button press.
        self.NameOutput.set(value= "")
        self.CatOutput.set(value="")
        self.PriceOutput.set(value="")
        self.OHOutput.set(value="")

    def Display(self):
        conn = sqlite3.connect('products.db')#PRODUCTS, PRODNAME
        c = conn.cursor()

        namegrab = self.ProdEntry.get()
        try:
            
            hold = c.execute("SELECT * FROM PRODUCTS WHERE PRODNAME = (?) ",(namegrab,))
            out = str(hold.fetchone())
            if out == "None":
                A = 4 / 0 #crash to fail the try command.
            self.tx.delete(1.0, tk.END)
            self.tx.insert(1.0, out)
            conn.commit()
            conn.close()
        except:
            w = mb.showinfo("error", "Sorry, There seems to have been an problem. Double check the item you are looking for exists and it is spelled correctly.")


    def ClearB(self):
        self.ProdEntry.delete(0, 'end')
        self.tx.delete(1.0, tk.END)



if __name__ == '__main__':
    MIDGUI()


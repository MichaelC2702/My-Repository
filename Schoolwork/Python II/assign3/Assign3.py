import tkinter as tk
from tkinter import *
from tkinter import messagebox as mb


class A3GUI():
    def __init__(self):
        self.mainWindow = tk.Tk
        self.root = Tk()
        self.var = IntVar()
        self.var.set(101)
        self.topframe = Frame(self.root)
        

        self.Timelabel = Label(self.topframe, text= "Time of Delivery")
        self.Timelabel.grid(row= 0, column= 0)

        self.stateslabel = Label(self.topframe, text= "States")
        self.stateslabel.grid(row= 0, column= 3, pady= 15)

        self.rbover = Radiobutton(self.topframe,
            text="Overnight",
            padx= 20,
            variable= self.var,
            value = 101).grid(row=1, column= 0)


        self.rb23 = Radiobutton(self.topframe,
            text="2-3 Days",
            padx= 20,
            variable= self.var,
            value = 201).grid(row=1, column= 1)

        
        self.rbweek = Radiobutton(self.topframe,
            text="1 week",
            padx= 20,
            variable= self.var,
            value = 301).grid(row=1, column= 2)


        self.states =("Nebraska", "Kansas", "Oklahoma", "Texas")
        self.dontbreak = ("Nebraska", "Kansas", "Oklahoma", "Texas")
        self.listB = Listbox(self.topframe)

        count = 1
        for I in self.states:
            self.listB.insert(count,I)
            count += 1
        self.listB.grid(row=1,column=3)


        self.optlabel = Label(self.topframe, text= "Shipping Options")
        self.optlabel.grid(row= 2, column= 0, pady = 15)

        self.checkvar1 = IntVar()
        self.chkfree = Checkbutton(self.topframe, text="Free Shipping", variable=self.checkvar1).grid(row=3, column=0, sticky=W)

        self.checkvar2 = IntVar()
        self.chktrack = Checkbutton(self.topframe, text="Tracking", variable=self.checkvar2).grid(row=3, column=1, sticky=W)

        self.checkvar3 = IntVar()
        self.chkInsure = Checkbutton(self.topframe, text="Insurance", variable=self.checkvar3).grid(row=3, column=2, sticky=W)



        self.Submit = Button(self.topframe, text = "Submit", command = self.display) 
        self.Submit.grid(row=5 , column=0, pady= 15)

        

        self.topframe.pack()
        self.root.mainloop()

    def display(self):
        try:
            rb = str(self.var.get())

            if rb == "101":
                rbinfo = "Overnight "

            elif rb == "201":
                rbinfo ="2-3 Days "
            
            elif rb == "301":
                rbinfo ="1 Week "

            totalinfo = (f'''
                {rbinfo}''') #I tried

            temp = self.listB.get(self.listB.curselection())
            totalinfo = (f'''{totalinfo} 
                {temp} ''')

            if self.checkvar1.get() == 1:
                totalinfo = (f'''{totalinfo} 
                    Free Shipping ''')

            if self.checkvar2.get() == 1:
                totalinfo = (f'''{totalinfo} 
                    Tracking ''')

            if self.checkvar3.get() == 1:
                totalinfo = (f'''{totalinfo} 
                    Insurance ''')

            w = mb.showinfo("Submit", totalinfo)
        except:
            w = mb.showinfo("Broken", "Sorry, something went wrong. Perhaps make sure you selected a State?" )

        

if __name__ == '__main__':
    A3GUI()
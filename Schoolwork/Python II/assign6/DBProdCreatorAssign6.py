import sqlite3

def main():
    conn = sqlite3.connect('Inventory.db')# Products and ProductDetails

    c = conn.cursor()
    
    c.execute('''CREATE TABLE IF NOT EXISTS Products (ProductID INTEGER PRIMARY KEY NOT NULL, PName VARCHAR(30) NOT NULL,
    InspectionCode INTEGER, ApprovedDate VARCHAR(10))''')

    try:
        c.execute('''INSERT INTO Products (ProductID, PName, InspectionCode, ApprovedDate) VALUES 
        (1, "Television", 638, "12/20/2015"), (2, "Monitor", 638, "05/27/2018"), (3, "Computer", 638, "02/19/2020"), 
        (4, "SmartPhone", 482, "07/29/2019"), (5, "Tablet", 482, "09/24/2019")''')#(6, "Laptop", 638, "06/28/2022")
    except:
        print("Table Already set up")

    ProdID = 0.5
    PName = ""
    InsCode = 0.5
    ApprDate = ""
    
    while ProdID != 0:
        ProdID = int(input("Enter the Product ID or 0 to stop adding products. "))
        try:
            if ProdID == 0:
                break
            PName = str(input("Enter the name of the product "))
            InsCode = int(input("Enter the Inspection code "))
            ApprDate = str(input("Enter the date the product was approved "))

            c.execute('INSERT INTO Products (ProductID, PName, InspectionCode, ApprovedDate) VALUES (?,?,?,?)', (ProdID, PName, InsCode, ApprDate))

        except:
            print("Sorry, something went wrong. Please make sure your ID is unique")

    conn.commit()
    conn.close()


if __name__ == '__main__':
    main()

            
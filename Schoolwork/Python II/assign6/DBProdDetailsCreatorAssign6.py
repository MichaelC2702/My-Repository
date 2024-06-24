import sqlite3

def main():
    conn = sqlite3.connect('Inventory.db')# Products and ProductDetails

    c = conn.cursor()
    
    c.execute('''CREATE TABLE IF NOT EXISTS ProductDetails (ProductID INTEGER NOT NULL, PManu VARCHAR(30) NOT NULL, Price FLOAT NOT NULL)''')


    try:
        c.execute('''INSERT INTO ProductDetails (ProductID, PManu, Price) Values
    (1, "ClearView", 149.99), (1, "LG", 179.99), (2, "ClearView", 239.99), (2, "LG", 249.99), (3, "MSI", 1299.99), (3, "Apple", 1349.99),
    (4, "Samsung", 379.99), (4, "Apple", 489.99), (5, "Apple", 449.99), (5, "Samsung", 479.99), (6, "HP", 799.99)''')#(6, "MSI", 864.99)
    except:
        print("Table Already set up")

    ProdID = 0.5
    PManu = ""
    Price = 0.5

    while ProdID != 0:
        ProdID = int(input("Enter the Product ID or 0 to stop adding product details. "))
        try:
            if ProdID == 0:
                    break
            PManu = str(input("Enter the name of the Manufacturer. "))
            Price = float(input("Enter the Price.  "))

            Test = c.execute(f'SELECT * FROM Products WHERE ProductID = {ProdID}', ) #This prevents product details being created for products that do not exist
            Test = c.fetchall()
            if Test == []:
                a = 4/0
            c.execute('INSERT INTO ProductDetails (ProductID, PManu, Price) VALUES (?,?,?)', (ProdID, PManu, Price))

        except:
            print("Sorry, something went wrong. Please make sure the Product ID is Valid.")


    conn.commit()
    conn.close()


if __name__ == '__main__':
    main()

            
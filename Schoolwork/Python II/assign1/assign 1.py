def main():
    try:
        prodName = str(input("Enter the name of your product. "))    
        if len(prodName) < 4:
            print("Sorry, We need a Valid Product I.D.. That I.D. might have been too short.")
            prodName = str(input("Enter the name of your product. "))   


        
        price = float(input("Enter the Price. "))
        while price <= 0:
            print("Sorry, we need a valid price. Valid Prices are positive non-zero numbers")
            price = float(input("Enter the Price. "))


        quantity = int(input("Enter the quantity. "))
        while quantity <= 0:
            print("Sorry, we need a positive number for this value.")
            quantity = int(input("Enter the quantity. "))   

        print (prodName, " sells for ", price, " with a total of ", quantity, " for a total of $", price * quantity)
        yes = input("press Enter to end")
        yes = yes

    except:
        print("Sorry, Something seems to have gone wrong. Remeber that product names have to be at least four letters, Prices and quantities must be positive non-zero numbers, and quantities must be whole numbers. ")


if __name__ == "__main__":
    main()

#I am so sorry for taking so long, no matter what I did the code would run, but neither show errors or display text. I went through so may revisions only to find I had forgot to put text in the first input query. 

    
    

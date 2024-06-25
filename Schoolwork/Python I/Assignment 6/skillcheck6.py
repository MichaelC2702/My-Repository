def main():
    x= 18
    y= 6
    z= 0

    try:
        a = x / y
        print(a)
    except:
        print("oops, 18 is somehow not divisible by 6 ")

    try:
        b = x / z
        print (b)
    except:
        print("oops, you can't divide by 0 in this reality yet.")


if __name__ == "__main__":
    main()

    

    

import Rectangle

def main():
    Rug1 = Rectangle.Rug(4, 3, 75)
    Rug2 = Rectangle.Rug(3, 7, 95)
    Rug3 = Rectangle.Rug(5, 5, 65)
    Rug4 = Rectangle.Rug(2, 4, 40)

    A = float(input('How long do you need your carpet to be?'))
    B = float(input('How Wide do you need Your carpet to be?'))

    Carpet_type1 = Rectangle.carpet(A, B, 5)
    Carpet_type2 = Rectangle.carpet(A, B, 5)
    Carpet_type3 = Rectangle.carpet(A, B, 5)

    Inventory_list = [Rug1, Rug2, Rug3, Rug4, Carpet_type1, Carpet_type2, Carpet_type3]
    for i in Inventory_list:
        print('The length is ', i.getLength())
        print('The Width is ', i.getWidth())
        if isinstance (i, Rectangle.Rug):
            print('The Price is ', i.getPrice())
            print('----------------------------------------------------')

        elif isinstance(i, Rectangle.carpet):
            print('the price per square foot is ', i.getprice_per_square_foot())
            print('----------------------------------------------------')

        else:
            print('What')
            

main()
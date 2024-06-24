import csv as c



def main():

    prod = input('Enter the product name: ')
    cat = input('Enter the product category: ')
    hand = input('Enter the number on hand: ')
    pri = input('Enter the unit price: ')

    data = [prod,cat,hand,pri]

    with open('Products.csv', "a", newline="") as File:
        writer = c.writer(File)
        writer.writerow(data)




if __name__ == '__main__':
    main()

            
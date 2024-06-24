import json as j


def main():
    data = open('products.json', 'r') # I found it easier to covert the file to a JSON file (All I had to do was re-save the file) as having a variable would not work for me for some reason
     
    a = []
    for Line in data:
        a.append(j.loads(Line))

    total = 0
    monthtotal = 0

    for Item in a:
        product = (Item["product"])
        price = (Item["price"])
        sold = (Item["sold"])

        monthtotal = float(price) * float(sold)
        monthtotal = round(monthtotal, 3) #Don't you just love when computers add an extra 15 digits to your decimals?
        total += monthtotal
        print (f'product: {product}, Monthly Sales: ${monthtotal}')
    print(f'Total: ${total}')

if __name__ == '__main__':
    main()

            
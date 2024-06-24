import json as j


def main():
    data = open('products.json', 'r')
     
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
        monthtotal = round(monthtotal, 3)
        total += monthtotal
        print (f'product: {product}, Monthly Sales: ${monthtotal}')
    print(f'Total: ${total}')

if __name__ == '__main__':
    main()

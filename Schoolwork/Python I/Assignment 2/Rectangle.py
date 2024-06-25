class Rectangle:
    def __init__(self, Length, Width):
        self.__Length = Length
        self.__Width = Width 

    def setLength(self, Length):
        self.__Length = Length

    def getLength(self):
        return self.__Length

    def setWidth(self, Width):
        self.__Width = Width

    def getWidth(self):
        return self.__Width

    def getArea(self):
        return self.__Length * self.__Width

class Rug(Rectangle):
    def __init__(self, Length, Width, Price):
        Rectangle.__init__(self, Length, Width)
        self.__Price = Price

    def getPrice(self):
        return self.__Price

class carpet(Rectangle):
    def __init__(self, Length, Width, price_per_square_foot):
        Rectangle.__init__(self, Length, Width)
        self.__price_per_square_foot = price_per_square_foot

    def setprice_per_square_foot(self, price_per_square_foot):
        self.__price_per_square_foot = price_per_square_foot

    def getprice_per_square_foot(self):
        return self.getArea() * self.__price_per_square_foot
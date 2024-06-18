CREATE TABLE Customers (CustomerID INTEGER NOT NULL, CustomerFirstName VARCHAR(20) 
 NOT NULL, CustomerLastName VARCHAR(20) NOT NULL, CustomerState VARCHAR(20) NOT NULL,
 CustomerCity VARCHAR(20) NOT NULL, CustomerStreet VARCHAR(20) NOT NULL, CustomerZip VARCHAR(15) NOT NULL,
 CustomerPhone VARCHAR(15), CustomerPayID INTEGER NOT NULL,
 CONSTRAINT Customers_PK PRIMARY KEY (CustomerID));
	
CREATE TABLE Restaurants (RestaurantID INTEGER NOT NULL, RestaurantName VARCHAR(30) NOT NULL,
 RestaurantPayID INTEGER NOT NULL, RestaurantState VARCHAR(20) NOT NULL, RestaurantCity VARCHAR(15) NOT NULL, 
 RestaurantStreet VARCHAR(20) NOT NULL, RestaurantZip VARCHAR(20) NOT NULL,
 RestaurantPhone VARCHAR(15) NOT NULL, RestaurantCuisine VARCHAR (20) NOT NULL,
 CONSTRAINT Restaurants_PK PRIMARY KEY (RestaurantID));

CREATE TABLE Drivers (DriverID INTEGER NOT NULL, DriverFirstName VARCHAR(20) NOT NULL, 
 DriverLastName VARCHAR(20), DriverPhone VARCHAR(15) NOT NULL, DriverPlateNum VARCHAR (10) NOT NULL,
 DriverLicenseNum VARCHAR (10) NOT NULL, DriverPayID INTEGER NOT NULL, DriverStatus VARCHAR(10)
 NOT NULL, CONSTRAINT Drivers_PK PRIMARY KEY (DriverID));

CREATE TABLE Orders (OrderID INTEGER NOT NULL, CustomerID INTEGER NOT NULL,
 RestaurantID INTEGER NOT NULL, DriverID INTEGER NOT NULL, OrderTime VARCHAR(25) NOT NULL,
 OrderStatus VARCHAR (15),
 CONSTRAINT Orders_PK PRIMARY KEY (OrderID), 
 CONSTRAINT Orders_CID_FK FOREIGN KEY(CustomerID) REFERENCES Customers(CustomerID),
 CONSTRAINT Orders_RID_FK FOREIGN KEY(RestaurantID) REFERENCES Restaurants(RestaurantID), 
 CONSTRAINT Orders_DID_FK FOREIGN KEY(DriverID) REFERENCES Drivers(DriverID));
 
/*** 
I do hope you understand nobody would make a 12 hr drive from Indianapolis to Omaha 
to deliver a fast food order. the rate on that would be crazy.
***/
 
INSERT INTO Customers(CustomerID, CustomerFirstName, CustomerLastName, CustomerState, 
 CustomerCity, CustomerStreet, CustomerZip, CustomerPhone, CustomerPayID) VALUES 
 (1, 'April', 'Ludgate', 'NE', 'Omaha', '123 S 55 Ave', '68132', '402-553-4397', 23456),
 (2, 'Leslie', 'Knope', 'IN', 'Pawnee','4387 Waffles Drive', '46011', '234-432-5437', 98754),
 (3, 'Ron', 'Swanson', 'IN', 'Pawnee','987 Bacon Avenue', '46011', '456-987-3265', 234789),
 (4, 'Andy', 'Dwyer', 'IN', 'Pawnee', '2468 The Pit', '46011', '', 12390);
 
INSERT INTO Restaurants(RestaurantID, RestaurantName, RestaurantState,
 RestaurantCity, RestaurantStreet, RestaurantZip,
 RestaurantPhone, RestaurantCuisine, RestaurantPayID) VALUES
 (1, 'Paunch Burger', 'IN', 'Pawnee', '6872 Lard Lane', '46011', '678-893-1568', 'Fast food', 4826),
 (2, "JJ's Diner", 'IN', 'Pawnee','23428 Main St.', '46011', '456-987-3185', 'Breakfast', 78623),
 (3, "Mulligan's", 'IN', 'Indianapolis', '6876 Classy Rd.', '46011', 'Steakhouse', 48623);
 

INSERT INTO Drivers (DriverID, DriverFirstName, DriverLastName, DriverPhone, DriverPlateNum,
 DriverLicenseNum, DriverPayID, DriverStatus) VALUES
 (1, 'Henry', 'Roth', '286-937-2250', 'IUC989', 'C04790049', 444862, 'Active'),
 (2, 'Charity', 'Ozborne', '815-605-0336', 'REW222', 'D89973937', 959227, 'Active'),
 (3, 'Fritz', 'Macias', '943-893-6193', 'XUA177', 'U06119817', 718371, 'Active'),
 (4, 'Brenden ', 'Hill', '513-284-9064', 'IOL455', 'X22173227', 334452, 'Active'),
 (5, 'Leah', 'Peters', '909-477-8843', 'AJA879', 'V44276914', 603268, 'Inactive');
 
INSERT INTO Orders (OrderID, CustomerID, RestaurantID, 
 DriverID, OrderTime, OrderStatus)
 VALUES 
 (1, 1, 1, 1, '9/30/2020 6:44' , 'Out'),
 (2, 1, 1, 2, '9/30/2020 10:44', 'Placed'),
 (3, 2, 2, 3, '9/30/2020 10:54', 'Fulfilled'),
 (4, 3, 3, 4, '9/30/2020 10:46', 'Placed'),
 (5, 4, 2, 1, '9/30/2020 11:44', 'cancelled');

 
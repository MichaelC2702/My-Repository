// assignment 1
// Michael Clarke
// converting Radius to Area and Circumfrence
// 09/11/2023

#include <iostream>
using namespace std;

int main()
{
    float Area, Radius, Circumfrence = 0;

    cout << "Enter the circle's radius: ";
    cin >> Radius; 
    Area = ((Radius * Radius) * 3.14159);   // I Couldn't get ^(2) to work, assuming that is not the proper syntax
    cout << "The Radius is " << Area << "\n";

    cout << "Enter the circle's radius: ";
    cin >> Radius;
    Circumfrence = ((2 * 3.14159) * Radius);
    cout << "The Circumfrence is " << Circumfrence;
}
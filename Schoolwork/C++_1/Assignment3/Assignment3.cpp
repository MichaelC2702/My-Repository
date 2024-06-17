// ClarkeAssignment3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Assignment 3
//Michael Clarke
//Update assignment 1 with Choice
//9/24/2023
//


#include <iostream>
using namespace std;

int main()
{
    float Area, Radius, Circumfrence = 0;
    bool Mode;

    cout << "Enter the circle's radius: ";
    cin >> Radius;

    cout << "Enter a 1 if you would like the circle's Radius or a 0 for the Circumfrence: ";
    cin >> Mode;
    
    //This might have been the fastest I have gotten done with a coding assignment
    if (Mode == 1)
    {
        Area = ((Radius * Radius) * 3.14159);   // I Couldn't get ^(2) to work, assuming that is not the proper syntax
        cout << "The Radius is " << Area << "\n";
    }
    else
    {
        Circumfrence = ((2 * 3.14159) * Radius);
        cout << "The Circumfrence is " << Circumfrence;
    }

}

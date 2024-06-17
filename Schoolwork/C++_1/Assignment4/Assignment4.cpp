//Assignment 4
//Michael Clarke
//Update assignment 3 with Loops
//9/24/2023
//


#include <iostream>
using namespace std;

int main()
{
    double Area, Radius, Circumfrence = 0;
    int Mode;

    float ShouldRun;
    float Cont;

    cout << "Do you want to find the Radius or Diameter of a Circle? Enter 1 to run or 0 to quit. ";
    cin >> Cont;

    while (Cont != 0)
    {
        do
        {
            cout << "Enter a 1 if you would like the circle's Radius, Enter 2 for the Circumfrence, or a 0 to quit: ";
            cin >> Mode;


            //This might have been the fastest I have gotten done with a coding assignment
            if (Mode == 1)
            {
                cout << "Enter the circle's radius: ";
                cin >> Radius;

                Area = ((Radius * Radius) * 3.14159);   // I Couldn't get ^(2) to work, assuming that is not the proper syntax
                cout << "The Radius is " << Area << "\n";
            }
            else if (Mode == 2)
            {
                cout << "Enter the circle's radius: ";
                cin >> Radius;

                Circumfrence = ((2 * 3.14159) * Radius);
                cout << "The Circumfrence is " << Circumfrence << "\n";;
            }
            else if (Mode !=0)
            {
                cout << "If you are seeing this message, Please double check your last input. " << "\n";
            }
            else
            {
                Cont = Mode;
            }
            
        } while (Mode != 0);
    }
}
//
//Assignment 3
//Michael Clarke
//Temprature conversion 
//12/07/2023
//
#include <iostream>
#include "ClarkeHeader.h" 
#include "Conversions.h" 
#include "Menu.h" 



int main()
{
    string Currentop;
    double initTemp = 0, afterTemp = 0;

    bool loopControl = true;
    char exitcon = 'X';

    getHeading("Assignment 3\n");
    cout << "\n";

    do
    {
        Currentop = menu();

        if (Currentop == "Exit")
        {
             exitcon = 'N';
             loopControl = false;
             break;
        }
        else
        {
            Convert(Currentop, initTemp, afterTemp);
        }

        if (exitcon != 'N')
        {
            outputGeneric(Currentop, initTemp, afterTemp);
        }

        while (exitcon == 'X')
        {
            cout << "\n";
            cout << "would you like to run this program again? Y or N. ";
            cin >> exitcon;
            exitcon = toupper(exitcon);
            if (exitcon == 'Y')
            {
                break;
            }
            else if (exitcon == 'N')
            {
                loopControl = false;
            }
            else
            {
                cout << "Sorry, something seems to have gone wrong. Please try again. \n";
            }
        }
        //reset exitcon for future runs
        exitcon = 'X';
    } while (loopControl == true);
}

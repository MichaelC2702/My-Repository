//
//Assignment 7
//Michael Clarke
//Temprature conversion
//10/29/2023
//
#include <iostream>
#include "ClarkeHeader.h" 
#include "Functions.h" 



int main()
{
    string initType;
    double initial_temp = 0, after_temp = 0;
    ConvType currentop;

    bool loopControl = true;
    char exitcon = 'X';

    getHeading("Assignment 7\n");
    cout << "\n";

    do
    {
        ConvType currentop = convSelector();

        switch (currentop)
        {

        case CelToFah:
            initType = "Celsius";
            initial_temp = inputTemp(initType);
            after_temp = ctoF(initial_temp);
            

        case CelToKel:
            initType = "Celsius";
            initial_temp = inputTemp(initType);
            after_temp = ctoK(initial_temp);
            

        case FahToCel:
            initType = "Fahrenheit";
            initial_temp = inputTemp(initType);
            after_temp = ftoC(initial_temp);
            

        case FahToKel:
            initType = "Fahrenheit";
            initial_temp = inputTemp(initType);
            after_temp = ftoK(initial_temp); 
            

        case KelToCel:
            initType = "Kelvin";
            initial_temp = inputTemp(initType);
            after_temp = ktoC(initial_temp);
         

        case KelToFah:
            initType = "Celsius";
            initial_temp = inputTemp(initType);
            after_temp = ktoF(initial_temp);
            

        case Exit:
            exitcon = 'N';
            loopControl = false;
        }


        if (exitcon != 'N')
        {
            outputGeneric(currentop, initial_temp, after_temp);
        }
       
        while (exitcon == 'X')
        {
            cout << "\n";
            cout << "would you like to run this program again? Y or N. ";
            cin >> exitcon;
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
                exitcon = 'X';
            }
        }
        //reset exitcon for future runs
        exitcon = 'X';
    } while (loopControl == true);
}

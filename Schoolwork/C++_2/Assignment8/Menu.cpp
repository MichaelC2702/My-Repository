#include <iostream>
#include <iomanip>
#include <conio.h>
#include "Menu.h" 

using namespace std;

//Changed to strings from the enum convtype to fit the assignment
string menu()
{
    char initType, afterType;
    string Conversion = "Exit";
    int loopcontrol = 1;
    int badEntry = 0;




    while (loopcontrol == 1)
    {
        try
        {


            cout << "\n";

            cout << "For the following questions, please enter  'f' for Farenheit, 'c' for Celsius, or 'k' for Kelvin. \n";

            cout << "Please enter the starting temperature or e to quit: ";

            cin >> initType;

            cout << "\n";

            // allows uppercase letters to be used
            initType = tolower(initType);

            // matching the conversions
            switch (initType)
            {
            case 'c':
                //Moved the if structure inside here so the error is thrown before
                if (initType != 'E')
                {
                    cout << "Please enter the temperature you want to convert to : ";

                    cin >> afterType;

                    cout << "\n";
                }
                // allows uppercase letters to be used
                afterType = tolower(afterType);
                if (afterType == 'f')
                {
                    Conversion = "CelToFah";
                    loopcontrol = 0;
                }
                else if (afterType == 'k')
                {
                    Conversion = "CelToKel";
                    loopcontrol = 0;
                }
                else
                {
                    //cout << "Error at convSelector c - # - invalid second type " << afterType;
                    throw true;
                }
                //I wonder how that was not a problem back then
                break;
            case 'f':
                if (initType != 'E')
                {
                    cout << "Please enter the temperature you want to convert to : ";

                    cin >> afterType;

                    cout << "\n";
                }
                // allows uppercase letters to be used
                afterType = tolower(afterType);
                if (afterType == 'c')
                {
                    Conversion = "FahToCel";
                    loopcontrol = 0;
                }
                else if (afterType == 'k')
                {
                    Conversion = "FahToKel";
                    loopcontrol = 0;
                }
                else
                {
                    //cout << "Error at convSelector f - # : invalid second type " << afterType;
                    throw true;
                }
                break;
            case 'k':
                if (initType != 'E')
                {
                    cout << "Please enter the temperature you want to convert to : ";

                    cin >> afterType;

                    cout << "\n";
                }
                // allows uppercase letters to be used
                afterType = tolower(afterType);
                if (afterType == 'f')
                {
                    Conversion = "KelToFah";
                    loopcontrol = 0;
                }
                else if (afterType == 'c')
                {
                    Conversion = "KelToCel";
                    loopcontrol = 0;
                }
                else
                {
                    //cout << "Error at convSelector k - # : invalid second type " << afterType;
                    throw true;
                }
                break;
            case 'e':
                Conversion = "Exit";
                loopcontrol = 0;
                break;
            default:
                //cout << "Error at convSelector # - # : invalid starting type " << initType;
                throw 0;
            }
        } 
        catch (bool)
        {
            cout << "Error at convSelector - invalid second type " << afterType;
            badEntry++;
        }
        catch (int)
        {
            cout << "Error at convSelector - invalid starting type " << initType;
            badEntry++;
        }
        if (badEntry == 3)
        {
            cout << "\n" << "Program Terminating due to bad entries. Please slow down and ensure your inputs.";
            _getch();
            terminate();
        }
    }

    return Conversion;
}

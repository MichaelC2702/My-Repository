//
//Assignment 9
//Michael Clarke
//Conversion Update
//1/08/2024
//
#include <iostream>
#include <conio.h>
#include "ClarkeHeader.h" 
#include "Conversions.h" 


int main()
{
    bool loopControl = true;
    char exitcon = 'X';
    char again = 'Y';
    int badEntry;
    bool TryLoop = true;

    Convert currentCycle;

    getHeading("Assignment 5\n");
    cout << "\n";


    do
    {
        //Ensure the again structure can be reentered
        TryLoop = true;

        currentCycle.setCurrentOp(currentCycle.Menu());

        if (currentCycle.getCurrentOp() == EXIT)
        {
            loopControl = false;
            TryLoop = false;
            again = 'N';
        }
        else if (currentCycle.getCurrentOp() == RETRY)
        {
            //Retry gets called when input failure occurs, so there is no need to enter the tryloop
            TryLoop = false;
        }
        else
        {        
            currentCycle.Conversion();
            currentCycle.ConvertOutPut();
        }

        //Tryloop both keeps the code in this segment when there is input failure for the again variable
        //but also allows the structure to be skipped easier when the EXIT and RETRY conditions occur
        while (TryLoop == true)
        {
            try
            {
                cout << "\n";
                cout << "Do you wish to make another conversion? Y or N ";
                cin >> again;
                again = toupper(again);

                if (again == 'Y')
                {
                    //TryLoop is set to false, else the only way to exit this structure is to cause an error
                    TryLoop = false;
                }
                else if (again == 'N')
                {
                    loopControl = false;
                    TryLoop = false;
                }
                else
                {
                    throw 0;
                }
                cout << "\n";
            }
            catch (int)
            {
                currentCycle.incrementBadEntry();
            }
        }
    } while (loopControl == true);
}
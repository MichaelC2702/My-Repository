//
//Assignment 5
//Michael Clarke
//
//1/08/2024
//
#include <iostream>
#include "ClarkeHeader.h" 
#include "Conversions.h" 
#include "Menu.h" 


int main()
{
    bool loopControl = true;
    char exitcon = 'X';
    char again = 'Y';
    double StoredBeforeUnit = 0;

    Convert currentCycle;

    getHeading("Assignment 5\n");
    cout << "\n";

    currentCycle.getFirstName();


    do
    {
        currentCycle.setCurrentOp(Menu(StoredBeforeUnit));
        currentCycle.setBeforeUnit(StoredBeforeUnit);

        currentCycle.Conversion();

        if (currentCycle.getCurrentOp() == EXIT)
        {
            loopControl = false;
            again = 'N';
        }
        else if (currentCycle.getCurrentOp() == RETRY)
        {
            loopControl = true;
        }
        else
        {
            currentCycle.ConvertOutPut();
        }

        // No point in asking again if the user decided to type Exit in the mode prompt
        if (again == 'Y')
        {
            cout << "\n";
            cout << "Do you wish to make another conversion? Y or N ";
            cin >> again;
            again = toupper(again);
        }

        if (again == 'Y')
        {
            loopControl = true;
        }
        else if (again == 'N')
        {
            loopControl = false;
        }
        cout << "\n";

    } while (loopControl == true);


}
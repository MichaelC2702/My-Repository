//Assignment 6
//Michael Clarke
//The Speedometer
//10/23/2023
//
#include <iostream>

#include "ClarkeHeader.h" 
#include "Functions.h" 

using namespace std;

int main()
{
    //Main Variables
    double newTire = 0, oldTire = 0, ratio = 0;
    int miles = 10;


    //Loop Variables
    bool runProgram = true;
    string runCalc;
    string confirm = "N";


    getHeading("Assignment 6\n");
    cout << "\n";
    cout << "Do you wish to do this tire conversion program? Y or N : ";
    
    // I chose a do-while loop as I felt it would be easier to create the exit condition
    do
    {
        //Feels weird putting cin here and not right after both cout statements, but putting it here means I only need one.
        cin >> runCalc;
        cout << "\n";

        if (runCalc == "Y")
        {
            // yeah this isn't needed but confirmation is nice
            do
            {
                // Calling an if right after starting a do while lioop was my only idea to not run the tire prompts on input failure
                if (confirm == "N")
                {
                    cout << "Please enter the old tire size : ";
                    cin >> oldTire;
                    cout << "Please enter the new tire size : ";
                    cin >> newTire;
                    cout << "\n";
                }
                else
                {
                    cout << "Sorry, Something seems to have gone wrong. Please be aware that input is case-sensitive. \n";
                }

                //confirmation
                cout << "Is this correct? Old tires : " << oldTire << " New tires : " << newTire << " Y or N : ";
                cin >> confirm;
                cout << "\n";

            } while (confirm != "Y");

            ratio = ratioCalc(newTire, oldTire);

            for (miles; miles <= 100; miles = miles + 10)
            {
                speedcalc(ratio, miles);
            }

        }
        else if (runCalc == "N")
        {
            runProgram = false;
            break;
        }
        else
        {
            cout << "Sorry, Something seems to have gone wrong. Please be aware that input is case-sensitive. \n";
        }

        //reset the confirm variable or it will always run with the first input
        confirm = "N";

        // reset miles too, otherwise calculation is skipped entirely
        miles = 10;

        cout << "\n";
        cout << "Do you wish to do this tire conversion program Again? Y or N :"; 

    } while (runProgram = true);
}
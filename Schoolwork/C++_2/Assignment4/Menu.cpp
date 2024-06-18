#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>
#include "ClarkeHeader.h" 
#include "Conversions.h" 
#include "Menu.h" 



ConversionOp Menu(double &BeforeUnit)
{

	string firstType = " ";
	string confirm = " ";
	// nothing should ever set LoopControl to false, I just need a dummy variable.
	bool loopControl = true;
	double tempunit = 0;

	int stringsize = 0;
	int stringPos = 0;
	char currentChar = ' ';
	string upperString = "";

	cout << "\n For the Following Questions, please choose your unit from Feet, Inches, Cm, Lbs, and Kg.";
	cout << "\n Please enter your starting unit or enter 'Exit' to end. ";

	cin >> firstType;

	//firstType = toupper(firstType);

	stringsize = firstType.size() - 1;
	while (stringPos <= stringsize)
	{
		currentChar = firstType.at(stringPos);
		currentChar = toupper(currentChar);
		upperString.append(1, currentChar);
		stringPos++;
	}
	firstType = upperString;

	//reset the string variables
	stringsize = 0;
    stringPos = 0;
	currentChar = ' ';
	upperString = "";

	if (firstType == "FEET")
	{
		while (loopControl == true)
		{
			cout << "\n" << "Do you wish to convert Feet / Inches to Centimeters? Y or N ";
			cin >> confirm;

			//confirm = toupper(confirm);
			stringsize = confirm.size() - 1;
			while (stringPos <= stringsize)
			{
				currentChar = confirm.at(stringPos);
				currentChar = toupper(currentChar);
				upperString.append(1, currentChar);
				stringPos++;
			}
			confirm = upperString;

			stringsize = 0;
			stringPos = 0;
			currentChar = ' ';
			upperString = "";

			if (confirm == "Y")
			{
				cout << "\n" << "Enter your value for Feet. ";
				cin >> tempunit;
				tempunit = tempunit * 12;
				cout << "\n" << "Enter your value for Inches. ";
				cin >> BeforeUnit;
				BeforeUnit += tempunit;


				return FItoCM;
			}
			else if (confirm == "N")
			{
				return RETRY;
			}
			else
			{
				cout << "\n" << "Sorry, something seems to have gone wrong, please try again.";
				return RETRY;
			}
		}
	}
	else if (firstType == "INCHES")
	{
		while (loopControl == true)
		{
			cout << "\n" << "Do you wish to convert Inches to Centimeters? Y or N ";
			cin >> confirm;

			stringsize = confirm.size() - 1;
			while (stringPos <= stringsize)
			{
				currentChar = confirm.at(stringPos);
				currentChar = toupper(currentChar);
				upperString.append(1, currentChar);
				stringPos++;
			}
			confirm = upperString;

			stringsize = 0;
			stringPos = 0;
			currentChar = ' ';
			upperString = "";

			if (confirm == "Y")
			{
				cout << "\n" << "Enter your value for Inches. ";
				cin >> BeforeUnit;

				return ItoCM;
			}
			else if (confirm == "N")
			{
				return RETRY;
			}
			else
			{
				cout << "\n" << "Sorry, something seems to have gone wrong, please try again.";
				return RETRY;
			}
		}
	}
	else if (firstType == "CM")
	{
		while (loopControl == true)
		{
			cout << "\n" << "Do you wish to convert Centimeters to Feet or Inches? Enter Feet, Inches or enter N for No. ";
			cin >> confirm;
			
			stringsize = confirm.size() - 1;
			while (stringPos <= stringsize)
			{
				currentChar = confirm.at(stringPos);
				currentChar = toupper(currentChar);
				upperString.append(1, currentChar);
				stringPos++;
			}
			confirm = upperString;

			stringsize = 0;
			stringPos = 0;
			currentChar = ' ';
			upperString = "";

			if (confirm == "FEET")
			{
				cout << "\n" << "Enter your value for Centimeters. ";
				cin >> BeforeUnit;

				return CMtoF;
			}
			else if (confirm == "INCHES")
			{
				cout << "\n" << "Enter your value for Centimeters. ";
				cin >> BeforeUnit;

				return CMtoI;
			}
			else if (confirm == "N")
			{
				return RETRY;
			}
			else
			{
				cout << "\n" << "Sorry, something seems to have gone wrong, please try again.";
				return RETRY;
			}
		}
	}
	else if (firstType == "LBS")
	{
		while (loopControl == true)
		{
			cout << "\n" << "Do you wish to convert Pounds to Kilograms? Y or N ";
			cin >> confirm;
			
			stringsize = confirm.size() - 1;
			while (stringPos <= stringsize)
			{
				currentChar = confirm.at(stringPos);
				currentChar = toupper(currentChar);
				upperString.append(1, currentChar);
				stringPos++;
			}
			confirm = upperString;

			stringsize = 0;
			stringPos = 0;
			currentChar = ' ';
			upperString = "";

			if (confirm == "Y")
			{
				cout << "\n" << "Enter your value for Pounds. ";
				cin >> BeforeUnit;

				return LBStoKG;
			}
			else if (confirm == "N")
			{
				return RETRY;
			}
			else
			{
				cout << "\n" << "Sorry, something seems to have gone wrong, please try again.";
				return RETRY;
			}
		}
	}
	else if (firstType == "KG")
	{
		while (loopControl == true)
		{
			cout << "\n" << "Do you wish to convert Kilograms to Pounds? Y or N ";
			cin >> confirm;

			stringsize = confirm.size() - 1;
			while (stringPos <= stringsize)
			{
				currentChar = confirm.at(stringPos);
				currentChar = toupper(currentChar);
				upperString.append(1, currentChar);
				stringPos++;
			}
			confirm = upperString;

			stringsize = 0;
			stringPos = 0;
			currentChar = ' ';
			upperString = "";

			if (confirm == "Y")
			{
				cout << "\n" << "Enter your value for Kilograms. ";
				cin >> BeforeUnit;

				return KGtoLBS;
			}
			else if (confirm == "N")
			{
				return RETRY;
			}
			else
			{
				cout << "\n" << "Sorry, something seems to have gone wrong, please try again.";
				return RETRY;
			}
		}
	}
	else if (firstType == "EXIT")
	{
		return EXIT;
	}
	else
	{
		cout << "\n" << "Sorry, something seems to have gone wrong, please try again.";
		return RETRY;
	}
	

}
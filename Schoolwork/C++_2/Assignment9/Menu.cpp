#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>
#include "ClarkeHeader.h" 
#include "Conversions.h" 



//Even though I moved Menu to the Conversions 
ConversionOp Convert::Menu()
{
	try
	{
		string firstType = " ";
		string confirm = " ";
		//There used to be a "loopcontrol" variable here, But none of the loops that relied on it needed to be loops in the first place, so there was no point.
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
				throw 0;
			}
		}
		else if (firstType == "INCHES")
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
				throw 0;
			}
		}
		else if (firstType == "CM")
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
				throw 0;
			}
		}
		else if (firstType == "LBS")
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
				throw 0;
			}
		}
		else if (firstType == "KG")
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
				throw 0;
			}
		}
		else if (firstType == "EXIT")
		{
			return EXIT;
		}
		else
		{
			throw 0;
		}
	}
	catch (int)
	{
		//Increment now also does the check to terminate the code
		incrementBadEntry();
		return RETRY;
	}


}
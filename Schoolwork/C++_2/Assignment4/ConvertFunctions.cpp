#include <iostream>
#include <conio.h>
#include "ClarkeHeader.h" 
#include "Conversions.h" 
#include "Menu.h" 


ConversionOp Convert :: getCurrentOp()
{
	return CurrentOp;
}

double Convert :: getBeforeUnit()
{
	return BeforeUnit;
}

void Convert::setCurrentOp(ConversionOp Current)
{
	this->CurrentOp = Current;
}

void Convert::setBeforeUnit(double Current)
{
	this->BeforeUnit = Current;
}


double Convert :: Conversion()
{
	switch (CurrentOp)
	{
		//FI and I toCM are the same as if you check in the Menu I convert Feet to Inches to be stored in one variable
		case FItoCM:
			AfterUnit = BeforeUnit * 2.54;
			return AfterUnit;

		case ItoCM:
			AfterUnit = BeforeUnit * 2.54;
			return AfterUnit;

		case CMtoF:
			AfterUnit = BeforeUnit / 30.48;
			return AfterUnit;

		case CMtoI:
			AfterUnit = BeforeUnit / 2.54;
			return AfterUnit;

		case LBStoKG:
			AfterUnit = BeforeUnit * 0.45359;
			return AfterUnit;

		case KGtoLBS:
			AfterUnit = BeforeUnit / 0.45359;
			return AfterUnit;

	}
}


void Convert :: ConvertOutPut()
{
	double feet = 0;
	double inches;
	string beforeType;
	string afterType;

	if (CurrentOp == FItoCM)
	{
		for (BeforeUnit; BeforeUnit >= 12; BeforeUnit -= 12)
		{
			feet++;
		}
		inches = BeforeUnit;
		beforeType = "Feet";
		afterType = "Centimeters";
	}
	else if (CurrentOp == ItoCM)
	{
		beforeType = "Inches";
		afterType = "Centimeters";
	}
	else if (CurrentOp == CMtoF)
	{
		beforeType = "Centimeters";
		afterType = "Feet";
	}
	else if (CurrentOp == CMtoI)
	{
		beforeType = "Centimeters";
		afterType = "Inches";
	}
	else if (CurrentOp == LBStoKG)
	{
		beforeType = "Pounds";
		afterType = "Kilograms";
	}
	else if (CurrentOp == KGtoLBS)
	{
		beforeType = "Kilograms";
		afterType = "Pounds";
	}


	if (CurrentOp == FItoCM)
	{
		cout << "\n" << feet << " Ft " << inches << " Inch(es) Converts to " << AfterUnit << " Centimeters.";
	}
	else
	{
		cout << "\n" << BeforeUnit << " " << beforeType << " Converts to " << AfterUnit << " " << afterType << ".";
	}

}


Convert :: ~Convert()
{
	//This has been triggering at the end, after I pass through exit.
	cout << "Press any key to end \n";
	_getch();
}
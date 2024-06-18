#include <iostream>
#include <conio.h>
#include "ClarkeHeader.h" 
#include "Conversions.h" 
#include "Menu.h" 


void getName::getFirstName()
{
	string name = "";
	cout << "\n" << "Please state your first name ";
	cin >> name;

	setFirstName(name);
}

void getName::setFirstName(string name)
{
	this->Fname = name; 
}

void getName::ConvertOutPut()
{
	cout << "\n" << Fname << ", ";
	
}

getName :: ~getName()
{
	cout << "\n" << "Thank you for using this program, " << Fname ;
	cout << "\n" << "Press any key to end.";
	_getch();
}

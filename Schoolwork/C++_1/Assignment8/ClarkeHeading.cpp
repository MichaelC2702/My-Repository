
#include <iostream>
#include <conio.h>
#include <fstream>
#include "ClarkeHeader.h" 


using namespace std;

// Global Variables
string firstName = "Michael";
string lastName = "Clarke";
void getHeading(string x)
{
	string assignment = x;
	cout << "\n\n  " << getFullName();
	cout << "\n  C++ Programming 1\n  " << assignment << endl << endl;
	return;
}

void getClosing()
{
	
	cout << "\n\n  Program ended";
	cout << "\n  Press the Enter key to continue.\n\n";
	_getch();
}

void outputHeading(ofstream& outFile, string x)
{
	string assignment = x;
	outFile << getFullName();
	outFile << "\nC++ Programming 1\n" << assignment << endl << endl;
}	// end BowersHeading function


void outputClosing(ofstream& outFile)
{
	outFile << "\n\nProgram ended";
}


string getFirstName()
{
	return firstName;
}

string getLastName()
{
	return lastName;
}

string getFullName()
{
	return getFirstName() + " " + getLastName();
}


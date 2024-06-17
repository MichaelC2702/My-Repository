#include <iostream>
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


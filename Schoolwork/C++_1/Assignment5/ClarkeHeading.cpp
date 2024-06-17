
#define _CRT_SECURE_NO_WARNINGS  //talk to them about what this does

#include <iostream>
#include <conio.h>
#include <chrono>
#include <ctime>
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
}	// end BowersHeading function

void getClosing()
{
	auto timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());
	cout << "\n\n  Program ended" << " at " << ctime(&timenow);
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
	auto timenow = chrono::system_clock::to_time_t(chrono::system_clock::now());
	outFile << "\n\nProgram ended" << " at " << ctime(&timenow);
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


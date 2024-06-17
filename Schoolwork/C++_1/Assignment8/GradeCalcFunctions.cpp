#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
#include <fstream>
#include "Functions.h" 



using namespace std;


string StudentEntry(ifstream& inFile)
{
	string currententry;
	getline(inFile, currententry);
	
	return currententry;
}

double GradeTotal(ifstream& inFile)
{

	double temptotal = 0;
	double numberofGrades = 0;
	double finalAmount;
	int listIndex = 0;

	char tempgrade = ' ';
	string gradelist;
	getline(inFile, gradelist);
	



	while (tempgrade != '%')
	{
		
		tempgrade = gradelist.at(listIndex);

		if (tempgrade == 'A')
		{
			temptotal = temptotal + 4;
			numberofGrades++;
		}
		else if (tempgrade == 'B')
		{
			temptotal = temptotal + 3;
			numberofGrades++;
		}
		else if (tempgrade == 'C')
		{
			temptotal = temptotal + 2;
			numberofGrades++;
		}
		else if (tempgrade == 'D')
		{
			temptotal = temptotal + 1;
			numberofGrades++;
		}
		else if (tempgrade == 'F')
		{
			numberofGrades++;
		}
		else if (tempgrade == '%')
		{
			break;
		}
		else
		{
			cout << "A grade seems to be missing or improperly inputted. Please make sure all grades in the input file are capitalized.";
			cout << "\n";
		}
		listIndex++;
	}

	finalAmount = temptotal / numberofGrades;

	return finalAmount;	
	// This is supposed to be two different structures in the assignment, but I have them together here as 
	// I only have to return one value this way, or else the only way I see of getting both total and 
	// numberofGrades variable back in the main would be to have the decision structure in the main file.
}

void GradeOutPut(ofstream& outFile, string name, double gpa)
{
	outFile << fixed << showpoint << setprecision(2);
	outFile << left << setw(25) << name << "'s GPA is ";
	outFile.unsetf(ios::left);
	outFile << right << setw(5) << gpa << endl;
	outFile.unsetf(ios::right);

	// no need for these two to have a seperate output function
	cout << fixed << showpoint << setprecision(2);
	cout << left << setw(25) << name << "'s GPA is ";
	cout.unsetf(ios::left);
	cout << right << setw(5) << gpa;
	cout.unsetf(ios::right);
	cout << "\n";
}
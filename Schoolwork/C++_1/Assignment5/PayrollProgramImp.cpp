#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
#include <fstream>
#include "Functions.h" 

using namespace std;

double getInfoOneEmp(ifstream& inFile, string& tempName)
{
	double regHours, ovtHours, wageRate, totalPay, MonthlyPay = 0;

	getline(inFile, tempName);
	inFile >> wageRate;

	for (int counter = 0; counter < 4; counter++) //Removed weeks being a variable becuase it is always 4.
	{
		inFile >> regHours;
		inFile >> ovtHours;

		totalPay = (regHours * wageRate) + (ovtHours * wageRate * 1.5);
		MonthlyPay = MonthlyPay + totalPay;

	} // end of the counting loop

	return MonthlyPay;
}

double getInfoOneEmpSalary(ifstream& inFile, string& tempName)
{
	double regHours, wageRate, totalPay, MonthlyPay = 0;

	getline(inFile, tempName);
	inFile >> wageRate;

	for (int counter = 0; counter < 4; counter++) //Removed weeks being a variable becuase it is always 4.
	{
		inFile >> regHours;
		wageRate = (wageRate / 12) / 4;

		totalPay = (regHours * wageRate);
		MonthlyPay = MonthlyPay + totalPay;

	} // end of the counting loop

	return MonthlyPay;
}

double tipEntry(int& entryNum)
{
	double tip = 0;
	entryNum += 1;
	cout << "\n";
	cout << "Be sure that there are 6 entries in the input file. This is for the person in position " << entryNum << "\n";
	cout << "how much has this person earned in tips? ";
	cin >> tip;

	return tip;
}


void employeeOutput(ofstream& outFile, const string& tempName, const double& tempGrossPay, const double& temptips)
{
	outFile << fixed << showpoint << setprecision(2);
	outFile << "Total Pay for " << tempName << " for the month is $" << setfill('*') << setw(10)
		<< tempGrossPay << setfill(' ') << " With tips (" << setfill('*') << setw(5) << temptips 
		<< ") Is " << setw(10) << tempGrossPay + temptips << setfill(' ') << endl;

}


//Assignment 5
//Michael Clarke
//The Roasted Bean Payroll Program Update
//10/8/2023
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <conio.h>
#include "ClarkeHeader.h"
#include "Functions.h" 

using namespace std;


int main()
{
	double regHours, ovtHours, wageRate, totalPay, hourlyEmp1MonthlyGrossPay,
		hourlyEmp2MonthlyGrossPay, hourlyEmp3MonthlyGrossPay, hourlyEmp4MonthlyGrossPay,
		salaryEmp1MonthlyGrossPay, salaryEmp2MonthlyGrossPay;

	string hourlyEmp1 = " ", hourlyEmp2 = " ", hourlyEmp3 = " ", hourlyEmp4 = " ",
		salaryEmp1 = " ", salaryEmp2 = " ";

	// for the Tip structure
	bool tipMode = 0;
	int entryNum = 0;

	//Employee tips
	double empTips1 = 0, empTips2 = 0, empTips3 = 0, empTips4 = 0, empTips5 = 0, empTips6 = 0;

	string ownerName = "Bobbie Draper";
	double ownerSalary = 75000;

	ifstream payrollInFile;
	ofstream payrollOutFile;

	payrollInFile.open("InputFile.txt");
	payrollOutFile.open("OutputFile.txt");
	getHeading("Assignment 5\n");

	cout << "\n";
	cout << "Did anyone get tips this month? Enter a 0 if no and a 1 if yes. ";
	cin >> tipMode;

	//almost wasn't a function, but because the assignment is about functions I made it one, even if it is a little less clear imo
	if (tipMode == 1)
	{
		empTips1 = tipEntry(entryNum);
		empTips2 = tipEntry(entryNum);
		empTips3 = tipEntry(entryNum);
		empTips4 = tipEntry(entryNum);
		empTips5 = tipEntry(entryNum);
		empTips6 = tipEntry(entryNum);
		cout << "\n";
	}



	outputHeading(payrollOutFile, "Assignment 5");
	
	//Owner output
	employeeOutput(payrollOutFile, ownerName, ownerSalary / 12, 0);

	//Hourly employees
	hourlyEmp1MonthlyGrossPay = getInfoOneEmp(payrollInFile, hourlyEmp1);
	payrollInFile.ignore(100, '\n');
	employeeOutput(payrollOutFile, hourlyEmp1, hourlyEmp1MonthlyGrossPay, empTips1);

	hourlyEmp2MonthlyGrossPay = getInfoOneEmp(payrollInFile, hourlyEmp2);
	payrollInFile.ignore(100, '\n');
	employeeOutput(payrollOutFile, hourlyEmp2, hourlyEmp2MonthlyGrossPay, empTips2);

	hourlyEmp3MonthlyGrossPay = getInfoOneEmp(payrollInFile, hourlyEmp3);
	payrollInFile.ignore(100, '\n');
	employeeOutput(payrollOutFile, hourlyEmp3, hourlyEmp3MonthlyGrossPay, empTips3);

	hourlyEmp4MonthlyGrossPay = getInfoOneEmp(payrollInFile, hourlyEmp4);
	payrollInFile.ignore(100, '\n');
	employeeOutput(payrollOutFile, hourlyEmp4, hourlyEmp4MonthlyGrossPay, empTips4);

	//Salaried Employees
	salaryEmp1MonthlyGrossPay = getInfoOneEmpSalary(payrollInFile, salaryEmp1);
	payrollInFile.ignore(100, '\n');
	employeeOutput(payrollOutFile, salaryEmp1, salaryEmp1MonthlyGrossPay, empTips5);

	salaryEmp2MonthlyGrossPay = getInfoOneEmpSalary(payrollInFile, salaryEmp2);
	payrollInFile.ignore(100, '\n');
	employeeOutput(payrollOutFile, salaryEmp2, salaryEmp2MonthlyGrossPay, empTips6);

	outputClosing(payrollOutFile);

	payrollInFile.close();
	payrollOutFile.close();


	getClosing();
}
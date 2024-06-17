// ClarkeAssignment2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Assignment 2
//Michael Clarke
//The Roasted Bean Payroll Program
//9/17/2023
//

#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
	//Setting Employee payrates
	float Frankie = 14.65;
	float Jim = 13.25;
	float Amos = 11.75;
	float Naomi = 11.75;

	//not going to lie, Spent almost 10 min trying to figure out why "41,300" wouldnt work. 
	float Fred = 41300;
	float Chrisjen = 39800;

	//Yes, I am insane. How can you tell? Seriously, This was my best idea to to this until after it was already typed
	float frank1, frank2, frank3, frank4, jim1, jim2, jim3, jim4, amos1, amos2, amos3, amos4, naomi1, naomi2, naomi3, naomi4;
	
	//If this is correct, They are 1s and 0s, so they should be convertable to integers, right?
	bool fred1, fred2, fred3, fred4, chris1, chris2, chris3, chris4;

	//To hold the total hours/weeks
	float frankHours, jimHours, amosHours, naomiHours, fredWeeks, chrisWeeks =0;

	//To hold the total amounts
	double frankTotal, jimTotal, amosTotal, naomiTotal, fredTotal, chrisTotal;

	cout << "Assignment 3, Programmed by Michael Clarke \n";
	cout << "For the following entries, Enter the hours the employee worked. \n";
	cout << "Frankie Adams, Week 1: ";
	cin >> frank1;
	cin.ignore(100, '\n');
	cout << " Week 2: ";
	cin >> frank2;
	cin.ignore(100, '\n');
	cout << " Week 3: ";
	cin >> frank3;
	cin.ignore(100, '\n');
	cout << " Week 4: ";
	cin >> frank4;
	cin.ignore(100, '\n');
	cout << "\n";
	frankHours = frank1 + frank2 + frank3 + frank4;
	// Adding variables after the new line because I am superstitous

	cout << "Jim Holden, Week 1: ";
	cin >> jim1;
	cin.ignore(100, '\n');
	cout << " Week 2: ";
	cin >> jim2;
	cin.ignore(100, '\n');
	cout << " Week 3: ";
	cin >> jim3;
	cin.ignore(100, '\n');
	cout << " Week 4: ";
	cin >> jim4;
	cin.ignore(100, '\n');
	cout << "\n";
	jimHours = jim1 + jim2 + jim3 + jim4;

	cout << "Naomi Nagata, Week 1: ";
	cin >> naomi1;
	cin.ignore(100, '\n');
	cout << " Week 2: ";
	cin >> naomi2;
	cin.ignore(100, '\n');
	cout << " Week 3: ";
	cin >> naomi3;
	cin.ignore(100, '\n');
	cout << " Week 4: ";
	cin >> naomi4;
    cin.ignore(100, '\n');
	cout << "\n";
	naomiHours = naomi1 + naomi2 + naomi3 + naomi4;

	cout << "Amos Burton, Week 1: ";
	cin >> amos1;
	cin.ignore(100, '\n');
	cout << " Week 2: ";
	cin >> amos2;
	cin.ignore(100, '\n');
	cout << " Week 3: ";
	cin >> amos3;
	cin.ignore(100, '\n');
	cout << " Week 4: ";
	cin >> amos4;
	cin.ignore(100, '\n');
	cout << "\n";
	amosHours = amos1 + amos2 + amos3 + amos4;

	cout << "For the following entries, Please only type '1' For if the employee worked that week and '0' if the the employee did not work that week \n";
	cout << "Fred Jhonson, Week 1: ";
	cin >> fred1;
	cin.ignore(100, '\n');
	cout << " Week 2: ";
	cin >> fred2;
	cin.ignore(100, '\n');
	cout << " Week 3: ";
	cin >> fred3;
	cin.ignore(100, '\n');
	cout << " Week 4: ";
	cin >> fred4;
	cin.ignore(100, '\n');
	cout << "\n";
	fredWeeks = fred1 + fred2 + fred3 + fred4;

	cout << "Chrisjen Avasarala, Week 1: ";
	cin >> chris1;
	cin.ignore(100, '\n');
	cout << " Week 2: ";
	cin >> chris2;
	cin.ignore(100, '\n');
	cout << " Week 3: ";
	cin >> chris3;
	cin.ignore(100, '\n');
	cout << " Week 4: ";
	cin >> chris4;
	cin.ignore(100, '\n');
	cout << "\n";
	chrisWeeks = chris1 + chris2 + chris3 + chris4;
	
	/*  Testing variables 
	cout << frankHours;
	cout << " ";
	cout << jimHours;
	cout << " ";
	cout << naomiHours;
	cout << " ";
	cout << amosHours;
	cout << " ";
	cout << fredWeeks;
	cout << " ";
	cout << chrisWeeks;*/
	
	//Multiply Hours by hourly wage
	frankTotal = Frankie * frankHours;
	jimTotal = Jim * jimHours;
	naomiTotal = Naomi * naomiHours;
	amosTotal = Amos * amosHours;

	//Devide yearly salary by 12 (for each month), 4 (for each week), them multiply by the weeks worked.
	fredTotal = Fred / 12 / 4 * fredWeeks;
	chrisTotal = Chrisjen /12 / 4 * chrisWeeks;

	/* testing again 
	cout << "\n";
	cout << frankTotal;
	cout << " ";
	cout << jimTotal;
	cout << " ";
	cout << naomiTotal;
	cout << " ";
	cout << amosTotal;
	cout << " ";
	cout << fredTotal;  
	cout << " ";
	cout << chrisTotal; */
	

	cout << fixed << showpoint << setprecision(2) << "\n";

	cout << left   << setw(20) << setfill('*')  << "Frankie Adams ";
	cout.unsetf(ios::left);
	cout << right << "\t$" << setw(9) << setfill('*')  << frankTotal;
	cout.unsetf(ios::right);
	cout << "\n";

	cout << left << setw(20) << setfill('*') << "Jim Holden ";
	cout.unsetf(ios::left);
	cout << right << "\t$" << setw(9) << setfill('*') << jimTotal;
	cout.unsetf(ios::right);
	cout << "\n";

	cout << left << setw(20) << setfill('*') << "Naomi Nagata ";
	cout.unsetf(ios::left);
	cout << right << "\t$" << setw(9) << setfill('*') << naomiTotal;
	cout.unsetf(ios::right);
	cout << "\n";

	cout << left << setw(20) << setfill('*') << "Amos Burton ";
	cout.unsetf(ios::left);
	cout << right << "\t$" << setw(9) << setfill('*') << amosTotal;
	cout.unsetf(ios::right);
	cout << "\n";

	cout << left << setw(20) << setfill('*') << "Fred Johnson ";
	cout.unsetf(ios::left);
	cout << right << "\t$" << setw(9) << setfill('*') << fredTotal;
	cout.unsetf(ios::right);
	cout << "\n";

	cout << left << setw(20) << setfill('*') << "Chrisjen Avasarala ";
	cout.unsetf(ios::left);
	cout << right << "\t$" << setw(9) << setfill('*') << chrisTotal;
	cout.unsetf(ios::right);
	cout << "\n";
}
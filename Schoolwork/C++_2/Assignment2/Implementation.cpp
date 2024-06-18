#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
#include <fstream>
#include "Conversions.h" 



using namespace std;

//ROW IS STUDENT, CLM IS GRADE
void getStudentInfo(ifstream& infile, const int NUM_GRADES, string tempName[], char tempGradeInput[][30], double tempGPA[])
{
	string currentline;
	int gradenum = 0, currentrow = 0, currentclm = 0;

	
	std::getline(infile, currentline);
	while (currentline != "" && currentrow < 10)
	{
		tempName[currentrow]= currentline;

		std::getline(infile, currentline);
		while (currentclm < NUM_GRADES)
		{
			try 
			{
				tempGradeInput[currentrow][currentclm] = toupper(currentline.at(currentclm));
				currentclm++;
			}
			catch(out_of_range)
			{
				break;
			}
					
		}
		currentclm = 0;
		currentrow++;
		std::getline(infile, currentline);
	}
}

//ROW IS STUDENT, CLM IS GRADE
void gradesToGPA(const int NUM_STUDENTS, const int NUM_GRADES, char tempGradeInput[][30], double tempGPA[])
{
	int curStuNum = 0;
	int curGradeNum = 0;
	double temptotal = 0;
	double badEntry = 0;
	double gradecount;
	double inlooptotal = 0;

	gradecount = NUM_GRADES;
	

	while (curStuNum < NUM_STUDENTS)
	{
		temptotal = ProcessGrades(curStuNum, 0, NUM_GRADES, tempGradeInput, badEntry);
		tempGPA[curStuNum] = CalculateGPA(temptotal, gradecount, badEntry);

		badEntry = 0;

		curStuNum++;
	}

}

//ROW IS STUDENT, CLM IS GRADE
double ProcessGrades(const int STUDENT, int gradecount, const int NUM_GRADES, char tempGradeInput[][30], double &badEntry)
{ 

	if (gradecount < NUM_GRADES) 
	{
		char tempgrade = tempGradeInput[STUDENT][gradecount];
        
		if (tempgrade == 'A')
		{
			return ProcessGrades(STUDENT, gradecount + 1, NUM_GRADES, tempGradeInput, badEntry) + 4;
		}
		else if (tempgrade == 'B')
		{
			return ProcessGrades(STUDENT, gradecount + 1, NUM_GRADES, tempGradeInput, badEntry) + 3;
		}
		else if (tempgrade == 'C')
		{
			return ProcessGrades(STUDENT, gradecount + 1, NUM_GRADES, tempGradeInput, badEntry) + 2;
		}
		else if (tempgrade == 'D')
		{
			return ProcessGrades(STUDENT, gradecount + 1, NUM_GRADES, tempGradeInput, badEntry) + 1;
		}
		else if (tempgrade == 'F')
		{
			return ProcessGrades(STUDENT, gradecount + 1, NUM_GRADES, tempGradeInput, badEntry) + 0;
		}
		else
		{
			cout << "A grade seems to be missing or improperly input." + 0;
			cout << "\n";
			badEntry++;
			return ProcessGrades(STUDENT, gradecount + 1, NUM_GRADES, tempGradeInput, badEntry);
		}
	}
	else
	{
		return 0.0;
	}
}

//ROW IS STUDENT, CLM IS GRADE
double CalculateGPA(double TempGPA, double NumGrades, double BadEntry)
{
	double GPA;

	GPA = TempGPA / (NumGrades - BadEntry);

	return GPA;
}



void GradeOutPut(ofstream& outFile, string tempname[], double tempGPA[])
{
	int loop = 0;

	cout << "\n";
	outFile << "     Student GPA Report";
	outFile << "\n";
	cout << "     Student GPA Report";
	cout << "\n";

	outFile << left << setw(25) << "Student" ;
	outFile.unsetf(ios::left);
	outFile << right << setw(5) << "GPA  ";
	outFile.unsetf(ios::right);
	outFile << "\n";

	cout << left << setw(25) << "Student";
	cout.unsetf(ios::left);
	cout << right << setw(5) << "GPA  ";
	cout.unsetf(ios::right);
	cout << "\n";


	while (loop < 10)
	{
		outFile << fixed << showpoint << setprecision(3);
		outFile << left << setw(25) << tempname[loop];
		outFile.unsetf(ios::left);
		outFile << right << setw(5) << tempGPA[loop] << endl;
		outFile.unsetf(ios::right);

		// no need for these two to have a seperate output function
		cout << fixed << showpoint << setprecision(3);
		cout << left << setw(25) << tempname[loop];
		cout.unsetf(ios::left);
		cout << right << setw(5) << tempGPA[loop];
		cout.unsetf(ios::right);
		cout << "\n";
		loop++;
	}
	cout << "\n";

	outFile << "\n";
	outFile << " Student GPA Report is done";
	cout << " Student GPA Report is done";

}
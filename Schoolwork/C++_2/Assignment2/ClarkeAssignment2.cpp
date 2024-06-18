//
//Assignment 2
//Michael Clarke
//Grade Documentation
//12/07/2023
//
#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
#include <fstream>
#include "ClarkeHeader.h"
#include "Conversions.h" 


int main()
{
    ifstream GradeInFile;
    ofstream GradeOutFile;

    GradeInFile.open("InputFile.txt");
    GradeOutFile.open("OutputFile.txt");

    getHeading("Assignment 8\n");
    cout << "\n";

    //10 students, up to 30 grades
    int stucount = 10;
    int gradecount = 30;
    char tempGradeInput[10][30];
    double tempGPA[10];
    string tempName[10];


    outputHeading(GradeOutFile, "Assignment 8");

    getStudentInfo(GradeInFile, gradecount, tempName, tempGradeInput, tempGPA);
    gradesToGPA(stucount, gradecount, tempGradeInput, tempGPA);

    GradeOutPut(GradeOutFile, tempName, tempGPA);


    outputClosing(GradeOutFile);


    GradeInFile.close();
    GradeOutFile.close();


    getClosing();
}

//
//Assignment 8
//Michael Clarke
//Grade Calc with Arrays
//11/5/2023
//
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include "ClarkeHeader.h"
#include "Functions.h" 




int main()
{
    ifstream GradeInFile;
    ofstream GradeOutFile;

    GradeInFile.open("InputFile.txt");
    GradeOutFile.open("OutputFile.txt");

    getHeading("Assignment 8\n");
    cout << "\n";

    string StudentList[10];
    double GPA[10];

    outputHeading(GradeOutFile, "Assignment 8");

    for (int loop = 0; loop < 10; loop++)
    {
        StudentList[loop] = StudentEntry(GradeInFile);
        GPA[loop] = GradeTotal(GradeInFile);
    }
     
    for (int loop = 0; loop < 10; loop++)
    {
        GradeOutPut(GradeOutFile, StudentList[loop], GPA[loop]);
    }

    outputClosing(GradeOutFile);


    GradeInFile.close();
    GradeOutFile.close();


    getClosing();
}

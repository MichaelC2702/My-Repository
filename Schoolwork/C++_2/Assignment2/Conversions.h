//#pragma once
#ifndef _Functions_imp
#define _Functions_imp

using namespace std;

void getStudentInfo(ifstream&, const int, string tempName[], char tempGradeInput[][30], double tempGPA[]); 
void gradesToGPA(const int, const int, char tempGradeInput[][30], double tempGPA[]);
double ProcessGrades(const int, int, const int, char[][30], double&);
double CalculateGPA(double, double, double);
void GradeOutPut(ofstream&, string tempname[], double tempGPA[]);
#endif
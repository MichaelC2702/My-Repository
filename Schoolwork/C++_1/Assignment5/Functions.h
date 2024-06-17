//#pragma once
#ifndef _Functions_imp
#define _Functions_imp

#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

double getInfoOneEmp(ifstream&, string&);
double getInfoOneEmpSalary(ifstream&, string&);
void employeeOutput(ofstream&, const string&, const double&, const double&);
double tipEntry(int& entryNum);

#endif
//#pragma once
#ifndef _Clarke_Heading_imp
#define _Clarke_heading_imp

#include <iostream>
#include <conio.h>
#include <chrono>
#include <ctime>

using namespace std;

// Function Prototypes
void getHeading(string);
void outputHeading(ofstream&, string);
void getClosing();
void outputClosing(ofstream&);
string getFirstName();
string getLastName();
string getFullName();

#endif
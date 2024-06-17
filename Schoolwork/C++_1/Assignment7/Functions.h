//#pragma once
#ifndef _Functions_imp
#define _Functions_imp

using namespace std;

enum ConvType { CelToFah, KelToFah, FahToCel, CelToKel, KelToCel, FahToKel, Exit };

ConvType convSelector();
double ctoF(double);
double ktoF(double);
double ftoC(double);
double ctoK(double);
double ktoC(double);
double ftoK(double);
double inputTemp(string);
void outputGeneric(ConvType, double, double);

#endif
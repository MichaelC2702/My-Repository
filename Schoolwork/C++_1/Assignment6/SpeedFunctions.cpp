#include <iostream>
#include <iomanip>
#include "Functions.h" 

using namespace std;

double ratioCalc(double newTire, double oldTire)
{
	double Ratio = 0;

	//given equasion
	Ratio = newTire / oldTire;

	return Ratio;
}

void speedcalc(double Ratio, double miles)
{
	double newMiles = 0;
	newMiles = miles * Ratio;
	
	// reset the setpresicion for looping, it is here in the first place as I imagine most comparisons aren't as clean as the example
	cout << fixed << noshowpoint << setprecision(0);
	cout  << "When your spedometer is reading " << setw(3) << miles << " you're actually going : " 
		<< setw(3) << fixed << showpoint << setprecision(2) << newMiles << "\n";
}
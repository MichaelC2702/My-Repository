#include <iostream>		/* cin & cout */
#include <conio.h>		/* _getch */
#include <time.h>       /* time */
#include "ClarkeHeader.h" 

using namespace std;

// Headers
void fillTheArray(int iTempArray[], int sIZE);
bool linearSearchOne(int ENTRY, int iTempArray[], int SIZE);
int linearSearchTwo(int ENTRY, int iTempArray[], int SIZE);
void programOutput(bool bTempDoesItExist, int iHowMany, int ENTRY, int IFCOUNTER);

int itterations = 0;


void main() 
{
	/*
		Finish adding Code to this module
	*/

	const int SIZE = 100000;
	const int ENTRY = 1320;
	//Adding another counter variable store the amount of times the first search functions iterated
	int  IFCOUNTER = 0;

	bool bDoesItExist;
	// Never ended up using iLocation or iCounter, because itterations variable does the same thing.
	int iCounter, iLocation, iHowMany = 0;

	int iNumArray[SIZE];

	getHeading("Assignment 9\n");
	cout << "\n";

	/* REQUIRED: Array as an agreement comment
	  Arrays are always passed as refrences, not as a single value, so every iteration that this function 
	  makes updates the array as if the array was being updated directly in the main function,
	  despite there being no '&' and the fillTheArray function being a void.
	*/
	fillTheArray(iNumArray, SIZE);
	cout << "The array is filled" << endl << endl;
	cout << "\npress anyKey to begin..." << endl;
	_getch();

	bDoesItExist = linearSearchOne(ENTRY, iNumArray, SIZE);

	if (bDoesItExist == true)
	{
		IFCOUNTER = itterations;
		iHowMany = linearSearchTwo(ENTRY, iNumArray, SIZE);
	}

	programOutput(bDoesItExist, iHowMany, ENTRY, IFCOUNTER);

	cout << "\n\npress anyKey to end..." << endl;
	_getch();

}//end of main


void fillTheArray(int iTempArray[], int SIZE) {
	int index;
	const int RANGE = 2500;

	/* REQUIRED: Why do we have to initialize random seed to get a random number?
	  Otherwise the array would always be the same

	*/
	srand(time(NULL));

	// Variable with all CAPITAL letters are considered constants
	for (index = 0; index <= SIZE - 1; index++)
	{
		iTempArray[index] = rand() % RANGE;
	}
}//end of fill the array


bool linearSearchOne(int ENTRY, int iTempArray[], int SIZE) {
	/*
		Finish adding Code to this module
	*/
	bool bTempDoesItExist = false;

	for (int loop = 0; loop < SIZE; loop++)
	{
		itterations++;
		if (iTempArray[loop] == ENTRY)
		{
			bTempDoesItExist = true;
			break;
		}
		
	}

	return bTempDoesItExist;
}//end of linear search one


int linearSearchTwo(int ENTRY, int iTempArray[], int SIZE) {
	/*
		Finish adding Code to this module
	*/
	int HowManyExist = 1;
	/* 
	   Passing in ifcounter as there shouldnt be any numbers that match ENTRY before that position.
	   This also means that this program should only look at the entire array once. I reduced it by one 
	   as the index starts at 0, so if I didnt need to then at worst it is checking one extra line 
    */
	int loop = itterations;
	

	for (loop; loop < SIZE; loop++)
	{
		itterations++;
		if (iTempArray[loop] == ENTRY)
		{
			HowManyExist++;
		}
	}

	return HowManyExist;
}//end of linear search two


void programOutput(bool bTempDoesItExist, int iHowMany, int ENTRY, int IFCOUNTER) {
	/*
		Finish adding Code to this module
	*/
	cout << "\n";
	if (bTempDoesItExist == false)
	{
		cout << "The program failed to find " << ENTRY << " In the array. This program ran this search " 
			<< itterations << " times";
	}

	else
	{
		cout << "The program found : " << iHowMany << " instances of : " << ENTRY <<
			" In the array. The first search took : " << IFCOUNTER << " Iterations to find one" 
			<< "\n" <<"and ran an additional "
			<< itterations - IFCOUNTER << " times to try and find more.";
	}
	cout << "\n";
}//end of program output


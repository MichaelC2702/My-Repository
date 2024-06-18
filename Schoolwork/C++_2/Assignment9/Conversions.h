//#pragma once
#ifndef _Functions_imp
#define _Functions_imp


using namespace std;

//FItoCM is Feet Inches to centimeters
enum ConversionOp { FItoCM, ItoCM, CMtoF, CMtoI, LBStoKG, KGtoLBS, EXIT, RETRY };

class Convert 
{
    /*I considered overloading the << operator, but with the abount of variables
         I have in the structure I have now, I felt it would not be worth it (and definitely not easy to 
         read). I also removed the name class from assignment 5 as I felt it was irrelevant.
         
      I did not include pointers as I feel that the class handles cross-function variables better. */

    public:

        //Decided to put Menu in here as that allows me to get rid of Get and Set beforeUnit functions
        ConversionOp Menu();

        double Conversion();
        void ConvertOutPut();
        void incrementBadEntry();

        ConversionOp getCurrentOp();

        void setCurrentOp(ConversionOp);

    private:
        double BeforeUnit;
        double AfterUnit;
        ConversionOp CurrentOp;
        int BadEntry = 0;

};


#endif
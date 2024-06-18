
//#pragma once
#ifndef _Functions_imp
#define _Functions_imp

using namespace std;

//FItoCM is Feet Inches to centimeters
enum ConversionOp {FItoCM, ItoCM, CMtoF, CMtoI, LBStoKG, KGtoLBS, EXIT, RETRY};

class Convert
{
    public:

        double Conversion();
        void ConvertOutPut();

        ConversionOp getCurrentOp();
        double getBeforeUnit();
        
        void setCurrentOp(ConversionOp);
        void setBeforeUnit(double);

        ~Convert();

    private:
        double BeforeUnit;
        double AfterUnit;
        ConversionOp CurrentOp;

};


#endif
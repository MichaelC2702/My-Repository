

//#pragma once
//Another include added when moving files from Microsoft's Visual Studio to VSC
#include <string>

#ifndef _Functions_imp
#define _Functions_imp


using namespace std;

//FItoCM is Feet Inches to centimeters
enum ConversionOp { FItoCM, ItoCM, CMtoF, CMtoI, LBStoKG, KGtoLBS, EXIT, RETRY };


class getName
{
public:

    void getFirstName();
    void setFirstName(string);
    void ConvertOutPut();

    ~getName();

private:
    string Fname;
};

class Convert : public getName
{
public:

    double Conversion();
    void ConvertOutPut();

    ConversionOp getCurrentOp();
    double getBeforeUnit();

    void setCurrentOp(ConversionOp);
    void setBeforeUnit(double);


private:
    double BeforeUnit;
    double AfterUnit;
    ConversionOp CurrentOp;

};


#endif
#include <iostream>
#include <iomanip>
#include "Conversions.h" 


using namespace std;

struct ConversionInfo
{
    string currentop;
    double initial_temp;
    double after_temp;

    double ctoF(double Cel)
    {
        double Far;
        Far = (5 * Cel) / 9 + 32;
        return Far;

    }

    double ctoK(double Cel)
    {
        double Kel;
        Kel = Cel + 273;
        return Kel;

    }

    //the formula for F to C on canvas is incorrect, it should be (f-32)5/9 
    double ftoC(double Far)
    {
        double Cel;
        Cel = 5 * (Far - 32) / 9;
        return Cel;

    }

    double ftoK(double Far)
    {
        double Kel;
        Kel = 5 * (Far - 32) / 9 + 273;
        return Kel;

    }

    double ktoC(double Kel)
    {
        double Cel;
        Cel = Kel - 273;
        return Cel;

    }

    double ktoF(double Kel)
    {
        double Far;
        Far = 9 * (Kel - 273) / 5 + 32;
        return Far;

    }
};

void Convert(string& currentop, double& initTemp, double& aftertemp)
{
    ConversionInfo CurrentConv;

    CurrentConv.currentop = currentop;
    //had to be converted to a if/else statement as strings are incompatable with switch statements
    if (CurrentConv.currentop == "CelToFah")
    {
        // removed the initType variable as all it did was pass the string into inputTemp
        CurrentConv.initial_temp = inputTemp("Celsius");
        CurrentConv.after_temp = CurrentConv.ctoF(CurrentConv.initial_temp);
    }
    else if (CurrentConv.currentop == "CelToKel")
    {
        CurrentConv.initial_temp = inputTemp("Celsius");
        CurrentConv.after_temp = CurrentConv.ctoK(CurrentConv.initial_temp);
    }
    else if (CurrentConv.currentop == "FahToCel")
    {
        CurrentConv.initial_temp = inputTemp("Fahrenheit");
        CurrentConv.after_temp = CurrentConv.ftoC(CurrentConv.initial_temp);
    }
    else if (CurrentConv.currentop == "FahToKel")
    {
        CurrentConv.initial_temp = inputTemp("Fahrenheit");
        CurrentConv.after_temp = CurrentConv.ftoK(CurrentConv.initial_temp);
    }
    else if (CurrentConv.currentop == "KelToCel")
    {
        CurrentConv.initial_temp = inputTemp("Kelvin");
        CurrentConv.after_temp = CurrentConv.ktoC(CurrentConv.initial_temp);

    }
    else if (CurrentConv.currentop == "KelToFah")
    {
        CurrentConv.initial_temp = inputTemp("Kelvin");
        CurrentConv.after_temp = CurrentConv.ktoF(CurrentConv.initial_temp);

    }
    else
    {
        cout << "This message should not appear";
        cout << "\n";
    }

    currentop = CurrentConv.currentop;
    initTemp = CurrentConv.initial_temp;
    aftertemp = CurrentConv.after_temp;
}


double inputTemp(string enterstring)
{

    double dTemp;

    cout << "Please enter the temperature in " << enterstring << " you want to convert : ";

    cin >> dTemp;

    return dTemp;

}


void outputGeneric(string conversion, double beforetemp, double aftertemp)
{

    string before, after;

    if (conversion == "CelToFah")
    {
        before = "Celsius";
        after = "Fahrenheit";
    }
    else if (conversion == "CelToKel")
    {
        before = "Celsius";
        after = "Kelvin";
    }
    else if (conversion == "FahToCel")
    {
        before = "Fahrenheit";
        after = "Celsius";
    }
    else if (conversion == "FahToKel")
    {
        before = "Fahrenheit";
        after = "Kelvin";
    }
    else if (conversion == "KelToCel")
    {
        before = "Kelvin";
        after = "Celsius";
    }
    else if (conversion == "KelToFah")
    {
        before = "Kelvin";
        after = "Fahrenheit";
    }

    cout << fixed << showpoint << setprecision(1);
    cout << beforetemp << " Degrees " << before << " Is equal to " << aftertemp << " degrees " << after << ".";

}

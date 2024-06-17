#include <iostream>
#include <iomanip>
#include "Functions.h" 

using namespace std;


ConvType convSelector()
{
    char initType, afterType;
    ConvType Conversion = Exit;
    int loopcontrol = 1;

    while (loopcontrol == 1)
    {
        cout << "For the following questions, please enter  'f' for Farenheit, 'c' for Celsius, or 'k' for Kelvin. \n";

        cout << "Please enter the starting temperature or E to quit: ";

        cin >> initType;

        cout << "\n";

        if (initType != 'E')
        {
            cout << "Please enter the temperature you want to convert to : ";

            cin >> afterType;

            cout << "\n";
        }

        // matching the conversions
        switch (initType)
        { 
            case 'c':
                if (afterType == 'f')
                {
                    Conversion = CelToFah;
                    loopcontrol = 0;
                }
                else if (afterType == 'k')
                {
                    Conversion = CelToKel;
                    loopcontrol = 0;
                }
                else
                {
                    cout << "Error at convSelector c - # - invalid second type " << afterType;
                }
            case 'f':
                if (afterType == 'c')
                {
                    Conversion = FahToCel;
                    loopcontrol = 0;
                }
                else if (afterType == 'k')
                {
                    Conversion = FahToKel;
                    loopcontrol = 0;
                }
                else
                {
                    cout << "Error at convSelector f - # : invalid second type " << afterType;
                }
            case 'k':
                if (afterType == 'f')
                {
                    Conversion = KelToFah;
                    loopcontrol = 0;
                }
                else if (afterType == 'c')
                {
                    Conversion = KelToCel;
                    loopcontrol = 0;
                }
                else
                {
                    cout << "Error at convSelector k - # : invalid second type " << afterType;
                }
            case 'E':
                Conversion = Exit;
                loopcontrol = 0;
            default:
                cout << "Error at convSelector # - # : invalid starting type " << initType;
        }
    }

    return Conversion;
}


double ctoF(double Cel) 
{
    double Far;
    Far = 9 / (5 * Cel) + 32;
    return Far;
}

double ctoK(double Cel)
{
    double Kel;
    Kel = Cel + 273;
    return Kel;
}

double ftoC(double Far)
{
    double Cel;
    Cel = 5 / 9 * (Far - 32);
    return Cel;
}

double ftoK(double Far)
{
    double Kel;
    Kel = 5 / 9 * (Far - 32) + 273;
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
    Far = 9 / 5 * (Kel - 273) + 32;
    return Far;
}


double inputTemp(string enterstring)
{

        double dTemp;

        cout << "Please enter the temperature in " << enterstring << " you want to convert : ";

        cin >> dTemp;

        return dTemp;

}

void outputGeneric(ConvType conversion, double beforetemp, double aftertemp)
{

    string before, after;

    switch (conversion)
    {

        case CelToFah:
            before = "Celsius";
            after = "Fahrenheit";

        case CelToKel:
            before = "Celsius";
            after = "Kelvin";

        case FahToCel:
            before = "Fahrenheit";
            after = "Celsius";

        case FahToKel:
            before = "Fahrenheit";
            after = "Kelvin";

        case KelToCel:
            before = "Celsius";
            after = "Celsius";

        case KelToFah:
            before = "Celsius";
            after = "Fahrenheit";
    }

    cout << fixed << showpoint << setprecision(1);
    cout << beforetemp << " Degrees " << before << " Is equal to " << aftertemp << " degrees " << after << ".";

}

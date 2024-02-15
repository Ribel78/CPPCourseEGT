#ifndef _FamilyCar_H_
#define _FamilyCar_H_

#include "Car.h"
#include <string>

//declare class
class FamilyCar : public Car{
public:
    FamilyCar(); //init class obj
    FamilyCar(string, string, carType, string, string, double, double, double);
    void setDistance(double);
    double getDistance();
    void setTax(double);
    double getTax();
    float calculateCoefDistance();
    double calculatePrice();
    void addExtraCharge(luxury);
    void removeExtraCharge(luxury);
    double caclulateExtraCharges();
    void printData();
    void listExtras();
    
private:
    double tax;
    double distance;
    float coef_distance;
};
#endif //_CLASSNAME_H_
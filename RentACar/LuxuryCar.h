#ifndef _LuxuryCar_H_
#define _LuxuryCar_H_

#include "Car.h"
#include <set>

class LuxuryCar : public Car{
public:
    LuxuryCar(); //init class obj
    LuxuryCar(string, string, carType, string, string, double, double, double, luxury);
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
    set<luxury> extraCharges;
};
#endif //_LuxuryCar_H_
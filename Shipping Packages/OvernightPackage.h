#ifndef _OvernightPackage_H_
#define _OvernightPackage_H_

//#include <iostream>
#include "Package.h"
using namespace std;

//declare class
class OvernightPackage : public Package{
public:
    OvernightPackage(Address, Address); //init class obj
    OvernightPackage(Address, Address, double, double); //init class obj
    ~OvernightPackage();
    void setBasePrice(double);
    double getBasePrice();
    void setWeight(double);
    double getWeight();
    double calculateCost();

private:
    Address senderAddress;
    Address receiverAddress;
    double basePrice;
    double weight;
};
#endif //_OvernightPackage_H_
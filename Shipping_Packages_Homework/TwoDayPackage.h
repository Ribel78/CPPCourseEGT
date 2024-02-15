#ifndef _TwoDayPackage_H_
#define _TwoDayPackage_H_

//#include <iostream>
#include "Package.h"
using namespace std;

//declare class
class TwoDayPackage : public Package{
public:
    TwoDayPackage(Address, Address); //init class obj
    TwoDayPackage(Address, Address, double, double); //init class obj
    ~TwoDayPackage();
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
#endif // _TwoDayPackage_H_
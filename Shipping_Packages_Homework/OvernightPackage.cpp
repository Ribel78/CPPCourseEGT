#include "OvernightPackage.h"

//define class constructors and functions

OvernightPackage::OvernightPackage(Address s, Address r): Package(s, r){}
OvernightPackage::OvernightPackage(Address s, Address r, double basePrice, double weight)
: Package(s, r), basePrice(basePrice), weight(weight){}
OvernightPackage::~OvernightPackage(){}

void OvernightPackage::setBasePrice(double basePrice){
    this->basePrice = basePrice;
}
double OvernightPackage::getBasePrice(){
    return this->basePrice;
}
void OvernightPackage::setWeight(double weight){
    this->weight = weight;
}
double OvernightPackage::getWeight(){
    return this->weight;
}
double OvernightPackage::calculateCost(){
    return this->basePrice*this->weight;
}
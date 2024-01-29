#include "TwoDayPackage.h"

//define class constructors and functions

TwoDayPackage::TwoDayPackage(Address s, Address r): Package(s, r){}
TwoDayPackage::TwoDayPackage(Address s, Address r, double basePrice, double weight)
: Package(s, r), basePrice(basePrice), weight(weight){}
TwoDayPackage::~TwoDayPackage(){}

void TwoDayPackage::setBasePrice(double basePrice){
    this->basePrice = basePrice;
}
double TwoDayPackage::getBasePrice(){
    return this->basePrice;
}
void TwoDayPackage::setWeight(double weight){
    this->weight = weight;
}
double TwoDayPackage::getWeight(){
    return this->weight;
}
double TwoDayPackage::calculateCost(){
    return this->basePrice*this->weight;
}
#include "FamilyCar.h"

//define class constructors and functions
FamilyCar::FamilyCar():Car(){}
FamilyCar::FamilyCar(
    string brand, 
    string model, 
    carType type, 
    string chassisNumber, 
    string plateNumber, 
    double fuelConsumption, 
    double tax, 
    double distance)
: Car( brand,  model,  type,  chassisNumber,  plateNumber,  fuelConsumption), tax(tax){
    setDistance(distance);
}
void FamilyCar::setDistance(double distance){
    this->distance = distance;
    this->coef_distance = calculateCoefDistance();
}
double FamilyCar::getDistance(){
    return this->distance;
}
void FamilyCar::setTax(double tax){
    this->tax = tax;
}
double FamilyCar::getTax(){
    return this->tax;
}
float FamilyCar::calculateCoefDistance(){
    return (this->distance < 500.00)? this->coef_distance = 0.7f : this->coef_distance = 0.4f;
}
double FamilyCar::calculatePrice(){
    return (this->tax + (this->coef_distance*this->distance));
}
void FamilyCar::addExtraCharge(luxury){
    cout << "Family Car does not have extra charges." << endl;
}
void FamilyCar::removeExtraCharge(luxury){
    cout << "Family Car does not have extra charges." << endl;
}
double FamilyCar::caclulateExtraCharges(){
    cout << "Family Car does not have extra charges." << endl;
    return 0;
}
void FamilyCar::printData(){
    cout << this->getBrand() << " " << this->getModel() <<" + " << "Family Car Data" << endl;
}
void FamilyCar::listExtras(){
    cout << "Family Car does not have extra charges." << endl;
}
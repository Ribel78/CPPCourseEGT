#include "Car.h"
#include "LuxuryCar.h"

// array of extra luxury charges {NONE,CHAMPAGNE,WINE,CHOCOLATE}
double luxury_price[] = {0.00, 100.00, 50.00, 40.00};

//define class constructors and functions
LuxuryCar::LuxuryCar():Car(){}
LuxuryCar::LuxuryCar(
    string brand, 
    string model, 
    carType type, 
    string chassisNumber, 
    string plateNumber, 
    double fuelConsumption, 
    double tax, 
    double distance, 
    luxury extraCharge)
    : Car(brand, model, type, chassisNumber, plateNumber, fuelConsumption),
    tax(tax){
    setDistance(distance);
    addExtraCharge(extraCharge);
}
void LuxuryCar::setDistance(double distance){
    this->distance = distance;
    this->coef_distance = calculateCoefDistance();
}
double LuxuryCar::getDistance(){
    return this->distance;
}
void LuxuryCar::setTax(double tax){
    this->tax = tax;
}
double LuxuryCar::getTax(){
    return this->tax;
}
float LuxuryCar::calculateCoefDistance(){
    return (this->distance < 200.00)? this->coef_distance = 0.6f : this->coef_distance = 0.4f;
}
double LuxuryCar::calculatePrice(){
    return (this->tax + (this->coef_distance*this->distance) + caclulateExtraCharges());
}
void LuxuryCar::addExtraCharge(luxury extraCharge){
    this->extraCharges.insert(extraCharge);
}
double LuxuryCar::caclulateExtraCharges(){
    set<luxury>::iterator it;
    double sum = 0.00;
    for (it = this->extraCharges.begin(); it != this->extraCharges.end(); ++it){
        sum += luxury_price[*it];
    }
    return sum;
}
void LuxuryCar::removeExtraCharge(luxury extraCharge){
    this->extraCharges.erase(extraCharge);
    if(this->extraCharges.empty()){
        this->addExtraCharge(NONE);
    }
}
void LuxuryCar::printData(){
    cout << this->getBrand() << " " << this->getModel() <<" + " << "Luxury Car Data" << endl;
}
void LuxuryCar::listExtras(){
    cout << "List of extras: " << endl;
    for (luxury lux : this->extraCharges){
        if (lux){
        cout << this->getLuxury(lux) << " ";
        } else {continue;}
    }
    cout << endl;
}
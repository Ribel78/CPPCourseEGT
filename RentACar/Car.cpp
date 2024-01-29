#include "Car.h"

//define class constructors and functions
Car::Car(){}
Car::Car(string brand, string model, carType type, string chassisNumber, string plateNumber, double fuelConsumption){
    setBrand(brand);
    setModel(model);
    setType(type);
    setChassisNumber(chassisNumber);
    setPlateNumber(plateNumber);
    setFuelConsumption(fuelConsumption);
}

void Car::setBrand(string brand){
    this->brand = brand;
}
string Car::getBrand(){
    return this->brand;
}
void Car::setModel(string model){
    this->model = model;
}
string Car::getModel(){
    return this->model;
}
void Car::setType(carType type){
    this->type = type;
}
carType Car::getType(){
    return this->type;
}
void Car::setChassisNumber(string chassisNumber){
    this->chassisNumber = chassisNumber;
}
string Car::getChassisNumber(){
    return this->chassisNumber;
}
void Car::setPlateNumber(string plateNumber){
    this->plateNumber = plateNumber;
}
string Car::getPlateNumber(){
    return this->plateNumber;
}
void Car::setFuelConsumption(double fuelConsumption){
    this->fuelConsumption = fuelConsumption;
}
double Car::getFuelConsumption(){
    return this->fuelConsumption;
}
void Car::printData(){
    cout << "This is Car data" << endl;
}
string Car::getLuxury(int idx){
    return this->luxury_str[idx];
}
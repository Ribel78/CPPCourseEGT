#include "RentACar.h"

//define class constructors and functions

RentACar::RentACar(){}
void RentACar::addCar(Car * car){
    this->cars.push_back(car);
}
void RentACar::removeCar(int idx){
    if(idx < this->cars.size()){
        this->cars.erase(this->cars.begin()+idx);
    }
}
void RentACar::listCars(){
    int idx = 0;
    for (Car * car : this->cars){
        cout << "Idx: " << idx << " - ";
        car->printData();
        idx+=1;
    }
}
Car* RentACar::carAt(int idx){
    return this->cars.at(idx);
}
#ifndef _RentACar_H_
#define _RentACar_H_

#include "Car.h"
#include <vector>

//declare class
class RentACar{
public:
    RentACar();
    void addCar(Car*);
    void removeCar(int);
    void listCars();
    Car* carAt(int);
private:
    vector<Car*> cars;
};
#endif //_RentACar_H_
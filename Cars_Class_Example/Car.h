#ifndef CPPCLASSES_CAR_H
#define CPPCLASSES_CAR_H
#include <iostream>
#include <string>
using namespace std;

class Car
{
public:
    Car();
    Car(string, int, string, string, string, string, string);
    void setModel(string);
    void setYear(int);
    void setColor(string);
    void setFuel(string);
    void setTransmission(string);
    void setPlate(string);
    void setVIN(string);
    void displayMessage();

private:
    string model;
    int year;
    string color;
    string fuel;
    string vin;
    string transmission;
    string plate;
};

#endif //CPPCLASSES_CAR_H
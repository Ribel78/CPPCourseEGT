#ifndef _Car_H_
#define _Car_H_

#include <iostream>
#include <string>
using namespace std;

enum carType {SEDAN, COMBI, HACHBACK};
enum luxury {NONE, CHAMPAGNE, WINE, CHOCOLATE};


//declare class
class Car{
public:
    Car(); //init class obj
    Car(string, string, carType, string, string, double); //init class obj
    void setBrand(string);
    string getBrand();
    void setModel(string);
    string getModel();  
    void setType(carType);
    carType getType();
    void setChassisNumber(string);
    string getChassisNumber();
    void setPlateNumber(string);
    string getPlateNumber();
    void setFuelConsumption(double);
    double getFuelConsumption();
    string getLuxury(int);
    
    virtual void printData();
    virtual void setDistance(double)= 0;
    virtual double getDistance() = 0;
    virtual void addExtraCharge(luxury) = 0;
    virtual void removeExtraCharge(luxury) = 0;
    virtual double caclulateExtraCharges() = 0;
    virtual double calculatePrice() = 0;
    virtual void listExtras() = 0;

private:
    string brand;
    string model;
    carType type; // SEDAN, COMBI, HACHBACK
    string chassisNumber;
    string plateNumber;
    double fuelConsumption;
    const string luxury_str[4] = {"NONE", "CHAMPAGNE", "WINE", "CHOCOLATE"};
};
#endif //_CLASSNAME_H_
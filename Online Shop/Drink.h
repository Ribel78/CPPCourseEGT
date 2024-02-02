#ifndef _Drink_H_
#define _Drink_H_

#include <iostream>
#include <string>
using namespace std;

enum DrinkType {WINE, GIN, WHISKEY, WATER, JUICE, TEA, COFFEE};

//declare class
class Drink{
public:
    
    Drink(); //init class obj
    //initialize with name, price, quantity, and type;
    Drink(string, float, int, DrinkType); //init class obj
    void setName(string); //set function
    string getName(); //get function
    void setPrice(float);
    float getPrice();
    void setInitQuantity(int);
    int getInitQuantity();
    void setQuantity(int);
    int getQuantity();
    void setType(DrinkType);
    DrinkType getType();
    void print();
    virtual float calculatePrice(int) = 0;

    virtual ~Drink(){};//if at least 1 virtual function - add virtual destructor 

private:
    string name;
    float price;
    int quantity;
    int temp_quantity;
    DrinkType type;

};
#endif //_Drink_H_
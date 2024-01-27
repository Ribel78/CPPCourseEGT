#ifndef _NonAlcoholicDrink_H_
#define _NonAlcoholicDrink_H_

#include "Drink.h"

using namespace std;

//declare class
class NonAlcoholicDrink : public Drink{
public:
    NonAlcoholicDrink();
    //initialize with name, price, quantity, type, liters and cityTax;
    NonAlcoholicDrink(string, float, int, DrinkType, float, float);
    void setLiters(float);
    float getLiters();
    void setCityTax(float);
    float getCityTax();
    float calculatePrice(int);

private:
    float liters;
    float cityTax;

};
#endif //_NonAlcoholicDrink_H_
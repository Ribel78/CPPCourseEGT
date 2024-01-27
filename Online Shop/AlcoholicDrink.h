#ifndef _AlcoholicDrink_H_
#define _AlcoholicDrink_H_

#include "Drink.h"

using namespace std;

//declare class
class AlcoholicDrink : public Drink{
public:
    AlcoholicDrink(); //init class obj
    //initialize with name, price, quantity, type, ABV and tax;
    AlcoholicDrink(string, float, int, DrinkType, float, float); //init class obj
    void setABV(float);
    float getABV();
    void setTax(float);
    float getTax();
    float calculatePrice(int);

private:
    float ABV; //alcohol by volume;
    float tax;

};
#endif //_AlcoholicDrink_H_
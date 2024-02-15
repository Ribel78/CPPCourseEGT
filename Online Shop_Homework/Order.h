#ifndef _Order_H_
#define _Order_H_

#include "Drink.h"
#include <vector>

//declare class
class Order{
public:
    
    Order();
    //initialize with date string,
    Order(string);
    void setOrderDate(string);
    string getOrderDate();
    void addDrink(Drink*);
    float getOrderTotal();
    void listItems();

private:
    void setOrderTotal();
    vector<Drink*> drinks;
    string orderDate;
    float orderTotal;
};
#endif //_Drink_H_
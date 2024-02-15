#ifndef _User_H_
#define _User_H_

#include "Order.h"
#include <vector>

//declare class
class User{
public:
    User();
    //initialize with username string,
    User(string);
    void setUserName(string);
    string getUserName();
    void addOrder(Order*);
    void listOrders();

private:
    string username;
    vector<Order*> orders;
};
#endif //_Drink_H_
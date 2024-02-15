//include header file(s)
#include "Order.h"

//#include <XXX> //include nescessary libraries

//define class constructors and functions

Order::Order(){}
//initialize with date;
Order::Order(string orderDate){
    setOrderDate(orderDate);
}
void Order::setOrderDate(string orderDate){
    this->orderDate = orderDate;
}
string Order::getOrderDate(){
    return this->orderDate;
}
// add drink to vector and remove 1 from drink's quantity
void Order::addDrink(Drink* drink){
    this->drinks.push_back(drink);
    drink->setQuantity(drink->getQuantity() - 1);
    setOrderTotal();
}
// find sum of all ordered drinks
void Order::setOrderTotal(){
    float sum = 0;
    for (Drink * drink: this->drinks){
        sum += drink->calculatePrice(1);
    }
    this->orderTotal = sum;

}
float Order::getOrderTotal(){
    return this->orderTotal;
}
void Order::listItems(){
    cout << "----- List Items from Order on ---" << this->getOrderDate() << "---" << endl;
    for (Drink* item : this->drinks){
        cout << item->getName() << " - " << item->calculatePrice(1) << endl;
    }
    cout << "---------------End of List------------------" << endl;
}
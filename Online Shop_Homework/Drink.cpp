//include header file(s)
#include "Drink.h"

//#include <XXX> //include nescessary libraries

//define class constructors and functions

Drink::Drink(){}
//initialize with name, price, quantity, and type;
Drink::Drink(string name, float price, int quantity, DrinkType type){
    setName(name);
    setPrice(price);
    this->quantity = quantity;
    setQuantity(quantity);
    setType(type);
}
//set drink name
void Drink::setName(string name){
    this->name = name;
}
string Drink::getName(){
    return this->name;
}
void Drink::setPrice(float price){
    this->price = price;
}
float Drink::getPrice(){
    return this->price;
}
//set initial quantity
void Drink::setInitQuantity(int quantity){
    this->quantity = quantity;
}
//get initial quantity
int Drink::getInitQuantity(){
    return this->quantity;
}
//set current quantity
void Drink::setQuantity(int quantity){
    this->temp_quantity = quantity;
}
//get current quantity
int Drink::getQuantity(){
    return this->temp_quantity;
}
void Drink::setType(DrinkType type){
    this->type = type;
}
DrinkType Drink::getType(){
    return this->type;
}
void Drink::print(){
    cout << this->name <<", Price: " << this-> price << " + Drink data" << endl;
}
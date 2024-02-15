//include header file(s)
#include "NonAlcoholicDrink.h"


NonAlcoholicDrink::NonAlcoholicDrink(){}
//initialize with name, price, quantity, and type;
NonAlcoholicDrink::NonAlcoholicDrink(
    string name, 
    float price, 
    int quantity, 
    DrinkType type,
    float liters,
    float cityTax)
: Drink (name, price, quantity, type)
{
    setLiters(liters);
    setCityTax(cityTax);
}
void NonAlcoholicDrink::setLiters(float liters){
    this->liters = liters;
}
float NonAlcoholicDrink::getLiters(){
    return this->liters;
}
void NonAlcoholicDrink::setCityTax(float cityTax){
    this->cityTax = cityTax;
}
float NonAlcoholicDrink::getCityTax(){
    return this->cityTax;
}
//CalculatePrice()  -> Quantity * Price + CityTax
float NonAlcoholicDrink::calculatePrice(int qty = 1){
    return (qty * this->getPrice() + this->cityTax);
}
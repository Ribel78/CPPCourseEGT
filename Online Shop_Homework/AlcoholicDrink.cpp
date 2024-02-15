//include header file(s)
#include "AlcoholicDrink.h"


AlcoholicDrink::AlcoholicDrink(){}
//initialize with name, price, quantity, and type;
AlcoholicDrink::AlcoholicDrink(
    string name, 
    float price, 
    int quantity, 
    DrinkType type,
    float ABV,
    float tax)
: Drink (name, price, quantity, type)
{
    setABV(ABV);
    setTax(tax);
}
void AlcoholicDrink::setABV(float ABV){
    this->ABV = ABV;
}
float AlcoholicDrink::getABV(){
    return this->ABV;
}
void AlcoholicDrink::setTax(float tax){
    this->tax = tax;
}
float AlcoholicDrink::getTax(){
    return this->tax;
}
//CalculatePrice() > Quantity * (Price  * Tax)
float AlcoholicDrink::calculatePrice(int qty = 1){
    return (qty * this->getPrice() * this->tax);
}
#include <iostream>
#include "Package.h"
#include "Address.h"

//define class constructors and functions

Package::Package(Address s, Address r)
: senderAddress(s), receiverAddress(r){}
Package::Package(Address s, Address r, double basePrice, double weight)
: senderAddress(s), receiverAddress(r), basePrice(basePrice), weight(weight){}
Package::~Package(){}

void Package::setSenderAddress(string address){
    this->senderAddress.setAddress(address);
}
void Package::setReceiverAddress(string address){
    this->receiverAddress.setAddress(address);
}
string Package::getSenderAddress(){
    return this->senderAddress.getAddress();
}
string Package::getReceiverAddress(){
    return this->receiverAddress.getAddress();
}
void Package::printSenderAddress(){
    cout << this->senderAddress.getAddress() << endl;
}
void Package::printReceiverAddress(){
    cout << this->receiverAddress.getAddress() << endl;
}

void Package::setBasePrice(double basePrice){
    this->basePrice = basePrice;
}
double Package::getBasePrice(){
    return this->basePrice;
}
void Package::setWeight(double weight){
    this->weight = weight;
}
double Package::getWeight(){
    return this->weight;
}
double Package::calculateCost(){
    return this->basePrice*this->weight;
}
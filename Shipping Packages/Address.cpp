#include "Address.h"

Address::Address(){
    setAddress("UNDEFINED");
}
Address::Address(string address){
    setAddress(address);
}
Address::~Address(){}

void Address::setAddress(string address){
    this->address = address;
}
string Address::getAddress(){
    return this->address;
}
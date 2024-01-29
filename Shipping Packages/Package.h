#ifndef _Package_H_
#define _Package_H_

#include "Address.h"
using namespace std;

//declare class
class Package{
public:
    Package(Address, Address);
    Package(Address, Address, double, double);
    ~Package();
    void setSenderAddress(string);
    void setReceiverAddress(string);
    string getSenderAddress();
    string getReceiverAddress();
    void printSenderAddress();
    void printReceiverAddress();
    virtual void setBasePrice(double);
    virtual double getBasePrice();
    virtual void setWeight(double);
    virtual double getWeight();
    virtual double calculateCost();
private:
    Address senderAddress;
    Address receiverAddress;
    double basePrice;
    double weight;
};
#endif //_Package_H_
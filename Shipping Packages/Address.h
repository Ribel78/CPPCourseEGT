#ifndef _Address_H_
#define _Address_H_

#include <string>
using namespace std;

class Address{
public:
    Address();
    Address(string);
    ~Address();
    void setAddress(string);
    string getAddress();
private:
    string address;
};

#endif //_Address_H_
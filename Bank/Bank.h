
#ifndef _BANK_H_
#define _BANK_H_

#include<iostream>
using namespace std;

class Account{

public:
    Account();
    Account(double);
    void credit(double);
    void debit(double);
    double getBalance();
private:
    double balance;

};

#endif
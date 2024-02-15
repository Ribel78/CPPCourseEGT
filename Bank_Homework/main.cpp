#include<iostream>
#include "Bank.h"

using namespace std;

int main(){

    Account acc1 = Account(100);
    Account acc2 = Account(300);
    cout << acc1.getBalance() << endl;
    acc1.credit(50);
    cout << acc1.getBalance() << endl;
    acc1.debit(200);
    cout << acc1.getBalance() << endl;

    double amount = acc1.getBalance();
    acc2.credit(amount);
    cout << acc2.getBalance() << endl;
    acc1.debit(amount);
    cout << acc1.getBalance() << endl;

    return 0;
}

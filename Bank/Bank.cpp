#include "Bank.h"

Account::Account(){};
Account::Account(double balance){
    
    if (balance >= 0)
    { //validate if greater or equal than 0
        this->balance = balance;
    } else { //display an error message
        this->balance = 0;
        cout << "The initial balance is invalid." << endl;
    };
};
void Account::credit(double amount){
    //should add an amount to the current balance.
    if (amount > 0) {
        this->balance += amount;
    } else {
        cout << "The amount must be positive value." << endl;
    };
    
};
void Account::debit(double amount){
    /*
    withdraw money from the Account and should ensure that the debit amount does not exceed the Account's balance. 
    If it does, the balance should be left unchanged and the function should print a message: "Debit amount exceeded account balance."    
    */
   if(balance-amount >= 0){
        this->balance -= amount;
   } else{
        cout << "Debit amount exceeded account balance" << endl;
   }
};
double Account::getBalance(){
    return this->balance;
};
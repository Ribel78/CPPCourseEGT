#include "User.h"

User::User(){}
//initialize with date;
User::User(string username){
    setUserName(username);
}
void User::setUserName(string username){
    this->username = username;
}
string User::getUserName(){
    return this->username;
}
void User::addOrder(Order* order){
    this->orders.push_back(order);
}
void User::listOrders(){
    for (Order * ord : this->orders){
        ord->listItems();
    }
}
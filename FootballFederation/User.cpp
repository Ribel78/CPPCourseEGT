#include "User.h"

User::User(string user_name, string password){
    setUser(user_name, password);
    cout << "User object " << user_name <<" was constructed " << endl;
}
User::~User(){
    cout << "User object "<< user_name << " was destructed" << endl;
}
void User::setUser(string user_name, string password){
    this->user_name = user_name;
    this->password = password;
}
#ifndef User_h
#define User_h

#include <iostream>
#include <string>
using namespace std;

class User{
public:
    User(string, string);
    ~User();
    void setUser(string, string);

private:
    string user_name;
    string password;
};

#endif  //User_h
#ifndef Employee_H
#define Employee_H
#include <string>
#include <iostream>

using namespace std;

class Employee{
public:
    Employee();
    Employee(string, string, string);
    void setName(string);
    string getName();
    void setEmployeeID(string);
    string getEmployeeID();
    void setPosition(string);
    string getPosition();
    void display();
private:
    string name;
    string employeeID;
    string position;
};
#endif //Employee_H
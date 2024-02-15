
#include "Employee.h"

//initialize class object with name, employee id and position using setter functions
Employee::Employee(){}
Employee::Employee(string name, string id, string pos){
    setName(name);
    setEmployeeID(id);
    setPosition(pos);
}
    void Employee::setName(string name){
        this->name = name;
    }
    string Employee::getName(){
        return this->name;
    }
    void Employee::setEmployeeID(string id){
        this->employeeID = id;
    }
    string Employee::getEmployeeID(){
        return this->employeeID;
    }
    void Employee::setPosition(string pos){
        this->position = pos;
    }
    string Employee::getPosition(){
        return this->position;
    }
    void Employee::display(){ 
        cout << getName() << "; " << getEmployeeID() <<"; " << getPosition() << endl;
    }
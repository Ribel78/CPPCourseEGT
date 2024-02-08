#pragma once

#include <vector>
#include <string>
#include "Workstation.h"

using namespace std;

//simple Employee class
class Employee{
public:
    Employee(string name, string type, string age)
    :name(name), type(type), age(age){}
    string getName(){ return name; }
    string getType(){ return type; }
    string getAge(){ return age; }

private:
    string name;
    string type;
    string age;
};

//more complex Employee class
class Employee2{
public:
    Employee2(string name, string type, string age, string building, string floor, string desc)
    :name(name), type(type), age(age){
        workstation.setBuilding(building);
        workstation.setFloor(floor);
        workstation.setDesc(desc);
    }
    string getName(){ return name; }
    string getType(){ return type; }
    string getAge(){ return age; }
    Workstation workLocation(){ return this->workstation;}
private:
    string name;
    string type;
    string age;
    Workstation workstation;
};

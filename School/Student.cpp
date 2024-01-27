#include "Student.h"
#include <iostream>
#include "Class.h"

Student::Student(string name, string id, Class& c)
:classObj(c){
    this->name = name;
    this->studentID = id;
}
string Student::getName(){
    return this->name;
}
void Student::getData(){
    cout
    << "Name: "
    << this->name
    << " ID :"
    << this->studentID
    << " Class: "
    << classObj.getClassID()
    << endl;
}
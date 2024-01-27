#include<iostream>
#include "Teacher.h"

Teacher::Teacher(string name, string title, Discipline& d)
:discipline(d){ // OK
    this->name = name;
    this->title = title;
    // this->discipline = d; // Error
}

void Teacher::getData(){
    cout
    << this->title
    << " "
    << this->name
    << " / ";
    discipline.getData();
}
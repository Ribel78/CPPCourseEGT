#include <iostream>
#include "Discipline.h"

Discipline::Discipline(string name, int lCount, int eCount){
    this->name = name;
    this->lecturesCount = lCount;
    this->exercisesCount = eCount;
};

void Discipline::getData(){
    cout 
    << this->name 
    << " " 
    << this->lecturesCount
    << " "
    << this->exercisesCount
    << endl;
}
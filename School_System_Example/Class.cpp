#include <iostream>
#include "Class.h"

Class::Class(char id, vector<Teacher>& t)
{
    this->classID = id;
    this->teachers = t;
}
char Class::getClassID(){
    return this->classID;
}
void Class::getTeachers(){
    cout << "Class ID: " << this->getClassID() << endl;
    for(Teacher teacher:this->teachers){
        teacher.getData();
    }
}
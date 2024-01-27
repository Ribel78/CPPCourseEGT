//include header file(s)
#include "Author.h"

//#include <XXX> //include nescessary libraries

//define class constructors and functions

Author::Author(){}
Author::Author(string name, string surname, string nationality)
:name(name), surname(surname),nationality(nationality){}

void Author::setName(string){
    this->name = name;
}
string Author::getName(){
    return this->name;
}
void Author::setSurame(string){
    this->surname = surname;
}
string Author::getSurname(){
    return this->surname;
}
void Author::setNationality(string){
    this->nationality = nationality;
}
string Author::getNationality(){
    return this->nationality;
}
void Author::printData(){
    cout
    << "Author: " << this->name << " " << this->surname << ", " << this->nationality
    << endl;
}
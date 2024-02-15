#ifndef _Author_H_
#define _Author_H_

#include <iostream>
using namespace std;

//declare class
class Author{
public:
    Author(); //init class obj
    Author(string, string, string); //init class obj
    void setName(string); //set function
    string getName(); //get function
    void setSurame(string); //set function
    string getSurname(); //get function
    void setNationality(string); //set function
    string getNationality(); //get function    
    void printData(); // print member information
    
private:
    string name;
    string surname;
    string nationality;
};
#endif //_Author_H_
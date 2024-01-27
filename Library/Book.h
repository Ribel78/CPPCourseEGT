#ifndef _Book_H_
#define _Book_H_
//try matching .h and .cpp files with class name
//#include <XXX> //include nescessary libraries
#include "Author.h"
#include <iostream>
using namespace std;

enum Genre{CLASSIC, CHILDRENS, SCIFI, BIOGRAPHICAL, ROMANCE, HORROR};

//declare class
class Book{
public:
    Book(); //init class obj
    Book(Author&, string, int, Genre); //init class obj
    void setTitle(string);
    string getTitle();
    void setYear(int);
    int getYear();
    void setGenre(Genre); //set function
    Genre getGenre(); //get function
    void printData(); // print member information

    
private:
    Author author;
    string title;
    int year;
    Genre genre;

};
#endif //_Book_H_
#ifndef _Library_H_
#define _Library_H_
#include <iostream>
#include <string>
#include <vector>
#include "Book.h"

//declare class
class Library{
public:
    Library(); //init class obj
    Library(vector<Book>); //init class obj
    void addBook(Book&);
    void findBook(string);
    void printData();
private:
    vector<Book> books;
};
#endif //_Library_H_
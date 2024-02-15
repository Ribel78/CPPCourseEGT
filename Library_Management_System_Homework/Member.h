#ifndef Member_H
#define Member_H

#include "Book.h"
#include <vector>

class Member{
public:
    Member(string, int, string);
    void display();
    void borrowBook(Book*);
private:
    string name;
    int age;
    string memberID;
    vector<Book*> bookList;
};
#endif //Member_H
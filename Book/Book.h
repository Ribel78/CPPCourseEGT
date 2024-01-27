#ifndef CPPCLASSES_BOOK_H
#define CPPCLASSES_BOOK_H
#include <string>
#include <iostream>
using namespace std;

class Book{
    public:
        Book();
        Book(string, string, int, float, int);
        void setTitle(string);
        void setAuthor(string);
        void setYear(int);
        void setPrice(float);
        void setQuantity(int);
        void inputData();
        string getTitle();
        string getAuthor();
        float getPrice();
        int getQuantity();
        void printData();

    private:
        string title;
        string author;
        int year;
        float price;
        int quantity;
};

#endif //CPPCLASSES_BOOK_H
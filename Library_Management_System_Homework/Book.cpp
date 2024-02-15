#include "Book.h"

//initialize Book with member initializer list
Book::Book(string title, string author, string ISBN)
:title(title), author(author), ISBN(ISBN){}

//display book private data
void Book::display(){
    cout << title << ";  "<< author << "; "<< ISBN << endl;
}
//include header file(s)
#include "Library.h"
#include <string>

//define class constructors and functions

Library::Library(){}
Library::Library(vector<Book> books):books(books){

}
void Library::addBook(Book& book){
    this->books.push_back(book);
}
void Library::findBook(string keyword){
    cout << "Search Results for: " << keyword << "\n";
    for (Book b : books){
        if (b.getTitle().find(keyword)!= -1){ // string::npos or -1
            cout << "------------------------------------\n";
            b.printData();
            cout << "------------------------------------\n";
        }
    }    
}
void Library::printData(){
    for (Book b : books){
        cout << "------------------------------------\n";
        b.printData();
        cout << "------------------------------------\n";
    }
}
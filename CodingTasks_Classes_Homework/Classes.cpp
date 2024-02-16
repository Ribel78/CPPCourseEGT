#include <iostream>
#include <string>

//class declaration block
class Book{
public: //public members and class constructor(s)
    //constructor with member initialization list
    Book(   std::string _title,
            std::string _author,
            int _pages)
            :title(_title), author(_author), pages(_pages){}
    //class function declaration
    void display(){
        std::cout 
        << "Book title: " << title << "\n"
        << "Author: " << author << "\n"
        << "Number of Pages: " << author << "\n"
        << std::endl;
    }
private: //private members, no direct access

    std::string title;
    std::string author;
    int pages;

};
int main(){
    //class object declarattion
    Book book("The Shallows","Nicholas Carr", 298);
    //accessing available object properties and methods via "." operator
    book.display();

    return 0;
}
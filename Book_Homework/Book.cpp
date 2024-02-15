#include "Book.h"

Book::Book(){};
Book::Book(string title, string author, int year, float price, int qty){
    setTitle(title);
    setAuthor(author);
    setYear(year);
    setPrice(price);
    setQuantity(qty);
};
void Book::setTitle(string title){
    this->title = title;
}
void Book::setAuthor(string author){
    this->author = author;
}
void Book::setYear(int year){
    this->year = year;
};
void Book::setPrice(float price){
    this->price = price;
}
void Book::setQuantity(int qty){
    this->quantity = qty;
}
void Book::inputData(){
    string temp;
    cout << "Title: "   ;  getline(cin>>ws, this->title); // cin>>ws - ignores any leading whitespace characters
    cout << "Author: "  ; getline(cin>>ws, this->author);
    cout << "Year: "    ;          cin >> this->year;
    cout << "Price: "   ;          cin >> this->price;
    cout << "Qty: "     ;          cin >> this->quantity;
};

string Book::getTitle(){
    return this->title;
}
string Book::getAuthor(){
    return this->author;
}
float Book::getPrice(){
    return this->price;
}
int Book::getQuantity(){
    return this->quantity;
}
void Book::printData(){
    cout << "Title: " << this->title 
        << "; Author: " << this->author 
        << "; Year: " << this->year
        << "; Price: " << this->price 
        << "; Qty: " << this->quantity 
        << endl;
}

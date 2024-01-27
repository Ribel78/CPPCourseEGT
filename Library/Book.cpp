//include header file(s)
#include "Book.h"

//#include <XXX> //include nescessary libraries

//define class constructors and functions
string genres[] = {"CLASSIC", "CHILDRENS", "SCIFI", "BIOGRAPHICAL", "ROMANCE", "HORROR"};
Book::Book(){}
Book::Book(Author& author, string title, int year, Genre genre)
:author(author), title(title), year(year), genre(genre){}

void Book::setTitle(string){
    this->title = title;
}
string Book::getTitle(){
    return this->title;
}
void Book::setYear(int){
    this->year = year;
}
int Book::getYear(){
    return this->year;
}
void Book::setGenre(Genre genre){
    this->genre = genre;
}
Genre Book::getGenre(){
    return this->genre;
}
void Book::printData(){
    cout
    << this->title << " " << this->year << " " << genres[this->genre]
    << endl;
    this->author.printData();
}


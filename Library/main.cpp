#include "Author.h"
#include "Book.h"
#include "Library.h"
#include <iostream>
#include <cstring>

using namespace std;

int main(){

    Author sk("Stephen", "King", "American");
    Author jv("Jules", "Verne", "French");
    Author iv("Ivan", "Vasov", "Bulgarian");
    Author ea("Edward", "Ardizzone", "British");
    Author rb("Rumen", "Belev", "Bulgarian");

    Book book1(sk, "It", 1947, Genre::HORROR);
    Book book2(jv, "Captain Nemo", 1905, Genre::CLASSIC);
    Book book3(sk, "Pet Sematary", 1983 , Genre::HORROR);
    Book book4(iv, "Under the Yoke", 1888, Genre::CLASSIC);
    Book book5(ea, "Tim's Last Voyage", 1950, Genre::CHILDRENS);
    Book book6(rb, "Competition", 2024, Genre::ROMANCE);

    Library lib;
    lib.addBook(book1);
    lib.addBook(book2);
    lib.addBook(book3);
    lib.addBook(book4);
    lib.addBook(book5);
    lib.addBook(book6);

    lib.printData();

    lib.findBook("Nemo");

    lib.findBook("pet");


    return 0;
}
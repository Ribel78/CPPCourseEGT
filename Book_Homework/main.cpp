#include <vector>
#include "Book.h"
using namespace std;

// find a book with minimal price - takes Books vector as argument
void minBookPrice(auto &vec_books){ //use of 'auto' in parameter declaration only available with '-std=c++20' or '-fconcepts'
    float minPrice = vec_books.at(0).getPrice();
    int idx = 0;
    for (int i = 1; i < vec_books.size(); i++){
        if (minPrice > vec_books.at(i).getPrice()){
            minPrice = vec_books.at(i).getPrice();
            idx = i;
        }
    }
    cout << "The book \"" << vec_books.at(idx).getTitle() << "\" has minimum price of:" << minPrice << endl;
}
// find a book with maximal price - takes Books vector as argument
void maxBookPrice(auto &vec_books){ //use of 'auto' in parameter declaration only available with '-std=c++20' or '-fconcepts'
    float maxPrice = vec_books.at(0).getPrice();
    int idx = 0;
    for (int i = 1; i < vec_books.size(); i++){
        if (maxPrice < vec_books.at(i).getPrice()){
            maxPrice = vec_books.at(i).getPrice();
            idx = i;
        }
    }
    cout << "The book \"" << vec_books.at(idx).getTitle() << "\" has maximum price of:" << maxPrice << endl;
}
// find books by author name
void findBookByAuthor(auto &vec_books){
    string author;
    cout << "Find books by author name: ";
    getline(cin >> ws, author);
    for (int i = 0; i < vec_books.size(); i++){
        if (author == vec_books.at(i).getAuthor())
        {
            vec_books.at(i).printData();
        }
        
    }
}

int main(){

    // Enter Book Data
    int amountBooks = 0;
    cout << "Amount of books to process: ";
    cin >> amountBooks;

    vector<Book> books;

    for (int i = 0; i < amountBooks; i++){
        Book b;
        b.inputData();
        books.push_back(b);
    }
    for (int i = 0; i < amountBooks; i++){
        books.at(i).printData();
    } 

    // Get Book with Min and Max Price
    minBookPrice(books);
    maxBookPrice(books);
    // Find Books by Author's Name
    findBookByAuthor(books);

    return 0;
}
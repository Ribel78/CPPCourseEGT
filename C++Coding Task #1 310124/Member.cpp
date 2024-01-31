#include "Member.h"

Member::Member(string name, int age, string memberID)
:name(name), age(age), memberID(memberID){}

//display Member private data and list of borrowed boks
void Member::display(){
    cout << name << "; " << age << "; " << memberID << endl;
    cout << "Borrowed books:\n";
    for (Book* book : bookList){
        book->display();
    }
    cout << "------- End of member data -------\n";
}
void Member::borrowBook(Book* book){
    bookList.push_back(book);
}
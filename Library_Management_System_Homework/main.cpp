#include "Book.h"
#include "Member.h"

int main(){
    //create Book objects
    Book book1("Title 1", "Author 1", "ISBN-1");
    Book book2("Title 2", "Author 2", "ISBN-2");
    Book book3("Title 3", "Author 3", "ISBN-3");

    cout << "Book 3 display data:\n";
    book3.display();
    cout << endl;
    
    //create Member objects 
    Member member1("Name 1", 21, "member ID1");
    Member member2("Name 2", 22, "member ID2");
    Member member3("Name 3", 23, "member ID3");
    //create a vector of Book obj pointers
    vector<Book*> library;
    library.push_back(&book1);
    library.push_back(&book2);
    library.push_back(&book3);
    //create a vector of Member obj pointers
    vector<Member*>members;
    members.push_back(&member1);
    members.push_back(&member2);
    members.push_back(&member3);

    //Members borrowing books
    member1.borrowBook(&book1);
    member2.borrowBook(&book1);
    member2.borrowBook(&book2);
    member3.borrowBook(&book1);
    member3.borrowBook(&book2);
    member3.borrowBook(&book3);

    //print out members info and borrowed books
    member1.display();
    member2.display();
    member3.display();

    return 0;
}
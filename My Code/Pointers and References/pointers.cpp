#include<iostream>

using std::cout;
using std::endl;
using std::cin;

//pointers;

int main(){
    int x = 10; //init x

    cout << x << endl; //value of x
    cout << &x << endl; // address of x

    int *ptr = &x; // pointer to address of x
    cout << *ptr << endl; //value
    cout << ptr << endl; // address

    cout << &ptr << endl; //address of the pointer

    *ptr = 30; //modify x via pointer
    cout << x << endl; //new x value

    return 0;

}
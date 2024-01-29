#include<iostream>
#include<string>
using namespace std;

// example of void function
void printSignOfNumber()
{
    int number;
    cout << "Enter positive or negative number:" <<endl;
    cin >> number;

    if (number > 0){
        cout << "+\n";
    }else{
        cout << "-\n";
    }

}
// example of return function
int sumOfTwoNumbers()
{
    int a,b;
    cout << "Integer A: \n";
    cin >> a;
    cout << "Integer B: \n";
    cin >> b;
    int sum = a + b;
    return sum;
}
int sumOfTwoNumbers2(int a, int b)
{
    int sum = a + b;
    return sum;
}
// reference and change global variable
void referGlobalVar(int & a)
{
    a = a + 1;
}

int main ()
{
    printSignOfNumber();
    cout << "Sum of two numbers: " << sumOfTwoNumbers() << endl;
    cout << "Sum of two numbers as function arguments: " << sumOfTwoNumbers2(13,15) << endl;

    int gVar = 66;
    cout << "Global variable gVar: " << gVar << endl;
    referGlobalVar(gVar);
    cout << "Global variable gVar modified by a function: " << gVar << endl;
    return 0;
}
#include<iostream>

using namespace std;

void printHello();
int sum (int a, int b);
int getMax (int a, int b, int c);

int main(){
    cout << getMax(5,5,8) << endl;
return 0;
}

void printHello(){
    cout << "Hello world!" << endl;
}

int sum (int a, int b){
    return a+b;
}
int getMax (int a, int b, int c){
    if (a>=b && a>=c) return a;
    if (b>=a && b>=c) return b;
    if (c>=a && c>=b) return c;
    return 0;
}
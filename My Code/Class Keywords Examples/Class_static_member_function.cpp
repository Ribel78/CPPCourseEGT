#include<iostream>
using namespace std;
//static class member and function example
class A{
public:
    A(string name, int adder):name(name),adder(adder){    }
    void add(){ // function to add specified adder number to the current common_sum value
        cout << name << " is adding " << adder << " to " << common_sum << endl;
        common_sum += adder;
    }
    static void getComonSum(){ // call this function outside any instance to get the static member value
        cout << "Current common sum is: " << A::common_sum << endl;
    }
private:
    string name;
    int adder;
    static int common_sum;
};
int A::common_sum = 0; //initialize the static member outside of class definition

int main(){

    A alex("Alex",3);
    A bob("Bob", 5);

    alex.add();
    bob.add();
    alex.add();
    bob.add();
    alex.add();
    bob.add();
    A::getComonSum();

    return 0;
}






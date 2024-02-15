#include<iostream>
#include<string>
#include<list>
#include<set>
#include<map>
#include <queue>
using namespace std;

int main(){

 list<int> numbers = {1,5,7,2,8,3,5,9,3};

list<int> s_numbers =  numbers;
s_numbers.sort();

for (int l : s_numbers){
    cout << l << endl;
}
for (int l : numbers){
    cout << l << endl;
}

cout << *numbers.begin() << endl;

    return 0;
}






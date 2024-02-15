#include<iostream>
#include<string>
#include<list>
#include<set>
#include<map>
using namespace std;

int main(){
// create list
    list<int> mylist;
    int number = 1;
    while (number > 0){
        cout << "Enter number: ";
        cin >> number;
        if (number > 0){
            mylist.push_back(number);
        } else {
            break;
        }
    }
//find sum
    int sum = 0;
//standard for loop
    for (int i : mylist){
        sum+=i;
    }
    cout << "Sum: " << sum << endl;

    sum = 0;
//loop using iterator
    for (list<int>::iterator i = mylist.begin(); i != mylist.end(); i++){
        sum+=*i;
    }
    cout << "Sum: " << sum << endl;

    int arr[20] = {8,8,5,7,4,4,4,4,4,4,1,4,4,4,8,8,5,5,12,12};
    set<int> mySet;
    for (int a : arr){
        mySet.insert(a);
    };
    map<int, int> myMap;
    int maxCount = 0;
    for (int s : mySet){
        cout << " " << s;
        myMap[s] = 0;
    }
    cout << "\n";
    for (pair<int, int> el: myMap){
        for (int i = 0; i < 20; i++){
            if (el.first == arr[i]){
                maxCount += 1;
                if (myMap[el.first] < maxCount){
                    myMap[el.first] = maxCount;
                }
            } else{
                maxCount = 0;
            }
        }
    }
    int maxLenght = 0;
    int maxNumber = -1;
    for (pair<int, int> el: myMap){
        cout << el.first << " : "<< el.second << endl;
        if (el.second > maxLenght){
            maxLenght = el.second;
            maxNumber = el.first;
        }
    }
    cout
    << "Number: " << maxNumber
    << " has max subset of " << maxLenght
    << endl;
    int idx = 0;
    bool sameNumber = false;
    for (int i = 0; i < 20; i++){
        if (arr[i] == maxNumber){
            for (int j = 0; j < maxLenght; j++){
                if (arr[i] == arr[i+j]){
                    sameNumber = true;
                } else{
                    sameNumber = false;
                    break;
                }
            }
        }
        if (sameNumber){ 
            idx = i;
        }
    }

    cout << "Startirng array Index: " << idx << endl;

    return 0;
}




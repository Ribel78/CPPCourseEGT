#include<iostream>
#include<string>
#include<list>
#include<set>
#include<map>
#include <queue>
#include <vector>
using namespace std;

// Containers and Iterators - Task 4

int main(){

    vector<string> v_str = {"efsa","asefgsarfg","sagsgas34","eatssr"};
    vector<string>::iterator it;
    for (string s : v_str){
        cout << s << endl;
    }
    //v_str.erase()
    for(it=v_str.begin(); it != v_str.end(); ++it){
        if(*it == "sagsgas34"){
            v_str.erase(it);
        }
    }
    for (string s : v_str){
        cout << s << endl;
    }
    return 0;
}

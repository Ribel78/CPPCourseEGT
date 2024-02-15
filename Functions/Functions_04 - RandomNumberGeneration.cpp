// default function parameter value and random number generation function examples

#include<iostream>
#include<cstdlib>

using namespace std;

void defargs(int a, int b, int c = 100){ // default value parametrers demo
//all parameters after the first with default value must also have default values!
    cout
    << a << " "
    << b << " "
    << c << " "
    << endl;
}
int main (){
    // enter only the first two default-less arguments
    cout <<"Third argument is default\n";
    defargs(3,2);

    unsigned seed; // variable to have the same random numbers generated
    //random number generation using time function as automatic seed value
    //time_t current_time;
    //seed = time(&current_time); // stores the current time in seconds to reference variable
    // use current time as seed for random generator (alternative)    
    seed = time(0);
    srand(seed); //pseudo-random number generator for rand() function
    // random number on each iteration
    for (int i=0; i < 3; i++){
        cout << rand() % 100
        << endl;
    }

    return 0;
}
#include<iostream>

using namespace std;

/*
Experiments with Recursive functions
Greatest common divisor (GCD)
https://en.wikipedia.org/wiki/Greatest_common_divisor
*/
//Euclidean algorithm - better one
int GCD (int a, int b); 

//Euclid's' algorithm
int eGCD(int a, int b); 

//Returns binary representation of an integer as a string
string toBinary(int number);
// not recursive but to complement the above function - converting back from binary to decimal
int toDecimal(string sNumber); 

int main(){
    cout << "Find greatest common divisor (GCD)\n";
    cout << "Enter two integers\n";
    int n1, n2;
    cin >> n1 >> n2;
    cout << "Euclidean GCD of "<< n1 << " and " << n2 << endl;
    cout << GCD(n1, n2) << endl;
    cout << "Euclid's' GCD of "<< n1 << " and " << n2 << endl;
    cout << eGCD(n1, n2) << endl;

    int number;
    cout << "Enter Integer to find its Binary form\n";
    cin >> number;
    cout << toBinary(number) << " converted back to " << toDecimal(toBinary(number))<< endl;
    cout << endl;
    cout << "Which number is 1001011001? " << toDecimal("1001011001") << endl;

    return 0;
}

int GCD (int a, int b){
    if (b == 0){
        //cout <<"b=0\n";
        return a;
    }
    //cout << "GCD("<< a << "," << b <<")\n";
    return GCD(b, a%b);
}

int eGCD(int a, int b){
    if (a==b){
        //cout <<"a=b\n";
        return a;
    }
    //cout << "eGCD("<< a << "," << b <<")\n";
    return eGCD((a>b)?a-b:a,(b>a)?b-a:b);
}

string toBinary(int number){
    if (number / 2 == 0){
        return to_string ( number % 2 );
    }      
        return toBinary( number /= 2 ) += to_string (number % 2);
}

int toDecimal(string sNumber){
    int decimal = 0; int exp2 = 1;
    for (int i = 0; i < sNumber.size(); i++){
        for (int j = 0; j < sNumber.size()-i-1; j++){ // exponent
            exp2 *= 2;
        }
        decimal += ((sNumber[i] == '1')? 1:0) * exp2;
        exp2 = 1;
    }
    return decimal;
}
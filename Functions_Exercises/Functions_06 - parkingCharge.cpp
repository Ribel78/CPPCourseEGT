#include<iostream>
#include<cmath>
//using namespace std;
using std::cout;
using std::endl;

int array[5] = {1,2,3,4,5};
int func(int a[], int arr_size){
    return a[0];
}

double parkingCharge(double hours){
    
    // 0.5 charge per hour
    // max charge above 24 hours $10.00
    float charge = 2.00f;
    if (hours <= 3 ){// if less than 3 hours $2.00
        return charge;
    }
    if (hours > 3 && hours < 24){
        return ((charge + (hours-3)*0.5) > 10 )? 10:(charge + (hours-3)*0.5);
    } else{
        return ((int)hours/24)*10 + ((int)hours%24)*0.5;
    }
    return 0;
}


int main(){
    cout << parkingCharge(3) << endl;
    cout << parkingCharge(5) << endl;
    cout << parkingCharge(21) << endl;
    cout << parkingCharge(24) << endl;
    cout << parkingCharge(26) << endl;
    cout << parkingCharge(123) << endl;
    cout << floor(12.01) << endl;
    cout << round(12.50) << endl;
    cout << ceil(12.01) << endl;
    cout << func(array,5) << endl;
    return 0;
}
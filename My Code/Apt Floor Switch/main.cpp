#include <iostream>

using namespace std;

int main (){
	// задай число за тестване
    long a = 23459;
    cout << "The number is: " << a << endl;
    // променлива за съхранение на обърнатото число
    long b = 0;
    
    // в случай че някой иска да сложи нули накрая
    int leadingZeros = 0;
    //изписване на числата от края към началото
    cout << "Pulling digits from the back:" << endl;
    while (a > 0)
    {
        cout << a % 10 << endl;
        // записва изваденото число
        b = b + (a % 10);
        b = b * 10;
        // ако b е още 0 увеличи leadingZeros с 1
        if (b == 0){
        	leadingZeros += 1;
        }
        // подготви a за следващото повторение
        a = a/10;
    }
    //премахване на последната 0 от b
    b = b/10;
    
	//изписване на числата от началото края
    cout << "Pulling digits from the front:" << endl;
    // практически копие на горния while цикъл но само за b
    while (b > 0)
    {
        cout << b % 10 << endl;
        // подготви b за следващото повторение
        b = b/10;
    }
    // принтирай крайни нули като водещи ако има някакви
        for (int i = 0; i < leadingZeros; i++){
    	cout << 0 << endl;
    }
    return 0;
}
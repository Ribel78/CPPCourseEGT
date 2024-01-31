#include <iostream>

float square(float x){
    return x*x;
}
int main(){
  /*
#1 Syntax Explanation - int* ptr = &var;

    Pointer holding the address of a variable var of type integer. 
    The pointer variable can provide access to the value at the address by the means of dereferencing
    Указател към адреса на целочистлена променлива var. Указателя може да даде достъп до стойността на променливата 
    чрез така наречения дереференсинг.
*/  
std::cout << "Pointer - address example\n";
int var = 25;
int* ptr = &var;
std::cout << "Address of var is: " << ptr << std::endl;
std::cout << "Value of var is: " << *ptr << std::endl; //dereferencing

/*
#2 Concept clarification - Explain the difference between a while and do-while loop in C++
    The condition for execution of the body of the loop is checked before the first cycle in the while loop and
    after the first cycle in the do-while loop. We can use the do-while loop when we want the code to be executed at least once.

    Условния израз на цикъла се проверява преди първото изпълнение на кода в тялото на цикъла за while и 
    след първия цикъл при do-while. do-while е предпочитан вариант когато искаме да изпълним кода на цикъла поне веднъж, независимо
    от резултата на условния израз.

*/
std::cout << "while example\n";
int targets = 3;
while (targets != 0){
    std::cout << "The rocket hit a target\n";
    targets -= 1;
}

// targets already equal to 0
std::cout << "do-while example\n";
do
{
    std::cout << "The rocket hit a target. Pack your bags!\n";
} while (targets != 0);

/*
#3 Code Analysis - Given a snippet of code containing a for loop, 
explain waht the loop does, including how many times it iterates and why
*/
for(int i = 0; i < 10; ++i){
    std::cout << i*5;
}
/*#3--
The for loop executes a code repeatedly if a condition is true
In most cases the condition involves a changing variable existing in the scope of the loop
in this case the variable i is initialized to 0 and incremented by 1 afer each loop
until it reaches the value of 10, at this point the condition no longer holds true and the loop cycle is terminated

for loop цикъла изпълнява код отново и отново докато дадено условие е истина
В повечето случаи условието е свързано с локална променлива съществуваща само в тялото на цикъла
В гоения случай това е променливата i която е инициализирана първоначално със стойнаосста 0
и увеличавана с 1 при всеки нов цикъл, докато не достигне 10. Когато това стане - условието
вече не е истина и цикълът се прекъсва.
*/

/*
#4 Function usage - Write about how functions prevent code duplication and
give an example of a simple C++ function that calculates the square of a number

Code duplication arise when using different parameters when calculating an expression or more complex block of code
For example if we need to calculate the squares of 3 different numbers we can write repetitive code for each number
or use a returning value function with different argument as an input.

Дупликацията на код се наблюдава при използване на различни параметри при изчисление на уравнение или по сложен
блок от код. Например ако трябва да зичислим квадратите на три различни числа можем да препишем един и същи код за тях или 
да използваме връщаща стойност функция която приема различен аргумент за вход на изчислението
*/
std::cout << "Code reusability via functions example\n";
float a = 5.6f;
float b = 7.8f;
float c = 8.98f;

float a_sqared = a*a;
float b_squared = b*b;
float c_squared = c*c;

//check the function "square" definition in the header
float a_sq = square(a);
float b_sq = square(b);
float c_sq = square(c);
/*
#5 Memory management - discuss the importance of memory management in C++ and explain 
the difference between stack and heap memory allocation
*/

/*
#6 Object Oriented Prgramming - Expalin the concept of encapsulation in C++ and how it is achieved using classes
*/

/*
#7 Error Handling - Describe how exceptions are used in C++for error handling, with an examplke of a try-catch block
*/

/*
#8 STL Containers - Write about the purpose and use of of the std::vector container in C++
*/

/*
#9 - Pointers and References - Discuss the difference between pointers and references in C++ 
and provide scenarios where one might be preffered over the other.
*/

/*
#10 - Advanced features - Expalin the concept of templayes in C++ and how they support generic programming.
Include a simple example of a template function
*/

    return 0;
}
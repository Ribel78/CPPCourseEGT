#include <iostream>
#include <vector>
float square(float x){
    return x*x;
}
class X{
public:
    X(std::string name):name(name){std::cout << name << " Object from X was created\n";}
    ~X(){std::cout << name << " Object from X was destroyed\n";}
private:
    std::string name;
};
//template function declaration
template <typename T>
T mult(T x, T y){
    return x*y;
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
    std::cout << i*5 << " ";
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
std::cout << "\nCode reusability via functions example\n";
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

Stack memory is the fastest system memory available to the program.
All objects are placed in the stack and kept there and removed once they are out of scope or executed respectivvely.
If the program becomes more complicated and requires more memory to handle larger objects they can be put in the heap
memory, which is bigger but slower. The difference as compared to the stacj memory is that the programmer must explicitly allocate
memory and delete the objects after they are no longer used.

Стак паметта е най-бързо достъпната за програмата системна памет. Живота на обектите се управлява автоматично - те се премахват от паметта
когато са извън тяхната област на съществувание. Хийп паметта за разлика от стак паметта е по-голяма но по-бавно достъпна.
И програмистът е отговорен за заделянето на памет и унищожаването на обектите след като не са нужни повече.
*/
std::cout << "#5 Difference between stack and heap memory allocation\n";
if(true){
    X obj_x("Stack Object");
}

X *obj_y = new X("Heap Object");
delete obj_y;

/*
#6 Object Oriented Prgramming - Expalin the concept of encapsulation in C++ and how it is achieved using classes
Encapsulation means enclosing object data and accessing it via object methods - meaning the data in the program is not
readily available from everywhere, but only through the intrface of the object thet contains it. 
The concept of Classes provide such encapsulation, where access to members is via getter and setter functions.

Енкапсулация е ограничаване на данните на обекта и достъпът до тяк само през методи на обекта, което означава че данните в една програма
не са лесно достъпни отвсякъде, а само през интерфейса на обекта който ги съдържа. Концепцията на класовете
предоставя такова енкапсулиране на данни, при което достъпа до членове на обкта става посредством функции за достъп (гетери и сетери).
*/

/*
#7 Error Handling - Describe how exceptions are used in C++for error handling, with an examplke of a try-catch block
A part code can be enclosed in a special block in attempt to manage errors that may arrise
usually done with try-throw-catch
*/

    int input;
    std::cout << "Enter age less than or equal to 18: ";
    std::cin >> input;
    try{
        if (input < 18){
        /*some expression to try*/
        throw input; //data type to throw on exception
        }
        if (input == 18){
            throw (double)input/5;
        }
    }
    catch(int x){ // catch the thrown value of type int and do something with it
        std::cout << "Error: Age - " << x <<" is bellow 18.\n";
    }
    catch(double x){ // catch the thrown value of type double and do something with it
        std::cout << "Error: 18 divided by 5 yelds a double " << x <<"." <<std::endl;;
    }    

/*
#8 STL Containers - Write about the purpose and use of of the std::vector container in C++

Vectors are containers used for storing multiple variables for later reuse and performing operations on individual or all members of the
vector called also elements. Vectors are available via the <vector> library and initialized by stating the type ov data they will contain

*/
//std::vector<int> arr (10); //init 10 elements with 0s
std::vector<int> arr {10, 20, 30 , 40, 50};
arr.push_back(60);
arr.erase(arr.begin()+2);
for (int& i : arr){ //using reference to element
    std::cout << i << ((&i != &arr.back())? " ":"\n"); 
    //taking the address of the element and comparing it with the last elem address to insrt newline instead of space
}

/*
#9 - Pointers and References - Discuss the difference between pointers and references in C++ 
and provide scenarios where one might be preffered over the other.

Pointer is a variable holding the address of another variable
Reference is variable that has access to another variable. The reference and target variable have the same address.
A ponter can change it's target variable, the reference can't.
*/

int the_variable = 30;
int another_variable = 50;
int* ptr_var = &the_variable; //pointer
int& varry = the_variable; //reference
*ptr_var = 31; //change the value


std::cout << "the_variable = " << the_variable << ", *ptr_var = " << *ptr_var << ", varry = " << varry << std::endl;
varry = 30; //change it back via reference
std::cout << "the_variable = " << the_variable << ", *ptr_var = " << *ptr_var << ", varry = " << varry << std::endl;
ptr_var = &another_variable; //point ot another variable now
the_variable +=10;
another_variable +=10; //change 50 to 60
// varry can't reffer to another variable

std::cout << "the_variable = " << the_variable << ", *ptr_var = " << *ptr_var << ", varry = " << varry << std::endl;

/*
#10 - Advanced features - Expalin the concept of templates in C++ and how they support generic programming.
Include a simple example of a template function

Template allows a block of code (function or class) to take different data types as arguments.
Improves reusability of code
See example template mult function in the header
*/

std::cout << "mult(int,int): " << mult(5, 7) << "; mult(double,double): " << mult(5.23, 7.36) << std::endl;

    return 0;
}
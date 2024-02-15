#include <iostream>
#include <string>

int main()
{
/*Task1
Напишете програма на С++, която:
Използва въведени от потребител цели числа
Проверява дали числото е четно или нечетно
Ако числото е четно, на екрана се извежда “even”, ако е нечетно – “odd”
*/
	// int number;
	// std::cout << "Enter a number:";
	// std::cin >> number;
	// std::cout<<"The number "<< number <<" is " << ((number%2==0)?"Even":"Odd") << std::endl;

	int number[3];
	std::cout << "Enter 3 positive integers :";
	std::cin >> number[0] >> number[1] >> number[2];
	for (int i = 0; i < 3; i++){
	std::cout<<"The number "<< number[i] <<" is " << ((number[i]%2==0)?"Even":"Odd") << std::endl;
	}
	// End of Task1
	return 0;
}
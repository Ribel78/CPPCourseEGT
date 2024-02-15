#include <iostream>
//#include <cstring>
#include <string>
using namespace std;

// bool operator<(string a, string b){
// 	return (a.length() < b.length());
// }
int main()
{
	
	int a=8, b=8, c=8, d=8;
	cout << "a++ = " << a++ << endl;
	cout << "++b = " << ++b << endl;
	cout << "c-- = " << c-- << endl;
	cout << "--d = " << --d << endl;

	string str1 = "A";
	string str2 = "AG";
	str1.append("Hello");
	str1.append(5, 'H');
	str1.append("NUMBEROFCHARS",6);
	str1.append(2, ' ');
	str1.append("NUMBEROFCHARS",8, 4);
	cout << str1 << endl;
	cout << (str1 < str2) << endl;
	return 0;
}
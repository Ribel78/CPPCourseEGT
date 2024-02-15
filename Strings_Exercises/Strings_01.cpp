#include<iostream>
#include<string>
using namespace std;

int main ()
{
    string s = "Hello, C++";
    int length = s.length();
    int idx = 5;
    char letter = s.at(idx); // equivalent to s[idx] (string is array)
    cout << length << endl;
    cout << "Letter at position: "<< idx <<" is :" << letter << endl;
    for (int i=0; i<length; i++ ){
        cout << "s[" << i << "] = " << s.at(i) << endl;
    }

    string ss;
    cout << "Enter long, spaced string: ";
    // cin >> ss; cout << ss << endl; // reads to first space
    getline( cin, ss);
    cout << ss << endl;

    //concatenation
    string s3 = s+ " and " +ss;
    cout << s3 << endl;    

    //comparison ; dictionary lookup behaviour
    string a = "Asen";
    string b = "Asenov";
    cout << boolalpha; //return true/false instead of 1/0
    cout << "Asen == Asenov : " << (a == b) << endl;
    cout << "Asen > Asenov : " << (a > b) << endl;
    cout << "Asen < Asenov : " << (a < b) << endl;
    cout << "Asenov.compare(Asen) : " << b.compare(a) << endl; // similar to above but returns integers (negative, 0(equal), positive)

    // append
    string full = a.append(" "); //append space " " to Asen
    full = a.append(b); // append "Asenov" to "Asen " - faster than string concatenation
    cout << full << endl;

    // search, match, replace
    // find character from a string
    string repl = "bibaraban";
    int idx2 = repl.find_first_of("ba");
    cout << idx2 << endl;
    idx2 = repl.find_first_of("ba", 3);
    cout << idx2 << endl;

    //find substring

    idx2 = repl.find("ba");
    cout << idx2 << endl;
    idx2 = repl.find("ba", 3);
    cout << idx2 << endl;

    // replace
    cout << repl.replace(repl.find("ban"),6,"bibara") << endl;

    string courseName = "C++ $ Programming $ Course $";
    idx = courseName.find("$");
    while (idx != string::npos) //string::npos if index can't be found
    {
        courseName.replace(idx, 1, "@");
        idx = courseName.find("$");
    }
    
    cout << courseName << endl;
    return 0;
    /*

    Напишете функции за
    * Четене на стринг въведен от клавиатурата, който се изписва отзад-напред
    * Преброяване на броя на гласните в дълго изречение и изписване на резултата 
    * Намиране на максималното от 3 числа.
    *  check Strings_02.cpp
    */
}
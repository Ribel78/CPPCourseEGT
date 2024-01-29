#include <iostream>
#include <string>
//using namespace std;
using std::cout;
using std::cin;
using std::string;
using std::endl;
// Четене на стринг въведен от клавиатурата, който се изписва отзад-напред
void reverseString();
// Преброяване на броя на гласните в дълго изречение и изписване на резултата
void vowelCount(string setence);
// Намиране на максималното от 3 числа.
float maxOfThree(float a, float b, float c);

int main()
{
    reverseString();
    string longSentence ="“Never follow anyone else’s path. Unless you’re in the woods and you’re lost and you see a path. Then by all means follow that path.";
    vowelCount(longSentence);
    cout << "Max number is: " << maxOfThree(23.678, 44.56, 44.56) << endl;
    return 0;
}

void reverseString(){ // reverse a string
    string str, strReverse, ch; // declare 3 string variables
    cout << "Enter string to reverse: ";
    getline(cin, str); // get multi-space string to reverse
    int len = str.length(); // get the string length
    
    for (int i = len-1; i>=0; i--){ //iterate backwards from str length to 0
        strReverse.append(ch.assign(str,i,1)); // converts char to a string and append to strReverse
    }
    cout << strReverse << endl; //print the reversed string
}

void vowelCount(string sentence){ // count the number of vowels
    char vowels[5] = {'a','i','u','e','o'}; // vowels array
    int vCount[5] = {0}; // init vowels count
    for (int i = 0; i < sentence.length(); i++){
        for (int j = 0; j < 5 ; j++){
            if (sentence.at(i) == tolower(vowels[j])){ //set capital chars to lower case
                vCount[j] += 1; // if match add 1 to vowel counter and breac this loop
                break;
            }
        }
    }
    // print out results
    cout << "Sentence: " << sentence << endl;
    cout << "Vowels count: " << endl;
    for (int j = 0; j < 5; j++){
        cout << vowels[j] << " : " << vCount[j] << endl;
    }
    
}

float maxOfThree(float a, float b, float c){ // find maximum of 3 numbers
    float max;
    if (a >= b){
        max = a;
    } else if(c >= b){
        max = c;
    } else{
        max = b;
    }
    return max;
}
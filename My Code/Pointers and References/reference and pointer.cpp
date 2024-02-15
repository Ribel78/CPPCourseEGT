#include <iostream>
using namespace std;
 
int main(){
    cout << "Testing references and pointers\n\n";

    float value_added_tax;
    float some_variable = 9000;

    cout << "Enter value for value_added_tax: ";
    cin >> value_added_tax;
    //declaring reference to variable
    float &vat = value_added_tax; // reference (alias) to value_added_tax, takes no memory
    // Nope! float &bs = 3.5;
    // Nope! float &bs;
    // float &vat = some_variable; // Nope! redeclaration of 'float& vat' not allowed
    // by the way "type& refName", "type & refName" and "type &refName" are all OK

    //testing
    cout << "value_added_tax = " << value_added_tax << endl;
    cout << "reference variable vat = " << vat << endl;
    vat+=1;
    cout << "After (vat+=1) vat = "<< vat;
    cout << "; value_added_tax = " << value_added_tax << endl;
    value_added_tax+=1;
    cout << "After (value_added_tax+=1) value_added_tax = " << value_added_tax;
    cout << "; vat = " << vat << endl;
    // both variable and reference point at the same value

    //declaring pointer
    float *arrow = &value_added_tax; // "*arrow" only on decalration, then use as "arrow" to get or assign new address or "*arrow" to get the value 
    cout << "Pointing at address of value_added_tax = " << arrow << endl;
    cout << "The value at the address of value_added_tax =  = " << *arrow << endl;
    arrow = &vat; //lets see the reference (vat) address and value
    cout << "Pointing at address of vat = " << arrow << endl;
    cout << "The value at the address of vat = " << *arrow << endl;
    cout << "NOTE! The same address and value for value_added_tax and its reference vat" << endl << endl;

    arrow = &some_variable; //same pointer taking new address of different variable. References can't do that
    cout << "Pointing at address of some_variable = " << arrow << endl; // notice different address and value
    cout << "The value at the address of some_variable = " << *arrow << endl;  
    cout << "NOTE! Different address for some_variable" << endl << endl;

    *arrow = 9001; //change the value at the address
    cout << "Changing the value at the address of some_variable to " << *arrow << endl;
    cout << "The value of some_variable = " << some_variable << endl;

    return 0;
}
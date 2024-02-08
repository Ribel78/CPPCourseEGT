/*
XML_Parser - using pugixml library:
https://pugixml.org/

*/
#include "Employee.h"
#include "Utilities.h"

int main(){

    // Task 1 - create a function that imports XML data and puts it in vector of Employee objects
    // function extract_XML_Employees in Utilities.h - XML file - employees.xml

    vector<Employee> employeesXML = extract_XML_Employees("employees.xml");
    cout << "Task1 - Simple employee list:"<< endl;
    cout << "List size: " << employeesXML.size() << endl;    
    printXML2Employee(employeesXML);

    cout << endl << endl;


    // Task 2 - create another function that imports more complex XML data and puts it in vector of Employee objects    
    // function extract_XML_Employees2 in Utilities.h - XML file - employees-advanced.xml

    vector<Employee2> employeesXML2 = extract_XML_Employees2("employees-advanced.xml");
    cout << "Task2 - Advanced employee list:"<< endl;
    cout << "List size: " << employeesXML2.size() << endl;    
    printXML2Employee2(employeesXML2);

    cout << endl << endl;
    // Example of function overloading
    cout << endl << endl;
    cout << "Example of function overloading\n";
    cout << endl << endl;
    
    cout << "Task1\n";
    printX(employeesXML);
    cout << "Task2\n";
    printX(employeesXML2);

    // Original example demonstrating XML file loading and parsing
    // xml_document doc;
    // if (!doc.load_file("employees.xml")) {
    //     cout << "Error\n";
    //     return -1;
    // }
    // xml_node empls = doc.child("EmployeesData").child("Employees");
    // for (xml_node_iterator it = empls.begin(); it !=empls.end(); ++it){
    //     cout << "Employee: ";
    //     for (xml_attribute_iterator ait = it->attributes_begin(); ait!= it->attributes_end(); ++ait){
    //         cout << " " << ait->name() << " = " << ait->value() << endl;
    //     }
    //     cout << endl;
    // }
    
    return 0;
}
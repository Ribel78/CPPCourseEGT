#include "Department.h"
int Department::numEmployees = 0;
Department::Department(string name, Employee* employees){
    setDepartmentName(name);
    this->employees = employees;
}

void Department::setDepartmentName(string name){
    this->departmentName = name;
}
string Department::getDepartmentName(){
    return this->departmentName;
}
void Department::addEmployee(Employee employee){
    Employee *ptr;
    ptr = employees + numEmployees;
    *ptr = employee;
    numEmployees += 1; //keep track of added employees
}
void Department::diplayEmployees(){
    Employee* ptr = employees;
    cout << "Employee data: \n";
    for (int i = 0; i < numEmployees; ++i){ //no need to loop through all 100 elements
        (ptr+i)->display(); //pointer arithmetic to get the modified elements in the list
    }
    cout << "Total number of employees: " << numEmployees << endl;
    cout << "--- end of record ---- \n";
}
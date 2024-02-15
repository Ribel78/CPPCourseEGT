#include "Employee.h"
#include "Department.h"

int main(){
    //create Employee objects
    Employee employee1("Name 1", "Empl ID 1", "Empl Position 1");
    Employee employee2("Name 2", "Empl ID 2", "Empl Position 2");
    Employee employee3("Name 3", "Empl ID 3", "Empl Position 3");
    Employee employee4("Name 4", "Empl ID 4", "Empl Position 4");
    Employee employee5("Name 5", "Empl ID 5", "Empl Position 5");

    //create an Employee array with fixed length
    Employee employees_array[100];

    //Initialize a department object with a name and pointer to the Employee array
    Department dpt("The Department", employees_array);
    //initially display 0 employees
    dpt.diplayEmployees();

    cout << "Adding employees to " << dpt.getDepartmentName() << endl;
    dpt.addEmployee(employee1);
    dpt.diplayEmployees();

    //Add the remaoning employees;
    dpt.addEmployee(employee2);
    dpt.addEmployee(employee3);
    dpt.addEmployee(employee4);
    dpt.addEmployee(employee5);
    dpt.diplayEmployees();

    return 0;
}
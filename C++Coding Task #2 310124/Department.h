#ifndef Department_H
#define Department_H
#include "Employee.h"

class Department{
public:
    Department(string, Employee*);
    void setDepartmentName(string);
    string getDepartmentName();
    void addEmployee(Employee);
    void diplayEmployees();
private:
    string departmentName;
    Employee* employees; //pointer to an array of employee objects (not vector?!)
    static int numEmployees;
};

#endif //Department_H
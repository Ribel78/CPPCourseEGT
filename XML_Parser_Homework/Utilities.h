#pragma once

#include <iostream>
#include <vector>
#include "Employee.h"
#include "pugixml.h"
using namespace std;
using namespace pugi;

//extract data from xml file (template - employees.xml) to Employee vector, takes filename as argumen
vector<Employee> extract_XML_Employees(const char* fileName){
    vector<Employee> employee_list;
    xml_document document;
    bool fileExist = true;
    try{
        if ( !document.load_file( fileName )){
            fileExist = false;
            throw "Error: file not loaded.";
        }        
    } catch(string msg){
        cout << msg << endl;
    }
    if (fileExist){
        xml_node employees = document.child("EmployeesData").child("Employees");
        for(xml_node_iterator it = employees.begin(); it !=employees.end(); ++it){
            string name, type, age;
            for (xml_attribute_iterator ait = it->attributes_begin(); ait != it->attributes_end(); ++ait){
                // string type casting - can't compare attribute name to string directly. Is there a better way?
                if((string)ait->name() == "Name") {
                    name = (string)ait->value();
                    continue;
                    }
                if((string)ait->name() == "Type") {
                    type = (string)ait->value();
                    continue;
                    }
                if((string)ait->name() == "Age") {
                    age = (string)ait->value();
                    continue;
                    }
            }
            Employee employee(name, type, age);
            employee_list.push_back(employee);
        }
    }
    return employee_list;
}

//extract data from xml file (template - employees-advanced.xml)to Employee2 vector, takes filename as argument
vector<Employee2> extract_XML_Employees2(const char* fileName){
    vector<Employee2> employee_list;
    xml_document document;
    bool fileExist = true;
    try{
        if ( !document.load_file( fileName )){
            fileExist = false;
            throw "Error: file not loaded.";
        }        
    } catch(string msg){
        cout << msg << endl;
    }
    if (fileExist){
        xml_node employees = document.child("EmployeesData").child("Employees");
        for(xml_node_iterator it = employees.begin(); it !=employees.end(); ++it){
            string name, type, age, building, floor, desc;
            for (xml_attribute_iterator ait = it->attributes_begin(); ait != it->attributes_end(); ++ait){
                // string type casting - can't compare attribute name to string directly. Is there a better way?
                if((string)ait->name() == "Name") {
                    name = (string)ait->value();
                    continue;
                    }
                if((string)ait->name() == "Type") {
                    type = (string)ait->value();
                    continue;
                    }
                if((string)ait->name() == "Age") {
                    age = (string)ait->value();
                    continue;
                    }
            }
        building = (string)it->first_child().attribute("Building").value();
        floor = (string)it->first_child().attribute("Floor").value();
        desc = (string)it->first_child().attribute("Desc").value();

        Employee2 employee(name, type, age, building, floor, desc);
        employee_list.push_back(employee);
        }
    }
    return employee_list;
}

//prints the data from Employee vector, takes Employee vector as argument
void printXML2Employee(vector<Employee>& employeesXML){
    for (Employee e : employeesXML){
        cout    << "Emplyee name: " << e.getName() 
                << "\tJob type: " << e.getType() 
                << "\tAge: " << e.getAge() << endl;
    }
}

//prints the data from Employee2 vector, takes Employee vector as argument
void printXML2Employee2(vector<Employee2>& employeesXML2){
    for (Employee2 e : employeesXML2){
        cout    << "Emplyee name: " << e.getName() 
                << "\tJob type: " << e.getType() 
                << "\tAge: " << e.getAge() 
                << "\t Building: " << e.workLocation().getBuilding()
                << "\t Floor: " << e.workLocation().getFloor()
                << "\t Desc: " << e.workLocation().getDesc()
                << endl;

    }
}

void printX(vector<Employee>& employeesXML){
    for (Employee e : employeesXML){
        cout    << "Emplyee name: " << e.getName() 
                << "\tJob type: " << e.getType() 
                << "\tAge: " << e.getAge() << endl;
    }
}

void printX(vector<Employee2>& employeesXML2){
    for (Employee2 e : employeesXML2){
        cout    << "Emplyee name: " << e.getName() 
                << "\tJob type: " << e.getType() 
                << "\tAge: " << e.getAge() 
                << "\t Building: " << e.workLocation().getBuilding()
                << "\t Floor: " << e.workLocation().getFloor()
                << "\t Desc: " << e.workLocation().getDesc()
                << endl;
    }
}
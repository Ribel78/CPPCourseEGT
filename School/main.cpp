#include <iostream>
#include<vector>
#include "Teacher.h"
#include "Discipline.h"
#include "Student.h"
#include "Class.h"

int main(){
// set variables of class Discipline
    Discipline history("History", 60, 5);
    Discipline math("Mathematics", 90, 6);
    Discipline geo("Geography", 45, 3);

// set variables of class Teacher
    Teacher teacher1("Ivan Ivanov", "Prof.", history);
    Teacher teacher2("Boyan Boyanov", "Mr.", math);
    Teacher teacher3("Celine Dion", "Ms.", geo);
    Teacher teacher4("Kiril Kirilov", "Dr.", history);
    Teacher teacher5("Vasil Vasilev", "Mr.", math);
    Teacher teacher6("Liliana Lilova", "Mrs.", geo);    

// two vector sets of teachers
    vector<Teacher> t1 = {teacher1,teacher5,teacher3};
    vector<Teacher> t2 = {teacher4,teacher2,teacher6};

// two variables of class Class
    Class classA ('A', t1);
    Class classB ('B', t2);

// set variables of class Student
    Student student1("Ivan Petrov", "IP2024", classA);
    Student student2("Maria Ivanova", "MI2024", classA);
    Student student3("Vanya Marieva", "VM2024", classA);
    Student student4("Petar Ivanov", "PI2024", classB);
    Student student5("Ivanka Marinova", "IM2024", classB);
    Student student6("Mariq Vancheva", "MV2024", classB);
    
    vector<Student> s = {student1, student2, student3,student4, student5, student6};

// Print disciplines data
    cout << "Disciplines: " << endl;
    history.getData();
    math.getData();
    geo.getData();
    cout << endl;

// get teachers in each class
    classA.getTeachers();
    cout << endl;
    classB.getTeachers();

// print students' names

    for (Student student : s){
        cout<< student.getName() << endl;
    }

// print students' data
    for (Student student : s){
        student.getData();
    }

    return 0;
}
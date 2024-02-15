#ifndef _Student_H_
#define _Student_H_

#include <string>
#include "Class.h"

using namespace std;

class Student{

public:
    Student(string, string, Class &);
    void getData();
    string getName();
    
private:
    string name;
    string studentID;
    Class classObj;

};

#endif //_Student_H_
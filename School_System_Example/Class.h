#ifndef _Class_H_
#define _Class_H_

#include "Teacher.h"
#include <vector>

using namespace std;

class Class{
public:    
    Class(char, vector<Teacher>&);
    char getClassID();
    void getTeachers();

private:
    char classID;
    vector<Teacher> teachers;
};

#endif //_Class_H_
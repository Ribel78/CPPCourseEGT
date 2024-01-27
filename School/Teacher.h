#ifndef _Teacher_H_
#define _Teacher_H_

#include <string>
#include "Discipline.h"

using namespace std;

class Teacher{
public:
    Teacher(string, string, Discipline&);
    void getData();

private:
    string name;
    string title;
    Discipline discipline;
};

#endif //_Teacher_H_
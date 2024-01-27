#ifndef _Discipline_H_
#define _Discipline_H_

#include <string>
using namespace std;

class Discipline{
public:
    Discipline(string, int, int);
    void getData();

private:
    string name;
    int lecturesCount;
    int exercisesCount;
};

#endif //_Discipline_H_

#ifndef _Shape_2D_
#define _Shape_2D_

#include "Shape.h"
#include<iostream>

using namespace std;

class Shape_2D : public Shape{
public:
    Shape_2D(double, double, char, string);
    void setName(string);
    string getName();
    void print() const;
    string getID();

private:
    double position;
    double size;
    char fill;
    string name;
    const string id = "Shape_2D";
};

#endif
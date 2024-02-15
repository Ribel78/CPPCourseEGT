#ifndef _Shape_H_
#define _Shape_H_
#include<iostream>
using namespace std;

//base class
class Shape{

public:
    Shape(double, double, char);
    void draw(double pos, double s, char col);
    virtual void print() const;
    virtual string getID();

private:
    double position;
    double size;
    char fill;
    const string id = "Shape";
};

#endif
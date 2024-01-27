
#ifndef _Square_H_
#define _Square_H_

#include "Square.h"
#include "Shape_2D.h"
#include<iostream>
using namespace std;

class Square : public Shape_2D{
public:
    Square(double, double, char, string);
    void print() const;
    void areaInfo() const;
    string getID();

private:
    double position;
    double size;
    char fill;
    string name;
    const string id = "Square";
};

#endif
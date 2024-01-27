#ifndef _Shape_2D_H_
#define _Shape_2D_H_

#include <iostream>
#include "Shape.h"

//declare class
class Shape_2D : public Shape {
public:
    Shape_2D(int);
    virtual void print();
    virtual double getArea();
    
private:
    double radius; // Circle
    double side; //Square, Triangle
    double height; // Triangle
};

#endif //_Shape_2D_H_
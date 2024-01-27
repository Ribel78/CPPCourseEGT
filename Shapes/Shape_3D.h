#ifndef _Shape_3D_H_
#define _Shape_3D_H_

#include <iostream>
#include "Shape.h"

//declare class
class Shape_3D : public Shape {
public:
    Shape_3D(int);
    virtual void print();
    virtual double getArea();
    double getVolume();
    void setH(double);
    double getH();
    
private:
    double height; // Triangle
};

#endif //_Shape_3D_H_
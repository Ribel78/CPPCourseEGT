#ifndef _Square_H_
#define _Square_H_

#include <iostream>
//#include "Shape.h"
#include "Shape_2D.h"

//declare class
class Square : public Shape_2D{
public:
    Square(int);
    virtual void print();
    virtual double getArea();
    
private:
    double radius; // Circle
    double side; //Square, Triangle
    double height; // Triangle
};

#endif //_Square_H_
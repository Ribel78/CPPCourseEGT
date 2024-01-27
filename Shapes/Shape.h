#ifndef _SHAPE_H_
#define _SHAPE_H_

#include <iostream>
//declare class
class Shape{
public:
    Shape(int);
    virtual void print();
    virtual double getArea();
    void setMember();
    int getMember();
    
private:
    int member;
};

#endif //_SHAPE_H_
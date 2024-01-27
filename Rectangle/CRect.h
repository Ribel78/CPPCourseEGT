#ifndef _CRECT_H_
#define _CRECT_H_

#include <iostream>
#include <vector>

#include "Point.h"
//declare class
class CRect{
public:
    CRect(Point&, Point&, Point&, Point&);
    CRect(double [2], double [2], double [2], double [2]); // does not work!!!
    void setPoint(char, double, double);
    void printPoints();
    void validate();
    bool isSquare();
    double length();
    double width();
    double perimeter();
    double area();

private:
    Point A;
    Point B;
    Point C;
    Point D;
    bool isValidRectangle = false;
    double hSide;
    double vSide;

};
#endif //_CRECT_H_
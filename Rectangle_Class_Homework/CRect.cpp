//include header file(s)
#include "CRect.h"
#include "Point.h"
#include<vector>

//#include <XXX> //include nescessary libraries

//define class constructors and functions

CRect::CRect(Point& a, Point& b, Point& c, Point& d)
:A(a), B(b), C(c), D(d) {
    validate();
}
CRect::CRect(double a[2], double b[2], double c[2], double d[2])
{
    this->A.co[0] = a[0]; this->A.co[1] = a[1];
    this->B.co[0] = b[0]; this->B.co[1] = b[1];
    this->C.co[0] = c[0]; this->C.co[1] = c[1];
    this->D.co[0] = d[0]; this->D.co[1] = d[1];
}

void CRect::setPoint(char ptID, double x, double y){
    switch (ptID)
    {
    case 'A':
        this->A.co[0] = x; this->B.co[1] = y; 
        break;
    case 'B':
        this->B.co[0] = x; this->B.co[1] = y; 
        break;
    case 'C':
        this->C.co[0] = x; this->C.co[1] = y; 
        break;
    case 'D':
        this->D.co[0] = x; this->D.co[1] = y; 
        break;              
    default:
        std::cout << "Error" << std::endl;
        break;
    }
}

void CRect::printPoints(){
    std::cout
    << "A - x:" << this->A.co[0] << " y:" << this->A.co[1] << "\n"
    << "B - x:" << this->B.co[0] << " y:" << this->B.co[1] << "\n"
    << "C - x:" << this->C.co[0] << " y:" << this->C.co[1] << "\n"
    << "D - x:" << this->D.co[0] << " y:" << this->D.co[1] << "\n"
    << std::endl;
}

void CRect::validate(){
    std::vector<Point> points;
    points.push_back(this->A);
    points.push_back(this->B);
    points.push_back(this->C);
    points.push_back(this->D);
    if (this->A.co[1] == this->B.co[1] && this->C.co[1] == this->D.co[1] && this->A.co[0] == this->D.co[0] && this->B.co[0] == this->C.co[0]){
        isValidRectangle = true;
        std::cout << "Shape is rectangle\n";
        this->hSide = this->B.co[0] - this->A.co[0];
        this->vSide = this->D.co[1] - this->A.co[1];
    }    
    for (Point point : points){
        if (point.co[0] < 0 || point.co[1] < 0 || point.co[0] > 20 || point.co[1] > 20 ){
            this->isValidRectangle = false;
            std::cout << "Shape is out of range\n";
            break;
        }
    }
}

bool CRect::isSquare(){
    if(isValidRectangle && (this->B.co[0]-this->A.co[0]) == this->D.co[1]- this->A.co[1]){
        std::cout << "Shape is square\n";
        return true;
    }else{
        std::cout << "Shape is not square\n";
        return false;
    }
}

double CRect::length(){
    if (isValidRectangle){
        return (this->hSide >= this->vSide) ? this->hSide:this->vSide;
    } else{
        std::cout << "Not a rectangle\n";
        return 0;
    }
}
double CRect::width(){
    if (isValidRectangle){
        return this->hSide;
    } else {
        std::cout << "Not a rectangle\n";
        return 0;
    }
    
}
double CRect::perimeter(){
    if (isValidRectangle){
        return (2*hSide + 2*vSide);
    } else {
        std::cout << "Not a rectangle\n";
        return 0;
    }
    
}
double CRect::area(){
    if (isValidRectangle){
        return hSide*vSide;
    } else {
        std::cout << "Not a rectangle\n";
        return 0;
    }
    
}
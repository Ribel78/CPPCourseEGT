//include header file(s)
#include <iostream>
#include "Shape_3D.h"

Shape_3D::Shape_3D(int m) : Shape(m){}

void Shape_3D::print(){
    std::cout << "3D Shape Info\n";
}

double Shape_3D::getArea(){
    std::cout << "3D Shape Area\n";
    return 0.0;
}
double Shape_3D::getVolume(){
    std::cout << "3D Shape volume calculation";
    return 0;
}

void Shape_3D::setH(double m){
    this->height = m;
}
double Shape_3D::getH(){
    return this->height;
}
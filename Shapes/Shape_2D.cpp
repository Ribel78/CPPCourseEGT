//include header file(s)
#include <iostream>
#include "Shape_2D.h"

Shape_2D::Shape_2D(int m) : Shape(m){}

void Shape_2D::print(){
    std::cout << "2D Shape Info\n";
}

double Shape_2D::getArea(){
    std::cout << "2D Shape Area\n";
    return 0.0;
}

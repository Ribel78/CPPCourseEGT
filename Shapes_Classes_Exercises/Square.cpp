//include header file(s)
#include <iostream>
#include "Square.h"
#include "Shape_2D.h"

Square::Square(int m) : Shape_2D(m){}

void Square::print(){
    std::cout << "2D Shape Info\n";
}

double Square::getArea(){
    std::cout << "2D Shape Area\n";
    return 0.0;
}

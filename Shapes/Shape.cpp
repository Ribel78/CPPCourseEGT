//include header file(s)
#include <iostream>
#include "Shape.h"

Shape::Shape(int m){
    this->member = m;
}

void Shape::print(){
    std::cout << "Shape Class Info";
}

double Shape::getArea(){
    std::cout << "return some area function\n" ;
    return 0;
}

void Shape::setMember(){

}
int Shape::getMember(){
    return this->member;
}
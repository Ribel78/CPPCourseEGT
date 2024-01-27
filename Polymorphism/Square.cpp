#include "Square.h"
#include "Shape_2D.h"

Square::Square(double pos, double s, char fill, string name): Shape_2D(pos, s, fill, name){}

void Square::print() const{
    cout << "This is Square\n";
}

void Square::areaInfo() const{
    cout << "The area of a square is (a^2)*size \n";
}
string Square::getID(){
    return this->id;
}
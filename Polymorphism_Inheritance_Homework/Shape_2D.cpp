#include "Shape.h"
#include "Shape_2D.h"
using namespace std;

Shape_2D::Shape_2D(double pos, double s, char fill, string name): Shape(pos, s, fill){
}

void Shape_2D::print() const{
    cout << "This is 2D shape\n";
}

void Shape_2D::setName(string name){
    this->name = name;
}

string Shape_2D::getName(){
    return this->name;
}
string Shape_2D::getID(){
    return this->id;
}
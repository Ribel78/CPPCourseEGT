//include header file(s)
#include "Point.h"

//define class constructors and functions

Point::Point(){
    this->co[0]= 0.0;
    this->co[1]= 0.0;
}
Point::Point(double x, double y){
    this->co[0] =x;
    this->co[1] = y;
}
Point::Point(double coords[2]){ //use array as parameter
    this->co[0] = coords[0];
    this->co[1] = coords[1];
}
#include <iostream>
#include "Point.h"
#include "CRect.h"


// using std::cout;
// using std::endl;

int main(){

    Point a(5, 2);
    Point b(15,2);
    Point c(15,10);
    Point d(5, 300);  

    CRect rect(a,b,c,d);
    rect.printPoints();
    rect.setPoint('D', 5, 10);
    rect.printPoints();
    rect.validate();
    std::cout << rect.isSquare() << std::endl;
    std::cout << "Longest side length: "<< rect.length() << std::endl;
    std::cout << "Width length: "<< rect.width() << std::endl;
    std::cout << "Perimeter: "<< rect.perimeter() << std::endl;
    std::cout << "Area: "<< rect.area() << std::endl;

    Point aPt({3,5}); // works
    std::cout << "Point init Attribute as arry \n";
    std::cout << aPt.co[0] << std::endl;
    std::cout << aPt.co[1] << std::endl;
    //CRect a_rect({1,3},{10,3},{10,17},{1,17}); // does not work
    return 0;
}
//Inheritance Demo
#include "Shape.h"
#include "Shape_2D.h"
#include "Shape_3D.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;

int main(){

    Shape *sPtr1 = new Shape_2D(30);
    Shape *sPtr2 = new Shape_3D(10);

   std::vector<Shape *> myShapes;
   myShapes.push_back(sPtr1);
   myShapes.push_back(sPtr2);
 
    for (int i=0; i<myShapes.size(); i++){
        myShapes.at(i)->print();
    }
    
    return 0;
}
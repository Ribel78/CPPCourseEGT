#include<iostream>
#include<vector>
#include "Shape.h"
#include "Shape_2D.h"
#include "Square.h"

using namespace std;

int main(){

    Shape s(12,5,'F');
    s.print();
    Shape_2D s2D(34,1,'N',"square");
    s2D.print();
    Square sq(23,4,'F',"sqr");
    sq.print();
    sq.areaInfo();

    Square* sq_ptr = &sq;
    sq_ptr->print();
    sq_ptr->areaInfo();

    vector<Shape*> shapes;
    shapes.push_back(&s);
    shapes.push_back(&s2D);
    shapes.push_back(&sq);

    for (Shape* s : shapes){
        s->print();
        cout <<"ID: " << s->getID() << endl;
        // if (s->getID()!="Shape" && s->getID()!="Shape_2D"){
        //     s->areaInfo();
        // }
    }

    return 0;
}

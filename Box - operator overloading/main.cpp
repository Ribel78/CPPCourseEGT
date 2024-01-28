
/*
- Да се реализира клас Box (кутия) с 3 полета за ширина, дължина и височина, конструктор и сет/гет методи. Да се предефинират оператори които биха позволили следния запис да работи:
box3 = box1 + box2;
където box1, box2, box3 са обекти от Box. Box3 се получава когато сложим двете кутии една над друга.
*/
#include <iostream>
using namespace std;

class Box{
    int width = 0;
    int depth = 0;
    int height = 0;
public:
    Box(int w, int d, int h):width(w), depth(d), height(h){};
    int getWidth(){return width;};
    int getDepth(){return depth;};
    int getHeight(){return height;};
    Box &operator+(Box& box){
        this->width = (this->width > box.width) ? this->width : box.width;
        this->depth = (this->depth > box.depth)? this->depth : box.depth;
        this->height += box.height;
        return *this;
    }
    friend ostream &operator<<(ostream& out, Box& b){
        out << "Box parameters - width:" << b.width << ", depth: " << b.depth << ", height:" << b.height << endl;
        return out;
    };
};

int main(){
    Box Box1(6, 15, 60);
    cout << Box1;
    Box Box2(8, 12, 15);
    cout << Box2;

    Box Box3 = Box1 + Box2;
    cout << Box3;

    return 0;
}
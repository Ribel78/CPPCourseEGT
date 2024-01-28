
/*
Create Class Box with 3 fields for width, depth and height, a constructor, and set/get methods
Define operator overloading which allow the following experession to work
box3 = box1 + box2;
where box1, box2, box3 are Box objects. 
Box3 is derived as if we put two boxes on top of each other.
Add operator overloads for >, < == (for volume comparison), 
<< to print class data, >> to set new class parameters.
*/
#include <iostream>
using namespace std;

class Box{
    int width = 0;
    int depth = 0;
    int height = 0;
    // overloaded stream output operator
    friend ostream &operator<<(ostream& output, Box& b){
        output << "Box parameters - width:" << b.width << ", depth: " << b.depth << ", height:" << b.height << endl;
        return output;
    }
    // overloaded stream input operator
    friend istream &operator>>(istream& input, Box& b){
        input >> b.width >> b.depth >> b.height;
        return input;
    }
public:
    Box(){};
    Box(double w, double d, double h):width(w), depth(d), height(h){};
    double getWidth(){return width;};
    double getDepth(){return depth;};
    double getHeight(){return height;};
    double getVolume() const {return width*depth*height;}
    // overloaded addition operator (adds heights and picks max widht or depth)
    Box &operator+(Box& box){
        this->width = (this->width > box.width) ? this->width : box.width;
        this->depth = (this->depth > box.depth)? this->depth : box.depth;
        this->height += box.height;
        return *this;
    }
 
};

// overloaded comparison operators based on objkect's volume defined outside of class
bool operator>(const Box& box1, const Box& box2){
    return box1.getVolume() > box2.getVolume();
}
bool operator<(const Box& box1, const Box& box2){
    return box1.getVolume() < box2.getVolume();
}
bool operator==(const Box& box1, const Box& box2){
    return box1.getVolume() == box2.getVolume();
}


int main(){
    Box Box1(6, 15, 60);
    cout << Box1;
    Box Box2(8, 12, 15);
    cout << Box2;

    Box Box3 = Box1 + Box2;
    cout << Box3;

    cout << boolalpha;
    cout << (Box1 < Box2) << endl;
    cout << (Box1 > Box2) << endl;

    Box Box4;
    cin >> Box4; // try 40 9 25 for equality comparison (true)
    cout << (Box3 == Box4) << endl;

    return 0;
}
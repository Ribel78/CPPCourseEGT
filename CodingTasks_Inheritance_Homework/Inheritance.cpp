#include <iostream>
#include <string>

//class declaration block
class Shape{
public: //public members and class constructor(s)
    //constructor with member initialization list
    Shape(std::string _color):color(_color){}

    void draw(){
        std::cout << "The color of Shape is: " << color << std::endl;
    }
protected: //protected members are accesible by derived classes
    std::string color;

};
class Circle : public Shape{
    public:
    Circle(std::string _color):Shape(_color){}
    //function overriding - same name different output
    void draw(){
        std::cout << "The Circle has " << color << " color."<< std::endl;
    }        
};
class Rectangle : public Shape{
    public:
    Rectangle(std::string _color):Shape(_color){}
    //function overriding - same name different output
    void draw(){
        std::cout << color << " the Rectangle is." << std::endl;
    }        
};
int main(){

    //class object declarattions
    Shape shape("Purple");
    shape.draw(); //prints out the declared color but with custom message
    
    Circle circle("Violet");
    circle.draw(); //...
    
    Rectangle rectangle("Electric");
    rectangle.draw();//... 

    return 0;
}
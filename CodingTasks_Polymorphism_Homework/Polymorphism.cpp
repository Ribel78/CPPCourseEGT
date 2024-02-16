#include <iostream>
#include <string>

//class declaration block
class Shape{
public: //public members and class constructor(s)
    //constructor with member initialization list
    Shape(std::string _color):color(_color){}

    /*
    virtual keyword allows polymorphism and correct choice
    when calling the derived classes overriden functions
    if derived class objects are created as pointers the
    Destructor must also be virtual
    */
    virtual ~Shape(){
        std::cout << "The object is destroyed." << std::endl;
    }
    void draw(){
        std::cout << "The color of Shape is: " << color << std::endl;
    }
    virtual double area(){
        std::cout <<"The Shape has undefined area. Returning 0.\n" << std::endl;
        return 0;
        }

protected: //protected members are accesible by derived classes
    std::string color;

};
class Circle : public Shape{
    public:
    //constructor with member initialization list
    Circle(std::string _color, double _r):Shape(_color), radius(_r){}
    //function overriding - same name different output
    void draw(){
        std::cout << "The Circle has " << color << " color."<< std::endl;
    }
    double area(){
        return radius*3.14;
    }
private:

    double radius;

};
class Rectangle : public Shape{
    public:
    //constructor with member initialization list
    Rectangle(std::string _color, double _w, double _h)
    :Shape(_color), width(_w), height(_h) {}
    //function overriding - same name different output
    void draw(){
        std::cout << color << " the Rectangle is." << std::endl;
    }
    double area(){
        return width*height;
    }
    private:

    double width;
    double height;    
};
/*
external function to acces the Shape objects and its derived classes via pointers
the object is accesed using a pointer to it's location
this way drived classes can also be declared as base class pointers
*/
void printArea(Shape* obj){
    std::cout << "The area of the object is:" << obj->area() << std::endl;
}

int main(){

    //class object declarattions
    Shape shape("Purple");
    shape.draw(); //prints out the declared color but with custom message
    shape.area();

    Circle circle("Violet", 100.0);
    circle.draw(); //...
    //calling it's own overriden area() function
    std::cout << "The object \"circle\" has area of: "<< circle.area() << "\n" << std::endl;
    
    Rectangle rectangle("Electric", 25.60, 38.19);
    rectangle.draw();//... 
    //calling it's own overriden area() function
    std::cout << "The object \"rectangle\" has area of: "<< rectangle.area() << "\n" << std::endl;

    //Use
    std::cout << "Taking object as address attribute and calling the respective area() function\n" << std::endl;
    printArea(&shape); // the attribute is the address to the object
    printArea(&circle); //...
    printArea(&rectangle);//...

    std::cout << "\nCreate a Circle object using -new directly as a as pointer - Circle* " << std::endl;
    
    Circle* newCircle = new Circle("Rose", 56.23); //init a derived class as pointer  
    newCircle->draw(); //calling the (pointer) object method via the -> operator  
    printArea(newCircle);

 std::cout << "\nThe Circle* is destroyed with -delete \n" << std::endl;   
    //pointers created in -new must be deleted with -delete
    delete newCircle;

    std::cout << "Destroying the obects after their life cycle " << std::endl;
    return 0;
}
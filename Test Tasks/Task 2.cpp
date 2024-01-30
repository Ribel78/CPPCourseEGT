#include <iostream>
#include <string>
#include <vector>
/*Task 2
Имплементирайте следната йерархия:
Напишете програма на C++ в която е имплементирана проста йерархия от класове, за да демонстрирате наследяване и полиморфизъм.
Например: Може да създадете базов клас Shape с метод draw(), и класове Circle and Rectangle , които да “override”-нат метода draw().
Използвайте указател (pointer) в примера.
*/
class Shape{
public:
	Shape(){
		setName("Shape");
	}
	void setName(std::string n){name = n;}
	std::string getName(){return name;}
	virtual void draw(){ //virtual keyword required if accessing derived classes from a container of Base class type
		std::cout << "Base class draw: Drawing a " << getName() << std::endl;
	};
private:
	std::string name;
};
class Circle : public Shape{
public:
	Circle(std::string c){
		setName("Circle");
		setColor(c);
	}
	void setColor(std::string c){color = c;}
	void draw(){
		std::cout << "Overriden draw: Drawing a " << color << " " << getName() << std::endl;
	}

private:
	std::string color;
};

class Rectangle : public Shape{
public:
	Rectangle(int w, int h):width(w), height(h){};
	std::string shapeType(){
		return (width == height)? "Square":"Rectangle";
	}
	void draw(){
		std::cout << "Overriden draw: Drawing a " << getName() << " of type " << shapeType() << std::endl;
	}	
private:
	int width;
	int height;
};

int main()
{
//Task 2 - continued
	std::cout << "Task 2 - creating a base Shape class object and executing the draw function" << std::endl;
	Shape s;
	s.draw();

	std::cout << "Creating a derived Circle class object and executing its draw function" << std::endl;
	Circle c("Red");
	c.draw();

	std::cout << "Creating a derived Rectangle class object and executing its draw function" << std::endl;
	Rectangle r(20,20);
	r.draw();

	std::cout << "Creating a pointer to new derived Rectangle class object and executing its draw function" << std::endl;	
	Rectangle* rect = new Rectangle(23,14);
	rect->draw();

	std::cout << "Create a vector of pointers to objects from base and different derived classes" << std::endl;
	std::vector<Shape*> shapes;
	shapes.push_back(&s);
	shapes.push_back(&c);
	shapes.push_back(&r);
	shapes.push_back(rect);

	std::cout << "Executing the objects' draw functions using the pointer elements from the vector\n";
	for (Shape* element : shapes){
		element->draw();
	}

	//End Task 2
	return 0;
}
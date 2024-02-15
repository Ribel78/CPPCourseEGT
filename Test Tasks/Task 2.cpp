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
	~Shape(){
		std::cout << "The object is deleted\n";
	}
	void setName(std::string n){name = n;}
	std::string getName(){return name;}
	virtual void draw(){ //virtual keyword required if accessing derived classes from a container of Base class type
		std::cout << "Base class draw: Drawing a " << getName() << std::endl << std::endl;
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
		std::cout << "Overriden draw: Drawing a " << color << " " << getName() << std::endl << std::endl;
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
		std::cout << "Overriden draw: Drawing a " << getName() << " of type " << shapeType() << std::endl << std::endl;
	}	
private:
	int width;
	int height;
};

int main()
{
	std::cout << "### Task 2 ###\n\n";
	std::cout << "Creating a base Shape class object and executing the draw function\n\n";
	Shape s;
	s.draw();

	std::cout << "Creating a derived Circle class object and executing its draw function\n\n";
	Circle c("Red");
	c.draw();

	std::cout << "Creating a derived Rectangle class object and executing its draw function\n\n";
	Rectangle r(20,20);
	r.draw();

	std::cout << "Creating a pointer to new derived Rectangle class object and executing its draw function\n\n";	
	Rectangle* rect = new Rectangle(23,14);
	rect->draw();

	std::cout << "Create a vector of pointers to objects from base and different derived classes\n\n";
	std::vector<Shape*> shapes;
	shapes.push_back(&s); //address to object as attribute
	shapes.push_back(&c); //...
	shapes.push_back(&r); //...
	shapes.push_back(rect); // this object was created as pointer

	std::cout << "Executing the objects' draw functions using the pointer elements from the vector\n\n";
	for (Shape* element : shapes){
		element->draw();
	}

	/*
	After the object is out of scope (at the end of the program in this case) a
	destructor is called to free up memory.
	Deleting the last object initiated as a pointer (with the new command) requires aditional deletion operation
	Comment out the next line to see the difference in the amount of destroyed objects.
	*/
	delete rect;

	//End Task 2
	return 0;
}
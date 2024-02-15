#include<iostream>
#include<string>
//Polymorphism and Virtual Member Functions
//base class
class Parent{
public:
    Parent(int _x):x(_x){}
    virtual ~Parent(){}; //destructor - see delete cycle in main
    void setX(int _x){ x = _x;}
    int getX() const { return x;}
    virtual void print() const {std::cout << "I am Parent \n";} //bound at compile time
    /*virtual keyword / dynamic binding / descision which print() function to use is at run time
    based on the selected as parameter object, see handleClass() */

private:
    int x;
};

//derived class - Child from Parent
class Child : public Parent{
public:
    Child(int _x, int _y): Parent(_x){ y = _y; }
    virtual ~Child(){}; //destructor - see delete cycle in main
    void setY(int _y) { y = _y;};
    int getY( ) const {return y;}
    void print() const {std::cout << "I am Child \n";}; //redefined function

private:
    int y;
};

class Daughter: public Parent{
public:
    using Parent::Parent; // No idea what it is, a constructor?
    virtual ~Daughter(){}; //destructor - see delete cycle in main
    void print() const {std::cout << "I am a Daughter \n";};
};

void handleClass(const Parent& par){ 
/*use references to utilize dynamic binding, without & defaults back to static binding
even with virtual keyword*/
    std::cout << par.getX() << "\n";
    par.print();
}

int main(){
    Parent p1(8);
    Child c1(2,3);
    //objects treated as their own classes - Child print() redefined - no 'virtual' keyword - static binding
    p1.print();
    c1.print();
    //objects treated as their base class - Child print() overrided - used 'virtual' keyword - dynamic binding
    handleClass(p1);
    handleClass(c1); //permited because of polymorphism Child inherits Parent
    /*removing the 'virtual' keyword prints Parent info*/

    //using pointers
    std::cout << "using pointers\n";
    Parent* par_ptr = &p1;
    par_ptr->print();
    Child* ch_ptr = &c1;
    ch_ptr->print();

    // create an array of base and derived objects pointers
    std::cout << "create an array of base and derived objects pointers\n";

    Parent* relatives[] = {new Parent(3), new Child(5,8), new Daughter(1)};
    //assign 3 memory addresses for the objects (dynamic memory allocation)
    //print info for each object
    for (Parent* rel: relatives){
        rel->print();
    }
    //after completion and using memory allocation, delete the objects
    for (Parent* rel: relatives){
        delete rel;
    }    
    return 0;
}
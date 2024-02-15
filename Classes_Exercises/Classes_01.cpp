// Classes and objects
#include <iostream>
#include <string>

using namespace std;

// class template
class Car
{
public:
    // setter function
    void setModel(string param_model){
        this->model = param_model;
    }

    // getter function
    string getModel(){
        return this->model;
    }
    void displayMessage(){
        cout << "Model: " << model << "; year is: " << year << "; color: " << color << ";" << endl;
    }

private:
    string model;
    int year;
    string color;
    string fuel;
    string vin;
    string transmission;
    string plate;
};

int main(){

    // class instance creation
    Car firstCar;
    string model_name;
    cout << "Enter model name:";
    cin >> model_name;
    firstCar.setModel(model_name);
    firstCar.displayMessage();

    string carModel = firstCar.getModel();
    cout << "The car model is: " << carModel << endl;

    //cout << "Hello world!" << endl;

    return 0;
}
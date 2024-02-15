// Classes and objects
#include <iostream>
#include <string>

using namespace std;

// class definition
class Car
{
public:
    // Constructor
    Car(string model, int year, string color, string fuel, 
        string vin, string transmission, string plate)
    {
        setModel(model);
        setYear(year); //use already made setter if we want to verify the data
        this->color = color;
        this->fuel = fuel;
        this->vin = vin;
        this->transmission = transmission;
        this->plate = plate;
    }

    // Setter functions
    void setModel(string param_model){
        this->model = param_model;
    }
    void setYear(int param_year){
        if(param_year > 1970 && param_year < 2024){
            this->year = param_year;
        } else {
            this->year = 0;
            cout << "Invalid year." << endl;
        }

    }    

    // Getter functions
    string getModel(){
        return this->model;
    }
    int getYear(){
        return this->year;
    }    
    // type getVar(){
    //     return this->var;
    // }   
    void displayMessage(){
        cout << "Model: " << model << "; Year: " << year << "; Color: " << color << "; Fuel: " << fuel << "; VIN: " << vin << "; Transm: " << transmission <<"; Plate: "<< plate<< endl;
    }

private:
    string model;
    int year;
    string color;
    string fuel;
    string vin;
    string transmission;
    string plate;
}; // class definition aways ends with ;

int main(){

    // class instance creation
    Car firstCar("Lada",1978,"Red","Diesel","ds6f6dasfd","Manual","AB 2345");
    Car secondCar("Moskvich",1990,"White","Gas","d7dfgg5ds","Manual","BG 1234");

    firstCar.displayMessage();

    string model_name;    int car_year;
    cout << "Enter model name:";
    cin >> model_name;
    cout << "Enter car year:";
    cin >> car_year;    
    firstCar.setModel(model_name);
    firstCar.setYear(car_year);   

    firstCar.displayMessage();

    string carModel = firstCar.getModel();
    cout << "The car model is: " << carModel << endl;
    int carYear = firstCar.getYear();
    cout << "The car year is: " << carYear << endl;

    secondCar.displayMessage();
    //cout << "Hello world!" << endl;

    return 0;
}
#include "Car.h"
#include "FamilyCar.h"
#include "LuxuryCar.h"
#include "RentACar.h"

int main(){

    //Car is abstract class

    cout << "Testing FamilyCar class" << endl;
    //FamilyCar(brand, model, type, chassisNumber, plateNumber, fuelConsumption, tax, distance);
    FamilyCar fc1("Mazda","3",HACHBACK,"M6-345", "6565BG", 9.90, 60.00, 300.50);
    FamilyCar fc2("Opel","Astra",COMBI,"OA-647", "4534BG", 10.30, 60.00, 200.00);

    //FamilyCar CoefDistance is 0.7 (<500 km), 0.4 (>=500 km)
    cout << fc2.getDistance() << endl;
    cout << fc2.calculateCoefDistance() << endl;
    fc2.setDistance(510.00);
    cout << fc2.calculateCoefDistance() << endl;
    cout << fc2.getTax() << " + (" 
    << fc2.calculateCoefDistance() << " * " 
    << fc2.getDistance() << ") = " 
    << fc2.calculatePrice() << endl;

    cout << "Testing LuxuryCar class" << endl;
    //LuxuryCar(brand, model, type, chassisNumber, plateNumber, fuelConsumption, tax, distance, extraCharge);
    LuxuryCar lc1("Mazda","6",SEDAN,"M6-211", "7777BG",8.90, 120.00, 100.50, CHOCOLATE);
    LuxuryCar lc2("Porsche","911",SEDAN,"P9-546", "8888BG",10.40, 120.00, 250.5, CHAMPAGNE);

    //LuxuryCar CoefDistance is 0.6 (<200 km), 0.4 (>=500)
    cout << lc1.getDistance() << endl;
    cout << lc1.calculateCoefDistance() << endl;
    lc1.setDistance(200.00);
    cout << lc1.calculateCoefDistance() << endl;

    cout << "Checking and updating distance field, recalculating Price" << endl;
    //FamilyCar price = tax+ (CoefDistance*distance) + extras (CHAMPAGNE=100, WINE=50, CHOCOLATE=40)
    cout << lc1.getTax() << " + (" 
    << lc1.calculateCoefDistance() << " * " 
    << lc1.getDistance() << ") + " 
    << lc1.caclulateExtraCharges() << " = "
    << lc1.calculatePrice() << endl;
    // add wine to extra charges (+ 50)
    lc1.addExtraCharge(WINE);
    cout << lc1.calculatePrice() << endl;
    // remove chocolate from extra charges (-40)
    lc1.removeExtraCharge(CHOCOLATE);
    cout << lc1.calculatePrice() << endl;

    // Vector of Abstract Class Test
    // vector<Car*> cars;
    // vector<Car*>::iterator it;
    // cars.push_back(&fc1);
    // cars.push_back(&fc2);
    // cars.push_back(&lc1);
    // cars.push_back(&lc2);
    // for (Car* car : cars){
    //     car->printData();
    // }
    // cars.erase(cars.begin()+1);
    // for (Car* car : cars){
    //     car->printData();
    // }   

    // RentACar add objects from FamilyCar and LuxuryCar as addresses and put them in vector pointer array
    RentACar rent;
    rent.addCar(&fc1);
    rent.addCar(&fc2);
    rent.addCar(&lc1);
    rent.addCar(&lc2);
    cout << "Rent-A-Car Cars" << endl;
    rent.listCars();
    //have access to objects methods in the vector array
    cout << rent.carAt(2)->getBrand() << " " << rent.carAt(2)->getModel() << endl;
    cout << "ChassisNumber: " << rent.carAt(2)->getChassisNumber() << endl;
    cout << "PlateNumber: " << rent.carAt(2)->getPlateNumber() << endl;
    cout << "FuelConsumption: "<< rent.carAt(2)->getFuelConsumption() << endl;
    cout << "CalculatePrice: " << rent.carAt(2)->calculatePrice() << endl;
    //remove car at index 2 from the list
    rent.removeCar(2);
    rent.listCars();
    //there is a different car at index 2 now
    rent.carAt(2)->printData();
    rent.carAt(2)->listExtras();
    //add new extra
    rent.carAt(2)->addExtraCharge(CHOCOLATE);
    rent.carAt(2)->listExtras();
    rent.carAt(2)->addExtraCharge(WINE);
    rent.carAt(2)->listExtras();
    cout << "Price : " << rent.carAt(2)->calculatePrice() << endl;
    //remove extra
    rent.carAt(2)->removeExtraCharge(CHAMPAGNE);
    rent.carAt(2)->listExtras();
    cout << "Price : " << rent.carAt(2)->calculatePrice() << endl;
    rent.carAt(2)->removeExtraCharge(WINE);
    rent.carAt(2)->removeExtraCharge(CHOCOLATE);
    rent.carAt(2)->listExtras();
    cout << "Price : " << rent.carAt(2)->calculatePrice() << endl;
    return 0;
}
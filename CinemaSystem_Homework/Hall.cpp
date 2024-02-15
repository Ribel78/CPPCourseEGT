#include "Hall.h"
//#include 

Hall::Hall(string hallName, int capacity){
    setName(hallName);
    setSeats(capacity);
}

void Hall::setName(string name){
    this->name = name;
}
string Hall::getName(){
    return this->name;
}
void Hall::setSeats(int capacity){
    this->seats = capacity;
}

Hall::Hall(string name, int capacity, vector<Screening> screeningList)
:screeningList(screeningList){
    setName(name);
    setSeats(capacity);
}

void Hall::setScreeningList (vector<Screening> screeningList){
    this->screeningList = screeningList;
}
void Hall::addScreening (Screening screening){
    this->screeningList.push_back(screening);
}
vector<Screening> Hall::getScreeningList (){
    return this->screeningList;
}

void Hall::print(){
    cout << "Hall is:"
    << this->name << " "
    << this->seats
    << endl;
    for(int i=0; i < this->screeningList.size(); i++){
        this->screeningList.at(i).print();
    }
}
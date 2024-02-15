#include <iostream>
#include <string>
#include <vector>
#include "Cinema.h"

Cinema::Cinema(string name, string address, vector<Hall> halls){
    setName(name);
    setAddress(address);
    setHallList(halls);
}
void Cinema::setName(string name){
    this->name = name;
}
string Cinema::getName(){
    return this->name;
}
void Cinema::setAddress(string address){
    this->address = address;
}
string Cinema::getAddress(){
    return this->address;
}
void Cinema::setHallList(vector<Hall> halls){
    this->hallList = halls;
}
vector<Hall> Cinema::getHallList(){
    return this->hallList;
}
void Cinema::addHall(Hall hall){
    this->hallList.push_back(hall);
}
void Cinema::print(){
    cout
    << "Cinema name: "
    << getName()
    << "Cinema address:"
    << getAddress()
    << endl;
    for (auto hall : hallList){
        hall.print();
    }
}
void Cinema::findMovie(string movieName, vector<Hall> halls){
    bool isFound = false;
    for(int i = 0; i < halls.size(); i++){
        Hall h = halls.at(i);
        vector<Screening> scr = h.getScreeningList();
        for (int j = 0 ; j < scr.size(); j++){
            Screening scrObj = scr.at(j);
            string currentMovieName = scrObj.getMovieName();
            if (currentMovieName == movieName)
            {
                isFound = true;
                cout
                << "We've found projection at:"
                << h.getName()
                << endl;
                h.print();
                cout << "Projection info: \n";
                scrObj.print();
            }
        }
    }
    if (isFound == false){
        cout << "Movie not found" << endl;
    }
}
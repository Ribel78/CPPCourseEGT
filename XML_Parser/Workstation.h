#pragma once
#include <string>
using namespace std;

//<Workstation Building="2" Floor="3" Desc="5" />
class Workstation{
    public:
    Workstation(){}
    Workstation(string building, string floor, string desc)
    :building(building), floor(floor), desc(desc){}

    void setBuilding(string building){this->building = building;}
    void setFloor(string floor){this->floor = floor;}
    void setDesc(string desc){this->desc = desc;}

    string getBuilding(){ return building; }
    string getFloor(){ return floor; }
    string getDesc(){ return desc; }
    
    private:
        string building;
        string floor;
        string desc;
};
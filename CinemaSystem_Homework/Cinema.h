#ifndef _Cinema_h_
#define _Cinema_h_

#include <string>
#include <vector>
#include "Hall.h"
//#include "Screening.h"

class Cinema{
public:
    Cinema(string, string, vector<Hall>);
    void setName(string);
    string getName();
    void setAddress(string);
    string getAddress();
    void setHallList(vector<Hall>);
    vector<Hall> getHallList();
    void addHall(Hall);
    //void addVectorOfHallsToList(vector<Hall>);
    void print();
    void findMovie(string, vector<Hall>);

private:
    string name;
    string address;
    vector<Hall> hallList;
};

#endif // _Cinema_h_
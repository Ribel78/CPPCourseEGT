#ifndef _Hall_h_
#define _Hall_h_

#include <iostream>
#include <string>
#include <vector>
#include "Screening.h"

using namespace std;

class Hall{
    public:
        Hall(string, int);
        Hall(string, int, vector<Screening>);
        void setScreeningList (vector<Screening>);
        void addScreening (Screening);
        vector<Screening> getScreeningList ();
        void setName(string);
        string getName();
        void setSeats(int);
        void print();

    private:
        string name;
        int seats;
        vector<Screening> screeningList;
};

#endif //_Hall_h_

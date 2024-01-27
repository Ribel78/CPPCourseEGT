#ifndef _Screening_h_
#define _Screening_h_

#include <iostream>
#include <string>

using namespace std;

class Screening{
    public:
    Screening(string, int);
    void setMovieName(string);
    void setSoldTickets(int);
    string getMovieName();
    int getSoldTickets();
    void print();

    private:
        string movieName;
        int soldTickets;

};

#endif //_Screening_h_
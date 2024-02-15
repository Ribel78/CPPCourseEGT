#include "Screening.h"

Screening::Screening(string movieName, int tickets){
    setMovieName(movieName);
    setSoldTickets(tickets);
}

void Screening::setMovieName(string movieName){
    if (movieName.length() > 1){
        this->movieName = movieName;
    } else {
        this->movieName = "Undefined";
        std::cerr << "Movie name too short" << endl;
    }
}

void Screening::setSoldTickets(int tickets){
    if (tickets >= 0)
    {
        this->soldTickets = tickets;
    } else{
        this->soldTickets = 0;
    }

}

string Screening::getMovieName(){
    return this->movieName;
}

int Screening::getSoldTickets(){
    return this->soldTickets;
}

void Screening::print(){
        cout 
        <<"Projection is: "
        << this->movieName << " "
        <<"Sold tickets: "
        << this->soldTickets
        << endl;
}
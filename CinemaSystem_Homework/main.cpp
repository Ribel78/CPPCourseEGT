#include<iostream>

#include "Screening.h"
#include "Hall.h"
#include "Cinema.h"

int main(){

    Screening sc1("Star Wars - Return of Jedi", 100);
    Screening sc2("The Godfather", 30);
    Screening sc3("Indiana Jones", 40);
    Screening sc4("Dune 2", 33);

    vector<Screening> screenings;
    vector<Screening> otherScreenings;
    screenings.push_back(sc1);
    screenings.push_back(sc2);
    otherScreenings.push_back(sc3);
    otherScreenings.push_back(sc4);

    Hall h1("Hall 8", 80, screenings);
    Hall h2("Hall 9", 90, screenings);
    // h1.print();
    // h2.print();
    Hall h3("Hall 10", 100, otherScreenings);
    // h3.print();
    Screening sc5("Nemo 2", 55);
    h3.addScreening(sc5);
    // h3.print();

    vector<Hall> halls;
    halls.push_back(h1);
    halls.push_back(h2);
    halls.push_back(h3);

    Cinema cinema("Arena","Sofia",halls);
    cinema.print();

    string movieName;
    cout << "Enter movie name:";
    getline(cin, movieName);
    cinema.findMovie(movieName, halls);

    return 0;
}
#include "Fixture.h"

/*
round; date; time; stadium; city;Team guest;Team host; Referee referee;
*/
Fixture::Fixture(
    int round, string date, string time, string stadium,
    string city,Team& guest,Team& host,Referee& referee)
:guest(guest), host(host), referee(referee)
{
    setRound(round);
    setDate(date);
    setTime(time);
    setStadium(stadium);
    setCity(city);    
}
Fixture::~Fixture(){}

void Fixture::setRound(int round){this->round=round;}
int Fixture::getRound(){return this->round;}
void Fixture::setDate(string date){this->date=date;}
string Fixture::getDate(){return this->date;}
void Fixture::setTime(string time){this->time=time;}
string Fixture::getTime(){return this->time;}
void Fixture::setStadium(string stadium){this->stadium=stadium;}
string Fixture::getStadium(){return this->stadium;}
void Fixture::setCity(string city){this->city=city;}
string Fixture::getCity(){return this->city;}
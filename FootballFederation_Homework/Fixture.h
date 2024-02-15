#ifndef _Fixture_h
#define _Fixture_h

#include <string>
#include "Team.h"
#include "Referee.h"
using namespace std;

class Fixture{
public:
    Fixture(int,string,string,string,string,Team&,Team&,Referee&);
    ~Fixture();
    void setRound(int);
    int getRound();
    void setDate(string);
    string getDate();
    void setTime(string);
    string getTime();
    void setStadium(string);
    string getStadium();
    void setCity(string);
    string getCity();
    void setGuest(Team&);
    Team getGuest();
    void setHost(Team&);
    Team getHost();
    void setReferee(Referee&);
    Referee getReferee();

private:
// Fixture  - Round, Date, Stadium, City, Guest Team, Host Team, Referee
    int round;
    string date;
    string time;
    string stadium;
    string city;
    Team guest;
    Team host;
    Referee referee;
};

#endif //_Fixture_h
#include "Team.h"

/*
    string name;
    string address;
    string city;
    string coach;
    vector<string> players;
    int wins;
    int losses;
    int draws;
    int points;
    int position;
*/
Team::Team(){}
Team::Team(string name, string address, string city, string coach,
vector<string> players,int wins,int losses,int draws,int points,int position)
{
    setName(name);
    setAddress(address);
    setCity(city);
    setCoach(coach);
    setPlayers(players);
    setWins(wins);
    setLosses(losses);
    setDraws(draws);
    setPoints(points);
    setPosition(position);
}
Team::~Team(){}
void Team::setName(string name){this->name=name;}
string Team::getName(){return this->name;}
void Team::setAddress(string address){this->address=address;}
string Team::getAddress(){return this->address;}
void Team::setCity(string city){this->city=city;}
string Team::getCity(){return this->city;}
void Team::setCoach(string coach){this->coach=coach;}
string Team::getCoach(){return this->coach;}
void Team::setPlayers(vector<string> players){this->players=players;}
vector<string> Team::getPlayers(){return this->players;}
void Team::setWins(int wins){this->wins=wins;}
int Team::getWins(){return this->wins;}
void Team::setLosses(int losses){this->losses=losses;}
int Team::getLosses(){return this->losses;}
void Team::setDraws(int draws){this->draws=draws;}
int Team::getDraws(){return this->draws;}
void Team::setPoints(int points){this->points=points;}
int Team::getPoints(){return this->points;}
void Team::setPosition(int position){this->position=position;}
int Team::getPosition(){return this->position;}

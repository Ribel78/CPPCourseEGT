#ifndef _Team_h
#define _Team_h

#include <string>
#include "Player.h"
#include <vector>
using namespace std;
// Информацията за отбора име, адрес, град, треньор, играчи, изиграни срещи(class Match), 
// победи, задгуби, равенства, точки и класиране (за година), снимка
class Team{
public:
    Team();
    Team(string, string, string, string,
    vector<string>,int,int,int,int,int);
    ~Team();
    void setName(string);
    string getName();
    void setAddress(string);
    string getAddress();
    void setCity(string);
    string getCity();
    void setCoach(string);
    string getCoach();
    void setPlayers(vector<string>);
    vector<string> getPlayers();
    void setWins(int);
    int getWins();
    void setLosses(int);
    int getLosses();
    void setDraws(int);
    int getDraws();  
    void setPoints(int);
    int getPoints();
    void setPosition(int);
    int getPosition(); 
private:
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

};

#endif
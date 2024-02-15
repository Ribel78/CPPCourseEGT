#ifndef _Admin_h
#define _Admin_h


#include <vector>
#include <string>
#include "User.h"
#include "Team.h"

using namespace std;
//Добавя, променя и отписва отбори. 
class Admin : public User{
public:
    Admin(string, string);
    ~Admin();
    void addTeam(Team&, vector<Team>&);
    void updateTeam(Team&, vector<Team>&);
    void removeTeam(Team&, vector<Team>&);
    void printTeams(vector<Team>&);

private:

};

#endif
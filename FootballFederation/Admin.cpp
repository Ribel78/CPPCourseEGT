#include "Admin.h"

Admin::Admin(string username, string password): User(username, password){
    cout << " An admin was born " << endl;
}
Admin::~Admin(){
    cout << " An admin has died " << endl;
}
//add team to teams vector if name not found
void Admin::addTeam(Team& t, vector<Team>& teams){
    bool notListed = true;
    string name = t.getName();
    for(Team team : teams){
        if (team.getName() == name){
            notListed = false;
            cout << "Adding new team aborted. Team with name "<< name <<" already exists." << endl;
            break;
        }
    }
    if(notListed){
        teams.push_back(t);
        cout << "Adding new team with name "<< name <<" successful." << endl;
    } 
}
//update team in teams if name found
void Admin::updateTeam(Team& t, vector<Team>& teams){
    string name = t.getName();
    for(int i = 0; i < teams.size(); i++){
        if (teams.at(i).getName() == name){
            teams.at(i) = t;
            cout << "Team "<< name <<" was updated." << endl;
            break;
        }
    }    
}
//erase team from teams if name found
void Admin::removeTeam(Team& t, vector<Team>& teams){
    string name = t.getName();
    vector<Team>::iterator itr;
    for (itr = teams.begin(); itr != teams.end(); ++itr){
        if(itr->getName()==name){
            teams.erase(itr);
            cout << "Team "<< name <<" was removed." << endl;
            break;
        }
    }
}

void Admin::printTeams(vector<Team>& teams){
    cout << "--- Printing Teams List ---\n";
    for(Team t : teams){
        cout << t.getName() << " / " << t.getCoach() << endl;
    }
    cout << "--- End of Teams List --- total number of teams: " << teams.size() << endl;
}
#include "Referee.h"

Referee::Referee(string user_name, string password): User(user_name, password){
    cout << " A referee was born" << endl;
}
Referee::~Referee(){
    cout << " A referee has died" << endl;
}
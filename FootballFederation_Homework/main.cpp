#include <iostream>
using namespace std;

#include "User.h"
#include "Admin.h"
#include "Team.h"
#include "Referee.h"
#include "Fixture.h"

int main(){

    vector<string> liverpoolPlayers = {"A","B","C","D","E","F","G"};
    vector<string> arsenalPlayers = {"A","B","C","D","E","F","G"};
    vector<string> mcPlayers = {"A","B","C","D","E","F","G"};
    vector<string> avPlayers = {"A","B","C","D","E","F","G"};
    vector<string> thPlayers = {"A","B","C","D","E","F","G"};
    vector<string> whuPlayers = {"A","B","C","D","E","F","G"};
    vector<string> chelseaPlayers = {"A","B","C","D","E","F","G"};
    vector<string> nuPlayers = {"A","B","C","D","E","F","G"};
    Team t1("Liverpool","Adr","City","CoachName",liverpoolPlayers,0,0,0,0,0);
    Team t2("Arsenal","Adr","City","CoachName",arsenalPlayers,0,0,0,0,0);
    Team t3("Manchester City","Adr","City","CoachName",mcPlayers,0,0,0,0,0);
    Team t4("Aston Villa","Adr","City","CoachName",avPlayers,0,0,0,0,0);
    Team t5("Tottenham Hotspur","Adr","City","CoachName",thPlayers,0,0,0,0,0);
    Team t6("West Ham United","Adr","City","CoachName",whuPlayers,0,0,0,0,0);
    Team t7("Chelsea","Adr","City","CoachName",chelseaPlayers,0,0,0,0,0);
    Team t8("Newcastle United","Adr","City","CoachName",nuPlayers,0,0,0,0,0);
    vector<Team> teams = {t1, t2, t3, t4, t5, t6, t7, t8};

    // User admin("Gosho", "saggsrgsrgr");
    // User referee("Misho", "sdfsbikfg");
    Admin admin ("Pesho", "asdsda");
    admin.printTeams(teams);
    // new team
    Team t9("Chrystal Palace","Adr","City","CoachName",chelseaPlayers,0,0,0,0,0);
    // updated team
    t2.setCoach("Boncho Bonchev");

    admin.addTeam(t9, teams); //add Chrystal Palace to teams vector
    admin.updateTeam(t2, teams); //updated coach name to Arsenal
    admin.removeTeam(t5, teams); // removed Tottenham Hotspur from teams vector
    admin.addTeam(t6, teams); //trying to add existing by name team - West Ham United
    
    admin.printTeams(teams); 

    Referee ref1("Misho", "sdfiyeryer");
    Referee ref2("Pesho", "4665ytfdgb");
    Referee ref3("Gosho", "354yhcv");

    Fixture f1(1,"15.08.2024","19:30","StadName","CityName",t1,t2,ref1);
    Fixture f2(1,"16.08.2024","19:30","StadName","CityName",t3,t4,ref2); 
    Fixture f3(1,"19.08.2024","19:30","StadName","CityName",t5,t6,ref3); 
    Fixture f4(1,"20.08.2024","19:30","StadName","CityName",t7,t8,ref1); 
    Fixture f5(2,"12.09.2024","19:30","StadName","CityName",t1,t7,ref2);
    Fixture f6(2,"13.09.2024","19:30","StadName","CityName",t2,t8,ref3); 
    Fixture f7(2,"25.09.2024","19:30","StadName","CityName",t5,t3,ref1); 
    Fixture f8(3,"05.10.2024","19:30","StadName","CityName",t2,t4,ref2); 

    vector<Fixture> fixtures = {f1, f2, f3, f4, f5, f6, f7, f8};
    // admin has to add, remove update fixtures
    //referee - Води отчет за всяка среща  -  резултат, картони, автори на попаденията, време на попаденията
    // admin ? create League Table - positions based on data - points

    //fan base - list fixtures - buy tickets(register) - see league table

    /*
    Системата да показва и статистическа информация – 
класиране, загуби на всеки отбор, победи на всеки отбор, 
брой зрители за отборите по срещи, картони и други. 
Статистиката се вижда от всички потребители.
    */
    return 0;
}
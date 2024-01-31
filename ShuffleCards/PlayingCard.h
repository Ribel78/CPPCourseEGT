#ifndef PlayingCard_H
#define PlayingCard_H
#include <iostream>
#include <string>
using namespace std;

class PlayingCard{
public:
    //initialize with type and suite chars
    PlayingCard(string, char);
    ~PlayingCard();
    void setType(string);
    string getType();
    void setSuite(char);
    char getSuite();
    void print();

private:
    string card_type;
    char card_suite;
};

#endif //PlayingCard_H
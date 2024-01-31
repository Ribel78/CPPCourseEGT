#ifndef DeckOfCards_H
#define DeckOfCards_H

#include "PlayingCard.h"
#include <vector>
#include <map>

class DeckOfCards{
public:
    DeckOfCards();
    ~DeckOfCards();
    void riffleShuffle();
    void displayDeck(bool, int);
private:
    vector<PlayingCard> cards;
    const string c_type[13] = {"2","3","4","5","6","7","8","9","10","J", "Q", "K", "A"};
    const char c_suite[4] = {'D', 'C', 'H', 'S'};
    map <char,string> suite{{'D',"♦"},{'C',"♣"},{'H',"♥"},{'S',"♠"}};
};

#endif //DeckOfCards_H
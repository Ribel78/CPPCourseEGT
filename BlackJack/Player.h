#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Card.h"
using namespace std;

class Player{
public:
    Player(); // init

    void init();                    // init cash, hand, dealCard with default vals or form file
    bool setDealCard();             //set HIT/STAY state
    void addCardToHand(Card card, bool faceUp);  // if dealCard add Card to hand // also to deal first two cards faceUp prop of Card obj

    int placeBet(int cash);         // choose amount to bet 100 or 1000 //update the cash
    void updateCash(int amount);    //change cash value with win/loss amount
    void calcHand(vector<Card> hand, vector<int> handValues); // calculate hand sum(s) // if all cards are up! Card.faceUp = true
    
    
private:
    int cash; // player's money default to 0
    vector<Card> hand; //a collection of Card-s dealt (init or load from file)
    vector<int> handValues; //all possible hand values (sums) (init or from file)
    bool dealCard; // choose HIT (1) or STAY (0) //Dealer Player needs some logic when to STAY
    

};
#endif //PLAYER_H
#include "Card.h"

Card::Card(CardKind kind, CardSuit suit, bool faceUp){
        setKind(kind);
        setSuit(suit);        
        setFaceUp(faceUp);
}
void Card::setKind(CardKind kind){
    this->kind = kind;
}

void Card::setSuit(CardSuit suit){
    this->suit = suit;
}

void Card::setFaceUp(bool faceUp){
    this->faceUp = faceUp;
}

CardKind Card::getKind(){return this->kind;}

CardSuit Card::getSuit(){return this->suit;}

bool Card::getFaceUp(){return this->faceUp;}

queue<Card> Card::createDealerShoe(int nDecks, bool rand, unsigned seed){
    queue<Card> dealerShoe;;
    return dealerShoe;
}
#ifndef CARD_H
#define CARD_H

#include <vector>
#include <queue>
using namespace std;

enum CardKind {CA, C1, C2, C3, C4, C5, C6, C7, C8, C9, C10, CJ, CQ, CK};
enum CardSuit {H, S, D, C};

/*
Card object
_enum CardKind - possible values:
CA, C1, C2, C3, C4, C5, C6, C7, C8, C9, C10, CJ, CQ, CK
_enum CardSuit - possible values
H, S, D, C
_bool - is the card facing up (1) or down (0)
*/
class Card{
    public:
        Card(CardKind, CardSuit, bool);

        void setKind(CardKind);
        void setSuit(CardSuit);        
        void setFaceUp(bool);

        CardKind getKind();
        CardSuit getSuit();
        bool getFaceUp();

    private:
        CardKind kind;
        CardSuit suit;
        bool faceUp; //1 up, 0, down
        /* to implement
        generate a map for a deck of Cards and use it 4,6, 8 times to fill in a suitable container of Cards (vector),
        randomize the container and return a pointer to a dealerShoe queue
        should this function be in this class?
        */
        static queue<Card> createDealerShoe(int nDecks, bool rand, unsigned seed);
};

#endif //CARD_H
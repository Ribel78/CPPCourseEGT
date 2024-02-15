#ifndef Shuffler_H
#define Shuffler_H

#include <vector>
#include <queue>
#include <string>
using namespace std;

enum CardKind {CA, C2, C3, C4, C5, C6, C7, C8, C9, C10, CJ, CQ, CK};
enum CardSuit {H, S, D, C};

/*
Card struct
_kind - enum CardKind - possible values:
CA, C2, C3, C4, C5, C6, C7, C8, C9, C10, CJ, CQ, CK
_suit - enum CardSuit - possible values
H, S, D, C
_bool - is the card facing up (1) or down (0)
*/
struct Card{
        CardKind kind;
        CardSuit suit;
        bool faceUp;
};

/*
Generates a Dealer Shoe (stack of shuffled playing cards of 1 or more card decks)
Initialize with
_nDecks - number of card decks
_randomize - bool - flag for randomizing the decks (false not implemented - use true or 1)
*/
class Shuffler{
    public:
        Shuffler(int nDecks, bool randomize);
        queue<Card> createDealerShoe();
        queue<Card> loadDealerShoe(vector<Card>& deck);
    private:
        int nDecks;
        bool randomize;
        vector<Card> deck;
};

#endif //Shuffler_H
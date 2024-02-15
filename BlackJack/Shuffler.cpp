#include "Shuffler.h"
#include <algorithm>
#include <random>
#include <chrono>

// Initialize the class
Shuffler::Shuffler(int nDecks, bool randomize)
:nDecks(nDecks), randomize(randomize){}

/*
Create new randomized Dealer Shoe of _nDecks of card decks
Returns:
queue<Card> of _nDecks*52 size or empty if randomize is false
*/
queue<Card> Shuffler::createDealerShoe(){
    queue<Card> dealerShoe;
    if(randomize){
        CardKind kind[] = {CA, C2, C3, C4, C5, C6, C7, C8, C9, C10, CJ, CQ, CK};
        CardSuit suit[] = {H, S, D, C};
        for (int n = 0; n < nDecks; n++){
            for (int i = 0; i < 52; i++){
                Card tmp {kind[i%13], suit[i/13], 1};
                deck.push_back(tmp);
            }
        }
        // good for random shuffle on each run //src: https://linuxhint.com/shuffle-vs-random-shuffle-cpp/
        unsigned seed = chrono::system_clock::now().time_since_epoch().count(); 
        shuffle(deck.begin(), deck.end(), default_random_engine(seed));
        for (int i = 0; i < 52*nDecks ; i++){
            dealerShoe.push(deck.at(i));
        }
    }
    return dealerShoe;
}
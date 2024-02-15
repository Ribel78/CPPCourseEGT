#include "PlayingCard.h"
#include "DeckOfCards.h"

int main(){
    //Try displaying suits with Unicode chars (true) or ASCII chars(false):
    bool fancyDisplay = false;

    DeckOfCards deck;
    cout << "Out of the box cards\n";
    deck.displayDeck(fancyDisplay, 13);
    cout << endl;

    int rifruf;
    cout << "Enter number of Riffle Shuffles:";
    cin >> rifruf;

    for (int i = 0 ; i<rifruf; i++){
        cout << "Shuffling cards #" << i+1 << "\n\n";
        deck.riffleShuffle();
        deck.displayDeck(fancyDisplay, 13);
        cout << endl;
    }

    return 0;
}
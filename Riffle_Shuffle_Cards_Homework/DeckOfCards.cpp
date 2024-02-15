#include "DeckOfCards.h"

DeckOfCards::DeckOfCards(){
    for (int i = 0; i < 52; i++){
        PlayingCard card(c_type[i%13], c_suite[i/13]);
        cards.push_back(card);
    }
}
DeckOfCards::~DeckOfCards(){}
void DeckOfCards::riffleShuffle(){
    if(cards.size() == 52){
        vector<PlayingCard> temp;
        for (int i = 0; i < 26; i++){
            temp.push_back(cards.at(i+26));
            temp.push_back(cards.at(i));
        }
        cards.swap(temp);
    }else{
        cout << "The deck of cards must have 52 cards. Reshuffling aborted.\n";
    }
}
//displayDeck(true:show suit unicode symbols|false:show suit chars, cards per row)
void DeckOfCards::displayDeck(bool beautify, int cpr){
    int counter = 0;
    for (auto card : cards){
        counter +=1;
        if(beautify)
            cout << "|" << card.getType() << suite[card.getSuite()] << "|";
        else
            cout << "|" << card.getType() << card.getSuite() << "|"; //in case unicode chars don't show up
        if (counter % cpr == 0)
            cout << endl;
    }
}
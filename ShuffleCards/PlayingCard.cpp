#include "PlayingCard.h"

PlayingCard::PlayingCard(string t, char s){
    setType(t);
    setSuite(s);
}
PlayingCard::~PlayingCard(){}
void PlayingCard::setType(string t){
    card_type = t;
}
string PlayingCard::getType(){
    return card_type;
}
void PlayingCard::setSuite(char s){
    card_suite = s;
}
char PlayingCard::getSuite(){
    return card_suite;
}
void PlayingCard::print(){
    cout << "|" << card_type << card_suite << "|";
}


#include <iostream>
#include <string>

#include <algorithm>
#include <random>
#include <chrono>

#include "Card.h"
#include "Player.h"

using namespace std;

/* 
Calculates all posible hand values (part of PlayerClass)
_vector<Card>& - dealt cards from a hand
_vector<int>&  - collection of int to store the hand values
*/
void calcHand(vector<Card>& cards, vector<int>& handValues){
    
    int sum = 0;
    int aces = 0;
    for(auto card : cards){ //get partial sum of just non-Ace cards
        if (card.getKind() == CA){ // count aces
            aces+=1;
        }else{
            sum += ((card.getKind() <= 10) ? card.getKind() : 10);
        }
    }
    sum += aces;
    handValues.push_back(sum);
    for (int i=0; i < aces ; i++){
        sum += 10;
        handValues.push_back(sum);
    }
}

int main(){

//We need two players
Player player;
Player dealer;

// TO DO queue<Card> dealerShoe (box with randomized decks of Cards)

// Testing Card - test with some player/dealer hands later

Card c1(C4, H, 1);
Card c2(C5, D, 1);
Card c3(CA, S, 1);

vector<Card> hand;
hand.push_back(c1);  hand.push_back(c2);  hand.push_back(c3);  //hand.push_back(c4);
//hand.push_back(c5);  hand.push_back(c6);  hand.push_back(c7);  hand.push_back(c8);

vector<int> handValues;

calcHand(hand, handValues);

for (auto elem : handValues){
    cout << "Total hand value: " << elem << endl;;
}


//shuffle testing code src: https://linuxhint.com/shuffle-vs-random-shuffle-cpp/

vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//unsigned seed = chrono::system_clock::now().time_since_epoch().count(); // good for random shuffle on each run
unsigned seed = 23535435; // we need a "stable" seed if we want to reload the game with the same dealerShoe container? Need to track number of played cards
shuffle(vec.begin(), vec.end(), default_random_engine(seed));
cout << "shuffled elements are:";
for (int& i : vec)
cout << ' ' << i;
cout << endl;
 
        return 0;
}


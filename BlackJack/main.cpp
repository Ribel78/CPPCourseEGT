#include <iostream>
#include <string>

#include <algorithm>
#include <random>
#include <chrono>

#include "Shuffler.h"
#include "Player.h"

using namespace std;

/* 
Calculates all posible hand values (part of PlayerClass)
_vector<Card>& - dealt cards from a hand
_vector<int>&  - collection of int to store the hand values
Updates the provided vector references
*/
void calcHand(vector<Card>& cards, vector<int>& handValues){
    
    int sum = 0;
    int aces = 0;
    for(auto card : cards){ //get partial sum of just non-Ace cards
        if (card.kind == CA){ // count aces
            aces+=1;
        }else{
            sum += ((card.kind <= 9) ? card.kind + 1 : 10); //+1 compensate for 0 indexing
        }
    }
    sum += aces; // add the acces count to the sum
    handValues.push_back(sum);
    for (int i = 0 ; i < aces ; i++){ // for the count of aces calculate the rest of possible sums
        sum += 10;
        handValues.push_back(sum);
    }
}

int main(){
//Work in progress - objects and functions are subject to change
//We need two players
Player player;
Player dealer;

// TO DO Create Player, GameLogic and GameAssets classes - link with SDL

// Test the Dealer's Shoe generation. Works!!!
vector<Card> hand;
Shuffler shuffler(6,true);
queue<Card> dealerShoe = shuffler.createDealerShoe();
cout << "dealerShoe.size() "<< dealerShoe.size() << endl;
int count = 0;
vector<int> handValues;
while (!dealerShoe.empty()){
        cout <<"Kind: " << dealerShoe.front().kind << " Suit: " << dealerShoe.front().suit << endl;
        hand.push_back(dealerShoe.front());
        dealerShoe.pop();
        count+=1;
        if (count%3 == 0){
            calcHand(hand, handValues); // updates vectors
            for (auto elem : handValues){
                cout << "Total hand value: " << elem << endl;;
            }
            cout << "dealerShoe.size() "<< dealerShoe.size() << endl;
            hand.resize(0);
            handValues.resize(0);
        }
}
        return 0;
}


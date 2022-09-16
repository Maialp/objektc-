#include "CardDeck.h"

CardDeck::CardDeck(){

    for(const auto& s : suitAndString){
        for (const auto& r : rankAndString){
            Card c{s.first, r.first};
            cards.push_back(c);
        }
   }
}
void CardDeck::swap(int a, int b){
    Card en = cards[a];
    Card to = cards[b];
    cards[b] = en; 
    cards[a] = to;
}
void CardDeck::print(){
    for (Card c : cards){
        cout << c.toString() << '\n';
    }
}
void CardDeck::printShort(){
    for (Card c : cards){
        cout << c.toStringShort()<< '\n';
    }
}
void CardDeck::shuffle(){
    for (int i = 0; i < 52; i++){
        int j = rand()%(52);
        swap(i,j);
    }
}
Card CardDeck::drawCard(){
    int length = size(cards);
    Card yourCard = cards[length-1];
    cards.pop_back();
    return yourCard;
}
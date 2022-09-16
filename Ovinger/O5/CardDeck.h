#pragma once
#include "Card.h"
#include "std_lib_facilities.h"


class CardDeck{
    private: 
        vector<Card> cards;
    public: 
        CardDeck();
        void swap(int a, int b);
        void print();
        void printShort();
        void shuffle();
        Card drawCard();
};
#pragma once
#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"

class Blackjack{
    private:
        vector<Card> playerCards;
        vector<Card> dealerCards;
    public:
        Blackjack();
        void drawPlayerCard(CardDeck& d);
        void drawDealerCard(CardDeck& d);
        void showCards();
        void calculateSum(int& player, int& dealer);
        int chooseAceVal();
        void showAndSumDealersCards(int& dealer);
};
#include "Blackjack.h"
#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"

Blackjack::Blackjack(){
    //Lager en kortstokk og stokker den:
    CardDeck d{};
    d.shuffle();

    //Trekker det første og andre kortet:
    for(int i = 0; i < 2; i++){
        drawPlayerCard(d);
        drawDealerCard(d);
    }
    //viser kortene som skal vises: 
    showCards();

    string choice;
    cout <<"Would you like to stand? (yes/no): "; 
    cin >> choice;

    int sumPlayer = 0; 
    int sumDealer = 0;
    while (choice == "no" && sumPlayer<21){
        calculateSum(sumPlayer, sumDealer);

        drawPlayerCard(d);
        if (sumDealer < 17){
            drawDealerCard(d);
        }
        showCards();
        cout <<"Would you like to stand? (yes/no): "; 
        cin >> choice;
        
    }
    // Flip the dealsers card:
    calculateSum(sumPlayer, sumDealer);
    showAndSumDealersCards(sumDealer);
    cout << "Your sum: " << sumPlayer << '\n' << "Dealers sum: " << sumDealer << '\n'; 

    //Erklærer vinneren:
    if (sumPlayer > 21){
        cout << "You lost...\n";
    }
    else if (sumDealer > 21){
        cout << "Your won!\n";
    }
    else if (sumPlayer > sumDealer){
        cout << "Your won!\n";
    }
    else{
        cout << "You lost...\n";
    }

}

void Blackjack::drawPlayerCard(CardDeck& d){
    Card player = d.drawCard();
    playerCards.push_back(player);
}
void Blackjack::drawDealerCard(CardDeck& d){
    Card dealer = d.drawCard();
    dealerCards.push_back(dealer);
}

void Blackjack::showCards(){
    cout << "Your cards: \n";
    for (Card c : playerCards){
        cout << c.toStringShort() << '\n';
    }
    cout << "Dealers cards: \n" << "Flipped card\n";
    for (int i = 1; i < size(dealerCards); i++){
        cout << dealerCards[i].toStringShort() <<'\n';
    }
}
void Blackjack::showAndSumDealersCards(int& dealer){
    cout << "Dealers cards: \n";
    for (Card c :dealerCards){
        cout << c.toStringShort()<< '\n';
    }
    dealer = 0;
    for (Card c : dealerCards){
        int cardRank = static_cast<int>(c.getRank());
        if (cardRank<11){
            dealer+=cardRank;
        }
        else if (cardRank == 14){
            int aceVal = chooseAceVal();
            dealer += aceVal;
        }
        else{
            dealer += 10;
        }
    }
}

void Blackjack::calculateSum(int& player, int& dealer){
    player = 0; 
    dealer = 0;
    for (Card c : playerCards){
        int cardRank = static_cast<int>(c.getRank());
        if (cardRank<11){
            player+=cardRank;
        }
        else if (cardRank == 14){
            int aceVal = chooseAceVal();
            player += aceVal;
        }
        else{
            player += 10;
        }
    }
    for (int i = 1; i<size(dealerCards); i++){
        int cardRank = static_cast<int>(dealerCards[i].getRank());
        if (cardRank<11){
            dealer+=cardRank;
        }
        else if (cardRank == 14){
            dealer += chooseAceVal();
        }
        else{
            dealer += 10;
        }

    }
}
int Blackjack::chooseAceVal(){
    int aceVal = 0; 
    cout << "Choose value of ace: ";
    cin >> aceVal;
    while ((aceVal != 1) && (aceVal != 11)){
        cout << "Please choose a valid value for your ace: ";
        cin >> aceVal;
    }
    return aceVal;
}
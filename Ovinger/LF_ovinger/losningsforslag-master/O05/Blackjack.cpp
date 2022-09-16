#include "Blackjack.h"

bool yn_question(string q)
// Returnere true når inputen fra brukeren er 'y', ellers false
{
	char yn;
	cout << q << " (y/n) ";
	cin >> yn;
	cin.ignore(256, '\n'); // Flere gyldige input blir ignorert
	if (yn == 'y')
		return true;
	return false;
	// return yn == 'y';
}

void Blackjack::roundInit() {
    if(deck.cardsLeft() < 16) {
        deck = CardDeck{};
        deck.shuffle();
    }
    playerHandSum = 0;
    dealerHandSum = 0;
    dealerHand.clear();
    playerHand.clear();
    playerDraw();
    playerDraw();
    dealerDraw();
    dealerDraw();
}

bool Blackjack::isAce(Card c) const {
    return c.getRank() == Rank::ace;
}


int Blackjack::getCardValue(Card c) const {
    return blackjackValues.at(c.getRank());

    // Alternativ løsning med switch
    /* switch(c.getRank()) {
        case Rank::two:
            return 2;
        case Rank::three:
            return 3;
        case Rank::four:
            return 4;
        case Rank::five:
            return 5;
        case Rank::six:
            return 6;
        case Rank::seven:
            return 7;
        case Rank::eight:
            return 8;
        case Rank::nine:
            return 9;
        case Rank::ten:
            return 10;
        case Rank::jack:
            return 10;
        case Rank::queen:
            return 10;
        case Rank::king:
            return 10;
        case Rank::ace:
            return 11;


    } */

   // Alternativ 2
   /*
   int val = static_cast<int>(c.getRank());
   if (c.getRank() == Rank::ace) {
       val = 11;
   }
   else if (static_cast<int>(c.getRank()) > 10) {
       val = 10;
   }
   return val;
   */
}

int Blackjack::getHandScore(vector<Card> hand) const {
    int score{0};
    int numberOfAces{0};
    for (const auto& c: hand) {
        score += getCardValue(c);
        if (isAce(c)) {
            numberOfAces++;
        }
    }
    // Siden ess kan ha verdien 1 eller 11 og vi i getCardValue() brukte 11, kan vi
    // endre verdien til 1 dersom det gjør poengsummen bedre.
    for (int i = 0; i < numberOfAces && score > 21; i++) {
        score -= 10;
    }
    return score;
}

void Blackjack::playerDraw(){
    playerHand.push_back(deck.drawCard());
    cout << "You got: " << playerHand.back().toString()<<'\n';
    playerHandSum = getHandScore(playerHand);
}

void Blackjack::dealerDraw(){
    dealerHand.push_back(deck.drawCard());
    dealerHandSum = getHandScore(dealerHand);
}

void Blackjack::playGame(){
    cout << "******* LET'S PLAY BLACKJACK! *********\n";
    deck.shuffle();
    bool playerWins = false;
    do {
        roundInit();

        cout << "Player hand is currently: " << playerHandSum << '\n';
        cout << "The dealer's open card is: " << dealerHand.at(0).toString() << '\n';

        // Spiller trekker kort
        while (playerHandSum < 21 && yn_question("Do you want another card?")) {
            cout << "Player draws a card\n";
            playerDraw();
            cout << "Player hand is currently: " << playerHandSum << '\n';
        }

        // Dealer trekker kort
        while (dealerHandSum < 17) {
            cout << "Dealer draws a card.\n";
            dealerDraw();
        }

        cout << "**************************************\n";
        cout << "Player's cards: ";
        for(const auto& c : playerHand){
            cout << c.toString() << ", "; 
        }
        cout << '\n';
        cout << "Player's hand: " << playerHandSum << '\n';

        cout << "Dealer's cards: ";
            for(const auto& c : dealerHand){
                cout << c.toString() << ", ";
            }
        cout << '\n';
        cout << "Dealer's hand: " << dealerHandSum << '\n';

        // Vinner bestemmes
        if (playerHandSum > 21) {
            cout << "Player burst.\n";
            playerWins = false;
        } else if (dealerHandSum > 21) {
            cout << "Dealer burst.\n";
            playerWins = true;
        } else if (dealerHandSum == 21 && dealerHand.size() == 2) {
            cout << "Dealer got blackjack!\n";
            playerWins = false;
        } else if (playerHandSum == 21 && playerHand.size() == 2) {
            cout << "Player got blackjack!\n";
            playerWins = true;
        } else if (dealerHandSum <= 21 && dealerHandSum > playerHandSum) {
            cout << "Dealer beat the player.\n";
            playerWins = false;
        } else if (playerHandSum <= 21 && playerHandSum > dealerHandSum) {
            cout << "Player beat the dealer.\n";
            playerWins = true;
        } else {
            cout << "Game was a draw.\n";
            playerWins = false;
        }

        if (playerWins) {
            cout << "You won! Congratulations!\n";
        } else {
            cout << "You lost!\n";
        }
    } while(yn_question("Do you want to play again?\n"));
}

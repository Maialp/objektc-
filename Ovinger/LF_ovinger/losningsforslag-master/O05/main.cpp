#include "std_lib_facilities.h"
#include "Blackjack.h"

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	// Test Rank og Suit
	Rank r = Rank::king;
	Suit s = Suit::hearts;

	string rank = rankToString(r);
	string suit = suitToString(s);

	cout << "Rank: " << rank << " Suit: " << suit << '\n';
	
	// Test Card-klassen
	Card c1{s, r};
	Card c2{Suit::spades, Rank::seven};

	cout << "c1: " << c1.toString() << " c2: " << c2.toString() << '\n';
	cout << "c1 short: " << c1.toStringShort() << " c2 short: " << c2.toStringShort() << '\n';

	// Test Carddeck-klassen
	CardDeck cd;
	cout << "Carddeck\n";
	cd.print();
	cd.shuffle();
	cout << "Carddeck short after shuffle\n";
	cd.printShort();

	// Test Blackjack klassen
	Blackjack bj;
	bj.playGame();
}

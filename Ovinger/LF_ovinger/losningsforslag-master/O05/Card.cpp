#include "Card.h"

string rankToString(Rank r) {
	return rankToStringMap.at(r);

	// Alternativ med switch
	/* switch(r) {
		case Rank::two:
			return "two";
		case Rank::three:
			return "three";
		case Rank::four:
			return "four";
		case Rank::five:
			return "five";
		case Rank::six:
			return "six";
		case Rank::seven:
			return "seven";
		case Rank::eight:
			return "eight";
		case Rank::nine:
			return "nine";
		case Rank::ten:
			return "ten";
		case Rank::jack:
			return "jack";
		case Rank::queen:
			return "queen";
		case Rank::king:
			return "king";
		case Rank::ace:
			return "ace";
	} */
}

string suitToString(Suit s) {
	return SuitToStringMap.at(s);

	// Alternativ med switch
	/* switch(s) {
		case Suit::clubs:
			return "clubs";
		case Suit::diamonds:
			return "diamonds";
		case Suit::hearts:
			return "hearts";
		case Suit::spades:
			return "spades";
	} */
}

Suit Card::getSuit() const {
	return s;
}
Rank Card::getRank() const {
	return r;
}

string Card::toString() const {
	return rankToString(r) + " of " + suitToString(s);
}

// Her kombineres første tegn fra suitToString() med rangen konvertert til et heltall.
// Dette kan gjøres fordi enumen Rank ble definert til å starte på verdien 2.
string Card::toStringShort() const {
	return suitToString(s).at(0) + to_string(static_cast<int>(r));
}


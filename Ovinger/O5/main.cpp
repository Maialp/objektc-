
#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"
#include "Blackjack.h"

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	
	Blackjack play{};

	keep_window_open();
}

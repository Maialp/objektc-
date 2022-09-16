#include "mastermind.h"
#include "masterVisual.h"
#include "utilities.h"
#include <cassert> // For assert()



bool askYesNoQuestion(string questionMessage)
//Returnere true når inputen fra brukeren er 'y', ellers false
{
	char answerFromUser;
	cout << questionMessage << " (y/n) ";
	cin >> answerFromUser;
	cin.ignore(256, '\n'); // Flere gyldige input blir ignorert
	if (answerFromUser == 'y')
		return true;
	return false;
	// return yn == 'y';
}

void playMastermind()
{
	constexpr int size = 4;
	constexpr int letters = 6;
	constexpr char startLetter = 'A';
	constexpr int maxTries = 6;
	/*Vi bruker constexpr og ikke const her fordi vi vet verdien til variablene før vi kjører koden.
    constexpr er konstanter der verdien blir bestemt i kompileringstid, og const er konstanter der 
    verdien blir bestemt i kjøretid. Du kan lese mer om const og constexpr i kapittel 4.3.1 i læreboka
    */

	
	bool playAgain = false;
	do {
		MastermindWindow mwin{900, 20, winW, winH, size, "Mastermind"};
		string code = randomizeString(size, startLetter, startLetter + letters - 1);
		string guess;
		int round = 0;
		cout << "*** Mastermind ***" << endl;
		
		cout << "Colors: a = red, b = green, c = yellow, d = blue, e = lilac, f = cyan" << endl << endl;
		
		// Viser CODE. addGuess brukes til å vise den hemmelige koden med parameter round = 0
		addGuess(mwin, code, startLetter);
		mwin.setCodeHidden(true);
		
	
		while (guess != code && round != maxTries) {
			cout << "What's your guess? (" << size << " chars)" << endl;
			guess = mwin.getInput(size, startLetter, startLetter + letters - 1);
			cout << "Your guess: " << guess << endl;
			++round;
			if(mwin.should_close()) {
				break;
			}

			int correct = checkCharactersAndPosition(code, guess);
			int correctChars = checkCharacters(code, guess);

			// Det nyeste gjettet legges til i grafikkvinduet sammen med riktig tilbakemelding.
			addGuess(mwin, guess, startLetter);
			addFeedback(mwin, correct, correctChars);
			mwin.redraw();
			
			// Hopp ut av løkken dersom spiller har gjettet koden.
			if (correct == size) {
				break;
			}

			cout << "Correct characters: " << correctChars << endl
				 << "Correct positions: " << correct << endl << "You have " << maxTries - round
				 << " tries left." << endl;
		}

		mwin.wait_for_close();
		
		if (guess == code) {
			cout << "Congratulations, you cracked the code!" << endl;
			mwin.setCodeHidden(false);
		} else {
			cout << "You didn't manage to crack the code..." << endl;
		}
		playAgain = askYesNoQuestion("Do you want to play again?");
	} while (playAgain);
}

int checkCharactersAndPosition(string code, string guess)
// precondition: code.length() == guess.length()
// Her bruker vi kommentaren over for å eksplisitt uttrykke preconditionen
// og vi bruker assert() til å sjekke preconditioen.
// Generelt er det ikke anbefalt å ha kommentarer som sier akkurat det samme som koden, så denne 
// kommentaren er diskutabel
{
	assert(code.length() == guess.length());
	int count = 0;
	for (unsigned int i = 0; i < code.length(); ++i) {
		if (code[i] == guess[i]) {
			++count;
		}
	}
	return count;
}

int checkCharacters(string code, string guess)
// precondition: code.length() == guess.length()
{
	assert(code.length() == guess.length());
	set<char> guessSet;
	for (char ch : guess) {
		guessSet.insert(ch);
	}
	// guessSet har nå alle de unike bokstavene i guess

	int count = 0;
	for (char ch : guessSet) {
		int guessCount = countChar(guess, ch);
		int codeCount = countChar(code, ch);
		count += min(guessCount, codeCount);
		// En bokstav må finnes i både guess og code for å telles. Derfor er
		// antall rette bokstaver gitt av minimum.
	}

	return count;
}

void playMastermindWithoutGraphics(){
	constexpr int size = 4;
	constexpr int letters = 6;
	constexpr char startLetter = 'A';
	constexpr int maxTries = 6;
	/*Vi bruker constexpr og ikke const her fordi vi vet verdien til variablene før vi kjører koden.
    constexpr er konstanter der verdien blir bestemt i kompileringstid, og const er konstanter der 
    verdien blir bestemt i kjøretid. Du kan lese mer om const og constexpr i kapittel 4.3.1 i læreboka
    */

	bool playAgain = false;
	do {
		string code = randomizeString(size, startLetter, startLetter + letters - 1);
		string guess;
		int round = 0;
		cout << "*** Mastermind ***" << endl;
	
		while (guess != code && round != maxTries) {
			cout << "What's your guess? (" << size << " chars) " << endl;
			guess = readInputToString(size, startLetter, startLetter + letters - 1);
			cout << "Your guess: " << guess << endl;
			++round;

			int correct = checkCharactersAndPosition(code, guess);
			int correctChars = checkCharacters(code, guess);

			if (correct == size) {
				break;
			}

			cout << "Correct characters: " << correctChars
				 << "\nCorrect positions: " << correct << endl << "You have " << maxTries - round
				 << " tries left." << endl;
		}
		
		if (guess == code) {
			cout << "Congratulations, you cracked the code!" << endl;
		} else {
			cout << "You didn't manage to crack the code..." << endl;
		}
		playAgain = askYesNoQuestion("Do you want to play again?");
	} while (playAgain);
}
//------------------------------------------------------------------------------

#include "masterVisual.h"

void addGuess(MastermindWindow &mwin, const string code, const char startLetter)
{
	mwin.guesses.push_back({code, startLetter});
}

void addFeedback(MastermindWindow &mwin, const int correctPosition, const int correctCharacter)
{
	mwin.feedbacks.push_back({correctPosition, correctCharacter});
}

void MastermindWindow::drawCodeHider()
{
	if(code_hidden) {
		draw_rectangle(Point{padX, 3 * padY}, winW - size * padX, padY, Color::black);
	}
}

MastermindWindow::MastermindWindow(int x, int y, int w, int h, int size, const string &title) 
: AnimationWindow(x, y, w, h, title),
guessBtn{upperLeftCornerBtn.x, upperLeftCornerBtn.y, btnW, btnH, "Add"},
guess{upperLeftCornerInBox.x, upperLeftCornerInBox.y, inBoxW, inBoxH, "Guess"},
size(size)
{
	add(guess);
	add(guessBtn);
	guessBtn.callback(cb_guess, this);
};

string MastermindWindow::wait_for_guess()
{
	while (!button_pressed && !should_close())
	{
		for(int guessIndex = 0; guessIndex < static_cast<int>(guesses.size()); guessIndex++) {
			// Legger til et gjett i grafikkvinduet i form av fargede rektangler.
			// xPos initialiseres likt hver gang denne funksjonen kalles, mens yPos er avhengig av round,
			// slik at gjetningene vises under hverandre.
			Guess guess = guesses.at(guessIndex);
			int xPos = padX;
			const int yPos = 3 * padY + 2 * padY * guessIndex;
			for (int i = 0; i < size; i++)
			{
				draw_rectangle(Point{xPos, yPos}, padX, padY, Color{guess.code[i] - guess.startLetter + 1});
				xPos += 2 * padX;
			}
		}

		for(int feedbackIndex = 0; feedbackIndex < static_cast<int>(feedbacks.size()); feedbackIndex++) {
			Feedback feedback = feedbacks.at(feedbackIndex);
			int xPos = 9 * padX + radCircle;
			const int yPos = 3.5 * padY + 2 * padY * (feedbackIndex + 1);
			for (int i = 0; i < size; i++)
			{
				Color indicatorColour = Color::gray;
				if (i < feedback.correctPosition)
				{
					indicatorColour = Color::black;
				}
				else if (i < (feedback.correctPosition + std::max<int>(0, feedback.correctCharacter - feedback.correctPosition)))
				{
					indicatorColour = Color::white;;
				}
				draw_circle(Point{xPos, yPos}, radCircle, indicatorColour);
			
				xPos += 2 * radCircle;
			}
		}

		// Should be drawn last as it has to be on top
		drawCodeHider();

		next_frame();
	}
	button_pressed = false;
	string newGuess = guess.value();
	guess.value(0);
	return newGuess;
}

string MastermindWindow::getInput(unsigned int n, char lower, char upper)
{
	bool validInput = false;
	string guess;
	while (!validInput && !should_close())
	{
		guess.clear();
		string input = wait_for_guess();
		if (input.size() == n)
		{
			for (unsigned int i = 0; i < n; i++)
			{
				char ch = input.at(i);
				if (isalpha(ch) && toupper(ch) <= upper && lower <= toupper(ch))
				{
					guess += toupper(ch);
				}
				else
					break;
			}
		}
		if (guess.size() == n)
		{
			validInput = true;
		}
		else
		{
			cout << "Invalid input guess again" << endl;
		}
	}
	return guess;
}

void MastermindWindow::setCodeHidden(bool hidden) {
	code_hidden = hidden;
}

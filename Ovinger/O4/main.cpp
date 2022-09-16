#include "std_lib_facilities.h"
#include "tests.h"
#include "utilities.h"
#include "mastermind.h"

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	Student maia;
	maia.name = "Maia";
	maia.studyProgram = "BFY";
	maia.age = 21;

	playMastermind();


	keep_window_open();
}


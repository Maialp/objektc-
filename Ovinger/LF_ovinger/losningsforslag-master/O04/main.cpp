
#include "std_lib_facilities.h"
#include "mastermind.h"
#include "tests.h"

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	
	testCallByValue();
	testCallByReference();

	testStudentStruct();
	
	testString();

	//playMastermindWithoutGraphics();

	playMastermind();
}

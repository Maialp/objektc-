#include "std_lib_facilities.h"
#include "cannonball.h"
#include "utilities.h"

void testDeviation(double compareOperand, double toOperand, double maxError, string name);

int main()
{
	playTargetPractice();

	keep_window_open();
}

void testDeviation(double compareOperand, double toOperand, double maxError, string name){
	double diff = abs(compareOperand - toOperand); 
	if(diff <= maxError){
		cout << name << " er tilnærmet lik " << toOperand << '\n';
	}
	else {
		cout << name << " er IKKE tilnærmet lik " << toOperand << '\n';
	}	
}


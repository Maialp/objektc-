#include "utilities.h"
#include "std_lib_facilities.h"

int randomWithLimits(int lower, int upper)
// Resultatet av modulooperasjonen (i parentes) blir et tilfeldig tall i
// området [0, upper - lower]. Ved å legge til (+) lower, blir området [lower, upper].
{
	return lower + (rand() % (upper - lower + 1));
}

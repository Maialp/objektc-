#include "std_lib_facilities.h"
#include "file.h"
#include "emnekatalog.h"
#include "temps.h"

//------------------------------------------------------------------------------'

int main()
{
	CourseCatalog emner; 
	emner.addCourse("TDT4102", "Prosdedyre- og objektorientert programmering");
	emner.addCourse("TDT4110", "Informasjonsteknologi grunnkurs");
	emner.addCourse("TMA4100", "Matematikk 1");

	
	vector<Temps> tempsVec  = readTemps("temperatures.txt");
	tempStats(tempsVec);

	keep_window_open();
}

//------------------------------------------------------------------------------

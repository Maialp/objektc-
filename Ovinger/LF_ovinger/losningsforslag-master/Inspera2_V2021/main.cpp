#include "case.h"
#include "file.h"
#include "decoding.h"
#include "case_gui.h"

int main(){
    // width, height and startPoint are for making a SearchWindow (gui)
    constexpr int width{800};
	constexpr int height{700};
	Point startPoint{100,100};

    //test you code here:
    //start test: (this is not part of the assignment/grading)
	Person undass{"Kaptein", "Undass", 314};
	Suspect f{"Fanny", "Skirbekk", 24};
	Suspect h{"Hakon", "Haugann", 24};
	Case tdt4102{"Pirat-mysteriet", TypeOfCase::robbery, 600, &undass};
	tdt4102.addSuspect(&f);
	tdt4102.addSuspect(&h);
	tdt4102.setDescription("Kaptein Undass var ute med skuta si da den ble overfalt av pirater. Piratene stjal kaffe og kanelboller.");
	tdt4102.addClue("En istykkerskutt skute");
	tdt4102.addClue("En halv kanelbolle pa dekk som piratene trolig mistet");
	tdt4102.addClue("Hakon drakk en kopp kaffe da jeg traff ham");
	tdt4102.addClue("Piratene pratet om C++ da de robbet skipet");
	
    cout << tdt4102;
    
    SearchWindow searchP{startPoint, width, height, "Case-GUI", tdt4102.getCases()};
    //end test    
	return gui_main();
}
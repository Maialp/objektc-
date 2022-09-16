#include "file.h"
#include "decoding.h"
#include "case_gui.h"

int main(){
    // width, height and startPoint are for making a SearchWindow (gui)
    constexpr int width{800};
	constexpr int height{700};
	Point startPoint{100,100};

    //test you code here:
    Person maia{"Maia", "Pettersen", 22};
    Case case1{"Den forsvunnede diamant", TypeOfCase::kidnapping, 300, &maia};

    //SearchWindow sw{startPoint, width, height, "Search Window",case1.getCases()};

    decoding("secret_message.txt", "solved_secret.txt");
    
	return gui_main();
}
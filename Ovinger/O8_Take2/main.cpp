
#include "std_lib_facilities.h"
#include "meetingWindow.h"

int main()
{
	Car car1{4};
	Car car2{2};
	Car car3{6};
	Car car4{1};

	const Person maia{"Maia L. Pettersen", "maialapidus@gmail.com", &car2};
	const Person per{"Per Hagen", "personmail@hotmail.com", &car1};
	const Person knud{"Knud Knudsen","nynorskjatakk@nynorsk.no"};
	const Person line{"Line Linesen", "line@mail.no", &car3};
	const Person frank{"Frank Estein", "esteinfrank@mail.no"};
	const Person anne{"Anne Panne", "a.panne@gmail.com", &car4};

	Meeting viktig{4, 1700, 1730, Campus::Trondheim, "Diskutering av viktige avgjørelser", &anne};
	viktig.addParticipant(&maia);
	viktig.addParticipant(&per);
	viktig.addParticipant(&knud);

	Meeting pizza{4,1800,2000,Campus::Trondheim,"Pizza og film", &maia};
	pizza.addParticipant(&per);
	pizza.addParticipant(&line);
	pizza.addParticipant(&frank);
	pizza.addParticipant(&knud);


	Point xy{300,200};
	int height = 600;
	int width = 400;
	MeetingWindow mw{xy, width, height,"My GUI"};
	gui_main();

	//cout << '\n'<<viktig << "\n\n";
	//cout << '\n'<<pizza << "\n\n";
	//cout<<maia<<'\n'<<per<<'\n'<<knud<<'\n';

	//keep_window_open();
}



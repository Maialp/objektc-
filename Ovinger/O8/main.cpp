#include "std_lib_facilities.h"
#include "car.h"
#include "meeting.h"
#include "meetingWindow.h"


int main()
{
	Car c{4};
	Car d{2};
	Person maia{"Maia", "maia@gmail.com", &c};
	Person trym("Trym", "trym@hotmail.com");
	Person catty("Catarina", "cats@bingmail.com", &d);
	Person silje("Silje", "siljesinmail@mail.no");
	
	Meeting m{4, 1300, 1345, Campus::Trondheim, "Superviktig møte", &trym};
	m.addParticipants(&maia);
	m.addParticipants(&silje);
	
	Meeting n{4, 1330, 1440, Campus::Trondheim, "Meget viktig møte", &catty};
	vector<const Person*> drivers = n.findPotentialCoDriving();
	for (const Person* p : drivers){
		cout << *p<< '\n'; 
	} 

	/* static constexpr int pad = 45; 
	static constexpr int btnW = 100; 
	static constexpr int btnH = 50; 
	static constexpr int fieldW = 250; 
	static constexpr int fieldH = 25; 
	static constexpr int fieldPad = 100; 
	static constexpr int windowW = 2*fieldPad+fieldW+btnW+pad;
	static constexpr int windowH = 4*pad+2*fieldH+btnH;
	const string title = "Meeting";

	Point start = Point{100,100};

	MeetingWindow mWin{start, windowW , windowH, title};
	gui_main();
	mWin.printPeople(); */
}
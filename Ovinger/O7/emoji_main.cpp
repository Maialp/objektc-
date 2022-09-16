#include "Simple_window.h"
#include "Emoji.h"

#include "std_lib_facilities.h"
#include "animal.h"
#include "Graph.h"

// Size of window and emoji radius
constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emojiRadius = 50;
Point emojiOne = Point{2*emojiRadius,2*emojiRadius};
Point emojiTwo = Point{5*emojiRadius, 2*emojiRadius};
Point emojiThree = Point{8*emojiRadius, 2*emojiRadius};
Point emojiFour = Point{11*emojiRadius, 2*emojiRadius};
Point emojiFive = Point{14*emojiRadius, 2*emojiRadius};

int main()
{
	using namespace Graph_lib;

	vector<unique_ptr<Animal>> animals; 
	animals.emplace_back(new Cat{"Pus", 2});
	animals.emplace_back(new Dog{"Faro", 11});

	for (int i = 0; i < animals.size(); ++i) {
        cout << animals[i]->toString() << '\n';
    }

	//Vector_ref<Animal> animalVec; 
	//Dog faro("Faro", 10);
	//Cat pus("Pus", 2);
	//animalVec.push_back(faro);
	//animalVec.push_back(pus);

	//for(int i = 0; i < animalVec.size();++i){
	//	cout << animalVec[i].toString() << endl;
	//}


	const Point tl{100, 100};
	const string win_label{"Emoji factory"};
	Simple_window win{tl, xmax, ymax, win_label};


	SmilingFace smile(emojiOne, emojiRadius);
	smile.attach_to(win);

	SadFace sad(emojiTwo, emojiRadius);
	sad.attach_to(win);

	AngryFace angry(emojiThree, emojiRadius);
	angry.attach_to(win);

	SurprizedFace wow(emojiFour, emojiRadius);
	wow.attach_to(win);

	HappyFace happy(emojiFive, emojiRadius);
	happy.attach_to(win);

	win.wait_for_button();


}

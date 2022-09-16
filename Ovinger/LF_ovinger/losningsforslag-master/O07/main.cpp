#include "Simple_window.h"
#include "Emoji.h"
#include "Animal.h"

// Definer størrelse på vindu og emoji
constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int emojiRadius = 50;

// Fest alle emojier i en Vector_ref<Emoji> - en vektor som konseptuelt holder referanser
// til Emoji-objekter - til et Window win.
void draw_emojis(Vector_ref<Emoji>& emojis, Graph_lib::Window& win)
{
	for (int i = 0; i < emojis.size(); ++i)
	{
		emojis[i].attach_to(win);
	}

	// Alternativt, med iteratorer:
	// for (auto it = emojis.begin(); it < emojis.end(); ++it)
	// {
	// 	(*it)->attach_to(win); // Bruker -> siden Vector_ref holder pekere under panseret
	// }

	// Alternativt, med range-for
	// for (auto e : emojis) {
	// 	e->attach_to(win); // Bruker -> siden Vector_ref holder pekere under panseret
	// }
}

int main()
{
	testAnimal();

	// Introduserer navnerom for grafikkbiblioteket
	using namespace Graph_lib;

	const Point tl{100, 100};
	const string win_label{"Emoji factory"};
	Simple_window win{tl, xmax, ymax, win_label};

	SmilingFace   smiley    { Point {xmax / 2 - emojiRadius, ymax / 2 - emojiRadius}, emojiRadius};
	SadFace       sad       { Point {xmax / 2 + emojiRadius, ymax / 2 - emojiRadius}, emojiRadius};
	SurprisedFace surprised { Point {xmax / 2 - emojiRadius, ymax / 2 + emojiRadius}, emojiRadius};
	AngryFace     angry     { Point {xmax / 2 + emojiRadius, ymax / 2 + emojiRadius}, emojiRadius};
	NeutralFace   neutral   { Point {xmax / 2 + 3 * emojiRadius, ymax / 2 - emojiRadius}, emojiRadius};
	WinkFace      wink      { Point {xmax / 2 + 3 * emojiRadius, ymax / 2 + emojiRadius}, emojiRadius};

	Vector_ref<Emoji> es;
	es.push_back(smiley);
	es.push_back(sad);
	es.push_back(surprised);
	es.push_back(angry);
	es.push_back(neutral);
	es.push_back(wink);
	draw_emojis(es, win);

	win.wait_for_button();
}

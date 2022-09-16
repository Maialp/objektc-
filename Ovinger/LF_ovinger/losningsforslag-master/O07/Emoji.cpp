#include "Emoji.h"

// Et gult, tomt ansikt.
Face::Face(Point c, int r) : face{c, r}
{
	face.set_fill_color(Color::yellow);
}

void Face::attach_to(Graph_lib::Window& win)
{
	win.attach(face);
}

// Et ansikt med to øyne.
EmptyFace::EmptyFace(Point c, int r)
	: Face{c, r},
	  leftEye{Point{c.x - 10, c.y - 5}, 10},
	  rightEye{Point{c.x + 10, c.y - 5}, 10}

{
	leftEye.set_fill_color(Color::green);
	rightEye.set_fill_color(Color::green);
}

void EmptyFace::attach_to(Graph_lib::Window& win)
{
	Face::attach_to(win);
	win.attach(leftEye);
	win.attach(rightEye);
}

// Et klassisk smilefjes, som arver fra EmptyFace
SmilingFace::SmilingFace(Point c, int r)
	: EmptyFace{c, r},
	  mouth{Point{c.x, c.y + 10}, 60, 40, 180, 360}
{
	mouth.set_color(Color::black);
}

void SmilingFace::attach_to(Graph_lib::Window& win)
{
	EmptyFace::attach_to(win);
	win.attach(mouth);
}

// Et overasket ansikt, som arver fra SmilingFace. mouth tegnes helt rundt,
// og er forskjøvet litt fra midten.
SurprisedFace::SurprisedFace(Point c, int r) : SmilingFace{c, r}
{
	mouth.set_start(0);
	mouth.seth(20);
	mouth.move(0, 20);
}

// Et trist ansikt, som arver fra EmptyFace.
SadFace::SadFace(Point c, int r)
	: EmptyFace{c, r},
	  mouth{Point{c.x, c.y + 30}, 60, 40, 0, 180}
{
	mouth.set_color(Color::blue);
}

void SadFace::attach_to(Graph_lib::Window& win)
{
	EmptyFace::attach_to(win);
	win.attach(mouth);
}

// Sint ansikt med firkantmunn og synlige tenner.
AngryFace::AngryFace(Point c, int r)
	: EmptyFace{c, r},
	  mouth{Point{c.x - 60 / 2, c.y + 10}, 60, 20},
	  leftBrow{Point{c.x - 20, c.y - 20}, Point{c.x - 5, c.y - 10}},
	  rightBrow{Point{c.x + 20, c.y - 20}, Point{c.x + 5, c.y - 10}}
{
	for (int i = -25; i <= 25; i += 10) {
		teeth.add(Point{c.x - i, mouth.point(0).y},
				  Point{c.x - i, mouth.point(0).y + 19});
	}

	leftBrow.set_style(Line_style{Line_style::solid, 2});
	rightBrow.set_style(Line_style{Line_style::solid, 2});

	mouth.set_color(Color::black);
	teeth.set_color(Color::black);
	leftBrow.set_color(Color::black);
	rightBrow.set_color(Color::black);
}

void AngryFace::attach_to(Graph_lib::Window& win)
{
	EmptyFace::attach_to(win);
	win.attach(leftBrow);
	win.attach(rightBrow);
	win.attach(teeth);
	win.attach(mouth);
}

// Et ansikt med et nøytralt utseende - rettlinjet munn.
NeutralFace::NeutralFace(Point c, int r)
	: EmptyFace{c, r},
	  mouth{Point{c.x - 30, c.y + 10}, Point{c.x + 30, c.y + 10}}
{
	mouth.set_color(Color::black);
}

void NeutralFace::attach_to(Graph_lib::Window& win)
{
	EmptyFace::attach_to(win);
}

// Et ansikt som ligner på SmilingFace med et blunkende høyreøye (160 deg Arc).
WinkFace::WinkFace(Point c, int r)
	: Face{c, r},
	  leftEye{Point{c.x - 10, c.y - 5}, 10},
	  rightEye{Point{c.x + 15, c.y}, 20, 20, 0, 160},
	  mouth{Point{c.x, c.y + 10}, 60, 40, 180, 360}
{
	leftEye.set_fill_color(Color::green);
	rightEye.set_style(Line_style{Line_style::solid, 3});

	rightEye.set_color(Color::black);
	mouth.set_color(Color::red);
}

void WinkFace::attach_to(Graph_lib::Window& win)
{
	Face::attach_to(win);
	win.attach(leftEye);
	win.attach(rightEye);
	win.attach(mouth);
}

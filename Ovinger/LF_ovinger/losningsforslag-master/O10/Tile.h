#pragma once
#include "GUI.h"

using namespace Graph_lib;

// De forskjellige tilstandene en Tile kan vaere i
enum class Cell { closed, open, flagged }; 

class Tile : public Button
{
	Cell state = Cell::closed;
	bool isMine = false;
	
	void set_label(string s) { label = s; redraw(); }
	void set_label_color(Color c) { pw->labelcolor(c.as_int()); redraw(); }
public:
	Tile(Point pos, int size, Graph_lib::Callback cb)
		 :Button(pos, size, size, "", cb) {}; 

	// Vis hvor mange miner det er i naborutene
	void setAdjMines(int n);

	void open();
	void reset();
	void flag();

	bool getIsMine() const { return isMine; };
	void setIsMine(bool isMine) { this->isMine = isMine; };
	Cell getState() const { return state; };
};

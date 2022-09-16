#pragma once
#include "GUI.h"
#include <string>


using namespace Graph_lib;

//De forskjellige tilstandene en Tile kan vaere i
enum class Cell { closed, open, flagged };

class Tile : public Button{
	Cell state = Cell::closed;
	void set_label(string s) { label = s; redraw(); }
	void set_label_color(Color c) { pw->labelcolor(c.as_int()); redraw();}
	bool isMine = false;
public:
	Tile(Point pos, int size, Graph_lib::Callback cb)
		:Button{pos, size, size, "", cb} {};
	
	Cell getState() const {return state; };
	bool getMine() const{return isMine;};
	void setMine(bool ifMine){isMine=ifMine;};
	void open();
	void flag();
	void setAdjMines(int n);
};

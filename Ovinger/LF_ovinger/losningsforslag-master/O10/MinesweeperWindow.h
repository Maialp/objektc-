#pragma once
#include "Window.h"
#include "Tile.h"

using namespace Graph_lib;
enum class MouseButton { left = FL_LEFT_MOUSE, right = FL_RIGHT_MOUSE }; 

// Minesweeper GUI
class MinesweeperWindow : public Graph_lib::Window
{
public:
	// storrelsen til hver tile
	static constexpr int cellSize = 30;

	MinesweeperWindow(Point xy, int width, int height, int mines, const string& title);
private:
	const int width;		// Bredde i antall tiles
	const int height;		// Hoyde i antall tiles
	const int mines;		// Antall miner
	int minesLeftUser;		// Antall miner spilleren har markeret at er igjen
	Vector_ref<Tile> tiles; // Vektor som inneholder alle tiles

	int remainingTiles; // Antall uaapnede tiles som gjenstaar for spillet er vunnet
	bool gameIsLost = false; 
	bool gameIsWon = false; 

	// hoyde og bredde i piksler
	int Height() const { return height * cellSize; } 
	int Width() const { return width * cellSize; }

	// Returnerer en vektor med nabotilene rundt en tile, der hver tile representeres som et punkt
	vector<Point> adjacentPoints(Point xy) const;
	// tell miner basert paa en liste tiles
	int countMines(vector<Point> coords) const;

	// Sjekker at et punkt er paa brettet
	bool inRange(Point xy) const { return xy.x >= 0 && xy.x< Width() && xy.y >= 0 && xy.y < Height(); }
	// Returnerer en tile gitt et punkt
	Tile& at(Point xy) { return tiles[xy.x / cellSize + (xy.y / cellSize) * width]; }
	const Tile& at(Point xy) const { return tiles[xy.x / cellSize + (xy.y / cellSize) * width]; }

	void openTile(Point xy);
	void flagTile(Point xy);

	// callback funksjoner for de tre knappene
	static void cb_quit(Address, Address pw) { reference_to<MinesweeperWindow>(pw).hide(); };
	static void cb_restart(Address, Address pw) { reference_to<MinesweeperWindow>(pw).restart(); }
	static void cb_click(Address, Address pw) { reference_to<MinesweeperWindow>(pw).click(); };
	void restart();
	void click();

	// Funksjoner som sjekker om spillet er vunnet eller tapt
	void gameLost();
	void gameWon();

	void addGameEndMenu(string s, Color c);

	// Medlemsvariabler knyttet til teksten overst i vinduet
	Text minesLeftText;
	Rectangle minesLeftBackground;

	// Medlemsvariabler knyttet til spillslutt
	Menu gameEndMenu;
	Rectangle gameEndBackGround;
	Text gameEndText;
};

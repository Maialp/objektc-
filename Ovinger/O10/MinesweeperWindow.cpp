#include "MinesweeperWindow.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctime>


MinesweeperWindow::MinesweeperWindow(Point xy, int width, int height, int mines, const string& title) :
	Graph_lib::Window{xy, width * cellSize, height*cellSize, title}, width{width}, height{height}, mines{mines}
	//Initialiser medlemsvariabler, bruker konstruktoren til Windowsklassen
{
	// Legg til alle tiles i vinduet
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			tiles.push_back(new Tile{ Point{j * cellSize, i * cellSize}, cellSize, cb_click });
			attach(tiles.back());
		}
	}

	srand((unsigned) time(0));
	//Legg til miner paa tilfeldige posisjoner
	int mineCount = 0;
	while(mineCount<mines){
		int mine = 1 + (rand()% (tiles.size()-1));
		if (!tiles[mine].getMine()){
			tiles[mine].setMine(true);
			mineCount++;
		}
	}

	// Fjern window reskalering
	resizable(nullptr);
	size_range(x_max(), y_max(), x_max(), y_max());
}


vector<Point> MinesweeperWindow::adjacentPoints(Point xy) const {
	vector<Point> points;
	for (int di = -1; di <= 1; ++di) {
		for (int dj = -1; dj <= 1; ++dj) {
			if (di == 0 && dj == 0) {
				continue;
			}

			Point neighbour{ xy.x + di * cellSize,xy.y + dj * cellSize };
			if (inRange(neighbour)) {
				points.push_back(neighbour);
			}
		}
	}

	return points;
}

void MinesweeperWindow::openTile(Point xy) {
	if (inRange(xy) && (at(xy).getState()==Cell::closed)){
		at(xy).open();
		if (!at(xy).getMine()){
			int adjMines = countMines(adjacentPoints(xy));
			if (adjMines > 0){
				at(xy).setAdjMines(adjMines);
			}
			else{
				for(Point p : adjacentPoints(xy)){
					openTile(p);
				}
			}
		}

		else if(at(xy).getMine()){
		cout << "You lost X(";
		}
	}

}

void MinesweeperWindow::flagTile(Point xy) {
	if (inRange(xy)){
		at(xy).flag();
	}
}

//Kaller openTile ved venstreklikk og flagTile ved hoyreklikk/trykke med to fingre paa mac
void MinesweeperWindow::click()
{
	Point xy{Fl::event_x(), Fl::event_y()};

	MouseButton mb = static_cast<MouseButton>(Fl::event_button());

	if (!inRange(xy)) {
		return;
	}

	switch (mb) {
	case MouseButton::left:
		openTile(xy);
		break;
	case MouseButton::right:
		flagTile(xy);
		break;
	}

	flush();
}

int MinesweeperWindow::countMines(vector<Point> coords) const{
	int mineCount = 0;
	for(Point p : coords){
		if (at(p).getMine()){
			mineCount++;
		}
	}
	return mineCount;
}
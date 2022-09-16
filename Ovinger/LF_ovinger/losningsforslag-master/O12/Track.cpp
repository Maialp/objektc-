#include "Track.h"
#include "utilities.h"
#include <FL/fl_draw.H>

Track::Track() : Fl_Widget(10, 10, 10, 10),
	spill{ "Sprites/spillSprite.jpeg" },
	boost{ "Sprites/boostSprite.jpeg" },
	peel{ "Sprites/peelSprite.jpeg" } 
{
	constexpr int nCircles = 30;

	for (size_t i = 0; i < nCircles; i++)	// Eksempelbane.
	{
		Obstacle toAdd = Obstacle::None;
		if (i % (nCircles / 4) == 0)
		{
			toAdd = Obstacle::Spill;
		}
		else if (i % (nCircles / 2) == 0)
		{
			toAdd = Obstacle::Peel;
		}
		else if (i % (nCircles / 3) == 0)
		{
			toAdd = Obstacle::Boost;
		}
		else
		{
			goals.push_back({
			screenWidth / 2 + screenWidth / 3.0 * cos(i * 2.0 / nCircles * 3.14),
			screenHeight / 2 - screenHeight / 3.0 * sin(i * 4.0 / nCircles * 3.14)
				});
			continue;
		}

		obstacles.push_back({
				  int(screenWidth / 2 + screenWidth / 3.0 * cos(i * 2.0 / nCircles * 3.14)),
				  int(screenHeight / 2 - screenHeight / 3.0 * sin(i * 4.0 / nCircles * 3.14)),
				  toAdd
			});
	}
}

void Track::draw()
{
	for (auto [x, y, type] : obstacles) // Teikner hindringar
	{
		switch (type)
		{
		case Obstacle::Spill:
			spill.draw(x - 25, y - 25);
			break;
		case Obstacle::Peel:
			peel.draw(x - 15, y - 15);
			break;
		case Obstacle::Boost:
			boost.draw(x - 10, y - 10);
			break;
		default:
			break;
		}
	}

	fl_color(FL_BLACK);

	for (auto[x, y] : goals) // Teikner maal
	{
		fl_begin_line();
		fl_circle(x, y, goalRadius);
		fl_end_line();
	}
}

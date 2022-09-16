#include "Vehicle.h"
#include <algorithm>

#include <FL/Fl.H>

#include "utilities.h"
#include "Track.h"

Vehicle::Vehicle(double x, double y, double angle, const Track& t) : 
	Fl_Widget(10, 10, 10, 10),
	physics{ x,y,angle }, // speed = 0
	track{ t },
	status{Obstacle::None}
{   }

void Vehicle::draw()
{
	// Sjekk om maal er treft
	auto [current_x, current_y] = track.getGoals()[currentGoal];
	if (circleCollision(physics.x - current_x, physics.y - current_y, vehicleRadius + goalRadius))
		currentGoal = (currentGoal+1) % track.getGoals().size();

	for (auto [x, y, type] : track.getObstacles()) // Behandle hindringar
	{
		if (circleCollision(x - physics.x, y - physics.y, vehicleRadius + (type == Obstacle::Boost ? boostRadius : type == Obstacle::Spill ? spillRadius : peelRadius)))
		{
			switch (type)
			{
			case Obstacle::Spill:
				physics.grip = 0.5;
				break;
			case Obstacle::Peel:
				if (status == Obstacle::Peel || physics.speed < 2.0)
					break;
				status = Obstacle::Peel;
				slideAngle = physics.angle;
				break;
			case Obstacle::Boost:
				physics.grip = 2;
				break;
			default:
				break;
			}
		}
	}

	auto [a_lin, a_ang] = steer();

	if (status == Obstacle::Peel)
	{
		physics.slide(slideAngle);
		if (physics.speed < 0.3)
			status = Obstacle::None;
	}
	else
	{
		physics.update(a_lin, a_ang);
	}

	// Hald Vehicle innanfor vindauget
	physics.x = std::min(std::max(vehicleRadius, physics.x), screenWidth - vehicleRadius);
	physics.y = std::min(std::max(vehicleRadius, physics.y), screenHeight - vehicleRadius);

	drawBody();
}

bool circleCollision(double delX, double delY, double sumR)
{
	return delX*delX + delY*delY <= sumR*sumR;
}

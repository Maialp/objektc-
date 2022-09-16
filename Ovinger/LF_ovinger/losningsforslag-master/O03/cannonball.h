#pragma once
#include "std_lib_facilities.h"

constexpr double pi = 3.14159265;
constexpr double gravity = 9.81;

// Del 1:
double acclY();

double velY(double initVelocityY, double time);

double posX(double initPosition, double initVelocity, double time);
double posY(double initPosition, double initVelocity, double time);

void printTime(double time);

double flightTime(double initVelocityY);

// Del 2:
double getUserInputTheta();
double getUserInputAbsVelocity();

double degToRad(double deg);

double getVelocityX(double theta, double absVelocity);
double getVelocityY(double theta, double absVelocity);
vector<double> getVelocityVector(double theta, double absVelocity);
double getDistanceTraveled(double velocityX, double velocityY);
double targetPractice(double distanceToTarget, double velocityX, double velocityY);

// Del 3:
void playTargetPractice();

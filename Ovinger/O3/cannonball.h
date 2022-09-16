#pragma once 

double acclY();     // Returenrer aksellerasjon i y-retning

double velY(double initVelocityY, double time); //Returnerer farten i y-retning

//Finner posisjonen i henholdsvis x-, og y-retning
double posX(double initPosition, double initVelocity, double time);
double posY(double initPosition, double initVelocity, double time);

void printTime(double time); //Printer time


//--------------DEL 2-------------------

double getUserInputTheta(); //Ber bruker om vinkel
double getUserInputAbsVelocity(); //Ber bruker om en absoluttfart
double degToRad(double deg); //Konverterer fra grader til radianer

//Gir farten i x-retn
double getVelocityX(double theta, double absVelocity); 
//Gir farten i y-retn 
double getVelocityY(double theta, double absVelocity);

//Lagrer fart i x- og y-retning i en vektor
vector<double> getVelocityVector(double theta, double absVelocity);

double getDistanceTraveled(double velocityX, double velocityY);

double targetPractice(double distanceToTarget, double  velocityX, double velocityY);
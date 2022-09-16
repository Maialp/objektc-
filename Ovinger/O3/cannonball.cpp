#include "std_lib_facilities.h"
#include "cannonball.h"

//a) 
double acclY(){
    double a_Y = -9.81;
    return a_Y;
}

//b) 
double velY(double initVelocityY, double time){
    double fartY = initVelocityY + (acclY() * time);
    return fartY;
}

//c) 
double posX(double initPosition, double initVelocity, double time){
    double posisjon = initPosition + (initVelocity*time);
    return posisjon;
}
double posY(double initPosition, double initVelocity, double time){
    double posisjon = initPosition + (initVelocity*time) + (acclY()*time*time*0.5);
    return posisjon;
}

//d) 
void printTime(double time){
    int hours = static_cast<int>(time/(60*60));
    time -= hours*60*60;
    int minutes = time/60;
    time -= minutes*60;
    
    cout << hours << " hours, "<< minutes << " minutes, and " << time << " seconds." <<'\n';
}

//e) 
double flightTime(double initVelocityY){
    double time = (-2)*(initVelocityY)/(acclY()); 
    return time;
}

//--------------DEL 2-------------------
//a) 
double getUserInputTheta(){
    double vinkel = 0; 
    cout << "Startvinkel: "; 
    cin >> vinkel; 
    return vinkel; 
}
double getUserInputAbsVelocity(){
    double absVelocity = 0; 
    cout << "Absolutt starthastighet: ";
    cin >> absVelocity; 
    return absVelocity;
}
double degToRad(double deg){
    double rad = deg*0.0174533; 
    return rad;
}
double getVelocityX(double theta, double absVelocity){
    double fartX = absVelocity*cos(theta);
    return fartX;
}
double getVelocityY(double theta, double absVelocity){
    double fartY = absVelocity*sin(theta);
    return fartY;
}
vector<double> getVelocityVector(double theta, double absVelocity){
    vector<double> velXY = {getVelocityX(theta, absVelocity), getVelocityY(theta, absVelocity)};
    return velXY;
}

//b) 
double getDistanceTraveled(double velocityX, double velocityY){
    double avstand = flightTime(velocityY)*velocityX;
    return avstand;
}
double targetPractice(double distanceToTarget, double  velocityX, double velocityY){
    double landingpoint = getDistanceTraveled(velocityX, velocityY);
    double diffrance = distanceToTarget-landingpoint;
    return diffrance;
}
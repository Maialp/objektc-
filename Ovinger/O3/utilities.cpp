#include "std_lib_facilities.h"
#include "cannonball.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

//a) 
//genererer tilfeldig tall:
int randomWithLimits(int rand_min, int rand_max){
    srand(static_cast<unsigned int>(time(nullptr)));
    int tilfeldig_tall = rand()%(rand_max-rand_min) + rand_min;
    return tilfeldig_tall;
}

void playTargetPractice(){
    int blink = randomWithLimits(100, 1000);
    cout << "Blinken er plassert " << blink << " meter unna startpunktet. Klarer du å treffe?\n";
    
    for(int i = 0; i < 10; i++){
        double theta = degToRad(getUserInputTheta());
        double initVel = getUserInputAbsVelocity();

        //velocity vector: 
        vector<double> velVec = getVelocityVector(theta, initVel);
        //Distanse fra mål
        double diff = targetPractice(blink, velVec[0], velVec[1]);

        if (abs(diff) <= 5){
            cout << "Gratulerer! Du traff blinken!\n";
            break;
        }
        else {
            if (diff < 0){
                cout << "Ballen landet " << abs(diff) << " for langt!\nPrøv igjen, du har " << 9-i << " liv igjen.\n";
            }
            else {
                cout << "Ballen landet " << abs(diff) << " for kort!\nPrøv igjen, du har " << 9-i << " liv igjen.\n";

            }
        }

        cout << '\n';
        
        if (i == 9){
            cout << "Du har brukt opp alle livene dine: Game over...\n";
        }
    }
}
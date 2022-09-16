#include "Vehicle.h"

Vehicle::Vehicle(double x, double y, double angle): Fl_Widget(10,10,10,10) {
    state.x = x; 
    state.y = y; 
    state.angle = angle;
    }

void Vehicle::draw(){
    move = steer();
    state.update(move.first, move.second);
    if(state.x-vehicleRadius <= 0){
        state.x = vehicleRadius;
    }
    if (state.y - vehicleRadius <=0){
        state.y = vehicleRadius;
    }
    if(state.x + vehicleRadius > screenWidth){
        state.x = screenWidth - vehicleRadius;
    }
    if(state.y + vehicleRadius > screenHeight){
        state.y = screenHeight - vehicleRadius;
    }
    drawBody();
}


PlayerVehicle::PlayerVehicle(double x, double y, double angle) : Vehicle(x,y,angle) {
    draw();
}

void PlayerVehicle::drawBody() const {
    fl_color(FL_GREEN);
    fl_begin_line();
    fl_pie(state.x,state.y,vehicleRadius,vehicleRadius,0,360);
    fl_end_line();
    fl_color(FL_DARK_BLUE);
    fl_begin_line();
    fl_line_style(0,5);
    fl_line(state.x+ vehicleRadius/2,state.y+ vehicleRadius/2, state.x + vehicleRadius*cos(state.angle), state.y + vehicleRadius*sin(state.angle));
    fl_end_line();
}

std::pair<double,double> PlayerVehicle::steer() const {
    std::pair<double,double> change;
    if (Fl::event_key(FL_Left)){
        change.first = -1;
        change.second = 0;
    }
    else if (Fl::event_key(FL_Right)){
        change.first = 1;
        change.second = 0;
    }
    else if (Fl::event_key(FL_Up)){
        change.first = 0;
        change.second = -1;
    }
    else if (Fl::event_key(FL_Down)){
        change.first = 0;
        change.second = 1;
    }
    else{
        change.first = 0;
        change.second = 0;
    }
    //return {change.second,change.first};
    return change;
}
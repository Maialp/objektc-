#include "Emoji.h"

void Face::attach_to(Graph_lib::Window& win){
    win.attach(face);
}
EmptyFace::EmptyFace(Point c, int r): Face{c,r}, eyeLeft{Point{c.x+14,c.y-r/4}, r/4}, eyeRight{Point{c.x-14,c.y-r/4}, r/4}{
    eyeLeft.set_color(Color::white);
    eyeRight.set_color(Color::white);
    eyeLeft.set_fill_color(Color::black);
    eyeRight.set_fill_color(Color::black);
}

void EmptyFace::attach_to(Graph_lib::Window& win){
    Face::attach_to(win);
    win.attach(eyeRight);
    win.attach(eyeLeft);
}

SmilingFace::SmilingFace(Point c, int r): EmptyFace{c,r}, smile{Point{c.x, c.y+r/4}, 3*r/4, r/2, 180, 360}
{
    smile.set_color(Color::black);
}

void SmilingFace::attach_to(Graph_lib::Window& win){
    EmptyFace::attach_to(win);
    win.attach(smile);
}

SadFace::SadFace(Point c, int r) : EmptyFace{c,r}, sadMouth{Point{c.x, c.y + r/2}, r/2, r/2, 0, 180}
{
    sadMouth.set_color(Color::black);
}
void SadFace::attach_to(Graph_lib::Window& win){
    EmptyFace::attach_to(win);
    win.attach(sadMouth);
}

AngryFace::AngryFace(Point c, int r) : SadFace{c, r},leftBrow{Line{Point{c.x -5, c.y-r/2}, Point{c.x-r/2,c.y-3*r/4}}}, 
    rightBrow{Line{Point{c.x +5, c.y-r/2}, Point{c.x+r/2,c.y-3*r/4}}}
{
    leftBrow.set_color(Color::black);
    rightBrow.set_color(Color::black);
}
void AngryFace::attach_to(Graph_lib::Window& win){
    SadFace::attach_to(win);
    win.attach(leftBrow);
    win.attach(rightBrow);
}

SurprizedFace::SurprizedFace(Point c, int r) : EmptyFace{c,r}, mouth{Point{c.x, c.y+3*r/10}, 35*r/100}{
    mouth.set_fill_color(Color::dark_red);
    mouth.set_color(Color::dark_red); 
}

void SurprizedFace::attach_to(Graph_lib::Window& win){
    EmptyFace::attach_to(win);
    win.attach(mouth);
}

HappyFace::HappyFace(Point c, int r) : SurprizedFace{c,r}, coverMouth{Point{c.x-6*r/10, c.y+r/2-60*r/100}, 3*r/2, 4*r/10}
{
    mouth.set_fill_color(Color::white);
    coverMouth.set_color(Color::yellow);
    coverMouth.set_fill_color(Color::yellow);
}

void HappyFace::attach_to(Graph_lib::Window& win){
    SurprizedFace::attach_to(win);
    win.attach(coverMouth);
}
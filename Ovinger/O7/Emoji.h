#pragma once

// Include Graph_lib library files that holds declarations needed for Window,
// and Shape derivatives.
#include "Graph.h"
#include "GUI.h"



using namespace Graph_lib;

// An abstract class. Concrete classes derived from this base class
// has to implement the member function attach_to().
class Emoji
{
public:
	// Disable copying. Disable slicing, etc.
	Emoji(const Emoji&) = delete;
	Emoji& operator=(const Emoji&) = delete;

	// Deleting the copy constructor also deletes the default constructor.
	// Emoji needs a default constructor.
	Emoji() {}
	// Emoji() = default; // is an alternative way of achieving the same.

	// The pure virtual function that has to be overriden for a deriving class
	// to be instantiable. Every class deriving from Emoji is supposed to
	// attach all its Shapes to a window. This makes the class abstract.
	virtual void attach_to(Graph_lib::Window&) = 0;

	// Relevant because Vector_ref can own Emojis and automatically cleans up.
	// Subject will be visited later in the course.
	virtual ~Emoji() {}
};

class Face : public Emoji{
	protected:
		Circle face;  
	public:
		virtual void attach_to(Graph_lib::Window& win) override = 0;
		Face(Point c, int r) : face(c, r) {face.set_fill_color(Color::yellow);face.set_color(Color::black);};  //Lager runding og fyller det med gult
};

class EmptyFace : public Face{
	protected:
		Circle eyeLeft; 
		Circle eyeRight;
	public:
		EmptyFace(Point c, int r);
		virtual void attach_to(Graph_lib::Window& win); 
};

class SmilingFace : public EmptyFace{
	protected:
		Arc smile; 
	public:
		SmilingFace(Point c, int r);
		void attach_to(Graph_lib::Window& win);
};
class SadFace : public EmptyFace{
	protected: 
		Arc sadMouth;
	public: 
		SadFace(Point c, int r);
		virtual void attach_to(Graph_lib::Window& win);
};

class AngryFace : public SadFace{
	protected:
		Line leftBrow;
		Line rightBrow;
	public:
		AngryFace(Point c, int r);
		void attach_to(Graph_lib::Window& win);
};

class SurprizedFace : public EmptyFace{
	protected:
		Circle mouth;
	public:
		SurprizedFace(Point c, int r);
		virtual void attach_to(Graph_lib::Window& win);
};

class HappyFace : public SurprizedFace{
	protected:
		Rectangle coverMouth;
	public:
		HappyFace(Point c, int r);
		void attach_to(Graph_lib::Window& win);
};

#pragma once
#include "Graph.h"
#include "GUI.h"

using namespace Graph_lib;

// Abstrakt klasse. Arvende konkrete klasser må implementere funksjonen attach_to()
// som en måte å feste Shape-objekter til vinduet de skal bli vist i.
class Emoji
{
public:
	// Sletter kopikonstruktør og tilordningsoperator fordi den allerede
	// er slettet for klassen Shape.
	Emoji(const Emoji&) = delete;
	Emoji& operator=(const Emoji&) = delete;

	// Når vi sletter kopikonstruktøren blir også defaultkonstruktøren slettet.
	// Emoji-klassen trenger en defaultkonstruktør.
	Emoji() {}
	// Emoji() = default; // Alternativ

	// En "pure virtual" funksjon, som må overstyres av arvende klasser
	// for å bli konkret. Alle klasser som arver fra Emoji skal feste
	// alle dens Shape-objekter til et vindu. Det gjør denne klassen abstrakt.
	virtual void attach_to(Graph_lib::Window&) = 0;

	// Relevant fordui Vector_ref kan eie Emoji-er og automatisk rydde opp.
	// Temaet vil bli tatt opp senere i kurset.
	virtual ~Emoji() {}
	// virtual ~Emoji() = default; // Alternativ som gir samme resultat
};

// Et gult, tomt ansikt.
// En abstrakt klasse.
class Face : public Emoji
{
public:
	Face(Point c, int r);
	void attach_to(Graph_lib::Window& win) override = 0;

private:
	Circle face;
};

// Et ansikt med to øyne.
class EmptyFace : public Face
{
public:
	EmptyFace(Point c, int r);
	void attach_to(Graph_lib::Window& win) override;

private:
	Circle leftEye;
	Circle rightEye;
};

// Et klassisk smilefjes, som arver fra EmptyFace.
class SmilingFace : public EmptyFace
{
public:
	SmilingFace(Point c, int r);
	void attach_to(Graph_lib::Window& win) override;

protected:
	// Protected tilgang til mouth. Løsningsforslaget bruker at
	// SurpricedFace, som her arver fra SmilingFace, har samme type
	// munn av typen Arc, bare at ellipsen tegnes helt rundt ved
	// å endre start og sluttvinkel.
	Arc mouth;
};

// Et overasket ansikt, som arver fra SmilingFace. Munnen tegnes helt rundt,
// og er forskjøvet litt fra midten.
// NB: dette er ment som et eksempel på dårlig kode!
class SurprisedFace : public SmilingFace
{
public:
	SurprisedFace(Point c, int r);
	// Det kan virke fornuftig å gjenbruke mouth fra SmilingFace-klassen,
	// som i dette eksempelet, da man slipper å definere attach_to()
	// eller deklarere mouth på nytt. Men det å arve fra en konkret klasse
	// kun for å unngå duplisering av kode er sjelden en god idé. I
	// dette tilfellet er problemet at det skaper en avhengighet mellom
	// SurprisedFace og SmilingFace. Hvis f.eks. SmilingFace plutselig
	// også får "smilende øyne" eller munnen endres litt, så vil dette
	// også endre på SurprisedFace-klassen. Man kan også prøve å tenke
	// på det intuitivt og si: "SurprisedFace er en type SmilingFace",
	// eller "SurprisedFace er en spesialisering av SmilingFace", og
	// konkludere med at dette ikke gir mye mening her.
};

// Et trist ansikt, som arver fra EmptyFace.
class SadFace : public EmptyFace
{
public:
	SadFace(Point c, int r);
	void attach_to(Graph_lib::Window& win) override;
	// Her arver vi fra EmptyFace. Det betyr at om vi endrer på den triste
	// munnen, så vil ikke dette påvirke andre klasser. Merk at dersom vi
	// hadde ønsket egne "triste øyne", så kunne det vært lurt å arve
	// direkte fra Face for å unngå avhengigheten til EmptyFace sine øyne.
	// Her er vi riktignok fornøyde med at SadFace har de samme øynene
	// som EmptyFace, og derfor er dette en fullgod løsning.
private:
	Arc mouth;
};

// Sint ansikt med firkantmunn og synlige tenner.
class AngryFace : public EmptyFace
{
public:
	AngryFace(Point c, int r);
	void attach_to(Graph_lib::Window& win) override;

private:
	Rectangle mouth;
	Lines teeth;
	Line leftBrow;
	Line rightBrow;
};

// Et ansikt med et nøytralt utseende - rettlinjet munn.
class NeutralFace : public EmptyFace
{
public:
	NeutralFace(Point c, int r);
	void attach_to(Graph_lib::Window& win) override;

private:
	Line mouth;
};

// Et ansikt som ligner på SmilingFace med et blunkende høyreøye (160 deg Arc).
class WinkFace : public Face
{
public:
	WinkFace(Point c, int r);
	void attach_to(Graph_lib::Window& win) override;

private:
	Circle leftEye;
	Arc rightEye;
	Arc mouth;
};

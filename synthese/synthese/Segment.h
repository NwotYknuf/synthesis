#pragma once
#include"Forme.h"
#include "Visitable.h"
#include "Vecteur2D.h"
#include <string>

using namespace std;

class Segment : public Forme, public Visitable{
private:
	Vecteur2D _deb;
	Vecteur2D _fin;

public:
	Segment();
	Segment(const string&, const Vecteur2D&, const Vecteur2D&);
	Segment(const string&, double, double, double, double);
	Segment(const Segment&);
	~Segment();

	const Vecteur2D& getDeb()const { return _deb; }
	const Vecteur2D& getFin()const { return _fin; }
	void setDeb(const Vecteur2D& v) { _deb = v; };
	void setFin(const Vecteur2D& v) { _fin = v; };

	Forme* clone()const;
	double aire() const;
	void affiche(ostream&)const;
	const string encoder()const;
	void accepte(Visiteur *);

	Forme* translation(const Vecteur2D &)const;
	Forme* rotation(const Vecteur2D &, double)const;
	Forme* echelle(const Vecteur2D &, double)const;

};


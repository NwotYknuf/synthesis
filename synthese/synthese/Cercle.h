#pragma once
#include "Vecteur2D.h"
#include "forme.h"
#include "Visitable.h"

class Visiteur;

class Cercle : public Forme, public Visitable {
private:
	Vecteur2D _centre;
	double _rayon;

public:
	Cercle();
	Cercle(string, double, double, double);
	Cercle(string, const Vecteur2D&, double);
	Cercle(const Cercle&);
	virtual ~Cercle();

	const Vecteur2D& getCentre()const { return _centre; }
	double getRayon()const { return _rayon; }
	void setPoint(const Vecteur2D &p) { _centre = p; }
	void setRayon(double d) { _rayon = d; }

	Forme* clone()const;
	double aire() const;
	void affiche(ostream&)const;
	void accepte(const Visiteur &);
};

#pragma once
#include "point.h"
#include "forme.h"
#include "Visitable.h"
#include "Visiteur.h"

class Cercle : public Forme, public Visitable{
private:
	Point _centre;
	double _rayon;

public:
	Cercle();
	Cercle(string, double, double, double);
	Cercle(string, const Point&, double);
	Cercle(const Cercle&);
	virtual ~Cercle();

	const Point& getCentre()const { return _centre; }
	double getRayon()const { return _rayon; }
	void setPoint(const Point &p) { _centre = p; }
	void setRayon(double d) { _rayon = d; }

	bool operator==(const Cercle &c);
	friend ostream& operator<<(ostream&, const Cercle&);

	void affiche(ostream&)const;
	void accepte(const Visiteur &);
};

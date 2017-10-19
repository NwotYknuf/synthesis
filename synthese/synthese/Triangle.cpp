#include "Triangle.h"
#include "Visiteur.h"
#include "point.h"

Triangle::Triangle(const string c, const Point &p1, const Point &p2, const Point &p3)
	: Forme(c){
	_p1 = p1;
	_p2 = p2;
	_p3 = p3;
}

void Triangle::accepte(const Visiteur &v) {
	v.visite(this);
}

void Triangle::affiche(ostream&os) {
	Forme::affiche(os);
	os << _p1 << _p2 << _p3;
}

Triangle :: ~Triangle() { };

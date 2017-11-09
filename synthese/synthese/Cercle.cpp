#pragma once
#include "Cercle.h"
#include "Visiteur.h"

const double PI = 3.14159265359;

Cercle::Cercle() : Forme(), _centre() {
	_rayon = 0;
}

Cercle::Cercle(string c, double x, double y, double rayon) : Forme(c), _centre(x, y) {
	_rayon = rayon;
}

Cercle::Cercle(string c, const Vecteur2D &p, double rayon) : Forme(c), _centre(p) {
	_rayon = rayon;
}

Cercle::Cercle(const Cercle &c) : Forme(c.getCouleur()), _centre(c._centre) {
	_rayon = c._rayon;
}

Cercle::~Cercle() { }

double Cercle::aire()const{
	return PI*_rayon*_rayon;
}

void Cercle::affiche(ostream&os)const {
	Forme::affiche(os);
	os << "	-centre : " << _centre << endl;
	os << "	-rayon : " << _rayon << endl;
}

void Cercle::accepte(const Visiteur &v) {
	v.visite(this);
}

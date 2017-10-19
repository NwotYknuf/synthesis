#pragma once
#include "Cercle.h"
#include "Visiteur.h"

Cercle::Cercle() : Forme(), _centre(){
	_rayon = 0;
}

Cercle::Cercle(string c, double x, double y, double rayon): Forme(c),_centre(x,y) {
	_rayon = rayon;
}

Cercle::Cercle(string c, const Point &p, double rayon) : Forme(c), _centre(p) {
	_rayon = rayon;
}

Cercle::Cercle(const Cercle &c): Forme(c.getCouleur()), _centre(c._centre) {
	_rayon = c._rayon;
}

Cercle::~Cercle() { }

bool Cercle::operator==(const Cercle &c){
	return _centre == c._centre && _rayon == c._rayon;
}

ostream& operator<<(ostream&os, const Cercle&c) {
	c.affiche(os);
	return os;
}

void Cercle::affiche(ostream&os)const {
	Forme::affiche(os);
	os << " centre : " << _centre << " rayon : " << _rayon;
}

void Cercle::accepte(const Visiteur &v)
{
	v.visite(this);
}


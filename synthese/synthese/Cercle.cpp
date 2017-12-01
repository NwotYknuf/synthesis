#pragma once
#include "Cercle.h"
#include "Visiteur.h"
#include <sstream>

using namespace std;

const double PI = 3.141592653589793238462643383279;

Cercle::Cercle() : Forme(), _centre() {
	_rayon = 0;
}

Cercle::Cercle(string c, double x, double y, double rayon) : Forme(c), _centre(x, y) {
	_rayon = rayon;
}

Cercle::Cercle(string c, const Vecteur2D &p, double rayon) : Forme(c), _centre(p) {
	_rayon = rayon;
}

Cercle::Cercle(const Cercle &c) : 
	Forme(c.getCouleur()), _centre(c._centre) {
	_rayon = c._rayon;
}

Cercle::~Cercle() { }

double Cercle::aire()const{
	return PI*_rayon*_rayon;
}

Forme* Cercle::clone()const {
	return new Cercle(*this);
}

void Cercle::affiche(ostream&os)const {
	os << "Cercle" << endl;
	Forme::affiche(os);
	os << "	-centre : " << _centre << endl;
	os << "	-rayon : " << _rayon << endl;
}

const string Cercle::encoder() const {
	ostringstream oss;
	oss << "cercle" << ","<< getCouleur() << "," << (int)_centre.getX() << "," << (int)_centre.getY() << "," << _rayon;
	return oss.str();
}

void Cercle::accepte(Visiteur *v) {
	v->visite(this);
}

Forme* Cercle::translation(const Vecteur2D & deplacement)const {
	Cercle* c = new Cercle(*this);
	c->_centre = _centre + deplacement;
	return c;
}

Forme* Cercle::rotation(const Vecteur2D & centre , double angle)const {
	Cercle* c = new Cercle(*this);
	double x1 = centre.getX();
	double y1 = centre.getY();
	double x2 = c->_centre.getX();
	double y2 = c->_centre.getY();
	
	c->_centre.setX((x2 - x1) * cos(angle) - (y2 - y1) * sin(angle) + x1);
	c->_centre.setY((x2 - x1)*sin(angle) + (y2 - y1)*cos(angle) + y1);

	return c;
}

Forme* Cercle::echelle(const Vecteur2D & centre, double facteur)const {
	Vecteur2D temp = _centre - centre;
	temp = temp * facteur;
	temp = temp + centre;

	return new Cercle(this->getCouleur(),temp, _rayon * fabs(facteur));
}

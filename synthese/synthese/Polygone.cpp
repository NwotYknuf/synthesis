#pragma once
#include"Polygone.h"
#include "Visiteur.h"
#include <sstream>

Polygone::Polygone() : Forme() { }

Polygone::Polygone(const string& couleur) : Forme(couleur) { }

Polygone::Polygone(const Polygone& p) : Forme(p.getCouleur()) {
	for (Triangle* t : p._triangles) {
		_triangles.push_back(new Triangle(*t));
	}
}

Polygone::~Polygone() { 
	for (Triangle* t : _triangles) {
		delete(t);
	}
}

void Polygone::setCouleur(const string& couleur) {
	Forme::setCouleur(couleur);

	for (Triangle* t : _triangles) {
		t->setCouleur(couleur);
	}

}

void Polygone::ajouteTriangle(const Triangle &t) {
	Triangle* temp = new Triangle(t);
	temp->setCouleur(this->getCouleur());
	_triangles.push_back(temp); 
}

Forme* Polygone::clone()const {
	return new Polygone(*this);
}

double Polygone::aire() const {
	double total = 0;
	for (Triangle* t : _triangles) {
		total += t->aire();
	}
	return total;
}

void Polygone::accepte(Visiteur*v) {
	v->visite(this);
}

const string Polygone::encoder()const {

	ostringstream oss;

	oss << "polygone," << getCouleur() << ",";

	for (Triangle* t : _triangles) {
		oss << t->encoder() << ";";
	}

	return oss.str();
}

void Polygone::affiche(ostream &o) const {
	o << "Triangle" << endl;
	Forme::affiche(o);
	o << "Liste des triangles : " << endl;
	for (Triangle* t : _triangles) {
		t->affiche(o);
	}
}

Forme* Polygone::translation(const Vecteur2D & deplacement)const {
	Polygone* p = new Polygone();
	p->setCouleur(getCouleur());

	for (Triangle* t : _triangles) {
		p->ajouteTriangle(*(Triangle*)t->translation(deplacement));
	}
	return p;
}

Forme* Polygone::rotation(const Vecteur2D & centre, double angle)const {
	Polygone* p = new Polygone();
	p->setCouleur(getCouleur());

	for (Triangle* t : _triangles) {
		p->ajouteTriangle(*(Triangle*)t->rotation(centre, angle));
	}
	return p;
}

Forme* Polygone::echelle(const Vecteur2D & centre, double ratio)const {
	Polygone* p = new Polygone();
	p->setCouleur(getCouleur());

	for (Triangle* t : _triangles) {
		p->ajouteTriangle(*(Triangle*)t->echelle(centre, ratio));
	}
	return p;
}

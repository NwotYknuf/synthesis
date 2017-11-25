#pragma once
#include"Quelconque.h"
#include "Visiteur.h"
#include <sstream>

Quelconque::Quelconque() : Forme() { }

Quelconque::Quelconque(const string& couleur) : Forme(couleur) { }

Quelconque::Quelconque(const Quelconque& q) : Forme(q.getCouleur()) {
	for (Triangle* t : q._triangles) {
		_triangles.push_back(new Triangle(*t));
	}
}

Quelconque::~Quelconque() { 
	for (Triangle* t : _triangles) {
		delete(t);
	}
}

void Quelconque::setCouleur(const string& couleur) {
	Forme::setCouleur(couleur);

	for (Triangle* t : _triangles) {
		t->setCouleur(couleur);
	}

}

void Quelconque::ajouteTriangle(const Triangle &t) {
	Triangle* temp = new Triangle(t);
	temp->setCouleur(this->getCouleur());
	_triangles.push_back(temp); 
}

Forme* Quelconque::clone()const {
	return new Quelconque(*this);
}

double Quelconque::aire() const {
	double total = 0;
	for (Triangle* t : _triangles) {
		total += t->aire();
	}
	return total;
}

void Quelconque::accepte(Visiteur*v) {
	v->visite(this);
}

const string& Quelconque::encoder()const {

	ostringstream oss;

	oss << "Quelquonque" << ",";

	for (Triangle* t : _triangles) {
		oss << t->encoder();
	}
	oss << "end" << "\r\n";

	return oss.str();
}

void Quelconque::affiche(ostream &o) const {
	o << "Triangle" << endl;
	Forme::affiche(o);
	o << "Liste des triangles : " << endl;
	for (Triangle* t : _triangles) {
		t->affiche(o);
	}
}

Forme* Quelconque::translation(const Vecteur2D & deplacement)const {
	Quelconque* q = new Quelconque(*this);
	for (Triangle* t : q->_triangles) {
		t = (Triangle*)(t->translation(deplacement));
	}
	return q;
}

Forme* Quelconque::rotation(const Vecteur2D & centre, double angle)const {
	Quelconque* q = new Quelconque(*this);
	for (Triangle* t : q->_triangles) {
		t = (Triangle*)(t->rotation(centre, angle));
	}
	return q;
}

Forme* Quelconque::echelle(const Vecteur2D & centre, double ration)const {
	Quelconque* q = new Quelconque(*this);
	for (Triangle* t : q->_triangles) {
		t = (Triangle*)(t->echelle(centre, ration));
	}
	return q;
}

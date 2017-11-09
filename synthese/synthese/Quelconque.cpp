#pragma once
#include"Quelconque.h"
#include "Visiteur.h"

Quelconque::Quelconque() : Forme() { }

Quelconque::Quelconque(string couleur) : Forme(couleur) { }

Quelconque::Quelconque(const Quelconque& q) : Forme(q.getCouleur()) {
	for (Triangle* t : q._triangles) {
		Triangle* temp = new Triangle(*t);
		temp->setCouleur(this->getCouleur());
		_triangles.push_back(temp);
	}
}

Quelconque::~Quelconque() { 
	for (Triangle* t : _triangles) {
		delete(t);
	}
}

void Quelconque::setCouleur(string couleur) {
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

double Quelconque::aire() const {
	double total = 0;
	for (Triangle* t : _triangles) {
		total += t->aire();
	}
	return total;
}

void Quelconque::accepte(const Visiteur&v) {
	v.visite(this);
}

void Quelconque::affiche(ostream &o) const {
	Forme::affiche(o);

	o << "Liste des triangles : " << endl;

	for (Triangle* t : _triangles) {
		t->affiche(o);
	}
}

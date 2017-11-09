#pragma once
#include"Quelconque.h"

Quelconque::Quelconque() : Forme() { }

Quelconque::Quelconque(string couleur) : Forme(couleur) { }

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

void Quelconque::ajouteTriangle(const Triangle &t) {
	_triangles.push_back(new Triangle(t));
}

double Quelconque::aire() const {
	double total = 0;
	for (Triangle* t : _triangles) {
		total += t->aire();
	}
	return total;
}

void Quelconque::accepte(const Visiteur&v) {

}

void Quelconque::affiche(ostream &o) const {
	Forme::affiche(o);

	for (Triangle* t : _triangles) {
		t->affiche(o);
	}
}

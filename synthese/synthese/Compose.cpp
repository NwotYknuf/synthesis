#pragma once
#include "Compose.h"
#include "Visiteur.h"

Compose::Compose() : Forme() { }

Compose::Compose(const string &couleur) : Forme(couleur){ }

Compose::Compose(const Compose& c) : Forme(getCouleur()){ 
	for (Forme* f : _formes) {
		Forme* temp = f->clone();
		temp->setCouleur(getCouleur());
		_formes.push_back(temp);
	}
}

Compose::~Compose() {
	for (Forme* f : _formes) {
		delete(f);
	}
}

void Compose::setCouleur(const string &couleur) {
	Forme::setCouleur(couleur);

	for (Forme* f : _formes) {
		f->setCouleur(couleur);
	}
}

void Compose::ajouteForme(const Forme &f) {
	Forme* temp = f.clone();
	temp->setCouleur(getCouleur());
	_formes.push_back(temp);
}

Forme* Compose::Compose::clone()const{
	return new Compose(*this);
}

double Compose::aire() const{
	double total = 0;
	for (Forme* f : _formes) {
		total += f->aire();
	}
	return total;
}

void Compose::accepte(Visiteur*v) {
	v->visite(this);
}

void Compose::affiche(ostream &o) const {
	o << "Compose" << endl;
	Forme::affiche(o);
	o << "Liste des formes : " << endl;

	for (Forme* f : _formes) {
		f->affiche(o);
	}
}

Forme* Compose::translation(const Vecteur2D & deplacement)const {
	Compose* c = new Compose(*this);
	for (Forme* f : c->_formes) {
		f = f->translation(deplacement);
	}
	return c;
}

Forme* Compose::rotation(const Vecteur2D & centre, double angle)const {
	Compose* c = new Compose(*this);
	for (Forme* f : c->_formes) {
		f = f->rotation(centre, angle);
	}
	return c;
}

Forme* Compose::echelle(const Vecteur2D & centre, double ratio)const {
	Compose* c = new Compose(*this);
	for (Forme* f : c->_formes) {
		f = f->echelle(centre, ratio);
	}
	return c;
}

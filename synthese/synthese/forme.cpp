#pragma once
#include "forme.h"
#include <iostream>
#include<string>

Forme::Forme()
{
}

Forme::Forme(const string &c) {
	_couleur = c;
}

Forme::Forme(const Forme& f) {
	_couleur = f._couleur;
}

Forme::~Forme()
{

}

ostream& operator<<(ostream &os, const Forme &f) {
	f.affiche(os);
	return os;
}

void Forme::affiche(ostream& os)const {
	os << "	-couleur : " <<  _couleur << endl;
}

#pragma once
#include "DessineVisiteur.h"
#include <iostream>
#include "Cercle.h"

using namespace std;

DessineVisiteur::DessineVisiteur(){ }

void DessineVisiteur::visite(const Cercle* c)const {
	cout << "Je dessine le cercle : " << *c << endl;
}

void DessineVisiteur::visite(const Triangle* t)const {
	cout << "Je dessine le triangle : " << (Forme*)t << endl;
}

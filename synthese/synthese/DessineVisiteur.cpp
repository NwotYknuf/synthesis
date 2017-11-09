#pragma once
#include "DessineVisiteur.h"
#include "Quelconque.h"
#include "Cercle.h"
#include "Triangle.h"
#include "Compose.h"
#include <iostream>

using namespace std;

DessineVisiteur::DessineVisiteur(){ }

void DessineVisiteur::visite(const Cercle *c) const{
	cout << "je dessine le cercle : " << endl << *c;
}

void DessineVisiteur::visite(const Triangle *t) const {
	cout << "je dessine le triangle : " << endl << *t;
}

void DessineVisiteur::visite(const Quelconque *q) const {
	cout << "je dessine le Quelquonque : " << endl << *q;
}

void DessineVisiteur::visite(const Compose *c) const {
	cout << "je dessine le compose : " << endl << *c;
}

#pragma once
#include "DessineVisiteur.h"
#include "Cercle.h"
#include "Triangle.h"
#include <iostream>

using namespace std;

DessineVisiteur::DessineVisiteur(){ }

void DessineVisiteur::visite(const Cercle *c) const{
	cout << "je dessine le cercle : " << endl << *c;
}

void DessineVisiteur::visite(const Triangle *t) const {
	cout << "je dessine le triangle : " << endl << *t;
}

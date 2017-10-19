#pragma once
#include "DessineVisiteur.h"
#include <iostream>
#include "Cercle.h"

using namespace std;

DessineVisiteur::DessineVisiteur(){ }

void DessineVisiteur::visite(Cercle* c)const {
	cout << "Je dessine le cercle : " << *c << endl;
}

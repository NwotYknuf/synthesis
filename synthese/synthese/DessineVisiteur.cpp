#pragma once
#include "DessineVisiteur.h"
#include<iostream>

DessineVisiteur::DessineVisiteur(){ }

void DessineVisiteur::visite(Cercle* c)const {
	cout << "Je dessine le cercle : " << *c;
}

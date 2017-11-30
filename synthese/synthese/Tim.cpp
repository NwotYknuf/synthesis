#pragma once
#include "Vecteur2D.h"
#include <iostream>
#include <string>
#include "DessineVisiteur.h"
#include "SauvegardeVisiteur.h"
#include "Cercle.h"
#include "Triangle.h"
#include	"Polygone.h"
#include "Compose.h"
#include "Fenetre.h"
#include "Forme.h"

const double PI = 3.1415926535;

int main(){

	string adresse = "127.0.0.1";
	int port = 8091;

	Vecteur2D _pos(10, 10);
	Vecteur2D _taille(500, 500);

	Fenetre fenetre("bonjour", _pos, _taille);
	DessineVisiteur* PabloPicsso;
	Cercle* c1 = new Cercle("rouge", 10, 10, 10);

	Vecteur2D p1(10, 10);
	Vecteur2D p2(10, 100);
	Vecteur2D p3(100, 10);
	Vecteur2D p4(100, 100);

	Triangle* t1 = new Triangle("rouge",p1, p2, p3);
	Triangle* t2 = new Triangle("bleu", p2, p3, p4);
	Polygone* p = new Polygone("cyan");

	p->ajouteTriangle(*t1);
	p->ajouteTriangle(*t2);

	Compose* cmp = new Compose("cyan");
	Cercle* c2 = new Cercle("rouge", 100, 100, 50);
	cmp->ajouteForme(*c1);
	cmp->ajouteForme(*c2);
	cmp->ajouteForme(*p);

	try {
		PabloPicsso = new DessineVisiteur(adresse, port, fenetre);
	}
	catch(char* s){
		cout << s << endl << "code :  "<< WSAGetLastError()<<endl;
		system("pause");
		exit(1);
	}
	
	PabloPicsso->visite(cmp);
	PabloPicsso->visite(t1);

	t1 = (Triangle*)t1->echelle(p4, -2);

	PabloPicsso->visite(t1);

	SauvegardeVisiteur* Napoleon = new SauvegardeVisiteur();

	Napoleon->visite(cmp);

	system("pause");

	return 0;
}

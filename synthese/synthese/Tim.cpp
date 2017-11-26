#pragma once
#include "Vecteur2D.h"
#include <iostream>
#include <string>
#include "DessineVisiteur.h"
#include "Cercle.h"
#include "Triangle.h"
#include	"Polygone.h"
#include "Compose.h"

const double PI = 3.1415926535;

int main(){

	string adresse = "127.0.0.1";
	int port = 8091;
	Vecteur2D p1(0, 0);
	Vecteur2D p2(1, 0);
	Vecteur2D p3(0, 1);
	Cercle* c = new Cercle("rouge", p1, 1.0);
	Triangle* t = new Triangle("bleu", p1, p2, p3);
	Compose* cmp = new Compose("vert");

	cmp->ajouteForme(*c);
	cmp->ajouteForme(*t);

	/*
	DessineVisiteur* test;

	try {
		test = new DessineVisiteur(adresse, port);
	}
	catch(char* s){
		cout << s << endl << "code :  "<< WSAGetLastError()<<endl;
	}

	try {
		test->visite(c);
	}
	catch (char* s) {
		cout << s << endl << "code :  " << WSAGetLastError() << endl;
	}
	*/
	
	cout << cmp->encoder() << endl;

	system("pause");

	return 0;
}

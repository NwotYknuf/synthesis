#pragma once
#include "Vecteur2D.h"
#include <iostream>
#include <string>
#include "DessineVisiteur.h"
#include "Cercle.h"
#include "Triangle.h"
#include	"Polygone.h"
#include "Compose.h"
#include "Fenetre.h"

const double PI = 3.1415926535;

int main(){

	string adresse = "127.0.0.1";
	int port = 8091;

	Vecteur2D _pos(10, 10);
	Vecteur2D _taille(500, 500);

	Fenetre fenetre("bonjour", _pos, _taille);
	DessineVisiteur* test;
	Cercle* c = new Cercle("rouge", 10, 10, 10);


	try {
		test = new DessineVisiteur(adresse, port, fenetre);

		Sleep(5);

		test->visite(c);
	}
	catch(char* s){
		cout << s << endl << "code :  "<< WSAGetLastError()<<endl;
	}
	
	system("pause");

	return 0;
}

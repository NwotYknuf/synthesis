#pragma once
#include "Vecteur2D.h"
#include <iostream>
#include <string>
#include "DessineVisiteur.h"
#include "Cercle.h"
#include "Triangle.h"
#include	"Quelconque.h"
#include "Compose.h"

const double PI = 3.1415926535;

int main(){

	string adresse = "127.0.0.1";
	int port = 8091;
	Cercle* c = new Cercle;
	
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

	string code = c->encoder();

	cout << code << endl;

	system("pause");

	return 0;
}

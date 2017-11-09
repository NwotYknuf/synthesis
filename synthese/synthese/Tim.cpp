#pragma once
#include "Vecteur2D.h"
#include <iostream>
#include <string>
#include "DessineVisiteur.h"
#include "Cercle.h"
#include "Triangle.h"
#include	"Quelconque.h"
#include "Compose.h"

int main(){

	cout << "// Vecteur \\\\"<<endl << endl;

	Vecteur2D u1(0.3, 0.7), u2(1, 0), v(0,1);

	cout << "u1 = " << u1 << endl;
	cout << "u2 = " << u2 << endl << endl;
	
	cout << "u1 * 2.5 = " << u1 * 2.5 << endl;
	cout << "u2,u1 = " << u2 - u1<<endl<<endl;

	cout << "// Cercle \\\\" << endl << endl;
	Cercle c1("rouge", u1, 1.5);
	DessineVisiteur pablo;
	pablo.visite(&c1);
	cout << "aire de c1 : " << c1.aire() << endl << endl;

	cout << "// Triangle \\\\" << endl << endl;
	Triangle t1("bleu", u1, u2, v);
	pablo.visite(&t1);
	cout << "aire de t1 : " << t1.aire() << endl << endl;

	cout << "// Quelconque \\\\" << endl << endl;

	Quelconque q1("magenta");
	Vecteur2D v1(12, 12);
	Triangle t2("vert", u1, u2, v1);

	q1.ajouteTriangle(t1);
	q1.ajouteTriangle(t2);

	pablo.visite(&q1);
	cout << "aire de t1 : " << q1.aire() << endl << endl;
	q1.setCouleur("moutarde");
	cout << "apres modification de la couleur : " << endl << q1 << endl << endl;


	cout << "// Compose \\\\" << endl << endl;
	Compose cmp1("rose");
	cmp1.ajouteForme(c1);
	cmp1.ajouteForme(q1);
	pablo.visite(&cmp1);
	cout << "aire de t1 : " << cmp1.aire() << endl << endl;

	system("pause");

	return 0;
}

#pragma once
#include "Vecteur2D.h"
#include <iostream>
#include <string>
#include "DessineVisiteur.h"
#include "Cercle.h"
#include "Triangle.h"

int main(){
	//goo.gl/QNUuZs

	cout << "// Vecteur \\\\"<<endl << endl;

	Vecteur2D u1(2, 3), u2(-5, 3), v(u1);

	cout << "u1 = " << u1 << endl;
	cout << "u2 = " << u2 << endl << endl;
	
	cout << "u1 * 2.5 = " << u1 * 2.5 << endl;
	cout << "u2,u1 = " << u2 - u1<<endl<<endl;

	cout << "// Cercle \\\\" << endl << endl;
	Cercle c1("rouge", u1, 1.5);
	DessineVisiteur pablo;
	pablo.visite(&c1);

	cout << "// Triangle \\\\" << endl << endl;
	Triangle t1("bleue", u1, u2, v);
	pablo.visite(&t1);

	system("pause");

	return 0;
}

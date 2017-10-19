#pragma once
#include "point.h"
#include "Vecteur2D.h"
#include "Cercle.h"
#include <iostream>
#include <string>
#include "DessineVisiteur.h"

int main(){

	Point p1(1, 1);
	Point p2(2,1);

	cout << "p1 = " << p1 << endl;
	cout << "p2 = " << p2 << endl;

	Point p3 = p1 + p2;
	cout << "p3 = p1 + p2 = " << p3 << endl;

	Vecteur2D v1(p1, p3);
	Vecteur2D v2(5,3,6,2);

	cout << "v1 = " << v1 << endl;
	cout << "v2 = " << v2 << endl;
	
	Vecteur2D v3 = v1 + v2;

	cout << "v3 = " << v3 << endl;

	Cercle c("red", p1, 12);

	DessineVisiteur pablopicasso;
	pablopicasso.visite(&c);
	system("pause");

	

	return 0;
}

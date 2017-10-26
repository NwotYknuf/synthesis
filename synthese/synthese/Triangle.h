#pragma once
#include <iostream>
#include "point.h"
#include "Visitable.h"
#include "forme.h"

using namespace std;

class Triangle : public Forme, public Visitable{
private:
	Point _p1, _p2, _p3;
	Triangle();

public:
	virtual ~Triangle();
	Triangle(const string, const Point &, const Point&, const Point&);

	void accepte(const Visiteur&);
	void affiche(ostream&)const;
};

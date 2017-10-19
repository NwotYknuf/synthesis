#pragma once
#include <iostream>
#include "point.h"
#include "Visitable.h"
#include "forme.h"

using namespace std;

class Triangle : public Forme, public Visitable{
private:
	Point _points[3];
	Triangle();

public:

	virtual ~Triangle();
	Triangle(const string, const Point &, const Point&, const Point&);

	const Point& getPoint(int);
	
	void accepter(const Visiteur&);
};

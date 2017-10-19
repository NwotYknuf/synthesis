#pragma once
#include "point.h"
#include <iostream>

class Vecteur2D
{
private:
	Point _p1;
	Point _p2;

public:
	Vecteur2D();
	Vecteur2D(const Vecteur2D & v);
	Vecteur2D(double, double, double, double);
	Vecteur2D(const Point & p1, const  Point & p2);
	virtual ~Vecteur2D();

	const Point& getP1()const { return _p1; }
	const Point& getP2()const { return _p2; }
	void setP1(const Point &p1) { _p1 = p1; }
	void setP2(const Point &p2) { _p2 = p2; }

	Vecteur2D operator=(const Vecteur2D&);
	friend ostream& operator<<(ostream&, const Vecteur2D&);
	Vecteur2D operator+(const Vecteur2D&) const;
};

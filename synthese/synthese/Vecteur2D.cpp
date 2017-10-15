#pragma once
#include "Vecteur2D.h"
#include "Point.h"

Vecteur2D::Vecteur2D()
	: _p1(), _p2() {}

Vecteur2D::Vecteur2D(double x1, double y1, double x2, double y2)
	: _p1(x1, y1), _p2(x2, y2) {}

Vecteur2D::Vecteur2D(const Point &p1, const Point &p2)
	: _p1(p1), _p2(p2) {}

Vecteur2D::~Vecteur2D() { }

Vecteur2D::Vecteur2D(const Vecteur2D& v)
	: _p1(v._p1), _p2(v._p2) {}

Vecteur2D Vecteur2D :: operator=(const Vecteur2D& v) const {
	return Vecteur2D(v);
}

ostream& operator<<(ostream &os, const Vecteur2D &v) {
	os << "origine : " << v._p1 << ", " << v._p2 - v._p1;
	return os;
}

Vecteur2D Vecteur2D::operator+(const Vecteur2D &v) const {
	return Vecteur2D(_p1, _p2 + v._p2 - v._p1);
}

#include "Triangle.h"
#include "Visiteur.h"
#include "point.h"



Triangle::Triangle(const string c, const Point &p1, const Point &p2, const Point &p3)
	: Forme(c){
	_points[0] = p1;
	_points[1] = p2;
	_points[2] = p3;
}

const Point& Triangle::getPoint(int index) {
	return _points[index];
}

void Triangle::accepter(const Visiteur &v) {
	v.visite(this);
}


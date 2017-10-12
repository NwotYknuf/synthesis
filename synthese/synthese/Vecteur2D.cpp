#include "Vecteur2D.h"
#include "Point.h"

#pragma region Constructeurs
Vecteur2D::Vecteur2D()
{

}

Vecteur2D::Vecteur2D(const Vecteur2D & vecteur) {

}

Vecteur2D::Vecteur2D(double x1, double x2, double x3, double x4) {
	_p1 = Point(x1, y1);
	_p2 = Point(x2, y2);
}

Vecteur2D::Vecteur2D(const Point & p1, const Point & p2) {
	_p1 = Point(p1);
	_p2 = Point(p2);
}

Vecteur2D::~Vecteur2D()
{
}
#pragma endrefion Constructeurs

#pragma region Getters / Setters

#pragma endregion Getters / Setters
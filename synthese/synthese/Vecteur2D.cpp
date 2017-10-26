#pragma once
#include "Vecteur2D.h"

Vecteur2D::Vecteur2D(){
	_x = 0;
	_y = 0;
}

Vecteur2D::Vecteur2D(const Vecteur2D & v){
	_x = v._x;
	_y = v._y;
}

Vecteur2D::Vecteur2D(double x, double y){
	_x = x;
	_y = y;
}

Vecteur2D::~Vecteur2D() { }

Vecteur2D Vecteur2D::operator=(const Vecteur2D &v){
	_x = v._x;
	_y = v._y;
	return *this;
}

bool Vecteur2D::operator==(const Vecteur2D &v){
	return _x == v._x && _y == v._y;
}

ostream& operator<<(ostream &os, const Vecteur2D &v){
	os << "(" << v._x << ", " << v._y << ")";
	return os;
}

Vecteur2D Vecteur2D::operator+(const Vecteur2D &v) const{
	return Vecteur2D(_x + v._x, _y + v._y);
}

Vecteur2D Vecteur2D::operator-(const Vecteur2D &v) const
{
	return Vecteur2D(_x - v._x, _y - v._y);
}

Vecteur2D Vecteur2D::operator*(double d) const
{
	return Vecteur2D(_x*d, _y*d);
}

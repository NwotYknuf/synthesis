#pragma once
#include"point.h"

Point::Point(){
	_x = _y = 0;
}

Point::Point(double x, double y){
	_x = x;
	_y = y;
}

Point::Point(const Point &p){
	_x = p._x;
	_y = p._y;
}

Point::~Point(){ }

Point Point::operator=(const Point &p)  {
	return Point(p._x, p._y);
}

bool Point::operator==(const Point&p) const {
	return (_y == p._y && _x == p._x);
}

ostream& operator<<(ostream& os, const Point&p){
	os << "(" << p._x << ", " << p._y << ")";
	return os;
}

Point Point::operator+(const Point &p) const {
	
	return Point(_x + p._x, _y + p._y);
}

Point Point::operator-(const Point &p) const {
	return Point(_x - p._x, _y - p._y);
}

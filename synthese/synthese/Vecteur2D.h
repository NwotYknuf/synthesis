#pragma once
#include <iostream>

using namespace std;

class Vecteur2D{
private:
	double _x;
	double _y;

public:
	Vecteur2D();
	Vecteur2D(const Vecteur2D&);
	Vecteur2D(double, double);
	virtual ~Vecteur2D();

	double getX() const { return _x; }
	double getY() const { return _y; }
	void setX(double x) { _x = x; }
	void setY(double y) { _y = y; }

	double distance(const Vecteur2D&)const;

	Vecteur2D operator=(const Vecteur2D&);
	bool operator==(const Vecteur2D&);
	friend ostream& operator<<(ostream&, const Vecteur2D&);
	Vecteur2D operator+(const Vecteur2D&) const;
	Vecteur2D operator-(const Vecteur2D&) const;
	Vecteur2D operator*(double) const;
};

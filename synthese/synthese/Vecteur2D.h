#pragma once
#include "point.h"
#include <stdio.h>
#include <stdlib.h>
class Vecteur2D
{
private:
	Point _p1;
	Point _p2;
public:
#pragma region Constructeurs
	Vecteur2D();
	Vecteur2D(const Vecteur2D & vecteur);
	Vecteur2D(int x1, int y1, int x2, int y2);
	virtual ~Vecteur2D();
#pragma endregion Constructeurs

#pragma region Getters / Setters
	Point getP1();
	Point getP2();

	void setP1();
	void setP2();
#pragma endregion Getters / Setters
};


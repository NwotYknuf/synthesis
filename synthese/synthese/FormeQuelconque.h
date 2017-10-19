#pragma once
#include "Triangle.h"

class FormeQuelconque
{
public:
	FormeQuelconque(Triangle t, ...);
	FormeQuelconque(const Triangle & t);
	virtual ~FormeQuelconque();

	void ajoutTriangle(const Triangle & t);
};


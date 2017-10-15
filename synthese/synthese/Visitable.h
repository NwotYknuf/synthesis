#pragma once
#include "Visiteur.h"

class Visitable {
public:
	virtual void accepte(const class Visiteur&) = 0;
};

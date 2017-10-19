#pragma once

class Visiteur;

class Visitable {
public:
	virtual void accepte(const class Visiteur&) = 0;
};

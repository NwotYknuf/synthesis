#pragma once

class Visiteur;

class Visitable {
public:
	virtual void accepte(const Visiteur&) = 0;
};

#pragma once

class Visiteur;

class Visitable {
public:
	virtual void accepte(Visiteur* ) = 0;
};

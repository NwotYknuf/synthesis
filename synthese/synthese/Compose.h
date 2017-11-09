#pragma once
#include  "forme.h"
#include "Visitable.h"
#include <vector>
#include <iostream>

using namespace std;

class Compose : public Forme, public Visitable {

private:
	vector<Forme*> _formes;

public:
	Compose();
	Compose(const string&);
	Compose(const Compose&);
	virtual ~Compose();

	void setCouleur(const string&);
	void ajouteForme(const Forme&);

	Forme* clone()const;
	double aire() const;

	void accepte(const Visiteur&);
	void affiche(ostream&)const;
};

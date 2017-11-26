#pragma once
#include  "forme.h"
#include "Visitable.h"
#include "Vecteur2D.h"
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
	void accepte(Visiteur*);
	const string encoder() const;
	void affiche(ostream&)const;

	Forme* translation(const Vecteur2D &)const;
	Forme* rotation(const Vecteur2D &, double)const;
	Forme* echelle(const Vecteur2D &, double)const;
	
};

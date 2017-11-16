#pragma once
#include  "forme.h"
#include "Triangle.h"
#include "Visitable.h"
#include <vector>
#include <iostream>

using namespace std;

class Quelconque : public Forme, public Visitable {
private:
	vector<Triangle*> _triangles;

public:
	Quelconque();
	Quelconque(const string&);
	Quelconque(const Quelconque&);
	virtual ~Quelconque();
	
	void setCouleur(const string&);
	void ajouteTriangle(const Triangle&);

	Forme* clone()const;
	double aire() const;
	Forme* translation(const Vecteur2D &)const;
	Forme* rotation(const Vecteur2D &, double)const;
	Forme* echelle(const Vecteur2D &, double)const;

	void accepte(Visiteur*);
	void affiche(ostream&)const;
};

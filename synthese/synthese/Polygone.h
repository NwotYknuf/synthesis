#pragma once
#include  "Forme.h"
#include "Triangle.h"
#include "Visitable.h"
#include <vector>
#include <iostream>

using namespace std;

class Polygone : public Forme, public Visitable {
private:
	vector<Triangle*> _triangles;

public:
	Polygone();
	Polygone(const string&);
	Polygone(const Polygone&);
	virtual ~Polygone();
	
	void setCouleur(const string&);
	void ajouteTriangle(const Triangle&);

	Forme* clone()const;
	double aire() const;
	void accepte(Visiteur*);
	const string encoder() const;
	void affiche(ostream&)const;

	Forme* translation(const Vecteur2D &)const;
	Forme* rotation(const Vecteur2D &, double)const;
	Forme* echelle(const Vecteur2D &, double)const;

};

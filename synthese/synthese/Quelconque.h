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
	Quelconque(string);
	Quelconque(const Quelconque&);
	virtual ~Quelconque();
	
	void setCouleur(string);
	void ajouteTriangle(const Triangle&);

	double aire() const;

	void accepte(const Visiteur&);
	void affiche(ostream&)const;
};

#pragma once
#include "Vecteur2D.h"
#include <string>

using namespace std;

class Fenetre{

private:
	string _titre;
	Vecteur2D _taille;

public:
	Fenetre();
	Fenetre(const string&, Vecteur2D);
	Fenetre(const Fenetre&);
	~Fenetre();

	const string getTitre()const { return _titre; }
	const Vecteur2D getTaille()const { return _taille; }
	void setTitre(const string &s) { _titre = s; }
	void setTaille(const Vecteur2D &v) { _taille = v; }

	const string encoder()const;

	friend ostream& operator<<(ostream&, Fenetre);

};


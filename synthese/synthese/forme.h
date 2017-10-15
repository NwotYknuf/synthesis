#pragma once
#include <iostream>
#include<string>

using namespace std;

class Forme
{
private:
	string _couleur;

public:
	Forme();
	Forme(string);
	Forme(const Forme&);
	virtual ~Forme();

	const string& getCouleur()const { return _couleur; }
	void setCouleur(const string &c) { _couleur = c; }

	Forme operator=(const Forme&);
	friend ostream& operator<<(ostream&, const Forme&);

	virtual void affiche(ostream&)const;
};

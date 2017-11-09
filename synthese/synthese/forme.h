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
	Forme(const string&);
	Forme(const Forme&);
	virtual ~Forme();

	const string& getCouleur()const { return _couleur; }
	virtual void setCouleur(const string &c) { _couleur = c; }

	virtual double aire() const = 0;
	virtual Forme* clone()const = 0;
	virtual void affiche(ostream&)const;

	friend ostream& operator<<(ostream&, const Forme&);
};

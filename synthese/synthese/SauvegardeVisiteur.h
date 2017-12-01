#pragma once
#include"Visiteur.h"
#include "Forme.h"
#include <string>

using namespace std;

class SauvegardeVisiteur : public Visiteur{
private:
	string _path;
	void sauvegarde(const Forme* f)const;

public:
	SauvegardeVisiteur();
	SauvegardeVisiteur(const string &);
	~SauvegardeVisiteur();

	void setPath(const string &path) { _path = path; }
	const string getPath()const { return _path; }

	void visite(const Cercle*)const;
	void visite(const Triangle*)const;
	void visite(const Polygone*)const;
	void visite(const Compose*)const;
	void visite(const Segment*)const;
};

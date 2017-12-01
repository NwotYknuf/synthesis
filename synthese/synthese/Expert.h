#pragma once
#include<string>
#include"Forme.h"

using namespace std;

class Expert
{
private:
	Expert* _suivant;

public:
	Expert() { _suivant = NULL; }
	Expert(Expert * e) { _suivant = e; }
	virtual ~Expert() { }

	Expert* getSuivant() const { return _suivant; }
	void setSuivant(Expert* suivant) { _suivant = suivant; }
	
	virtual Forme* gere(const string &req) const = 0;

};


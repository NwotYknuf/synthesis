#pragma once
#include"Visiteur.h"

class DessineVisiteur : Visiteur {

private:

public :
	DessineVisiteur();
	void visite(const Cercle*)const;
	void visite(const Triangle*)const;

};

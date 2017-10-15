#pragma once
#include"Visiteur.h"

class DessineVisiteur : Visiteur {

private:

public :
	DessineVisiteur();

	void visite(Cercle*)const;
};

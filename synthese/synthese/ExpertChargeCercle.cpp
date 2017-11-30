#include "ExpertChargeCercle.h"
#include "utils.h"
#include "Cercle.h"

Forme* ExpertChargeCercle::gere(const string &req) const {
	vector<string> args;
	split(req, ",", args);

	if (args[0] == "cercle") {
		string couleur = args[1];
		double Ox = stod(args[2]);
		double Oy = stod(args[3]);
		double rayon = stod(args[4]);

		return new Cercle(couleur, Ox, Oy, rayon);
	}
	else {
		return getSuivant() != NULL ? getSuivant()->gere(req) : NULL;
	}
}

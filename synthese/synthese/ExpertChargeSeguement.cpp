#pragma once
#include "ExpertChargeSeguement.h"
#include "utils.h"
#include "Segment.h"

Forme* ExpertChargeSeguement::gere(const string& req) const {
	vector<string> args;
	split(req, ",", args);

	if (args[0] == "cercle") {
		string couleur = args[1];
		double Ox = stod(args[2]);
		double Oy = stod(args[3]);
		double Ax = stod(args[4]);
		double Ay = stod(args[5]);

		return new Segment(couleur, Ox, Oy, Ax, Ay);
	}
	else {
		return getSuivant() != NULL ? getSuivant()->gere(req) : NULL;
	}
}
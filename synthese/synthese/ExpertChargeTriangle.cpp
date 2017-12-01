#include "ExpertChargeTriangle.h"
#include "utils.h"
#include "Triangle.h"

Forme* ExpertChargeTriangle::gere(const string &req) const {
	vector<string> args;
	split(req, ",", args);

	if (args[0] == "triangle") {

		string* couleur = new string(args[1]);
		double Ax = stod(args[2]);
		double Ay = stod(args[3]);
		double Bx = stod(args[4]);
		double By = stod(args[5]);
		double Cx = stod(args[6]);
		double Cy = stod(args[7]);

		return new Triangle(*couleur, Vecteur2D(Ax, Ay),
			Vecteur2D(Bx, By), Vecteur2D(Cx, Cy));
	}
	else {
		return getSuivant() != NULL ? getSuivant()->gere(req) : NULL;
	}
}

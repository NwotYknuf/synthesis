#include "ExpertChargePolygone.h"
#include "utils.h"
#include "Polygone.h"

Forme* ExpertChargePolygone::gere(const string& req) const {
	vector<string> args;
	split(req, ",", args);

	Polygone* res = new Polygone();

	if (args[0] == "polygone") {
		string suiteReq = req.substr(9, 0);
		args.clear();
		split(suiteReq, ";", args);

		for(string ssReq : args){
			res->ajouteTriangle(*(Triangle*)getSuivant()->gere(ssReq));
		}

		return res;
	}
	else {
		return getSuivant() != NULL ? getSuivant()->gere(req) : NULL;
	}
}

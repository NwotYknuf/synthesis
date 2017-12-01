#include "ExpertChargePolygone.h"
#include "utils.h"
#include "Polygone.h"

Forme* ExpertChargePolygone::gere(const string& req) const {
	vector<string> args;
	split(req, ",", args);


	if (args[0] == "polygone") {
		string suiteReq = req.substr(args[0].size() + 1 + args[1].size() + 1);
		
		vector<string> composants;
		split(suiteReq, ",", composants);
		string* couleur = new string(args[1]);

		Polygone* res = new Polygone(*couleur);

		for(string ssReq : composants){
			res->ajouteTriangle(*(Triangle*)getSuivant()->gere(ssReq));
		}

		return res;
	}
	else {
		return getSuivant() != NULL ? getSuivant()->gere(req) : NULL;
	}
}

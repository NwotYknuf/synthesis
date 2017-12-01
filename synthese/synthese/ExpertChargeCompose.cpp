#pragma once
#include "ExpertChargeCompose.h"
#include "Compose.h"
#include "utils.h"


Forme* ExpertChargeCompose::gere(const string& req) const {
	vector<string> args;
	split(req, ",", args);
	
	if (args[0] == "compose") {		
		string suiteReq = req.substr(args[0].size() + 1 + args[1].size() + 1);

		vector<string> composants;
		getComposants(suiteReq, '[', ']', composants);
		string* couleur = new string(args[1]);

		Compose* res = new Compose(*couleur);
		for (string reqCompo : composants) {
			res->ajouteForme(*gere(reqCompo));
		}
		return res;
	}
	else {
		return getSuivant() != NULL ? getSuivant()->gere(req) : NULL;
	}
}

#pragma once
#include "ExpertChargeCompose.h"
#include "Compose.h"
#include "utils.h"


Forme* ExpertChargeCompose::gere(const string& req) const {
	vector<string> args;
	split(req, ",", args);

	Compose* res = new Compose();

	if (args[0] == "compose") {
		string suiteReq = req.substr(8, 0);
		vector<string> composants;
		getComposants(suiteReq, '[', ']', composants);

		for (string reqCompo : composants) {
			res->ajouteForme(*gere(reqCompo));
		}
		return res;
	}
	else {
		return getSuivant() != NULL ? getSuivant()->gere(req) : NULL;
	}
}

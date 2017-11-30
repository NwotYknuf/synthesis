#pragma once
#include <string>
#include "Expert.h"
#include <vector>

class ExpertChargeSeguement : public Expert{
private:
	ExpertChargeSeguement() { }

public:
	ExpertChargeSeguement(Expert* e) : Expert(e) { }
	~ExpertChargeSeguement() { }

	Forme* gere(const string &) const;
};


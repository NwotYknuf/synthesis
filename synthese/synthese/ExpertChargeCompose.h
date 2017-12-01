#pragma once
#include <string>
#include "Expert.h"
#include <vector>

class ExpertChargeCompose : public Expert{
private:
	ExpertChargeCompose();
	
public:
	ExpertChargeCompose(Expert* e) : Expert(e) { }
	~ExpertChargeCompose() { };

	Forme* gere(const string &) const;

};


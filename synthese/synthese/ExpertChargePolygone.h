#pragma once
#include <string>
#include "Expert.h"
#include <vector>

class ExpertChargePolygone : public Expert{
private:
	ExpertChargePolygone();

public:
	ExpertChargePolygone(Expert* e) : Expert(e) { }
	~ExpertChargePolygone() { }

	Forme* gere(const string &) const;
};


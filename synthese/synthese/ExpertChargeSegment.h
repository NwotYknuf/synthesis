#pragma once
#include <string>
#include "Expert.h"
#include <vector>

class ExpertChargeSegment : public Expert{
private:
	ExpertChargeSegment() { }

public:
	ExpertChargeSegment(Expert* e) : Expert(e) { }
	~ExpertChargeSegment() { }

	Forme* gere(const string &) const;
};


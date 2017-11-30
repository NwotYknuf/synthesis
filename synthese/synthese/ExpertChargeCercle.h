#pragma once
#include <string>
#include "Expert.h"
#include <vector>

using namespace std;

class ExpertChargeCercle : public Expert{

private :
	ExpertChargeCercle();

public:
	ExpertChargeCercle(Expert* e) : Expert(e) { }
	~ExpertChargeCercle() { }

	Forme* gere(const string &) const;
};


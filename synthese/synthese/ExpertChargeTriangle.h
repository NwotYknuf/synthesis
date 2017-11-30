#pragma once
#include <string>
#include "Expert.h"
#include <vector>

class ExpertChargeTriangle : public Expert{
private :
	ExpertChargeTriangle();
	
public:
	ExpertChargeTriangle(Expert* e) : Expert(e) { }
	~ExpertChargeTriangle() { }

	Forme* gere(const string &) const;
};


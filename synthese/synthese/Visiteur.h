#pragma once

class Cercle;
class Triangle;

class Visiteur {
private:

public:
	virtual void visite(const Cercle*)const = 0;
	virtual void visite(const Triangle*)const = 0;
};

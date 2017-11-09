#pragma once

class Cercle;
class Triangle;
class Quelconque;
class Compose;

class Visiteur {
private:

public:
	virtual void visite(const Cercle*)const = 0;
	virtual void visite(const Triangle*)const = 0;
	virtual void visite(const Quelconque*)const = 0;
	virtual void visite(const Compose*)const =0;

};

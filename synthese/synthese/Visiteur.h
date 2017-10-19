#pragma once

class Cercle;

class Visiteur {
private:

public:
	virtual void visite(Cercle*)const = 0;
};

#pragma once

class Cercle;
class Triangle;
class Polygone;
class Compose;
class Segment;

class Visiteur {
private:

public:
	virtual void visite(const Cercle*)const = 0;
	virtual void visite(const Triangle*)const = 0;
	virtual void visite(const Polygone*)const = 0;
	virtual void visite(const Compose*)const = 0;
	virtual void visite(const Segment*)const =0;

};

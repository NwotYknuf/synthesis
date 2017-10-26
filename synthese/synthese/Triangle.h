#pragma once
#include "forme.h"
#include "Visitable.h"
#include "Vecteur2D.h"

class Triangle : public Forme, public Visitable{
	private:
		Vecteur2D _p1, _p2, _p3;

public:
	Triangle();
	Triangle(const string, const Vecteur2D &, const Vecteur2D&, const Vecteur2D&);
	Triangle(const Triangle&);
	virtual ~Triangle();

	const Vecteur2D& getP1()const { return _p1; }
	const Vecteur2D& getP2()const { return _p2; }
	const Vecteur2D& getP3()const { return _p3; }
	void setP1(const Vecteur2D&p) { _p1 = p; }
	void setP2(const Vecteur2D&p) { _p2 = p; }
	void setP3(const Vecteur2D&p) { _p3 = p; }

	bool operator==(const Triangle &);

	void accepte(const Visiteur&);
	void affiche(ostream&)const;
};

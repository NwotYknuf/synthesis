#include "Triangle.h"
#include "Visiteur.h"

Triangle::Triangle() : Forme(),_p1(), _p2(), _p3() { }

Triangle::Triangle(const string c, const Vecteur2D &p1, const Vecteur2D &p2, const Vecteur2D &p3)
	: Forme(c), _p1(p1), _p2(p2), _p3(p3) { }

Triangle::Triangle(const Triangle &t)
	: Forme(t.getCouleur()), _p1(t._p1), _p2(t._p2), _p3(t._p3) { }

Triangle::~Triangle() { }

double Triangle::aire()const {
	double xA = _p1.getX();
	double yA = _p1.getY();
	double xB = _p2.getX();
	double yB = _p2.getY();
	double xC = _p3.getX();
	double yC = _p3.getY();

	return 0.5 * (
		((xB - xA)*(yC - yA))
		- ((xC-xA)*(yB - yA))
		);
}

void Triangle::accepte(const Visiteur &v){
	v.visite(this);
}

void Triangle::affiche(ostream &os) const{
	Forme::affiche(os);
	os << "	-p1 : " << _p1 << endl;
	os << "	-p2 : " << _p2 << endl;
	os << "	-p3 : " << _p3 << endl;
}

#include "Triangle.h"
#include "Visiteur.h"

Triangle::Triangle() : Forme(),_p1(), _p2(), _p3() { }

Triangle::Triangle(const string c, const Vecteur2D &p1, const Vecteur2D &p2, const Vecteur2D &p3)
	: Forme(c), _p1(p1), _p2(p2), _p3(p3) { }

Triangle::Triangle(const Triangle &t)
	: Forme(t.getCouleur()), _p1(t._p1), _p2(t._p2), _p3(t._p3) { }

Triangle::~Triangle() { }

Forme* Triangle::clone()const{
	return new Triangle(*this);
}

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

void Triangle::accepte(Visiteur *v){
	v->visite(this);
}

void Triangle::affiche(ostream &os) const{
	os << "Triangle" << endl;
	Forme::affiche(os);
	os << "	-p1 : " << _p1 << endl;
	os << "	-p2 : " << _p2 << endl;
	os << "	-p3 : " << _p3 << endl;
}

Forme* Triangle::translation(const Vecteur2D &deplacement)const {
	Triangle* t = new Triangle(*this);
	t->_p1 = t->_p1 + deplacement;
	t->_p2 = t->_p2 + deplacement;
	t->_p3 = t->_p3 + deplacement;
	return t;
}

Forme* Triangle::rotation(const Vecteur2D &centre, double angle)const {
	Triangle* t = new Triangle(*this);
	double a = centre.getX();
	double b = centre.getY();
	double x = t->_p1.getX();
	double y = t->_p1.getY();
	
	t->_p1.setX(a + x * cos(angle) - y * sin(angle));
	t->_p1.setY(b + x * sin(angle) + y * cos(angle));

	x = t->_p2.getX();
	y = t->_p2.getY();

	t->_p2.setX(a + x * cos(angle) - y * sin(angle));
	t->_p2.setY(b + x * sin(angle) + y * cos(angle));

	x = t->_p3.getX();
	y = t->_p3.getY();

	t->_p3.setX(a + x * cos(angle) - y * sin(angle));
	t->_p3.setY(b + x * sin(angle) + y * cos(angle));
	
	return t;
}

Forme* Triangle::echelle(const Vecteur2D &centre, double facteur)const {
	Triangle* t = new Triangle(*this);
	
	t->_p1 = t->_p1 - centre;
	t->_p1 = t->_p1 * facteur;
	t->_p1 = t->_p1 + centre;

	t->_p2 = t->_p2 - centre;
	t->_p2 = t->_p2 * facteur;
	t->_p2 = t->_p2 + centre;

	t->_p3 = t->_p3 - centre;
	t->_p3 = t->_p3 * facteur;
	t->_p3 = t->_p3 + centre;

	return t;
}

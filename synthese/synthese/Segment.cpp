#include "Segment.h"
#include"Visiteur.h"
#include <sstream>

Segment::Segment() : Forme(), _deb(), _fin() { }

Segment::Segment(const string& couleur, const Vecteur2D& deb, const Vecteur2D& fin)
	: Forme(couleur), _deb(deb), _fin(fin) { }

Segment::Segment(const string& couleur, double x1, double y1, double x2, double y2)
	: Forme(couleur), _deb(x1, y1), _fin(x2, y2) { }

Segment::Segment(const Segment &s)
	: Forme(s.getCouleur()), _deb(s._deb), _fin(s._fin) { }

Segment::~Segment() { }

Forme*  Segment::clone() const {
	return new Segment(*this);
}

double Segment::aire()const {
	return 0.0;
}

void Segment::affiche(ostream& os)const {
	os << "Segument" << endl;
	Forme::affiche(os);
	os << "	-deb : " << _deb << endl;
	os << "	-fin : " << _fin << endl;
}

const string Segment::encoder()const {
	ostringstream oss;
	oss << "segument" << "," << getCouleur() << "," << _deb.getX() << "," << _fin.getY();
	return oss.str();	
}

void Segment::accepte(Visiteur* v) {
	v->visite(this);
}

Forme* Segment::translation(const Vecteur2D & deplacement)const {
	Segment* s = new Segment(*this);
	s->_deb = _deb + deplacement;
	s->_fin = _deb + deplacement;
	return s;
}

Forme* Segment::rotation(const Vecteur2D & centre, double angle)const {
	Segment* s = new Segment(*this);
	double a = centre.getX();
	double b = centre.getY();
	double x = s->_deb.getX();
	double y = s->_deb.getY();

	s->_deb.setX(a + x * cos(angle) - y * sin(angle));
	s->_deb.setY(b + x * sin(angle) + y * cos(angle));

	x = s->_fin.getX();
	y = s->_fin.getY();
	
	s->_fin.setX(a + x * cos(angle) - y * sin(angle));
	s->_fin.setY(b + x * sin(angle) + y * cos(angle));

	return s;
}

Forme* Segment::echelle(const Vecteur2D & centre, double facteur)const {
	Segment* s = new Segment(*this);

	s->_deb = s->_deb - centre;
	s->_deb = s->_deb * facteur;
	s->_deb = s->_deb + centre;

	s->_fin = s->_fin - centre;
	s->_fin = s->_fin * facteur;
	s->_fin = s->_fin + centre;

	return s;
}

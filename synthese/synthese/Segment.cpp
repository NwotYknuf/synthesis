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
	oss << "segment" << "," << getCouleur() 
		<< "," << (int)_deb.getX() <<"," << (int)_deb.getY()
		<< "," << (int)_fin.getX() << "," << (int)_fin.getY();
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
	double x1 = centre.getX();
	double y1 = centre.getY();
	double x2 = s->_deb.getX();
	double y2 = s->_deb.getY();

	s->_deb.setX((x2 - x1) * cos(angle) - (y2 - y1) * sin(angle) + x1);
	s->_deb.setY((x2 - x1)*sin(angle) + (y2 - y1)*cos(angle) + y1);

	x2 = s->_fin.getX();
	y2 = s->_fin.getY();
	
	s->_deb.setX((x2 - x1) * cos(angle) - (y2 - y1) * sin(angle) + x1);
	s->_deb.setY((x2 - x1)*sin(angle) + (y2 - y1)*cos(angle) + y1);

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

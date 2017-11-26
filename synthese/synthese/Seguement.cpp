#include "Seguement.h"
#include"Visiteur.h"
#include <sstream>

Seguement::Seguement() : Forme(), _deb(), _fin() { }

Seguement::Seguement(const string& couleur, const Vecteur2D& deb, const Vecteur2D& fin)
	: Forme(couleur), _deb(deb), _fin(fin) { }

Seguement::Seguement(const string& couleur, double x1, double y1, double x2, double y2)
	: Forme(couleur), _deb(x1, y1), _fin(x2, y2) { }

Seguement::Seguement(const Seguement &s)
	: Forme(s.getCouleur()), _deb(s._deb), _fin(s._fin) { }

Seguement::~Seguement() { }

Forme*  Seguement::clone() const {
	return new Seguement(*this);
}

double Seguement::aire()const {
	return 0.0;
}

void Seguement::affiche(ostream& os)const {
	os << "Segument" << endl;
	Forme::affiche(os);
	os << "	-deb : " << _deb << endl;
	os << "	-fin : " << _fin << endl;
}

const string Seguement::encoder()const {
	ostringstream oss;
	oss << "Segument" << "," << getCouleur() << "," << _deb.getX() << "," << _fin.getY() << "\r\n";
	return oss.str();	
}

void Seguement::accepte(Visiteur* v) {
	v->visite(this);
}

Forme* Seguement::translation(const Vecteur2D & deplacement)const {
	Seguement* s = new Seguement(*this);
	s->_deb = _deb + deplacement;
	s->_fin = _deb + deplacement;
	return s;
}

Forme* Seguement::rotation(const Vecteur2D & centre, double angle)const {
	Seguement* s = new Seguement(*this);
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

Forme* Seguement::echelle(const Vecteur2D & centre, double facteur)const {
	Seguement* s = new Seguement(*this);

	s->_deb = s->_deb - centre;
	s->_deb = s->_deb * facteur;
	s->_deb = s->_deb + centre;

	s->_fin = s->_fin - centre;
	s->_fin = s->_fin * facteur;
	s->_fin = s->_fin + centre;

	return s;
}

#include "Fenetre.h"
#include <sstream>

Fenetre::Fenetre() : _pos(), _taille(){
	_titre = "";
}

Fenetre::Fenetre(const string& titre, Vecteur2D taille)
	: _taille(taille) {
	_titre = titre;
}

Fenetre::Fenetre(const Fenetre& f)
	: _titre(f._titre), _taille(f._taille){ }

Fenetre::~Fenetre(){ }

const string Fenetre::encoder() const {
	ostringstream oss;
	oss << _titre << "," << _taille.getX() <<"," << _taille.getY() << "\r\n";
	return oss.str();
}

ostream& operator<<(ostream& os, Fenetre f) {
	os << "titre : " << f._titre << endl;
	os << "taille : " << f._taille;
	return os;
}

#include "Fenetre.h"
#include <sstream>

Fenetre::Fenetre() : _pos(), _taille(){
	_titre = "";
}

Fenetre::Fenetre(const string& titre, Vecteur2D pos, Vecteur2D taille)
	: _pos(pos), _taille(taille) {
	_titre = titre;
}

Fenetre::Fenetre(const Fenetre& f)
	: _titre(f._titre), _pos(f._pos), _taille(f._taille){ }

Fenetre::~Fenetre(){ }

const string Fenetre::encoder() const {
	ostringstream oss;
	oss << _titre << "," << _pos.getX() << "," << _pos.getY() << "," << _taille.getX() <<"," << _taille.getY() << "\r\n";
	return oss.str();
}

ostream& operator<<(ostream& os, Fenetre f) {
	os << "titre : " << f._titre << endl;
	os << "pos : " << f._pos;
	os << "taille : " << f._taille;
	return os;
}

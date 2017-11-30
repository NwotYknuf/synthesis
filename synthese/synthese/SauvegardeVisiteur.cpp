#pragma once
#include "SauvegardeVisiteur.h"
#include"Cercle.h"
#include"Triangle.h"
#include"Segment.h"
#include"Compose.h"
#include "Polygone.h"
#include <fstream>
#include<iostream>

using namespace std;

SauvegardeVisiteur::SauvegardeVisiteur(){
	_path = ".\\forme.txt";
}

SauvegardeVisiteur::SauvegardeVisiteur(const string& path) {
	_path = path;
}

SauvegardeVisiteur::~SauvegardeVisiteur(){

}

void SauvegardeVisiteur::sauvegarde(const Forme* f) const{
	ofstream fichier(_path, ios::trunc);

	if (fichier) {
		fichier << f->encoder() + "\r\n";
		fichier.close();
	}
	else
		throw "Impossible d'ouvrir le fichier !";
}

void SauvegardeVisiteur::visite(const Cercle*c)const {
	sauvegarde(c);
}

void SauvegardeVisiteur::visite(const Triangle*t)const {
	sauvegarde(t);
}

void SauvegardeVisiteur::visite(const Polygone*p)const {
	sauvegarde(p);
}
	
void SauvegardeVisiteur::visite(const Compose*cmp)const {
	sauvegarde(cmp);
}

void SauvegardeVisiteur::visite(const Segment*s)const {
	sauvegarde(s);
}
#pragma once

#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include "DessineVisiteur.h"
#include "Quelconque.h"
#include "Cercle.h"
#include "Triangle.h"
#include "Compose.h"
#include "MonWinsock.h"
#include <iostream>
#include<sstream>

using namespace std;

DessineVisiteur::DessineVisiteur(const string &adresse, int port){
	
	MonWinsock::getInstance();

	_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (_sock == INVALID_SOCKET)
			throw "la création du socket a échoué";
	
	_sockaddr.sin_family = AF_INET;
	_sockaddr.sin_addr.s_addr = inet_addr(adresse.c_str());
	_sockaddr.sin_port = htons((short)port);
	
	if (connect(_sock, (SOCKADDR *)&_sockaddr, sizeof(sockaddr)) == SOCKET_ERROR)
		throw "La connexion au serveur de dessin a échoué";
}

DessineVisiteur::~DessineVisiteur() {

	if (shutdown(_sock, SD_BOTH) == SOCKET_ERROR)
		throw "la coupure de connexion a échoué";
	
	if (closesocket(_sock))
		throw "La fermeture du socket a échoué";

}

void DessineVisiteur::visite(const Cercle *c) const{
	ostringstream oss;
	
	oss << "testFenetre" << ", " << 0 << ", " << 0 << ", " << 500 << ", " << 500 << "\r\n";

	string req = oss.str();

	if (send(_sock, req.c_str(), req.length(), 0) == SOCKET_ERROR)
		throw "échec de l'envoi de la requête d'ouverture de fenêtre graphique";
}

void DessineVisiteur::visite(const Triangle *t) const {
	cout << "je dessine le triangle : " << endl << *t;
}

void DessineVisiteur::visite(const Quelconque *q) const {
	cout << "je dessine le Quelquonque : " << endl << *q;
}

void DessineVisiteur::visite(const Compose *c) const {
	cout << "je dessine le compose : " << endl << *c;
}

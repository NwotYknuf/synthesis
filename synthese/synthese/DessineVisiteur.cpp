#pragma once

#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include "DessineVisiteur.h"
#include "Polygone.h"
#include "Cercle.h"
#include "Triangle.h"
#include "Compose.h"
#include "MonWinsock.h"
#include "Seguement.h"
#include "Fenetre.h"
#include <iostream>
#include<sstream>

using namespace std;

DessineVisiteur::DessineVisiteur(const string &adresse, int port, const Fenetre& f){
	
	MonWinsock::getInstance();

	_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (_sock == INVALID_SOCKET)
			throw "la cr�ation du socket a �chou�";
	
	_sockaddr.sin_family = AF_INET;
	_sockaddr.sin_addr.s_addr = inet_addr(adresse.c_str());
	_sockaddr.sin_port = htons((short)port);
	
	if (connect(_sock, (SOCKADDR *)&_sockaddr, sizeof(sockaddr)) == SOCKET_ERROR)
		throw "La connexion au serveur de dessin a �chou�";

	string req = f.encoder();
	if (send(_sock, req.c_str(), req.length(), 0) == SOCKET_ERROR)
		throw "�chec de l'envoi de la requ�te d'ouverture de fen�tre graphique";
}

DessineVisiteur::~DessineVisiteur() {

	if (shutdown(_sock, SD_BOTH) == SOCKET_ERROR)
		throw "la coupure de connexion a �chou�";
	
	if (closesocket(_sock))
		throw "La fermeture du socket a �chou�";

}

void DessineVisiteur::visite(const Cercle *c) const{
	string req = c->encoder();
	if (send(_sock, req.c_str(), req.length(), 0) == SOCKET_ERROR)
		throw "�chec de l'envoi de la requ�te de dessin d'un cercle";
}

void DessineVisiteur::visite(const Triangle *t) const {
	string req = t->encoder();
	if (send(_sock, req.c_str(), req.length(), 0) == SOCKET_ERROR)
		throw "�chec de l'envoi de la requ�te de dessin d'un triangle";
}

void DessineVisiteur::visite(const Polygone *q) const {
	string req = q->encoder();
	if (send(_sock, req.c_str(), req.length(), 0) == SOCKET_ERROR)
		throw "�chec de l'envoi de la requ�te de dessin d'un polygone";
}

void DessineVisiteur::visite(const Compose *c) const {
	string req = c->encoder();
	if (send(_sock, req.c_str(), req.length(), 0) == SOCKET_ERROR)
		throw "�chec de l'envoi de la requ�te de dessin d'un compose";
}

void DessineVisiteur::visite(const Seguement *s) const {
	string req = s->encoder();
	if (send(_sock, req.c_str(), req.length(), 0) == SOCKET_ERROR)
		throw "�chec de l'envoi de la requ�te de dessin d'un Seguement";
}

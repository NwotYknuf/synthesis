#pragma once
#include"Visiteur.h"
#include<string>
#include <WinSock2.h>

class Fenetre;
using namespace std;

class DessineVisiteur : Visiteur {

private:
	SOCKET _sock;
	SOCKADDR_IN _sockaddr;
	
public :
	DessineVisiteur(const string &, int, const Fenetre &);
	~DessineVisiteur();

	void visite(const Cercle*)const;
	void visite(const Triangle*)const;
	void visite(const Polygone*)const;
	void visite(const Compose*)const;
	void visite(const Seguement*)const;
};

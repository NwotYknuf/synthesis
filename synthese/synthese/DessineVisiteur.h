#pragma once
#include"Visiteur.h"
#include<string>
#include <WinSock2.h>

using namespace std;

class DessineVisiteur : Visiteur {

private:
	SOCKET _sock;
	SOCKADDR_IN _sockaddr;
	
public :
	DessineVisiteur(const string &, int);
	~DessineVisiteur();
	void visite(const Cercle*)const;
	void visite(const Triangle*)const;
	void visite(const Quelconque*)const;
	void visite(const Compose*)const;

};

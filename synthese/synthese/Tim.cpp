#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include<fstream>
#include "DessineVisiteur.h"
#include "SauvegardeVisiteur.h"
#include "ExpertChargeCompose.h"
#include "ExpertChargePolygone.h"
#include	"ExpertChargeTriangle.h"
#include "ExpertChargeCercle.h"
#include "ExpertChargeSegment.h"
#include "Vecteur2D.h"
#include "Cercle.h"
#include "Triangle.h"
#include	"Polygone.h"
#include "Compose.h"
#include "Segment.h"
#include "Fenetre.h"

double PI = 3.1415926535;
string adresse = "127.0.0.1";
int port = 8091;
string path = ".\\formes\\monCompose.txt";

void p4() {
	//connexion
	DessineVisiteur* PabloPicasso;
	Vecteur2D _taille(500.0, 500.0);
	Fenetre fenetre("Chargement", _taille);

	try {
		PabloPicasso = new DessineVisiteur(adresse, port, fenetre);
	}
	catch (char* s) {
		cout << s << endl << "code :  " << WSAGetLastError() << endl;
		system("pause");
		exit(1);
	}

	//Création de la chaine de responsabilité
	ExpertChargeSegment * chargeSeguement = new ExpertChargeSegment(NULL);
	ExpertChargeCercle * chargeCercle = new ExpertChargeCercle(chargeSeguement);
	ExpertChargeTriangle * chargeTriangle = new ExpertChargeTriangle(chargeCercle);
	ExpertChargePolygone *chargePolygone = new ExpertChargePolygone(chargeTriangle);
	ExpertChargeCompose *chargeCompose = new ExpertChargeCompose(chargePolygone);
	
	//Chargement
	string req = "";
	ifstream fichier(path, ios::in);
	if (fichier) {
		fichier >> req;
		fichier.close();
	}
	else {
		throw "l'ouverture du fichier a echoue";
	}

	Forme* recu = chargeCompose->gere(req);
		
	//Dessin
	if (recu) {
		PabloPicasso->visite((Compose*)recu);
	}
	else {
		throw "forme non geree";
	}
}

void p3() {
	//connexion
	DessineVisiteur* PabloPicasso;
	Vecteur2D _taille(500.0, 500.0);
	Fenetre fenetre("Sauvegarde", _taille);

	try {
		PabloPicasso = new DessineVisiteur(adresse, port, fenetre);
	}
	catch (char* s) {
		cout << s << endl << "code :  " << WSAGetLastError() << endl;
		system("pause");
		exit(1);
	}
	//Creation
	Vecteur2D centre(50.0, 50.0);
	Vecteur2D p1(50.0, 50.0);
	Vecteur2D p2(50.0, 100.0);
	Vecteur2D p3(100.0, 50.0);
	Vecteur2D p4(100.0, 100.0);

	Cercle* c1 = new Cercle("rouge", centre, 50.0);
	Triangle* t1 = new Triangle("vert", p1, p2, p3);
	Triangle* t2 = new Triangle("vert", p2, p3, p4);
	
	Compose* cmp1 = new Compose("cyan");
	cmp1->ajouteForme(*c1);
	cmp1->ajouteForme(*t1);

	Compose* cmp2 = new Compose("jaune");
	cmp2->ajouteForme(*cmp1);
	cmp2->ajouteForme(*t2);

	//dessin
	PabloPicasso->visite(cmp2);

	//sauvegarde
	SauvegardeVisiteur* Homere = new SauvegardeVisiteur(path);

	Homere->visite(cmp2);
}

void p2() {
	//connexion
	DessineVisiteur* PabloPicasso;
	Vecteur2D _taille(500.0, 500.0);
	Fenetre fenetre("Composes et Polygones", _taille);

	try {
		PabloPicasso = new DessineVisiteur(adresse, port, fenetre);
	}
	catch (char* s) {
		cout << s << endl << "code :  " << WSAGetLastError() << endl;
		system("pause");
		exit(1);
	}

	//Creation des formes
	Vecteur2D centre(50.0, 50.0);
	Vecteur2D p1(50.0, 50.0);
	Vecteur2D p2(50.0, 100.0);
	Vecteur2D p3(100.0, 50.0);
	Vecteur2D p4(100.0, 100.0);

	Cercle* c1 = new Cercle("rouge", centre, 50.0);
	Segment*s1 = new Segment("bleu", 50.0, 50.0, 100.0, 100.0);
	Triangle* t1 = new Triangle("vert", p1, p2, p3);
	Triangle* t2 = new Triangle("rouge", p2, p3, p4);

	Polygone* poly = new Polygone("bleu");
	poly->ajouteTriangle(*t1);
	poly->ajouteTriangle(*t2);

	Compose* cmp = new Compose("cyan");
	cmp->ajouteForme(*c1);
	cmp->ajouteForme(*poly);
	
	//affichage
	cout << *cmp << endl;
	cout << "Apres translation : " << endl << endl;
	Forme * transforme = cmp->translation(Vecteur2D(200.0, 0.0));
	cout << *transforme << endl << endl ;

	cout << "Apres rotation : " << endl << endl;
	transforme = transforme->rotation(centre, PI / 3);
	cout << *transforme << endl << endl;

	cout << "Apres echelle : " << endl << endl;
	transforme = transforme->echelle(centre, 2);
	cout << *transforme << endl << endl;

	//Dessin
	PabloPicasso->visite(cmp);
	PabloPicasso->visite((Compose*)transforme);

}

void p1() {
	//connexion
	DessineVisiteur* PabloPicasso;
	Vecteur2D _taille(500.0, 500.0);
	Fenetre fenetre("Formes", _taille);

	try {
		PabloPicasso = new DessineVisiteur(adresse, port, fenetre);
	}
	catch (char* s) {
		cout << s << endl << "code :  " << WSAGetLastError() << endl;
		system("pause");
		exit(1);
	}

	//Creation des formes	
	Vecteur2D centre(50.0, 50.0);
	Cercle* c1 = new Cercle("rouge", centre, 50.0);

	Vecteur2D p1(50.0, 50.0);
	Vecteur2D p2(50.0, 100.0);
	Vecteur2D p3(100.0, 50.0);

	Segment*s1 = new Segment("bleu", 50.0, 50.0, 100.0, 100.0);
	Triangle* t1 = new Triangle("vert", p1, p2, p3);

	cout << "c1 = " << endl << *c1 << endl;
	cout << "t1 = " << endl << *t1 << endl;
	cout << "s1 = " << endl << *s1 << endl;

	cout << "aire de c1 : " << c1->aire() << endl;
	cout << "aire de t1 : " << t1->aire() << endl;
	cout << "aire de s1 : " << s1->aire() << endl;

	//Dessin
	PabloPicasso->visite(c1);
	PabloPicasso->visite(t1);
	PabloPicasso->visite(s1);
}

int main(){
	p1();
	system("pause");

	p2();
	system("pause");

	p3();
	system("pause");

	p4();
	system("pause");

	
	return 0;
}

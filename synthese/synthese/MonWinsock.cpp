#pragma once
#include "MonWinsock.h"

using namespace std;

MonWinsock * MonWinsock::instance = NULL;

MonWinsock * MonWinsock::getInstance() {
	if (!instance) {
		instance = new MonWinsock;
	}
	return instance;
}

MonWinsock::MonWinsock(){
	if (WSAStartup(MAKEWORD(2, 0), &wsaData)) {
		throw "L'initialisation a échoué";
	}
}

MonWinsock::~MonWinsock() {
	WSACleanup();
}

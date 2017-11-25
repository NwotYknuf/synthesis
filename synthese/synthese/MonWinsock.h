#pragma once
#include <winsock.h>

#pragma comment(lib,"ws2_32.lib") 

class MonWinsock{
private :
	WSADATA wsaData;
	MonWinsock();
	static MonWinsock* instance;
public:
	static MonWinsock * getInstance();
	~MonWinsock();
};


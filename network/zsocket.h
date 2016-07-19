/********************************************************************
	created:	2014/12/18
	created:	18:12:2014   10:37
	filename: 	D:\workspace\creater\engine\Classes\network\zsocket.h
	file path:	D:\workspace\creater\engine\Classes\network
	file base:	zsocket
	file ext:	h
	author:		ferchiel
	
	purpose:	wrap function
*********************************************************************/

#ifndef __Z_SOCKET_H__
#define __Z_SOCKET_H__

#include "ztype.h"

#ifdef _WIN32
#include <winsock2.h>
typedef int32				socklen_t;
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <arpa/inet.h>
typedef int32				SOCKET;

//#pragma region define win32 const variable in linux
#define INVALID_SOCKET	-1
#define SOCKET_ERROR	-1
//#pragma endregion
#endif


class zSocket
{
public:
	zSocket();
	~zSocket();

	int32 init(int32 af, int32 type, int32 pro);
	int32 connect(const char* ip, unsigned short port);
	int32 select();
	int32 recv(void* buf, int32 len, int32 flag = 0);
	int32 send(const void* buf, int32 len, int32 flag = 0);
	int32 ioctl(int32 type, int32* arg);
	int32 setopt(int32 lvl, int32 opt, void* res, uint32 ol);
	int32 close();

private:
	SOCKET _sock;
	fd_set _fdr;
};


#endif
/********************************************************************
	created:	2014/12/18
	created:	18:12:2014   10:39
	filename: 	D:\workspace\creater\engine\Classes\network\zsocket.cpp
	file path:	D:\workspace\creater\engine\Classes\network
	file base:	zsocket
	file ext:	cpp
	author:		ferchiel
	
	purpose:	
*********************************************************************/

#include "zsocket.h"
#include "cocos2d.h"

#ifdef WIN32
#pragma comment(lib, "wsock32")
#endif

zSocket::zSocket()
{
#ifdef _WIN32
	WSADATA wsa={0};
	WSAStartup(MAKEWORD(2,2),&wsa);
#endif // _WIN32
}

zSocket::~zSocket()
{
#ifdef _WIN32
	WSACleanup();
#endif // _WIN32
}

int32 zSocket::init(int32 af, int32 type, int32 pro)
{
	_sock = socket(af, type, pro);
	if (_sock < 0)
	{
		printf("[ERROR]: socket init Failed!");
		return -1;
	}

	//// set non-blocking io
	//int32 arg = 1;
	//ioctl(FIONBIO, &arg);
	return 0;
}

int32 zSocket::connect(const char* ip, unsigned short port)
{
	struct sockaddr_in sa;
	struct hostent* hp;

	hp = gethostbyname(ip);
	if(!hp){
		int32 lasterr = GetLastError();
		printf("[ERROR]: gethostbyname Failed!");
		close();
		return -1;
	}
	memset(&sa, 0, sizeof(sa));
	memcpy((char*)&sa.sin_addr, hp->h_addr, hp->h_length);
	sa.sin_family = hp->h_addrtype;
	sa.sin_port = htons(port);

	if (::connect(_sock, (sockaddr*)&sa, sizeof(sa)) != 0)
	{
		printf("[ERROR]: connect Failed!");
		int err  = GetLastError();
		close();
		return -1;
	}
	printf("Client connect OK £¡ IP: %s:%d \n",ip,port);
	return 0;
}

int32 zSocket::select()
{
	FD_ZERO(&_fdr);
	FD_SET(_sock, &_fdr);

	timeval tm;
	tm.tv_sec = 0;
	tm.tv_usec = 0;

	int32 ret;
	if ((ret = ::select(_sock, &_fdr, 0, 0, &tm)) == SOCKET_ERROR)
	{
		printf("[ERROR]: select Failed!");
		close();
		return -1;
	}
	if (FD_ISSET(_sock, &_fdr))
	{
		return 0;
	}
	return -1;
}

int32 zSocket::recv(void* buf, int32 len, int32 flag /*= 0*/)
{
	return ::recv(_sock, (char*)buf, len, flag);
}

int32 zSocket::send(const void* buf, int32 len, int32 flag /*= 0*/)
{
	return ::send(_sock, (const char*)buf, len, flag);
}

int32 zSocket::close()
{
#if _WIN32
	return closesocket(_sock);
#else 
	return ::close(_sock);
#endif	// _WIN32
}

int32 zSocket::ioctl(int32 type, int32* arg)
{
#ifdef _WIN32
	return ::ioctlsocket(_sock, type, (u_long*)(arg));
#else
	return ::ioctl(_sock, type, arg);
#endif
}

int32 zSocket::setopt(int32 lvl, int32 opt, void* res, uint32 ol)
{
	return ::setsockopt(_sock, lvl, opt, (const char*)res, ol);
}



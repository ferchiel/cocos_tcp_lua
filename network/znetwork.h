/********************************************************************
	created:	2014/12/18
	created:	18:12:2014   10:33
	filename: 	D:\workspace\creater\engine\Classes\network\znetwork.h
	file path:	D:\workspace\creater\engine\Classes\network
	file base:	znetwork
	file ext:	h
	author:		ferchiel
	
	purpose:	connect & sendMsg to lua
*********************************************************************/
#ifndef __Z_NETWORK_H__
#define __Z_NETWORK_H__

#include "ztype.h"
#include "zbase.h"
#include <mutex>


class zSocket;
class zBuffer;

class zNetwork : public zEventBase
{
public:
	static zNetwork* inst();
	~zNetwork();

	virtual const char* get_class_name()
	{
		return __zClassName[__zClassNetwork];
	}

	int32 init();
	int32 connect();
	int32 send(zBuffer* buf);
	int32 clean();
	int32 disconnect();

	// get msg count
	int32 msg();
	int32 incMsg();
	int32 decMsg();

	zBuffer* getBuffer();

protected:
	zNetwork();

private:
	int32 _connect();
	int32 _isLength();

	//: debug
public:
	int32 _b;

private:
	zSocket* _sock;
	zBuffer* _buffer;

	int32 _received;		// msg receive size
	int32 _length;			// msg length
	volatile int32 _msg;				// waiting for process msg count

	std::mutex _mutex;	// process mutex

private:
	static zNetwork* _inst;
};



#endif
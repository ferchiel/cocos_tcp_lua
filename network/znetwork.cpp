/********************************************************************
	created:	2014/12/18
	created:	18:12:2014   10:33
	filename: 	D:\workspace\creater\engine\Classes\network\znetwork.cpp
	file path:	D:\workspace\creater\engine\Classes\network
	file base:	znetwork
	file ext:	cpp
	author:		ferchiel
	
	purpose:
*********************************************************************/

#include "znetwork.h"
#include "zsocket.h"
#include "zbuffer.h"
#include "cocos2d.h"
#include <thread>

#include "lua/zluaevent.h"

#ifdef _WIN32
#define sleep(x) Sleep(x)
#else
#define sleep(x) usleep(x * 1000)
#endif	// _WIN32

zNetwork* zNetwork::_inst = 0;

zNetwork* zNetwork::inst()
{
	if (!_inst)
		_inst = new zNetwork();
	return _inst;
}

zNetwork::zNetwork()
	: _sock(0)
	, _buffer(0)
	, _received(0)
	, _msg(0)
	, _b(0)
{
}

zNetwork::~zNetwork()
{
	clean();
}

int32 zNetwork::init()
{
	if (!_sock)
	{
		_sock = new zSocket();
		_sock->init(AF_INET, SOCK_STREAM, 0);		// tcpip
		int32 res = 0;
		_sock->setopt(SOL_SOCKET, SO_RCVBUF, &res, 512 * 1024);		// 512k?
		_sock->setopt(SOL_SOCKET, SO_SNDBUF, &res, 512 * 1024);
		//_sock->setopt(SOL_SOCKET, SO_KEEPALIVE, &res, 1);
	}
	return 0;
}

int32 zNetwork::connect()
{
	std::thread conth(&zNetwork::_connect, this);
	conth.detach();
	return 0;
}

int32 zNetwork::_connect()
{
	if (!_sock)
		return -1;

	// addr config in lua
	int ret = _sock->connect("172.31.244.2", 40100);
	if (0 == ret && !_buffer)
		_buffer = new zBuffer(10240);

	// event call back function
	zEventPipe *ep = zEventPipe::inst();
	ep->command("connect", this);

	if (0 != ret)
		return -1;

	while (1)
	{
		if (_sock->select() == 0)
		{
			if (_received < sizeof(_length))
			{
				int32 len = 0;
				int32 rc = _sock->recv(&len, sizeof(_length) - _received);
				char* ptrLength = (char*)(&_length);
				memcpy(ptrLength + _received, &len, rc);
				_received += rc;
				if (_received < sizeof(_length))		// length is not recv over
				{
					continue;				// wait msg length receive over
				}

				// check the msg length
				if (_length == 0)
				{
					// remove not receiving end of the message
					char* pwrt = _buffer->wd_ptr();
					pwrt -= _received;
					_received = 0;				// re-receive the message..
					// event call back function
					zEventPipe *ep = zEventPipe::inst();
					ep->command("disconnect", this);
					return 0;
				}

				if (_length < 0)
				{
					// event call back function
					zEventPipe *ep = zEventPipe::inst();
					ep->command("msgerr", this);
					return -1;
				}
			}

			// write to buffer
			_buffer->tryreset();
			if (_buffer->expend(_length) < 0)
			{
				perror("[ERR]: not enough mem...!");
				return -1;
			}

			char* pwrt = _buffer->wd_ptr();
			int32 rsz = _sock->recv((void*)pwrt, _length);
			_buffer->wd_ptr(rsz);
			_length -= rsz;
			_received += rsz;
			if (_length <= 0)			// msg receive over
			{
				_received = 0;
				incMsg();

				// receive a new full msg
				// call back to lua function
				zEventPipe *ep = zEventPipe::inst();
				ep->command("data", this);
				return -1;
			}
		}

		sleep(1);
	}
	return 0;
}

int zNetwork::send(zBuffer* buf)
{
	int32 len = 0;
	int32 realsz = 0;
	do 
	{
		char* rdptr = buf->rd_ptr();
		char* wtptr = buf->wd_ptr();
		len = wtptr - rdptr;
		realsz = _sock->send(rdptr, len);
		buf->rd_ptr(realsz);
	} while (realsz < len);
	buf->tryreset();
	return 0;
}

int zNetwork::clean()
{
	delete _sock;
	_sock = 0;
	delete _buffer;
	_buffer = 0;

	_received = 0;
	_length = 0;
	_msg = 0;
	return 0;
}

zBuffer* zNetwork::getBuffer()
{
	return _buffer;
}

int32 zNetwork::incMsg()
{
	_mutex.lock();
	_msg++;
	_mutex.unlock();
	return _msg;
}

int32 zNetwork::decMsg()
{
	_mutex.lock();
	_msg--;
	_mutex.unlock();
	return _msg;
}

int32 zNetwork::msg()
{
	return _msg;
}

int32 zNetwork::disconnect()
{
	return _sock->close();
}




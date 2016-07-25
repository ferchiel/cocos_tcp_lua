/********************************************************************
	created:	2014/12/18
	created:	18:12:2014   10:35
	filename: 	D:\workspace\creater\engine\Classes\network\zbuffer.h
	file path:	D:\workspace\creater\engine\Classes\network
	file base:	zbuffer
	file ext:	h
	author:		ferchiel

	purpose:	
*********************************************************************/

#ifndef __Z_BUFFER_H__
#define __Z_BUFFER_H__

#include "../ztype.h"
#include "../zbase.h"

#define __zBufferGrouth 16

class zBuffer : public zEventBase
{
public:
	zBuffer(uint32 sz, uint32 vg = __zBufferGrouth);
	~zBuffer();

	virtual const char* get_class_name()
	{
		return __zClassName[__zClassBuffer];
	}

	template<typename T>
	T get();
	template<>
	const char* get();

	template<typename T>
	void set(T v);
	template<>
	void set(const char* v);

	uint32 growth();
	uint32 growth(uint32 v);

	char* rd_ptr();
	void rd_ptr(uint32 sz);		// byte

	char* wd_ptr();
	void wd_ptr(uint32 sz);

	void reset();
	void tryreset();
	int32 expend(uint32 sz);

	int32 avail();
	int32 free();

private:
	char* _begin;
	char* _write;
	char* _read;

	uint32 _sz;
	uint32 _growth;
};

template<>
void zBuffer::set(const char* v)
{
	uint32 sz = strlen(v) + 1;
	if (expend(sz))
		return;
	strcpy(_write, v);
	_write += sz;
	return;
}

template<>
const char* zBuffer::get()
{
	if (_read >= _write) 
		return 0;
	const char* ret = _read;
	uint32 sz = strlen(_read) + 1;
	_read += sz;
	return ret;
}

template<typename T>
void zBuffer::set(T v)
{
	if (expend(sizeof(v)))
		return;
	*((T*)(_write)) = v;
	_write += sizeof(v);
	return;
}

template<typename T>
T zBuffer::get()
{
	if (_read >= _write) 
		return 0;
	T ret = *((T*)(_read)); 
	_read += sizeof(ret);
	return ret;
}

#endif


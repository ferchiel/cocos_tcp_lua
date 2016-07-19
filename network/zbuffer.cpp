/********************************************************************
	created:	2014/12/18
	created:	18:12:2014   10:36
	filename: 	D:\workspace\creater\engine\Classes\network\zbuffer.cpp
	file path:	D:\workspace\creater\engine\Classes\network
	file base:	zbuffer
	file ext:	cpp
	author:		ferchiel
	
	purpose:	
*********************************************************************/

#include "zbuffer.h"

#include <assert.h>
#include <stdlib.h>


zBuffer::zBuffer(uint32 sz, uint32 vg /*= __zBufferGrouth*/)
	: _sz(sz)
	, _growth(vg)
{
	_begin = (char*)malloc(sz);
	_write = _read = _begin;
}

zBuffer::~zBuffer()
{
	::free(_begin);
	_begin = _write = _read = 0;
	_sz = 0;
}

uint32 zBuffer::growth()
{
	return _growth;
}

uint32 zBuffer::growth(uint32 v)
{
	return _growth += v;
}

int32 zBuffer::expend(uint32 sz)
{
	uint32 de2w = _begin + sz - _write;
	if (de2w >= sz)
		return 0;

	uint32 times = (sz - de2w) / _growth + 1;

	uint32 dw = _write - _begin;
	uint32 dr = _read - _begin;
	char* readdr = (char*)realloc(_begin, _sz += times * _growth);
	if (!readdr)
		return -1;

	_begin = readdr;
	_write = _begin + dw;
	_read = _begin + dr;
	return 0;
}

void zBuffer::reset()
{
	_read = _write = _begin;
	return;
}

char* zBuffer::rd_ptr()
{
	return _read;
}

void zBuffer::rd_ptr(uint32 sz)
{
	if (_read + sz <= _write)
		_read += sz;
}

char* zBuffer::wd_ptr()
{
	return _write;
}

void zBuffer::wd_ptr(uint32 sz)
{
	if (_write + sz <= _begin + _sz)
		_write += sz;
}

void zBuffer::tryreset()
{
	if (_read == _write)
		reset();
}

int32 zBuffer::avail()
{
	return _write - _read;
}

int32 zBuffer::free()
{
	return _begin + _sz - _write;
}



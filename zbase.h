/********************************************************************
	created:	2015/01/31
	created:	31:1:2015   17:22
	filename: 	D:\workspace\creater\engine\Classes\zbase.h
	file path:	D:\workspace\creater\engine\Classes
	file base:	zbase
	file ext:	h
	author:		ferchiel
	
	purpose:	
*********************************************************************/

#ifndef __Z_BASE_H__
#define __Z_BASE_H__

#include "ztype.h"
#include <map>

static enum
{
	__zClassNetwork = 0,
	__zClassBuffer,

	// add here
	__zClassCount,
};

static const char* __zClassName[] = {
	"zNetwork_",
	"zBuffer_",

	// add here
};

// init to 0
static int32 __obj_counter = 0;

class zEventBase
{
public:
	zEventBase();
	~zEventBase();

	virtual const char* get_class_name() = 0;
	virtual int32 get_object_id()
	{
		return __obj_id;
	}

	int32 registeEvent(const char* evt, int32 luafn);
	int32 unregisteEvent(const char* evt);
	int32 cleanupEvent();
	int32 getEventLuaFn(const char* evt);

private:
	std::map<std::string, int32> _eventsList;

	// obj id start from 0
	int32 __obj_id;
};


#endif


/********************************************************************
	created:	2015/01/31
	created:	31:1:2015   16:48
	filename: 	D:\workspace\creater\engine\Classes\lua\zluaevent.h
	file path:	D:\workspace\creater\engine\Classes\lua
	file base:	zluaevent
	file ext:	h
	author:		ferchiel
	
	purpose:	
*********************************************************************/

#ifndef __Z_LUA_EVENT_H__
#define __Z_LUA_EVENT_H__

#include "../ztype.h"
#include <map>
#include <queue>
#include <string>


class zEventBase;

typedef struct __zEvent
{
	int32 getId() { return _event_id; }

	std::string _event;
	int32 _objId;
	// add other infomation

private:
	int32 _event_id;
	int32 _release;

	__zEvent *_prev, *_next;

	// refused to external create
private:
	__zEvent() {};
	~__zEvent() {};
	friend class zEventFactory;
} zEvent, * p_zEvent;

class zEventFactory
{
public:
	static zEventFactory* inst();
	~zEventFactory();

	p_zEvent create();
	int32 release(int32 id);
	int32 release(p_zEvent evt);
	void makeDirty();
	int32 update(float dt);
	int32 clear();

private:
	zEventFactory();

private:
	int32 _event_id;
	int32 _dirty;
	p_zEvent _head, _tail;

	static zEventFactory* _inst;
};

class zEventDispatcher
{
public:
	static zEventDispatcher* inst();
	~zEventDispatcher();

	typedef int32 (*event_fn)(zEventBase*, int32);

public:
	int32 update(float dt);
	int32 init();

	int32 addProcessor(zEventBase* obj);
	int32 removeProcessor(int32 objId);

private:
	typedef std::map<std::string, event_fn> eventsExecute;
	// event name to execute function
	// event name = class name + event
	eventsExecute _executes;

	typedef std::map<int32, zEventBase*> eventsObject;
	// object is the event processor
	eventsObject _processors;


private:
	zEventDispatcher();

private:
	static zEventDispatcher *_inst;
};

class zEventPipe
{
public:
	static zEventPipe* inst();
	~zEventPipe();

	int32 command(p_zEvent evt);
	int32 command(const char *evt, zEventBase* obj);
	p_zEvent pop();
	int32 clear();
	int32 empty();
	int32 count();

private:
	zEventPipe();

private:
	std::queue<p_zEvent> _events;

	static zEventPipe *_inst;
};


#endif

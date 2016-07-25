#include "zbase.h"
#include "lua/zluaevent.h"


zEventBase::zEventBase()
	: __obj_id(++__obj_counter) 
{
	// add this to dispatcher
	zEventDispatcher *ed = zEventDispatcher::inst();
	ed->addProcessor(this);
}

zEventBase::~zEventBase()
{
	// remove events from dispatcher
	zEventDispatcher *ed = zEventDispatcher::inst();
	ed->removeProcessor(get_object_id());	
}

int32 zEventBase::registeEvent(const char* evt, int32 luafn)
{
	if (!evt)
		return -1;

	// make full event name
	std::string eventName = get_class_name();
	eventName += evt;

	_eventsList.insert(std::make_pair(eventName, luafn));
	return 0;
}

int32 zEventBase::unregisteEvent(const char* evt)
{
	if (!evt)
		return -1;

	// make full event name
	std::string eventName = get_class_name();
	eventName += evt;

	auto it = _eventsList.find(eventName);
	if (it != _eventsList.end())
		_eventsList.erase(it);

	return 0;
}

int32 zEventBase::cleanupEvent()
{
	_eventsList.clear();
	return 0;
}

int32 zEventBase::getEventLuaFn(const char* evt)
{
	if (!evt)
		return -1;

	auto it = _eventsList.find(evt);
	if (it == _eventsList.end())
		return -1;

	return  it->second;
}



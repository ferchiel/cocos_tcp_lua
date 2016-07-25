#include "zluaevent.h"
#include "../zbase.h"
#include "../event/zevent.h"

zEventFactory* zEventFactory::_inst = 0;
zEventFactory* zEventFactory::inst()
{
	if (!_inst)
	{
		_inst = new zEventFactory();
	}
	return _inst;
}

zEventFactory::zEventFactory()
	: _event_id(0)
	, _dirty(0)
	, _head(0)
	, _tail(0)
{

}

zEventFactory::~zEventFactory()
{
	clear();
}

p_zEvent zEventFactory::create()
{
	p_zEvent e = new __zEvent();
	e->_event_id = _event_id;
	e->_release = 0;
	e->_prev = 0;
	e->_next = 0;
	_event_id++;

	if (_tail)
	{
		_tail->_next = e;
		e->_prev = _tail;
		_tail = e;
		return e;
	}

	if (!_head && !_tail)
	{
		_head = _tail = e;
		return e;
	}

	//: todo err...fucking
	return 0;
}

int32 zEventFactory::release(int32 id)
{
	p_zEvent tar = _head;
	while (tar != _tail)
	{
		if (tar->getId() == id)
			return release(tar);

		tar = tar->_next;
	}
	// can`t find the event
	return -1;	
}

int32 zEventFactory::release(p_zEvent evt)
{
	evt->_release = 1;
	return evt->getId();
}

void zEventFactory::makeDirty()
{
	if (_dirty != 1)
		_dirty = 1;
}

int32 zEventFactory::update(float dt)
{
	if (!_dirty)
		return 0;

	p_zEvent p = _head;
	while (p)
	{
		if (!p->_release)
		{
			p = p->_next;
			continue;
		}

		p_zEvent pv = p->_prev;
		p_zEvent nt = p->_next;
		pv ? pv->_next = nt : _head = nt;
		nt ? nt->_prev = pv : _tail = pv;
		delete p;
		p = nt;
	}

	_dirty = 0;
	return 0;
}

int32 zEventFactory::clear()
{
	p_zEvent p = _head;
	while(p)
	{
		p_zEvent nt = p->_next;
		delete p;
		p = nt;
	}

	_head = 0;
	_tail = 0;
	return 0;
}

zEventDispatcher* zEventDispatcher::_inst = 0;
zEventDispatcher* zEventDispatcher::inst()
{
	if (!_inst)
	{
		_inst = new zEventDispatcher();
	}
	return _inst;
}

zEventDispatcher::zEventDispatcher()
{

}

zEventDispatcher::~zEventDispatcher()
{

}

int32 zEventDispatcher::update(float dt)
{
	zEventPipe *ep = zEventPipe::inst();
	zEventFactory *ef = zEventFactory::inst();

	while (!ep->empty())
	{
		p_zEvent e = ep->pop();

		auto pit = _processors.find(e->_objId);
		if (pit == _processors.end())
		{
			// obj already release
			// discard the event
			ef->release(e);
			continue;
		}
		zEventBase* obj = pit->second;

		auto eit = _executes.find(e->_event);
		if (eit == _executes.end())
		{
			ef->release(e);
			continue;
		}

		if ((eit->second)(obj, obj->getEventLuaFn(e->_event.c_str())))
		{
			//: todo 
			//execute event callback function err
		}

		ef->release(e);
	}
	return 0;
}

int32 zEventDispatcher::addProcessor(zEventBase* obj)
{
	if (!obj)
		return -1;

	auto ret = _processors.insert(std::make_pair(obj->get_object_id(), obj));
	if (!ret.second)
		return -1;

	return 0;
}

int32 zEventDispatcher::removeProcessor(int32 objId)
{
	auto it = _processors.find(objId);
	if (it == _processors.end())
		return -1;

	_processors.erase(it);
	return 0;
}

zEventPipe* zEventPipe::_inst = 0;
zEventPipe* zEventPipe::inst()
{
	if (!_inst)
	{
		_inst = new zEventPipe();
	}
	return _inst;
}

zEventPipe::zEventPipe()
{

}

zEventPipe::~zEventPipe()
{

}

int32 zEventPipe::command(p_zEvent evt)
{
	_events.push(evt);
	return 0;
}

int32 zEventPipe::command(const char *evt, zEventBase* obj)
{
	if (!evt || !obj)
		return -1;

	zEventFactory *fac = zEventFactory::inst();
	p_zEvent e = fac->create();

	if (!e)			// create event err
		return -1;

	// make full event name
	e->_event = obj->get_class_name();
	e->_event += evt;

	e->_objId = obj->get_object_id();

	return command(e);
}

p_zEvent zEventPipe::pop()
{
	p_zEvent ret = _events.front();
	_events.pop();
	return ret;
}

int32 zEventPipe::clear()
{
	_events.swap(std::queue<p_zEvent>());
	return 0;
}

int32 zEventPipe::empty()
{
	return _events.empty() ? 1 : 0;
}

int32 zEventPipe::count()
{
	return _events.size();
}



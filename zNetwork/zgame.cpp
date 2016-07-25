#include "zgame.h"
#include "lua/zluaevent.h"


bool zgame::applicationDidFinishLaunching()
{
	// init ... then run lua script
	zEventDispatcher *_eventDispatcher = zEventDispatcher::inst();
	if (_eventDispatcher->init() <= 0)
	{
		//: todo 
		// error log...
	}
	cocos2d::Director::getInstance()->getScheduler()->scheduleUpdateForTarget(this, 0, false);

	AppDelegate::applicationDidFinishLaunching();
	return true;
}

int32 zgame::update(float dt)
{
	// execute per frame
	zEventFactory *_eventFactory = zEventFactory::inst();
	if (_eventFactory->update(dt) != 0)
	{
		//: todo 
		// error log...
	}

	zEventDispatcher *_eventDispatcher = zEventDispatcher::inst();
	if (_eventDispatcher->update(dt) != 0)
	{
		//: todo
		// error log...
	}

	return 0;
}

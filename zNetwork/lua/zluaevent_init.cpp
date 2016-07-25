#include "event/zevent.h"
#include "zluaevent.h"

class zNetwork;
class zBuffer;

int32 zEventDispatcher::init()
{
	// wtf...
	std::string cls = __zClassName[__zClassNetwork];
	_executes[cls + "connect"] = evtNetworkConnect;
	_executes[cls + "disconnect"] = evtNetworkConnect;
	_executes[cls + "msgerr"] = evtNetworkConnect;
	_executes[cls + "data"] = evtNetworkConnect;

	return _executes.size();
}


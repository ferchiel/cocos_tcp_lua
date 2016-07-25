#include "zevent.h"
#include "../lua/zlua.h"

#include "../network/znetwork.h"
#include "../network/zbuffer.h"

int32 evtNetworkData(zEventBase* obj, int32 fn)
{
	// process network connect success
	// call back to lua function
#if __zLuaDebug <= 0
	zNetwork *nw = (zNetwork*)obj;
#else
	zNetwork *nw = dynamic_cast<zNetwork *>(obj);
	if (nullptr == nw)
	{
		printf("[EVENT]: evtNetworkConnect dynamic_cast obj err");
		return -1;
	}
#endif // __zLuaDebug <= 0
	auto L = cocos2d::LuaEngine::getInstance()->getLuaStack()->getLuaState();
	// get lua function
	toluafix_get_function_by_refid(L, fn);
	if (!lua_isfunction(L, -1))
	{
		printf("[LUA ERROR] function refid '%d' does not reference a Lua function", fn);
		lua_pop(L, 1);
		return false;
	}
	// push arguments
	object_to_luaval(L, "zBuffer", nw->getBuffer());

	if (0 != lua_pcall(L, 1, 0, 0))
	{
		CCLOG("[EVENT]: event call lua function error, lua function id: %d", fn);
		return -1;
	}

	return 0;
}

#include "zevent.h"
#include "lua/zlua.h"

#include "network/znetwork.h"

#include "cocos2d.h"
#include "CCLuaEngine.h"
#include "tolua_fix.h"
#include "LuaBasicConversions.h"


int32 evtNetworkDisconnect(zEventBase* obj, int32 fn)
{
	// process network connect success
	// call back to lua function
#if __zLuaDebug <= 0
	zNetwork *nw = (zNetwork*)obj;
#else
	zNetwork *nw = dynamic_cast<zNetwork *>(obj);
	if (nullptr == nw)
	{
		CCLOG("[EVENT]: evtNetworkConnect dynamic_cast obj err");
		return -1;
	}
#endif // __zLuaDebug <= 0

	auto L = cocos2d::LuaEngine::getInstance()->getLuaStack()->getLuaState();
	// get lua function
	toluafix_get_function_by_refid(L, fn);
	if (!lua_isfunction(L, -1))
	{
		CCLOG("[LUA ERROR] function refid '%d' does not reference a Lua function", fn);
		lua_pop(L, 1);
		return false;
	}
	// push arguments
	object_to_luaval(L, "zNetwork", nw);

	if (0 != lua_pcall(L, 1, 0, 0))
	{
		CCLOG("[EVENT]: event call lua function error, lua function id: %d", fn);
		return -1;
	}

	return 0;
}



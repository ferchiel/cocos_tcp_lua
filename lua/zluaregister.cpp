#include "zluaregister.h"
#include "lua/zluanetwork.h"
#include "lua/zluabuffer.h"

int32 register_z_module(lua_State* L)
{
	lua_getglobal(L, "_G");
	if (lua_istable(L, -1))
	{
		register_zbuffer(L);
		register_znetwork(L);
	}
	lua_pop(L, 1);
	return 1;
}


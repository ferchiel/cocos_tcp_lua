#ifndef __Z_LUA_H__
#define __Z_LUA_H__

extern "C"
{
#include "../lua5.1.4/lua.h"
#include "../lua5.1.4/lualib.h"
#include "../lua5.1.4/lauxlib.h"
}
#include "../ztype.h"

#define __zLuaFn(cls, fn) \
	int32 lua_##cls##_##fn(lua_State* L)

#define  __zRegFn(cls, fn) \
	tolua_function(L,#fn, lua_##cls##_##fn)


#endif
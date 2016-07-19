#ifndef __Z_LUA_H__
#define __Z_LUA_H__

#include "ztype.h"

#if __zLuaDebug
#include "tolua++.h"
static tolua_Error tolua_err;
#endif

#define __zLuaFn(cls, fn) \
	int32 lua_##cls##_##fn(lua_State* tolua_S)

#define  __zRegFn(cls, fn) \
	tolua_function(tolua_S,#fn, lua_##cls##_##fn)


#endif
#ifndef __Z_LUA_BUFFER_H__
#define __Z_LUA_BUFFER_H__

#include "ztype.h"

#ifdef __cplusplus
extern "C" {
#endif
#include "tolua++.h"
#ifdef __cplusplus
}
#endif

int32 register_zbuffer(lua_State* tolua_S);

#endif
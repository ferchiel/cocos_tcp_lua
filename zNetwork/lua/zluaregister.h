/********************************************************************
	created:	2015/01/28
	created:	28:1:2015   17:13
	filename: 	D:\workspace\creater\engine\Classes\lua\zluaregister.h
	file path:	D:\workspace\creater\engine\Classes\lua
	file base:	zluaregister
	file ext:	h
	author:		ferchiel
	
	purpose:	
*********************************************************************/

#ifndef __Z_LUA_REGISTER_H__
#define __Z_LUA_REGISTER_H__

#include "ztype.h"

#ifdef __cplusplus
extern "C" {
#endif
#include "tolua++.h"
#ifdef __cplusplus
}
#endif

// keep cocos styl
TOLUA_API int32 register_z_module(lua_State* L);


#endif


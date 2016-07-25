/********************************************************************
	created:	2015/01/28
	created:	28:1:2015   11:40
	filename: 	D:\workspace\creater\engine\Classes\lua\zluanetwork.h
	file path:	D:\workspace\creater\engine\Classes\lua
	file base:	zluanetwork
	file ext:	h
	author:		ferchiel
	
	purpose:	
*********************************************************************/

#ifndef __Z_LUA_NETWORK_H__
#define __Z_LUA_NETWORK_H__


#include "ztype.h"

#ifdef __cplusplus
extern "C" {
#endif
#include "tolua++.h"
#ifdef __cplusplus
}
#endif

int32 register_znetwork(lua_State* tolua_S);


#endif


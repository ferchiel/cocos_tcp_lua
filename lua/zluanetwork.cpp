#include "zluanetwork.h"
#include "zlua.h"
#include "network/znetwork.h"
#include "network/zbuffer.h"
#include "lua/zluaevent.h"
#include "LuaBasicConversions.h"


__zLuaFn(zNetwork, inst)
{
	uint8 args = 0;

#if __zLuaDebug >= 1
	if (!tolua_isusertable(tolua_S, 1, "znetwork", 0, &tolua_err))
	//if (!tolua_isusertype(tolua_S,1,"znetwork",0,&tolua_err))
	{
		tolua_error(tolua_S,"#ferror in function 'lua_znetwork_inst'.",&tolua_err);
		return 0;
	}
#endif

	args = lua_gettop(tolua_S)-1;
	if (args == 0)
	{
		zNetwork* znet = zNetwork::inst();
		object_to_luaval<zNetwork>(tolua_S, "znetwork", znet);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "znetwork inst",args, 0);
	return 0;
}


__zLuaFn(zNetwork, init)
{
	zNetwork* znet = 0;
	uint8 args = 0;

#if __zLuaDebug >= 1
	if (!tolua_isusertype(tolua_S,1,"znetwork",0,&tolua_err))
	{
		tolua_error(tolua_S,"#ferror in function 'lua_znetwork_init'.",&tolua_err);
		return 0;
	}
#endif

	znet = (zNetwork*)tolua_tousertype(tolua_S,1,0);

#if __zLuaDebug >= 1
	if (!znet) 
	{
		tolua_error(tolua_S,"invalid 'znetwork' in function 'lua_znetwork_init'", nullptr);
		return 0;
	}
#endif

	args = lua_gettop(tolua_S)-1;
	if (args == 0)
	{
		znet->init();
		return 0;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "znetwork:init(buffer size)",args, 1);
	return 0;
}

__zLuaFn(zNetwork, connect)
{
	zNetwork* znet = 0;
	uint8 args = 0;

#if __zLuaDebug >= 1
	if (!tolua_isusertype(tolua_S,1,"znetwork",0,&tolua_err))
	{
		tolua_error(tolua_S,"#ferror in function 'lua_znetwork_connect'.",&tolua_err);
		return 0;
	}
#endif

	znet = (zNetwork*)tolua_tousertype(tolua_S,1,0);

#if __zLuaDebug >= 1
	if (!znet) 
	{
		tolua_error(tolua_S,"invalid 'znetwork' in function 'lua_znetwork_connect'", nullptr);
		return 0;
	}
#endif

	args = lua_gettop(tolua_S)-1;
	if (args == 0)
	{
		znet->connect();
		return 0;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "znetwork:connect()",args, 0);
	return 0;
}

__zLuaFn(zNetwork, send)
{
	zNetwork* znet = 0;
	uint8 args = 0;

#if __zLuaDebug >= 1
	if (!tolua_isusertype(tolua_S,1,"znetwork",0,&tolua_err))
	{
		tolua_error(tolua_S,"#ferror in function 'lua_znetwork_send'.",&tolua_err);
		return 0;
	}
#endif

	znet = (zNetwork*)tolua_tousertype(tolua_S,1,0);

#if __zLuaDebug >= 1
	if (!znet) 
	{
		tolua_error(tolua_S,"invalid 'znetwork' in function 'lua_znetwork_send'", nullptr);
		return 0;
	}
#endif
	args = lua_gettop(tolua_S)-1;
	if (args == 1)
	{
		if (!tolua_isusertype(tolua_S, -1, "zbuffer", 0, &tolua_err))
		{
			tolua_error(tolua_S,"invalid argument type in function 'lua_znetwork_send', expecting 'zbuffer'", nullptr);
			return 0;
		}

		zBuffer *_buf = static_cast<zBuffer*>(tolua_tousertype(tolua_S, -1, 0));
		znet->send(_buf);
		return 0;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "znetwork:send(buffer)",args, 1);
	return 0;
}

__zLuaFn(zNetwork, clean)
{
	zNetwork* znet = 0;
	uint8 args = 0;

#if __zLuaDebug >= 1
	if (!tolua_isusertype(tolua_S,1,"znetwork",0,&tolua_err))
	{
		tolua_error(tolua_S,"#ferror in function 'lua_znetwork_clean'.",&tolua_err);
		return 0;
	}
#endif

	znet = (zNetwork*)tolua_tousertype(tolua_S,1,0);

#if __zLuaDebug >= 1
	if (!znet) 
	{
		tolua_error(tolua_S,"invalid 'znetwork' in function 'lua_znetwork_clean'", nullptr);
		return 0;
	}
#endif

	args = lua_gettop(tolua_S)-1;
	if (args == 0)
	{
		znet->clean();
		return 0;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "znetwork:clean()",args, 0);
	return 0;
}

__zLuaFn(zNetwork, disconnect)
{
	zNetwork* znet = 0;
	uint8 args = 0;

#if __zLuaDebug >= 1
	if (!tolua_isusertype(tolua_S,1,"znetwork",0,&tolua_err))
	{
		tolua_error(tolua_S,"#ferror in function 'lua_znetwork_disconnect'.",&tolua_err);
		return 0;
	}
#endif

	znet = (zNetwork*)tolua_tousertype(tolua_S,1,0);

#if __zLuaDebug >= 1
	if (!znet) 
	{
		tolua_error(tolua_S,"invalid 'znetwork' in function 'lua_znetwork_disconnect'", nullptr);
		return 0;
	}
#endif

	args = lua_gettop(tolua_S)-1;
	if (args == 0)
	{
		znet->disconnect();
		return 0;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "znetwork:disconnect()",args, 0);
	return 0;
}

__zLuaFn(zNetwork, getBuffer)
{
	zNetwork* znet = 0;
	uint8 args = 0;

#if __zLuaDebug >= 1
	if (!tolua_isusertype(tolua_S,1,"znetwork",0,&tolua_err))
	{
		tolua_error(tolua_S,"#ferror in function 'lua_znetwork_getBuffer'.",&tolua_err);
		return 0;
	}
#endif

	znet = (zNetwork*)tolua_tousertype(tolua_S,1,0);

#if __zLuaDebug >= 1
	if (!znet) 
	{
		tolua_error(tolua_S,"invalid 'znetwork' in function 'lua_znetwork_getBuffer'", nullptr);
		return 0;
	}
#endif

	args = lua_gettop(tolua_S)-1;
	if (args == 0)
	{
		zBuffer *_buffer = znet->getBuffer();
		object_to_luaval<zBuffer>(tolua_S, "zbuffer", _buffer);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "znetwork:getBuffer()",args, 0);
	return 0;
}

__zLuaFn(zNetwork, msg)
{
	zNetwork* znet = 0;
	uint8 args = 0;

#if __zLuaDebug >= 1
	if (!tolua_isusertype(tolua_S,1,"znetwork",0,&tolua_err))
	{
		tolua_error(tolua_S,"#ferror in function 'lua_znetwork_msg'.",&tolua_err);
		return 0;
	}
#endif

	znet = (zNetwork*)tolua_tousertype(tolua_S,1,0);

#if __zLuaDebug >= 1
	if (!znet) 
	{
		tolua_error(tolua_S,"invalid 'znetwork' in function 'lua_znetwork_msg'", nullptr);
		return 0;
	}
#endif

	args = lua_gettop(tolua_S)-1;
	if (args == 0)
	{
		int32 msg = znet->msg();
		tolua_pushnumber(tolua_S, msg);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "znetwork:msg()",args, 0);
	return 0;
}

__zLuaFn(zNetwork, incMsg)
{
	zNetwork* znet = 0;
	uint8 args = 0;

#if __zLuaDebug >= 1
	if (!tolua_isusertype(tolua_S,1,"znetwork",0,&tolua_err))
	{
		tolua_error(tolua_S,"#ferror in function 'lua_znetwork_incMsg'.",&tolua_err);
		return 0;
	}
#endif

	znet = (zNetwork*)tolua_tousertype(tolua_S,1,0);

#if __zLuaDebug >= 1
	if (!znet) 
	{
		tolua_error(tolua_S,"invalid 'znetwork' in function 'lua_znetwork_incMsg'", nullptr);
		return 0;
	}
#endif

	args = lua_gettop(tolua_S)-1;
	if (args == 0)
	{
		int32 msg = znet->incMsg();
		tolua_pushnumber(tolua_S, msg);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "znetwork:incMsg()",args, 0);
	return 0;
}

__zLuaFn(zNetwork, decMsg)
{
	zNetwork* znet = 0;
	uint8 args = 0;

#if __zLuaDebug >= 1
	if (!tolua_isusertype(tolua_S,1,"znetwork",0,&tolua_err))
	{
		tolua_error(tolua_S,"#ferror in function 'lua_znetwork_decMsg'.",&tolua_err);
		return 0;
	}
#endif

	znet = (zNetwork*)tolua_tousertype(tolua_S,1,0);

#if __zLuaDebug >= 1
	if (!znet) 
	{
		tolua_error(tolua_S,"invalid 'znetwork' in function 'lua_znetwork_decMsg'", nullptr);
		return 0;
	}
#endif

	args = lua_gettop(tolua_S)-1;
	if (args == 0)
	{
		int32 msg = znet->decMsg();
		tolua_pushnumber(tolua_S, msg);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "znetwork:decMsg()",args, 0);
	return 0;
}

__zLuaFn(zNetwork, on)
{
	zNetwork* znet = 0;
	uint8 args = 0;

#if __zLuaDebug >= 1
	if (!tolua_isusertype(tolua_S,1,"znetwork",0,&tolua_err))
	{
		tolua_error(tolua_S,"#ferror in function 'lua_znetwork_on'.",&tolua_err);
		return 0;
	}
#endif

	znet = (zNetwork*)tolua_tousertype(tolua_S,1,0);

#if __zLuaDebug >= 1
	if (!znet) 
	{
		tolua_error(tolua_S,"invalid 'znetwork' in function 'lua_znetwork_on'", nullptr);
		return 0;
	}
#endif

	args = lua_gettop(tolua_S)-1;
	if (args == 2)
	{
		const char *_eventName = tolua_tostring(tolua_S, 2, "");
		if (strcmp(_eventName, "") == 0)
		{
			tolua_error(tolua_S,"invalid argument type in function 'lua_znetwork_on' string, expecting 'znetwork'", nullptr);
			return 0;
		}

		int32 fn_id =  toluafix_ref_function(tolua_S, 3, 0);
		if (fn_id == 0)
		{
			tolua_error(tolua_S,"invalid argument type in function 'lua_znetwork_on' ref function, expecting 'znetwork'", nullptr);
			return 0;
		}

		znet->registeEvent(_eventName, fn_id);

		return 0;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "znetwork:on()",args, 2);
	return 0;
}

int32 register_znetwork(lua_State* tolua_S)
{
	tolua_usertype(tolua_S,"znetwork");
	tolua_cclass(tolua_S,"znetwork","znetwork","",nullptr);

	tolua_beginmodule(tolua_S,"znetwork");

	__zRegFn(zNetwork, inst);
	__zRegFn(zNetwork, init);
	__zRegFn(zNetwork, connect);
	__zRegFn(zNetwork, disconnect);
	__zRegFn(zNetwork, send);
	__zRegFn(zNetwork, clean);
	__zRegFn(zNetwork, getBuffer);
	__zRegFn(zNetwork, msg);
	__zRegFn(zNetwork, incMsg);
	__zRegFn(zNetwork, decMsg);
	__zRegFn(zNetwork, on);

	tolua_endmodule(tolua_S);
	std::string typeName = typeid(zNetwork).name();
	g_luaType[typeName] = "znetwork";
	g_typeCast["znetwork"] = "znetwork";
	return 1;
}

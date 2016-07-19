#include "zluabuffer.h"
#include "zlua.h"
#include "network/zbuffer.h"
#include "LuaBasicConversions.h"
#include "lua/zluaevent.h"


__zLuaFn(zBuffer, create)
{
	zBuffer* buffer = 0;
	uint8 args = 0;

#if __zLuaDebug >= 1
	if (!tolua_isusertable(tolua_S,1,"zbuffer",0,&tolua_err))
	{
		tolua_error(tolua_S,"#ferror in function 'lua_zbuffer_create'.",&tolua_err);
		return 0;
	}
#endif

	args = lua_gettop(tolua_S)-1;
	if (args == 1)
	{
		if (!tolua_isnumber(tolua_S, -1, 0, &tolua_err))
		{
			tolua_error(tolua_S,"invalid argument type in function 'lua_zbuffer_create', expecting a number",&tolua_err);
			return 0;
		}
		int32 sz = tolua_tonumber(tolua_S, -1, 0);
		buffer = new zBuffer(sz);
		object_to_luaval<zBuffer>(tolua_S, "zbuffer", buffer);
		return 1;
	}
	else if (args == 2)
	{
		if (!tolua_isnumber(tolua_S, -1, 0, &tolua_err))
		{
			tolua_error(tolua_S,"invalid argument #1 type in function 'lua_zbuffer_create', expecting a number",&tolua_err);
			return 0;
		}
		if (!tolua_isnumber(tolua_S, -2, 0, &tolua_err))
		{
			tolua_error(tolua_S,"invalid argument #2 type in function 'lua_zbuffer_create', expecting a number",&tolua_err);
			return 0;
		}
		int32 sz = tolua_tonumber(tolua_S, -2, 0);
		int32 grouth = tolua_tonumber(tolua_S, -1, 0);
		buffer = new zBuffer(sz, grouth);
		object_to_luaval<zBuffer>(tolua_S, "zbuffer", buffer);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zbuffer:create(sz, grouth)",args, 1);
	return 0;
}

__zLuaFn(zBuffer, release)
{
	zBuffer* buffer = 0;
	uint8 args = 0;

#if __zLuaDebug >= 1
	if (!tolua_isusertype(tolua_S,1,"zbuffer",0,&tolua_err))
	{
		tolua_error(tolua_S,"#ferror in function 'lua_zbuffer_release'.",&tolua_err);
		return 0;
	}
#endif

	buffer = (zBuffer*)tolua_tousertype(tolua_S,1,0);

#if __zLuaDebug >= 1
	if (!buffer) 
	{
		tolua_error(tolua_S,"invalid 'zbuffer' in function 'lua_zbuffer_release'", nullptr);
		return 0;
	}
#endif

	args = lua_gettop(tolua_S)-1;
	if (args == 0)
	{
		delete buffer;
		return 0;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zbuffer:release()",args, 0);
	return 0;
}

__zLuaFn(zBuffer, int8)
{
	zBuffer* buffer = 0;
	uint8 args = 0;

#if __zLuaDebug >= 1
	if (!tolua_isusertype(tolua_S,1,"zbuffer",0,&tolua_err))
		return 0;
#endif

	buffer = (zBuffer*)tolua_tousertype(tolua_S,1,0);

#if __zLuaDebug >= 1
	if (!buffer) 
	{
		tolua_error(tolua_S,"invalid 'zbuffer' in function 'lua_zbuffer_int8'", nullptr);
		return 0;
	}
#endif

	args = lua_gettop(tolua_S)-1;
	if (args == 0)
	{
		int8 v = buffer->get<int8>();
		tolua_pushnumber(tolua_S, v);
		return 1;
	}
	else if (args == 1)
	{
		int8 v = tolua_tonumber(tolua_S, -1, 0);
		buffer->set(v);
		return 0;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zbuffer:int8()",args, 0);
	return 0;
}

__zLuaFn(zBuffer, int16)
{
	zBuffer* buffer = 0;
	uint8 args = 0;

#if __zLuaDebug >= 1
	if (!tolua_isusertype(tolua_S,1,"zbuffer",0,&tolua_err))
		return 0;
#endif

	buffer = (zBuffer*)tolua_tousertype(tolua_S,1,0);

#if __zLuaDebug >= 1
	if (!buffer) 
	{
		tolua_error(tolua_S,"invalid 'zbuffer' in function 'lua_zbuffer_int16'", nullptr);
		return 0;
	}
#endif

	args = lua_gettop(tolua_S) - 1;
	if (args == 0)
	{
		int16 v = buffer->get<int16>();
		tolua_pushnumber(tolua_S, v);
		return 1;
	}
	else if (args == 1)
	{
		int16 v = tolua_tonumber(tolua_S, -1, 0);
		buffer->set(v);
		return 0;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zbuffer:int16()",args, 0);
	return 0;
}

__zLuaFn(zBuffer, int32)
{
	zBuffer* buffer = 0;
	uint8 args = 0;

#if __zLuaDebug >= 1
	if (!tolua_isusertype(tolua_S,1,"zbuffer",0,&tolua_err))
		return 0;
#endif

	buffer = (zBuffer*)tolua_tousertype(tolua_S,1,0);

#if __zLuaDebug >= 1
	if (!buffer) 
	{
		tolua_error(tolua_S,"invalid 'zbuffer' in function 'lua_zbuffer_int32", nullptr);
		return 0;
	}
#endif

	args = lua_gettop(tolua_S) - 1;
	if (args == 0)
	{
		int32 v = buffer->get<int32>();
		tolua_pushnumber(tolua_S, v);
		return 1;
	}
	else if (args == 1)
	{
		int32 v = tolua_tonumber(tolua_S, -1, 0);
		buffer->set(v);
		return 0;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zbuffer:int32()",args, 0);
	return 0;
}

__zLuaFn(zBuffer, int64)
{
	zBuffer* buffer = 0;
	uint8 args = 0;

#if __zLuaDebug >= 1
	if (!tolua_isusertype(tolua_S,1,"zbuffer",0,&tolua_err))
		return 0;
#endif

	buffer = (zBuffer*)tolua_tousertype(tolua_S,1,0);

#if __zLuaDebug >= 1
	if (!buffer) 
	{
		tolua_error(tolua_S,"invalid 'zbuffer' in function 'lua_zbuffer_int64'", nullptr);
		return 0;
	}
#endif

	args = lua_gettop(tolua_S) - 1;
	if (args == 0)
	{
		int64 v = buffer->get<int64>();
		tolua_pushnumber(tolua_S, v);
		return 1;
	}
	else if (args == 1)
	{
		int64 v = tolua_tonumber(tolua_S, -1, 0);
		buffer->set(v);
		return 0;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zbuffer:int64()",args, 0);
	return 0;
}

__zLuaFn(zBuffer, uint8)
{
	zBuffer* buffer = 0;
	uint8 args = 0;

#if __zLuaDebug >= 1
	if (!tolua_isusertype(tolua_S,1,"zbuffer",0,&tolua_err))
		return 0;
#endif

	buffer = (zBuffer*)tolua_tousertype(tolua_S,1,0);

#if __zLuaDebug >= 1
	if (!buffer) 
	{
		tolua_error(tolua_S,"invalid 'zbuffer' in function 'lua_zbuffer_uint8'", nullptr);
		return 0;
	}
#endif

	args = lua_gettop(tolua_S)-1;
	if (args == 0)
	{
		uint8 v = buffer->get<uint8>();
		tolua_pushnumber(tolua_S, v);
		return 1;
	}
	else if (args == 1)
	{
		uint8 v = tolua_tonumber(tolua_S, -1, 0);
		buffer->set(v);
		return 0;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zbuffer:uint8()",args, 0);
	return 0;
}

__zLuaFn(zBuffer, uint16)
{
	zBuffer* buffer = 0;
	uint8 args = 0;

#if __zLuaDebug >= 1
	if (!tolua_isusertype(tolua_S,1,"zbuffer",0,&tolua_err))
		return 0;
#endif

	buffer = (zBuffer*)tolua_tousertype(tolua_S,1,0);

#if __zLuaDebug >= 1
	if (!buffer) 
	{
		tolua_error(tolua_S,"invalid 'zbuffer' in function 'lua_zbuffer_uint16'", nullptr);
		return 0;
	}
#endif

	args = lua_gettop(tolua_S)-1;
	if (args == 0)
	{
		uint16 v = buffer->get<uint16>();
		tolua_pushnumber(tolua_S, v);
		return 1;
	}
	else if (args == 1)
	{
		uint16 v = tolua_tonumber(tolua_S, -1, 0);
		buffer->set(v);
		return 0;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zbuffer:uint16()",args, 0);
	return 0;
}

__zLuaFn(zBuffer, uint32)
{
	zBuffer* buffer = 0;
	uint8 args = 0;

#if __zLuaDebug >= 1
	if (!tolua_isusertype(tolua_S,1,"zbuffer",0,&tolua_err))
		return 0;
#endif

	buffer = (zBuffer*)tolua_tousertype(tolua_S,1,0);

#if __zLuaDebug >= 1
	if (!buffer) 
	{
		tolua_error(tolua_S,"invalid 'zbuffer' in function 'lua_zbuffer_uint32'", nullptr);
		return 0;
	}
#endif

	args = lua_gettop(tolua_S)-1;
	if (args == 0)
	{
		uint32 v = buffer->get<uint32>();
		tolua_pushnumber(tolua_S, v);
		return 1;
	}
	else if (args == 1)
	{
		uint32 v = tolua_tonumber(tolua_S, -1, 0);
		buffer->set(v);
		return 0;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zbuffer:uint32()",args, 0);
	return 0;
}

__zLuaFn(zBuffer, uint64)
{
	zBuffer* buffer = 0;
	uint8 args = 0;

#if __zLuaDebug >= 1
	if (!tolua_isusertype(tolua_S,1,"zbuffer",0,&tolua_err))
		return 0;
#endif

	buffer = (zBuffer*)tolua_tousertype(tolua_S,1,0);

#if __zLuaDebug >= 1
	if (!buffer) 
	{
		tolua_error(tolua_S,"invalid 'zbuffer' in function 'lua_zbuffer_uint64'", nullptr);
		return 0;
	}
#endif

	args = lua_gettop(tolua_S)-1;
	if (args == 0)
	{
		uint64 v = buffer->get<uint64>();
		tolua_pushnumber(tolua_S, v);
		return 1;
	}
	else if (args == 1)
	{
		uint64 v = tolua_tonumber(tolua_S, -1, 0);
		buffer->set(v);
		return 0;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zbuffer:uint64()",args, 0);
	return 0;
}

__zLuaFn(zBuffer, float)
{
	zBuffer* buffer = 0;
	uint8 args = 0;

#if __zLuaDebug >= 1
	if (!tolua_isusertype(tolua_S,1,"zbuffer",0,&tolua_err))
		return 0;
#endif

	buffer = (zBuffer*)tolua_tousertype(tolua_S,1,0);

#if __zLuaDebug >= 1
	if (!buffer) 
	{
		tolua_error(tolua_S,"invalid 'zbuffer' in function 'lua_zbuffer_float'", nullptr);
		return 0;
	}
#endif

	args = lua_gettop(tolua_S)-1;
	if (args == 0)
	{
		float v = buffer->get<float>();
		tolua_pushnumber(tolua_S, v);
		return 1;
	}
	else if (args == 1)
	{
		float v = tolua_tonumber(tolua_S, -1, 0);
		buffer->set(v);
		return 0;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zbuffer:float()",args, 0);
	return 0;
}

__zLuaFn(zBuffer, double)
{
	zBuffer* buffer = 0;
	uint8 args = 0;

#if __zLuaDebug >= 1
	if (!tolua_isusertype(tolua_S,1,"zbuffer",0,&tolua_err))
		return 0;
#endif

	buffer = (zBuffer*)tolua_tousertype(tolua_S,1,0);

#if __zLuaDebug >= 1
	if (!buffer) 
	{
		tolua_error(tolua_S,"invalid 'zbuffer' in function 'lua_zbuffer_float'", nullptr);
		return 0;
	}
#endif

	args = lua_gettop(tolua_S)-1;
	if (args == 0)
	{
		float v = buffer->get<float>();
		tolua_pushnumber(tolua_S, v);
		return 1;
	}
	else if (args == 1)
	{
		float v = tolua_tonumber(tolua_S, -1, 0);
		buffer->set(v);
		return 0;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zbuffer:float()",args, 0);
	return 0;
}

__zLuaFn(zBuffer, string)
{
	zBuffer* buffer = 0;
	uint8 args = 0;

#if __zLuaDebug >= 1
	if (!tolua_isusertype(tolua_S,1,"zbuffer",0,&tolua_err))
		return 0;
#endif

	buffer = (zBuffer*)tolua_tousertype(tolua_S,1,0);

#if __zLuaDebug >= 1
	if (!buffer) 
	{
		tolua_error(tolua_S,"invalid 'zbuffer' in function 'lua_zbuffer_string'", nullptr);
		return 0;
	}
#endif

	args = lua_gettop(tolua_S)-1;
	if (args == 0)
	{
		const char* v = buffer->get<const char*>();
		tolua_pushstring(tolua_S, v);
		return 1;
	}
	else if (args == 1)
	{
		const char* v = tolua_tostring(tolua_S, -1, 0);
		buffer->set(v);
		return 0;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zbuffer:string()",args, 0);
	return 0;
}

__zLuaFn(zBuffer, table)
{
	//: todo
	// wtf 一毛钱的思路都没有...
	return 0;
}

__zLuaFn(zBuffer, bin)		// what`s this???
{
	return 0;
}

__zLuaFn(zBuffer, read)
{
	return 0;
}

__zLuaFn(zBuffer, rd_ptr)
{
	return 0;
}

__zLuaFn(zBuffer, wr_ptr)
{
	return 0;
}

__zLuaFn(zBuffer, reset)
{
	zBuffer* buffer = 0;
	uint8 args = 0;

#if __zLuaDebug >= 1
	if (!tolua_isusertype(tolua_S,1,"zbuffer",0,&tolua_err))
		return 0;
#endif

	buffer = (zBuffer*)tolua_tousertype(tolua_S,1,0);

#if __zLuaDebug >= 1
	if (!buffer) 
	{
		tolua_error(tolua_S,"invalid 'zbuffer' in function 'lua_zbuffer_reset'", nullptr);
		return 0;
	}
#endif

	args = lua_gettop(tolua_S)-1;
	if (args == 0)
	{
		buffer->reset();
		return 0;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zbuffer:reset()",args, 0);
	return 0;
}

__zLuaFn(zBuffer, avail)
{
	zBuffer* buffer = 0;
	uint8 args = 0;

#if __zLuaDebug >= 1
	if (!tolua_isusertype(tolua_S,1,"zbuffer",0,&tolua_err))
		return 0;
#endif

	buffer = (zBuffer*)tolua_tousertype(tolua_S,1,0);

#if __zLuaDebug >= 1
	if (!buffer) 
	{
		tolua_error(tolua_S,"invalid 'zbuffer' in function 'lua_zbuffer_avail'", nullptr);
		return 0;
	}
#endif

	args = lua_gettop(tolua_S)-1;
	if (args == 0)
	{
		int32 v = buffer->avail();
		tolua_pushnumber(tolua_S, v);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zbuffer:avail()",args, 0);
	return 0;
}

__zLuaFn(zBuffer, free)
{
	zBuffer* buffer = 0;
	uint8 args = 0;

#if __zLuaDebug >= 1
	if (!tolua_isusertype(tolua_S,1,"zbuffer",0,&tolua_err))
		return 0;
#endif

	buffer = (zBuffer*)tolua_tousertype(tolua_S,1,0);

#if __zLuaDebug >= 1
	if (!buffer) 
	{
		tolua_error(tolua_S,"invalid 'zbuffer' in function 'lua_zbuffer_free'", nullptr);
		return 0;
	}
#endif

	args = lua_gettop(tolua_S)-1;
	if (args == 0)
	{
		int32 v = buffer->free();
		tolua_pushnumber(tolua_S, v);
		return 1;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zbuffer:free()",args, 0);
	return 0;
}

__zLuaFn(zBuffer, growth)
{
	zBuffer* buffer = 0;
	uint8 args = 0;

#if __zLuaDebug >= 1
	if (!tolua_isusertype(tolua_S,1,"zbuffer",0,&tolua_err))
		return 0;
#endif

	buffer = (zBuffer*)tolua_tousertype(tolua_S,1,0);

#if __zLuaDebug >= 1
	if (!buffer) 
	{
		tolua_error(tolua_S,"invalid 'zbuffer' in function 'lua_zbuffer_growth'", nullptr);
		return 0;
	}
#endif

	args = lua_gettop(tolua_S)-1;
	if (args == 0)
	{
		uint32 v = buffer->growth();
		tolua_pushnumber(tolua_S, v);
		return 1;
	}
	else if (args == 1)
	{
		uint32 v = tolua_tonumber(tolua_S, -1, 0);
		buffer->growth(v);
		return 0;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zbuffer:growth()",args, 0);
	return 0;
}

__zLuaFn(zBuffer, on)
{
	zBuffer* zbuf = 0;
	uint8 args = 0;

#if __zLuaDebug >= 1
	if (!tolua_isusertype(tolua_S,1,"zbuffer",0,&tolua_err))
	{
		tolua_error(tolua_S,"#ferror in function 'lua_zbuffer_on'.",&tolua_err);
		return 0;
	}
#endif

	zbuf = (zBuffer*)tolua_tousertype(tolua_S,1,0);

#if __zLuaDebug >= 1
	if (!zbuf)
	{
		tolua_error(tolua_S,"invalid 'zbuffer' in function 'lua_zbuffer_on'", nullptr);
		return 0;
	}
#endif

	args = lua_gettop(tolua_S)-1;
	if (args == 2)
	{
		const char *_eventName = tolua_tostring(tolua_S, 2, "");
		if (strcmp(_eventName, "") == 0)
		{
			tolua_error(tolua_S,"invalid argument type in function 'lua_zbuffer_on' string, expecting 'zbuffer'", nullptr);
			return 0;
		}

		int32 fn_id =  toluafix_ref_function(tolua_S, 3, 0);
		if (fn_id == 0)
		{
			tolua_error(tolua_S,"invalid argument type in function 'lua_zbuffer_on' ref function, expecting 'zbuffer'", nullptr);
			return 0;
		}

		zbuf->registeEvent(_eventName, fn_id);

		return 0;
	}
	luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "zbuffer:on()",args, 2);
	return 0;
}

int32 register_zbuffer(lua_State* tolua_S)
{
	tolua_usertype(tolua_S,"zbuffer");
	tolua_cclass(tolua_S,"zbuffer","zbuffer","",nullptr);

	tolua_beginmodule(tolua_S,"zbuffer");

	__zRegFn(zBuffer, create);
	__zRegFn(zBuffer, release);
	__zRegFn(zBuffer, int8);
	__zRegFn(zBuffer, uint8);
	__zRegFn(zBuffer, int16);
	__zRegFn(zBuffer, uint16);
	__zRegFn(zBuffer, int32);
	__zRegFn(zBuffer, uint32);
	__zRegFn(zBuffer, int64);
	__zRegFn(zBuffer, uint64);
	__zRegFn(zBuffer, float);
	__zRegFn(zBuffer, double);
	__zRegFn(zBuffer, string);
	__zRegFn(zBuffer, table);
	//////////////////////////////////////////////////////////////////////////
	// 暂时没有实现
	__zRegFn(zBuffer, bin);
	__zRegFn(zBuffer, read);
	__zRegFn(zBuffer, rd_ptr);
	__zRegFn(zBuffer, wr_ptr);
	//////////////////////////////////////////////////////////////////////////
	__zRegFn(zBuffer, reset);
	__zRegFn(zBuffer, avail);			// get available bytes for reading
	__zRegFn(zBuffer, free);			// get free bytes for writing
	__zRegFn(zBuffer, growth);		// get / set growth value
	__zRegFn(zBuffer, on);

	tolua_endmodule(tolua_S);

	std::string typeName = typeid(zBuffer).name();
	g_luaType[typeName] = "zbuffer";
	g_typeCast["zbuffer"] = "zbuffer";

	return 1;
}

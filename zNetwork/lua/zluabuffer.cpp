#include "zluabuffer.h"
#include "zlua.h"
#include "../network/zbuffer.h"
#include "zluaevent.h"

//#define _POP_AND_RETURN()

__zLuaFn(zBuffer, create)
{
	int args = lua_gettop(L);
	if (args == 1)
	{
		if (!lua_isnumber(L, -1))
			return 0;

		int sz = lua_tonumber(L, -1);
		lua_pop(L, 1);
		zBuffer* buf = new zBuffer(sz);
		if (!buf)
			return 0;
		
		lua_pushlightuserdata(L, (void*)buf);
		return 1;
	}
	else if (args == 2)
	{
		if (!lua_isnumber(L, -1) || !lua_isnumber(L, -2))
			return 0;
		int sz = lua_tonumber(L, -1);
		int grouth = lua_tonumber(L, -2);
		lua_pop(L, 2);
		zBuffer* buf = new zBuffer(sz, grouth);
		if (!buf)
			return 0;
		lua_pushlightuserdata(L, (void*)buf);
		return 1;
	}
	return 0;
}

__zLuaFn(zBuffer, release)
{
	if (!lua_isuserdata(L, -1))
		return 0;
	zBuffer* buffer = (zBuffer*)lua_touserdata(L, -1);
	lua_pop(L, 1);
	delete buffer;
	return 0;
}

__zLuaFn(zBuffer, int8)
{
	int args = lua_gettop(L);
	if (args == 1)
	{
		if (!lua_isuserdata(L, -1))
			return 0;

		zBuffer* buf = (zBuffer*)lua_touserdata(L, -1);
		lua_pop(L, 1);
		if (!buf)
			return 0;
		int8 ret = buf->get<int8>();
		lua_pushnumber(L, ret);
		return 1;
	}
	else if (args == 2)
	{
		if (!lua_isuserdata(L, -1) || !lua_isnumber(L, -2))
			return 0;

		zBuffer* buf = (zBuffer*)lua_touserdata(L, -1);
		int8 v = (int8)lua_tonumber(L, -2);
		lua_pop(L, 2);
		if (!buf)
			return 0;
		
		buf->set<int8>(v);
		return 0;
	}
	return 0;
}

__zLuaFn(zBuffer, int16)
{
	int args = lua_gettop(L);
	if (args == 1)
	{
		if (!lua_isuserdata(L, -1))
			return 0;

		zBuffer* buf = (zBuffer*)lua_touserdata(L, -1);
		lua_pop(L, 1);
		if (!buf)
			return 0;
		int16 ret = buf->get<int16>();
		lua_pushnumber(L, ret);
		return 1;
	}
	else if (args == 2)
	{
		if (!lua_isuserdata(L, -1) || !lua_isnumber(L, -2))
			return 0;
		zBuffer* buf = (zBuffer*)lua_touserdata(L, -1);
		int16 v = (int16)lua_tonumber(L, -2);
		lua_pop(L, 2);
		if (!buf)
			return 0;
		
		buf->set<int16>(v);
		return 0;
	}
	return 0;
}

__zLuaFn(zBuffer, int32)
{
	int args = lua_gettop(L);
	if (args == 1)
	{
		if (!lua_isuserdata(L, -1))
			return 0;

		zBuffer* buf = (zBuffer*)lua_touserdata(L, -1);
		lua_pop(L, 1);
		if (!buf)
			return 0;
		int32 ret = buf->get<int32>();
		lua_pushnumber(L, ret);
		return 1;
	}
	else if (args == 2)
	{
		if (!lua_isuserdata(L, -1) || !lua_isnumber(L, -2))
			return 0;
		zBuffer* buf = (zBuffer*)lua_touserdata(L, -1);
		int32 v = (int32)lua_tonumber(L, -2);
		lua_pop(L, 2);
		if (!buf)
			return 0;
		
		buf->set<int32>(v);
		return 0;
	}
	return 0;
}

__zLuaFn(zBuffer, int64)
{
	int args = lua_gettop(L);
	if (args == 1)
	{
		if (!lua_isuserdata(L, -1))
			return 0;

		zBuffer* buf = (zBuffer*)lua_touserdata(L, -1);
		lua_pop(L, 1);
		if (!buf)
			return 0;
		int64 ret = buf->get<int64>();
		lua_pushnumber(L, ret);
		return 1;
	}
	else if (args == 2)
	{
		if (!lua_isuserdata(L, -1) || !lua_isnumber(L, -2))
			return 0;
		zBuffer* buf = (zBuffer*)lua_touserdata(L, -1);
		int64 v = (int64)lua_tonumber(L, -2);
		lua_pop(L, 2);
		if (!buf)
			return 0;
		
		buf->set<int64>(v);
		return 0;
	}
	return 0;
}

__zLuaFn(zBuffer, uint8)
{
	int args = lua_gettop(L);
	if (args == 1)
	{
		if (!lua_isuserdata(L, -1))
			return 0;

		zBuffer* buf = (zBuffer*)lua_touserdata(L, -1);
		lua_pop(L, 1);
		if (!buf)
			return 0;
		lua_settop(L, 0);
		uint8 ret = buf->get<uint8>();
		lua_pushnumber(L, ret);
		return 1;
	}
	else if (args == 2)
	{
		if (!lua_isuserdata(L, -1) || !lua_isnumber(L, -2))
			return 0;
		zBuffer* buf = (zBuffer*)lua_touserdata(L, -1);
		uint8 v = (uint8)lua_tonumber(L, -2);
		lua_pop(L, 2);
		if (!buf)
			return 0;
		
		buf->set<uint8>(v);
		return 0;
	}
	return 0;
}

__zLuaFn(zBuffer, uint16)
{
	int args = lua_gettop(L);
	if (args == 1)
	{
		if (!lua_isuserdata(L, -1))
			return 0;

		zBuffer* buf = (zBuffer*)lua_touserdata(L, -1);
		lua_pop(L, 1);
		if (!buf)
			return 0;
		uint16 ret = buf->get<uint16>();
		lua_pushnumber(L, ret);
		return 1;
	}
	else if (args == 2)
	{
		if (!lua_isuserdata(L, -1) || !lua_isnumber(L, -2))
			return 0;
		zBuffer* buf = (zBuffer*)lua_touserdata(L, -1);
		uint16 v = (uint16)lua_tonumber(L, -2);
		lua_pop(L, 2);
		if (!buf)
			return 0;
		
		buf->set<uint16>(v);
		return 0;
	}
	return 0;
}

__zLuaFn(zBuffer, uint32)
{
	int args = lua_gettop(L);
	if (args == 1)
	{
		if (!lua_isuserdata(L, -1))
			return 0;

		zBuffer* buf = (zBuffer*)lua_touserdata(L, -1);
		lua_pop(L, 1);
		if (!buf)
			return 0;
		uint32 ret = buf->get<uint32>();
		lua_pushnumber(L, ret);
		return 1;
	}
	else if (args == 2)
	{
		if (!lua_isuserdata(L, -1) || !lua_isnumber(L, -2))
			return 0;
		zBuffer* buf = (zBuffer*)lua_touserdata(L, -1);
		uint32 v = (uint32)lua_tonumber(L, -2);
		lua_pop(L, 2);
		if (!buf)
			return 0;
		
		buf->set<uint32>(v);
		return 0;
	}
	return 0;
}

__zLuaFn(zBuffer, uint64)
{
	int args = lua_gettop(L);
	if (args == 1)
	{
		if (!lua_isuserdata(L, -1))
			return 0;

		zBuffer* buf = (zBuffer*)lua_touserdata(L, -1);
		lua_pop(L, 1);
		if (!buf)
			return 0;
		uint64 ret = buf->get<uint64>();
		lua_pushnumber(L, ret);
		return 1;
	}
	else if (args == 2)
	{
		if (!lua_isuserdata(L, -1) || !lua_isnumber(L, -2))
			return 0;
		zBuffer* buf = (zBuffer*)lua_touserdata(L, -1);
		uint64 v = (uint64)lua_tonumber(L, -2);
		lua_pop(L, 2);
		if (!buf)
			return 0;
		
		buf->set<uint64>(v);
		return 0;
	}
	return 0;
}

__zLuaFn(zBuffer, float)
{
	int args = lua_gettop(L);
	if (args == 1)
	{
		if (!lua_isuserdata(L, -1))
			return 0;

		zBuffer* buf = (zBuffer*)lua_touserdata(L, -1);
		lua_pop(L, 1);
		if (!buf)
			return 0;
		float ret = buf->get<float>();
		lua_pushnumber(L, ret);
		return 1;
	}
	else if (args == 2)
	{
		if (!lua_isuserdata(L, -1) || !lua_isnumber(L, -2))
			return 0;
		zBuffer* buf = (zBuffer*)lua_touserdata(L, -1);
		float v = (float)lua_tonumber(L, -2);
		lua_pop(L, 2);
		if (!buf)
			return 0;
		
		buf->set<float>(v);
		return 0;
	}
	return 0;
}

__zLuaFn(zBuffer, double)
{
	int args = lua_gettop(L);
	if (args == 1)
	{
		if (!lua_isuserdata(L, -1))
			return 0;

		zBuffer* buf = (zBuffer*)lua_touserdata(L, -1);
		lua_pop(L, 1);
		if (!buf)
			return 0;
		double ret = buf->get<double>();
		lua_pushnumber(L, ret);
		return 1;
	}
	else if (args == 2)
	{
		if (!lua_isuserdata(L, -1) || !lua_isnumber(L, -2))
			return 0;
		zBuffer* buf = (zBuffer*)lua_touserdata(L, -1);
		double v = (double)lua_tonumber(L, -2);
		lua_pop(L, 2);
		if (!buf)
			return 0;
		
		buf->set<double>(v);
		return 0;
	}
	return 0;
}

__zLuaFn(zBuffer, string)
{
	int args = lua_gettop(L);
	if (args == 1)
	{
		if (!lua_isuserdata(L, -1))
			return 0;

		zBuffer* buf = (zBuffer*)lua_touserdata(L, -1);
		lua_pop(L, 1);
		if (!buf)
			return 0;
		const char* ret = buf->get<const char*>();
		lua_pushstring(L, ret);
		return 1;
	}
	else if (args == 2)
	{
		if (!lua_isuserdata(L, -1) || !lua_isstring(L, -2))
			return 0;
		zBuffer* buf = (zBuffer*)lua_touserdata(L, -1);
		const char* str = lua_tostring(L, -2);
		lua_pop(L, 2);
		if (!buf)
			return 0;
		
		buf->set<const char*>(str);
		return 0;
	}
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
	if (!lua_isuserdata(L, -1))
		return 0;
	zBuffer* buf = (zBuffer*)lua_touserdata(L, -1);
	lua_pop(L, 1);
	if (!buf)
		return 0;
	buf->reset();
	return 0;
}

__zLuaFn(zBuffer, avail)
{
	if (!lua_isuserdata(L, -1))
		return 0;
	zBuffer* buf = (zBuffer*)lua_touserdata(L, -1);
	lua_pop(L, 1);
	if (!buf)
		return 0;
	int ret = buf->avail();
	lua_pushnumber(L, ret);
	return 1;
}

__zLuaFn(zBuffer, free)
{
	if (!lua_isuserdata(L, -1))
		return 0;
	zBuffer* buf = (zBuffer*)lua_touserdata(L, -1);
	lua_pop(L, 1);
	if (!buf)
		return 0;
	int ret = buf->free();
	lua_pushnumber(L, ret);
	return 1;
}

__zLuaFn(zBuffer, growth)
{
	int args = lua_gettop(L);
	if (args == 1)
	{
		if (!lua_isuserdata(L, -1))
			return 0;
		zBuffer* buf = (zBuffer*)lua_touserdata(L, -1);
		lua_pop(L, 1);
		if (!buf)
			return 0;

		uint32 ret = buf->growth();
		lua_pushnumber(L, ret);
		return 1;
	}
	else if (args == 2)
	{
		if (!lua_isuserdata(L, -1) || !lua_isnumber(L, -2))
			return 0;
		zBuffer* buf = (zBuffer*)lua_touserdata(L, -1);
		uint32 v = lua_tonumber(L, -2);
		lua_pop(L, 2);
		if (!buf)
			return 0;

		buf->growth(v);
		return 0;
	}
}

__zLuaFn(zBuffer, on)
{
	if (!lua_isuserdata(L, -1) || !lua_isstring(L, -2) || !lua_isfunction(L, -3))
		return 0;

	zBuffer* zbuf = (zBuffer*)lua_touserdata(L, -1);
	const char* ename = lua_tostring(L, -2);
	lua_pop(L, 2);
	int luafunc = luaL_ref(L, LUA_REGISTRYINDEX);
	if (luafunc == LUA_REFNIL)
		return 0;
	lua_pop(L, 1);
	zbuf->registeEvent(ename, luafunc);
	return 0;
}

int32 register_zbuffer(lua_State* L)
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

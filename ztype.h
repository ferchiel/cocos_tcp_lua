/********************************************************************
	created:	2015/01/31
	created:	31:1:2015   17:22
	filename: 	D:\workspace\creater\engine\Classes\ztype.h
	file path:	D:\workspace\creater\engine\Classes
	file base:	ztype
	file ext:	h
	author:		ferchiel
	
	purpose:	
*********************************************************************/

#ifndef __Z_TYPE_H__
#define __Z_TYPE_H__

#define __zLuaDebug 1

#if _WIN32
typedef __int8 int8;
typedef __int16 int16;
typedef __int32 int32;
typedef __int64 int64;
typedef unsigned __int8 uint8;
typedef unsigned __int16 uint16;
typedef unsigned __int32 uint32;
typedef unsigned __int64 uint64;
#else
typedef int8_t int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;
typedef unsigned int8_t uint8;
typedef unsigned int16_t uint16;
typedef unsigned int32_t uint32;
typedef unsigned int64_t uint64;
#endif


#endif


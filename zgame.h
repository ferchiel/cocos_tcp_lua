/********************************************************************
	created:	2015/02/03
	created:	3:2:2015   10:03
	filename: 	D:\workspace\creater\engine\Classes\zgame.h
	file path:	D:\workspace\creater\engine\Classes
	file base:	zgame
	file ext:	h
	author:		ferchiel
	
	purpose:	
*********************************************************************/

#ifndef __Z_GAME_H__
#define __Z_GAME_H__

#include "ztype.h"
#include "AppDelegate.h"

class zgame : public AppDelegate
{
public:
	/**
		@brief    Implement Director and Scene init code here.
		@return true    Initialize success, app continue.
		@return false   Initialize failed, app terminate.
    */
    bool applicationDidFinishLaunching();

	int32 update(float dt);

};


#endif
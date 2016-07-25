#ifndef __Z_EVENT_H__
#define __Z_EVENT_H__

#include "../ztype.h"
#include "../zbase.h"

extern int32 evtNetworkConnect(zEventBase* obj, int32 fn);
extern int32 evtNetworkDisconnect(zEventBase* obj, int32 fn);
extern int32 evtNetworkMsgerr(zEventBase* obj, int32 fn);
extern int32 evtNetworkData(zEventBase* obj, int32 fn);

#endif




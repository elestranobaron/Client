#ifndef __DMO_H__
#define __DMO_H__


#include "mediaerr.h"

// When using ATL we get collisions on Lock so in this case rename
// IMediaObject::Lock to IMediaObject::DMOLock

#ifdef FIX_LOCK_NAME
#define Lock DMOLock
#endif
#include "mediaobj.h"
#ifdef FIX_LOCK_NAME
#undef Lock
#endif
#include "dmoreg.h"
#include "dmort.h"

#endif //__DMO_H__

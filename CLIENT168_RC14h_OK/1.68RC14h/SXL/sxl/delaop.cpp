// delaop -- operator delete[](void *) REPLACEABLE
#include <xstddef>

 #if _HAS_ARRAY_NEW
 #if !_SP2 || _DLL
void __cdecl operator delete[](void *p) _THROW0()
	{	// free an allocated object
	operator delete(p);
	}
 #endif /* !_SP2 || _DLL */
 #else
 #endif /* _HAS_ARRAY_NEW */

/*
 * Copyright (c) 1994-1999 by P.J. Plauger.  ALL RIGHTS RESERVED. 
 * Consult your license regarding permissions and restrictions.
 V2.33:099I */

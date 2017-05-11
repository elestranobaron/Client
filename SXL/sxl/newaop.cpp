// newaop -- operator new[](size_t) REPLACEABLE
#include <new>

 #if _HAS_ARRAY_NEW
 #if !_SP2 || _DLL
void *__cdecl operator new[](size_t size) _THROW0(/* std::bad_alloc */)
	{	// try to allocate size bytes for an array
	return (operator new(size));
	}
 #endif /* !_SP2 || _DLL */
 #else
 #endif

/*
 * Copyright (c) 1994-1999 by P.J. Plauger.  ALL RIGHTS RESERVED. 
 * Consult your license regarding permissions and restrictions.
 V2.33:099I */

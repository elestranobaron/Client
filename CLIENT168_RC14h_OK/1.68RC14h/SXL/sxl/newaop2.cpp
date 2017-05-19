#include <new>

 #if _HAS_ARRAY_NEW
void *__cdecl operator new[](size_t size, const std::nothrow_t& x)
	_THROW0()
	{	// try to allocate size bytes for an array
	return (operator new(size, x));
	}
 #else
 #endif

/*
 * Copyright (c) 1995 by P.J. Plauger.  ALL RIGHTS RESERVED. 
 * Consult your license regarding permissions and restrictions.
 V2.33:099I */

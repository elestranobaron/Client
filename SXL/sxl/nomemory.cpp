#include <new>
_STD_BEGIN

_CRTIMP2 void __cdecl _Nomemory()
	{	// report out of memory
	static const bad_alloc nomem;
	_RAISE(nomem);
	}

const nothrow_t nothrow = nothrow_t();

_STD_END

/*
 * Copyright (c) 1994-1998 by P.J. Plauger.  ALL RIGHTS RESERVED. 
 * Consult your license regarding permissions and restrictions.
 V2.33:099I */

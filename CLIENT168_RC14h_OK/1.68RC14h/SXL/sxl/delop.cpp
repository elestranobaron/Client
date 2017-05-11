// delop -- operator delete(void *) REPLACEABLE
#include <cstdlib>
#include <xstddef>

void __cdecl operator delete(void *p) _THROW0()
	{	// free an allocated object
	if (p != 0)
		free(p);
	}

/*
 * Copyright (c) 1994 by P.J. Plauger.  ALL RIGHTS RESERVED. 
 * Consult your license regarding permissions and restrictions.
 V2.33:099I */

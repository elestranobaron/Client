// throw -- terminate on thrown exception REPLACEABLE
#include <cstdio>
#include <cstdlib>
#include <exception>
_STD_BEGIN

_CRTIMP2 void __cdecl _Throw(const exception& ex)
	{	// report error and die
	const char *s2 = ex.what();
	fputs("exception: ", stderr);
	fputs(s2 != 0 ? s2 : "unknown", stderr);
	fputs("\n", stderr);
	abort();
	}
_STD_END

/*
 * Copyright (c) 1994-1999 by P.J. Plauger.  ALL RIGHTS RESERVED. 
 * Consult your license regarding permissions and restrictions.
 V2.33:099I */

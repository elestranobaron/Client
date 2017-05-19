#include <fstream>
#include <iostream>

#pragma warning(disable: 4074)
#pragma init_seg(compiler)

_STD_BEGIN
		// OBJECT DECLARATIONS
static filebuf ferr(stderr);
_CRTIMP2 ostream cerr(&ferr);

		// INITIALIZATION CODE
struct _Init_cerr {
	_Init_cerr()
		{_Ptr_cerr = &cerr;
		cerr.tie(_Ptr_cout);
		cerr.setf(ios_base::unitbuf);
		}
	};
static _Init_cerr init_cerr;

_STD_END

/*
 * Copyright (c) 1998 by P.J. Plauger.  ALL RIGHTS RESERVED. 
 * Consult your license regarding permissions and restrictions.
 V2.33:099I */

#include <fstream>
#include <iostream>

#pragma warning(disable: 4074)
#pragma init_seg(compiler)

_STD_BEGIN
		// OBJECT DECLARATIONS
static filebuf flog(stderr);
_CRTIMP2 ostream clog(&flog);

		// INITIALIZATION CODE
struct _Init_clog {
	_Init_clog()
		{_Ptr_clog = &clog;
		clog.tie(_Ptr_cout);
		}
	};
static _Init_clog init_clog;

_STD_END

/*
 * Copyright (c) 1998 by P.J. Plauger.  ALL RIGHTS RESERVED. 
 * Consult your license regarding permissions and restrictions.
 V2.33:099I */

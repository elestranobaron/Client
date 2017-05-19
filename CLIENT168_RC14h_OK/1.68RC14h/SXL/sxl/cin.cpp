#include <fstream>
#include <iostream>

#pragma warning(disable: 4074)
#pragma init_seg(compiler)

_STD_BEGIN
		// OBJECT DECLARATIONS
static filebuf fin(stdin);
_CRTIMP2 istream cin(&fin);

		// INITIALIZATION CODE
struct _Init_cin {
	_Init_cin()
		{_Ptr_cin = &cin;
		cin.tie(_Ptr_cout);
		}
	};
static _Init_cin init_cin;

_STD_END

/*
 * Copyright (c) 1998 by P.J. Plauger.  ALL RIGHTS RESERVED. 
 * Consult your license regarding permissions and restrictions.
 V2.33:099I */

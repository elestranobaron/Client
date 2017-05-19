#include <fstream>
#include <iostream>

#pragma warning(disable: 4074)
#pragma init_seg(compiler)

_STD_BEGIN
		// OBJECT DECLARATIONS
static filebuf fout(stdout);
_CRTIMP2 ostream cout(&fout);

		// INITIALIZATION CODE
struct _Init_cout {
	_Init_cout()
		{_Ptr_cout = &cout;
		if (_Ptr_cin != 0)
			_Ptr_cin->tie(_Ptr_cout);
		if (_Ptr_cerr != 0)
			_Ptr_cerr->tie(_Ptr_cout);
		if (_Ptr_clog != 0)
			_Ptr_clog->tie(_Ptr_cout);
		}
	};
static _Init_cout init_cout;

_STD_END

/*
 * Copyright (c) 1998-1999 by P.J. Plauger.  ALL RIGHTS RESERVED. 
 * Consult your license regarding permissions and restrictions.
 V2.33:099I */

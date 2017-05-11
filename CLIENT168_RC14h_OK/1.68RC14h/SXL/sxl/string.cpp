// string -- template string support functions
#include <istream>
_STD_BEGIN


		// report a length_error
_CRTIMP2 void _String_base::_Xlen() const
	{_THROW(length_error, "string too long"); }

		// report an out_of_range error
_CRTIMP2 void _String_base::_Xran() const
	{_THROW(out_of_range, "invalid string position"); }
_STD_END

/*
 * Copyright (c) 1995-1998 by P.J. Plauger.  ALL RIGHTS RESERVED. 
 * Consult your license regarding permissions and restrictions.
 V2.33:099I */

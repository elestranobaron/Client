// handler.cpp -- minimal std::set_new_handler
#include <new>

typedef int (__cdecl *new_hand)(size_t);
new_hand _set_new_handler(new_hand);

_STD_BEGIN
_CRTIMP2 new_handler __cdecl set_new_handler(new_handler new_p)
	{	// remove current handler
	new_p = (new_handler)_set_new_handler((new_hand)new_p);
	return new_p;
	}
_STD_END

/*
 * Copyright (c) 1999 by P.J. Plauger.  ALL RIGHTS RESERVED. 
 * Consult your license regarding permissions and restrictions.
 V2.33:099I */

#include <iostream>
_STD_BEGIN

#pragma warning(disable: 4074)
#pragma init_seg(compiler)

		// OBJECT DECLARATIONS
_CRTIMP2 istream *_Ptr_cin = 0;
_CRTIMP2 ostream *_Ptr_cout = 0;
_CRTIMP2 ostream *_Ptr_cerr = 0;
_CRTIMP2 ostream *_Ptr_clog = 0;

		// WIDE OBJECTS
_CRTIMP2 wistream *_Ptr_wcin = 0;
_CRTIMP2 wostream *_Ptr_wcout = 0;
_CRTIMP2 wostream *_Ptr_wcerr = 0;
_CRTIMP2 wostream *_Ptr_wclog = 0;

		// FINALIZATION CODE
struct _Atexit_list {
	struct _Atexit_list *next;
	void (*pf)();
	};
static _Atexit_list *atlist = 0;

_CRTIMP2 bool _Loc_atexit(void (__cdecl *pf)())
	{	/* add to wrapup list */
	_Atexit_list *p = (_Atexit_list *)malloc(sizeof (_Atexit_list));
	if (p == 0)
		return (false);
	else
		{	/* got space, chain it in */
		_Lockit _Lk;
		p->pf = pf;
		p->next = atlist;
		atlist = p;
		return (true);
		}
	}

struct _Init_atexit {
	~_Init_atexit()
		{	// process wrapup functions
		while (atlist != 0)
			{_Lockit _Lk;
			_Atexit_list *p = atlist;
			if (p == 0)
				break;	// check for race
			void (*pf)() = p->pf;
			atlist = p->next;
			free(p);
			(*pf)();
			}
		}
	};
static _Init_atexit init_atexit;
_STD_END

char _PJP_CPP_Copyright[] =
	"Copyright (c) 1992-1998 by P.J. Plauger,"
	" licensed by Dinkumware, Ltd."
	" ALL RIGHTS RESERVED.";

/*
 * Copyright (c) 1998-1999 by P.J. Plauger.  ALL RIGHTS RESERVED. 
 * Consult your license regarding permissions and restrictions.
 V2.33:099I */

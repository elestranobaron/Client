#include <new>
#include <xiosbase>
_STD_BEGIN

#define NSTDSTR	8	/* cin, wcin, etc. */


int ios_base::_Index = 0;
bool ios_base::_Sync = true;
_CRTIMP2 fpos_t _Fpz = {0};
extern _CRTIMP2 const streamoff _BADOFF = -1;

static ios_base *stdstr[NSTDSTR + 1] = {0};
static char stdopens[NSTDSTR + 1] = {0};

void ios_base::clear(iostate ns, bool ex)
	{	// clear all but selected state bits
	_State = (iostate)(ns & _Statmask);
	if ((_State & _Except) == 0)
		;
	else if (ex)
		_RERAISE;
	else if (_State & _Except & badbit)
		_THROW(failure, "ios_base::badbit set");
	else if (_State & _Except & failbit)
		_THROW(failure, "ios_base::failbit set");
	else
		_THROW(failure, "ios_base::eofbit set");
	}

ios_base& ios_base::copyfmt(const ios_base& rhs)
	{	// copy format info from another ios_base
	if (this != &rhs)
		{	// copy all but _State
		_Tidy();
		*_Ploc = *rhs._Ploc;
		_Fmtfl = rhs._Fmtfl;
		_Prec = rhs._Prec;
		_Wide = rhs._Wide;
		_Iosarray *p = rhs._Arr;
		for (_Arr = 0; p != 0; p = p->_Next)
			if (p->_Lo != 0 || p->_Vp != 0)
				{	// copy over nonzero array values
				iword(p->_Index) = p->_Lo;
				pword(p->_Index) = p->_Vp;
				}
		_Fnarray *q;
		for (q = rhs._Calls; q != 0; q = q->_Next)
			register_callback(q->_Pfn, q->_Index);
		_Callfns(copyfmt_event);
		exceptions(rhs._Except);	// cause any throw at end
		}
	return (*this);
	}

locale ios_base::imbue(const locale& _Ln)
	{	// imbue a new locale into stream
	locale _Lo = *_Ploc;
	*_Ploc = _Ln;
	_Callfns(imbue_event);
	return (_Lo);
	}

void ios_base::register_callback(event_callback _P, int _Idx)
	{	// register a callback function
	_Calls = new _Fnarray(_Idx, _P, _Calls);
	}

ios_base::~ios_base()
	{	// destroy an ios_base
	if (0 < _Stdstr && 0 < --stdopens[_Stdstr])
		return;
	_Tidy();
	delete _Ploc;
	}

void ios_base::_Callfns(event ev)
	{	// call registered functions
	_Fnarray *p;
	for (p = _Calls; p != 0; p = p->_Next)
		(*p->_Pfn)(ev, *this, p->_Index);
	}

ios_base::_Iosarray& ios_base::_Findarr(int idx)
	{	// locate or make a variable array element
	static _Iosarray stub(0, 0);
	_Iosarray *p, *q;
	if (idx < 0)
		{	// handle bad index
		setstate(badbit);
		return (stub);
		}
	for (p = _Arr, q = 0; p != 0; p = p->_Next)
		if (p->_Index == idx)
			return (*p);
		else if (q == 0 && p->_Lo == 0 && p->_Vp == 0)
			q = p;
	if (q != 0)
		{	// recycle existing element
		q->_Index = idx;
		return (*q);
		}
	_Arr = new _Iosarray(idx, _Arr);
	return (*_Arr);
	}

void ios_base::_Addstd()
	{	// add standard stream to destructor list
	_Lockit _Lk(_LOCK_STREAM);
	for (; _Stdstr < NSTDSTR; ++_Stdstr)
		if (stdstr[_Stdstr] == 0 || stdstr[_Stdstr] == this)
			break;
	stdstr[_Stdstr] = this;
	++stdopens[_Stdstr];
	}

void ios_base::_Init()
	{	// initialize a new ios_base
	_Ploc = new locale;
	_Except = goodbit;
	_Fmtfl = skipws | dec;
	_Prec = 6;
	_Wide = 0;
	_Arr = 0;
	_Calls = 0;
	clear(goodbit);
	}

void ios_base::_Tidy()
	{	// discard storage for an ios_base
	_Callfns(erase_event);
	_Iosarray *q1, *q2;
	for (q1 = _Arr; q1 != 0; q1 = q2)
		q2 = q1->_Next, delete q1;
	_Arr = 0;
	_Fnarray *q3, *q4;
	for (q3 = _Calls; q3 != 0; q3 = q4)
		q4 = q3->_Next, delete q3;
	_Calls = 0;
	}
_STD_END

/*
 * Copyright (c) 1994-1998 by P.J. Plauger.  ALL RIGHTS RESERVED. 
 * Consult your license regarding permissions and restrictions.
 V2.33:099I */

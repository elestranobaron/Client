// locale0 -- class locale basic member functions
#include <climits>
#include <locale>
_STD_BEGIN

static locale classic_locale(_Noinit);
locale::_Locimp *locale::_Locimp::_Clocptr = 0;
locale::_Locimp *locale::_Locimp::_Global = 0;
int locale::id::_Id_cnt = 0;

_TEMPLATE_STAT const size_t ctype<char>::table_size =
	1 << CHAR_BIT;

const locale& __cdecl locale::classic()
	{	// get reference to "C" locale
	_Init();
	return (classic_locale);
	}

locale __cdecl locale::empty()
	{	// make empty transparent locale
	_Init();
	return (locale(new _Locimp(true)));
	}

const locale::facet *locale::_Getfacet(size_t _Id) const
	{	// look up a facet in locale object
	_Lockit _Lk(_LOCK_LOCALE);
	const facet *_F = _Id < _Ptr->_Nfv ? _Ptr->_Fv[_Id] : 0;
	return (_F != 0 || !_Ptr->_Xpar ? _F
		: _Id < _Locimp::_Global->_Nfv
			? _Locimp::_Global->_Fv[_Id] : 0);
	}

bool locale::operator==(const locale& _X) const
	{	// compare locales for equality
	return (_Ptr == _X._Ptr || name().compare("*") != 0
		&& name().compare(_X.name()) == 0);
	}

locale::_Locimp *__cdecl locale::_Init()
	{	// setup _Global and "C" locales
	_Lockit _Lk(_LOCK_LOCALE);
	if (_Locimp::_Global == 0)
		{	// create new locales
		_Locimp::_Global = new _Locimp;
		_Loc_atexit(&_Tidy);
		_Locimp::_Global->_Cat = all;
		_Locimp::_Global->_Name = "C";
		_Locimp::_Clocptr = _Locimp::_Global;
		_Locimp::_Clocptr->_Incref();
		new (&classic_locale) locale(_Locimp::_Clocptr);
		}
	return (_Locimp::_Global);
	}

void __cdecl locale::_Tidy()
	{	// discard _Global locale
	_Lockit _Lk(_LOCK_LOCALE);
	if (_Locimp::_Global != 0)
		delete _Locimp::_Global->_Decref();
	}

locale::_Locimp::_Locimp(bool _Xp)
	: locale::facet(1), _Fv(0), _Nfv(0),
		_Cat(none), _Xpar(_Xp), _Name("*")
	{	// construct an empty _Locimp
	}

locale::_Locimp::~_Locimp()
	{	// destruct a _Locimp
	_Lockit _Lk(_LOCK_LOCALE);
	for (size_t _N = _Nfv; 0 < _N; )
		if (_Fv[--_N] != 0)
			delete _Fv[_N]->_Decref();
	free(_Fv);
	}

_Locinfo::_Locinfo(const char *_Name)
	: _Lk(_LOCK_LOCALE)
	{	// switch to a named locale
	_Oname = setlocale(LC_ALL, 0);
	_Nname = _Name == 0
		|| (_Name = setlocale(LC_ALL, _Name)) == 0
			? "*" : _Name; }

_Locinfo::~_Locinfo()
	{	// destroy a _Locinfo object, revert locale
	if (0 < _Oname.size())
		setlocale(LC_ALL, _Oname.c_str()); }
_STD_END

/*
 * Copyright (c) 1996-1998 by P.J. Plauger.  ALL RIGHTS RESERVED. 
 * Consult your license regarding permissions and restrictions.
 V2.33:099I */

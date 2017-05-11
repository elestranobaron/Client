/* yvals.h values header for Microsoft C/C++ */

#if 1000 < _MSC_VER /*IFSTRIP=IGN*/
#pragma once
#endif

#ifndef _YVALS
#define _YVALS

 #define _HAS_ARRAY_NEW        (1200 <= _MSC_VER)
 #define _HAS_PLACEMENT_DELETE (1200 <= _MSC_VER)
 #if 1200 <= _MSC_VER	/* V6.0 permanently disable */
  #pragma warning(disable: 4514 4710)
 #elif 1100 <= _MSC_VER	/* V5.0 permanently disable */
  #pragma warning(disable: 4097 4511 4512 4514 4710 4804)
 #endif

#include <use_ansi.h>

#ifdef  _MSC_VER
#pragma pack(push,8)
#endif  /* _MSC_VER */
#if 1200 <= _MSC_VER
#pragma warning(push,3)
#endif

#ifndef _SP2
 #define _SP2	0 /* define as 1 to fix linker errors with V6.0 SP2 */
#endif

/* Define _CRTIMP2 */
 #ifndef _CRTIMP2
  #ifdef  CRTDLL2
   #define _CRTIMP2 __declspec(dllexport)
  #else   /* ndef CRTDLL2 */
   #ifdef  _DLL
    #define _CRTIMP2 __declspec(dllimport)
   #else   /* ndef _DLL */
    #define _CRTIMP2
   #endif  /* _DLL */
  #endif  /* CRTDLL2 */
 #endif  /* _CRTIMP2 */

 #ifndef _HAS_EXCEPTIONS
  #define  _HAS_EXCEPTIONS  1	/* predefine as 0 to disable exceptions */
 #endif


		/* NAMESPACE */
 #if defined(__cplusplus)
  #define _STD			std::
  #define _STD_BEGIN	namespace std {
  #define _STD_END		};
  #define _STD_USING
 #else
  #define _STD			::
  #define _STD_BEGIN
  #define _STD_END
 #endif /* __cplusplus */

_STD_BEGIN
		/* TYPE bool */
 #if defined(__cplusplus)
typedef bool _Bool;
 #endif /* __cplusplus */

		/* INTEGER PROPERTIES */
#define _MAX_EXP_DIG	8	/* for parsing numerics */
#define _MAX_INT_DIG	32
#define _MAX_SIG_DIG	36

		/* STDIO PROPERTIES */
#define _Filet _iobuf
 #ifndef _FPOS_T_DEFINED
  #define _FPOSOFF(fp)	((long)(fp))
 #endif /* _FPOS_T_DEFINED */
#define _IOBASE	_base
#define _IOPTR	_ptr
#define _IOCNT	_cnt

		/* NAMING PROPERTIES */
 #if defined(__cplusplus)
  #define _C_LIB_DECL extern "C" {
  #define _END_C_LIB_DECL }
 #else
  #define _C_LIB_DECL
  #define _END_C_LIB_DECL
 #endif /* __cplusplus */
 #if defined(__cplusplus)

		// LOCK MACROS
#define _LOCK_LOCALE
#define _LOCK_MALLOC
#define _LOCK_STREAM
		// CLASS _Lockit
class _CRTIMP2 _Lockit
	{	// lock while object in existence
public:
  #ifdef _MT
   #define _LOCKIT(x)	lockit x
	explicit _Lockit();
	~_Lockit();
  #else
   #define _LOCKIT(x)
	explicit _Lockit()
		{}
	~_Lockit()
		{}
  #endif /* _MT */
	_Lockit& operator=(const _Lockit&);
	};
 #endif /* __cplusplus */

		/* MISCELLANEOUS MACROS AND TYPES */
typedef int _Mbstatet;
#define _ATEXIT_T	void
#define _Mbstinit(x)	mbstate_t x = {0}
#define _Loc_atexit	_Loc_atexit
_STD_END
#if 1200 <= _MSC_VER
#pragma warning(pop)
#endif
#ifdef  _MSC_VER
#pragma pack(pop)
#endif  /* _MSC_VER */

#endif /* _YVALS */

/*
 * Copyright (c) 1996-1999 by P.J. Plauger.  ALL RIGHTS RESERVED. 
 * Consult your license regarding permissions and restrictions.
 V2.33:099I */

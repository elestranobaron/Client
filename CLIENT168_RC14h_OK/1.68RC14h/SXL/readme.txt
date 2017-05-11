Dinkumware, Ltd.
398 Main Street
Concord MA  01742
	USA
+1-978-371-2773

The Dinkum C++ Library and the Dinkum C++ Library Reference are
Copyright (c) 1992-1999 by P.J. Plauger. This code is protected by
copyright. ALL RIGHTS RESERVED. See the Copyright and License
Notice at the end of this file for further details.

Version 2.33. This product contains all the source code of the
Dinkum C++ Library and the Dinkum C++ Library Reference as packaged
for Microsoft Visual C++ V5.0 or V6.0 (VC++). It is licensed by
Dinkumware, Ltd. only for use in conjunction with a valid license
for VC++, which you must obtain separately. Microsoft Corporation
is in no way involved with the production or release of this
product.


-----------

16 June 1999

This shipment constitutes a full working version of the Dinkum
C++ Library packaged for use with VC++. It is complete and highly
compatible with the final C++ Standard. It also features:

support for member template functions
fixes for known C++ library bugs in VC++
much quieter operation at warning level 4
optional use of exception handling
hash tables as STL template containers

Due to limitations of the VC++ compiler, however, it does NOT
support:

template functions with no argument dependencies
partial specialization of templates
member template classes
wchar_t as a distinct type
array new/delete operators (V5.0 only)
placement deletes (V5.0 only)
member template functions in basic_string (DLL only)

The documentation in the subdirectory html describes any
workarounds visible to the programmer as a result of these
limitations.

To eliminate misleading warnings at level 4, library headers
must occasionally disable specific warnings and leave them
disabled. This occurs far more often for V5.0 than for V6.0.
We have endeavored to minimize such actions, but please note
that some warnings may be suppressed outside of library code.

Please let us know if there are any problems, or if you need
any additional assistance.


Dinkumware Tech Support


-----------

INSTALLATION AND USE

Copy this directory tree to a Windows95/98/NT system. We use
c:\sxl, but you can place it anywhere.

The library comes with three versions pre-built: the statically
linked single-threaded library (sxl.lib), the statically linked
multi-threaded library (sxlmt.lib), and the dynamically linked
library (sxlrt.lib and sxlrt233.dll). Instructions for building
debugging versions of these libraries are given below.

To use the Dinkumware library in a project, after creating
the project select Project | Settings. Then select the C/C++
tab, and set Category to Preprocessor. In the type-in box
labeled "Additional include directories:" add the path to the
include directory in your installation of the Dinkumware
library -- typically c:\sxl\include. Then select the Link
tab, and set Category to Input. In the type-in box labeled
"Object/library modules:" add the appropriate object library --
sxl.lib, sxlmt.lib, or sxlrt.lib -- making sure that the library
name appears before any of the system library names. Then, in
the type-in box labeled "Additional library path", add the path
to the library directory in your installation of the Dinkumware
library -- typically c:\sxl\lib. Click OK to save the changes.

If you are using one of the DLLs supplied, be sure to add the
appropriate directory to the executable search path -- typically
c:\sxl\bin. Alternatively, you may choose to copy the DLLs you
use to a directory already in the search path.

IMPORTANT: be sure to use the correct version of the library
for your project. Visual C++ does not select the correct
version for you. If you use the wrong version of the library
the linker will report undefined symbols.

You can also use the library when compiling from the command
line, as in a DOS session or batch script. First check the
setting of the environment variable SXLDir in v50setup.bat or
v60setup.bat, which you will find in the root of the tree --
typically c:\sxl. The code assumes that the appropriate version
of VC++ is installed at its default location. If it is somewhere
else, change the setting of the environment variable MSDevDir
in the setup script. (Because this is a short alias for a long
file name, you may well have to change it in any case.)

For V5.0, execute

	v50setup.bat

or for V6.0, execute

	v60setup.bat

to set the environment variables you need to compile properly,
and to execute the other commands defined in this directory
tree.

The directory tree contains several subdirectories:

bin -- holds the library DLLs as well as batch scripts that can
	be executed in any directory (v50setup or v60setup adds bin
	to PATH)

html -- holds the HTML pages for the on-line documentation,
	rooted in index.html

include -- holds the include files, additions or replacements
	to the standard headers needed to implement this library
	atop the existing MS include files

lib -- holds sxl.lib (the statically linked single-threaded
	library), sxlmt.lib (the statically linked multi-threaded
	library), and sxlrt.lib (the import library for the DLL
	implementation of the library), the additions to
	the object library needed to implement this library atop
	the existing MS libraries

sxl -- holds library source files that replace or supplement
	existing MS object library source files (supplies
	object files for lib\sxl.lib)

test -- a scratch directory, with one or two tiny test files

To compile and link the file xxx.cpp using the
single-threaded, statically linked library in any directory,
execute:

	sxlcl xxx

To compile and link the file xxx.cpp using the
multi-threaded, statically linked library in any directory,
execute:

	sxlmtcl xxx

To compile and link the file xxx.cpp using the
dynamicly linked library in any directory, execute:

	sxlrtcl xxx

You will find compiler/linker output in xxx.log, which the
batch script copies to the display before terminating.

To remove all files created by sxlcl, sxlmtcl, or sxlrtcl with
names of the form xxx.*, execute:

	sxltidy xxx

For a MUCH more aggressive cleanup, execute:

	sxltidy

Note that it deletes ALL files in the current directory that
match *.exe, *.idb, *.ilk, *.log, *.mak, *.map, *.mdp, *.obj,
*.pch, *.pdb, *.res, *.exp, or *.dll, as well as the file ncb.

To rebuild all of the libraries, execute sxlbuild.bat in the
root of the directory tree. It takes approximately five minutes
on a 200 MHz Pentium. The file sxlbuild.log captures any
compiler, linker or lib reports.

To disable the use of exception handling in the library,
predefine the macro _HAS_EXCEPTIONS with value zero when
compiling all files, including library modules. (You can also
patch the definition of _HAS_EXCEPTIONS at the top of the
header yvals.h to eliminate the need for this define.)
Please note that we have not supplied any prebuilt object
libraries with exceptions disabled.


-----------

DEBUG BUILDS

To create debug builds of the three library versions, execute
sxldbuild.bat in the root of the directory tree. It takes
approximately five minutes on a 200 MHz Pentium. The file
sxlbuild.log captures any compiler, linker, or lib reports.

A successful build produces three debug versions of the library:
the statically linked single-threaded library (sxld.lib), the
statically linked multi-threaded library (sxlmtd.lib), and the
dynamically linked library (sxlrtd.lib and sxlrt233d.dll).

Once you have built debug versions of the libraries you can
use the batch files sxlcl.bat, sxlmtcl.bat, and sxlrtcl.bat,
discussed above, to compile and link with the debug versions
of the libraries by adding the /d switch on the command line:

	sxlcl /d xxx
	sxlmtcl /d xxx
	sxlrtcl /d xxx


-----------

REBUILDING FOR V6.0 SP2

If you need libraries that work with V6.0 SP2, you must predefine
the macro _SP2 to a nonzero value, then rebuild the libraries. This
definition is needed only when you rebuild the library. You don't
need it when you use the library, but there's no harm in leaving
it in place.

You can make this change by editing the value assigned to the macro
in yvals.h, or you can add a define to the command line. The simplest
way to do the latter is to edit the definitions of SXLCMD and SXLCMDD
in v60setup.bat so that they look like this:

set  SXLCMD=cl /nologo /W3 /GR /GX /DWIN32 /Oityb1 /Gs /D_SP2=1
set SXLCMDD=cl /nologo /W3 /GR /GX /DWIN32 /Od /Zi /D_DEBUG /D_SP2=1

The resulting static libraries WILL NOT WORK with any compiler version
other than V6.0 SP2. The DLLs are not affected by this change, so you
don't need to worry about incompatibilities if you use the DLL versions
of the library.


-----------

REPORTING

Please report any bugs or difficulties to:

	Tech Support
	Dinkumware, Ltd.
	398 Main Street
	Concord MA  01742
		USA
	+1-978-371-2773 (UTC -4 hours, -5 November through March)
	+1-978-371-9014 (FAX)
	support@dinkumware.com

Good luck,

Dinkumware Tech Support


-----------

UPDATE HISTORY

----
V2.33:

This shipment fixes the following problems:

-- compiler error, operator delete(void *, void *) already has a body

-- linker error, duplicate definition of operator delete(void *)

-- compiler error, unexpected 'class bad_cast' at typeinfo.h(61)

-- compiler error (debug build), no overloaded version of operator new[]
takes three arguments

-- NuMega BoundsChecker reports "memory allocation conflict"

-- warnings sometimes get turned on after being disabled by user code
or other headers

VC++ 6.0 SP2 USERS

You will sometimes get a linker error, duplicate definition of operator
new[](size_t) or duplicate definition of operator delete[](void *),
when linking with a non-DLL runtime library. The problem does not occur
when you use the DLL version of the runtime library. This is the result
of a bug that Microsoft introduced in SP2. It has been fixed in SP3. If
you prefer to stay with SP2, see the instructions below for rebuilding
the libraries to work with SP2.

----
V2.32:

This shipment incorporates many small changes to quiet level 4 warnings.
It also adds numerous pragmas to quiet warnings that cannot be otherwise
silenced. As much as possible, it restores warnings to user-specified
levels, but it cannot always do so, particularly with V5.0.

This shipment also adds debugging versions of the libraries.

----
V2.31:

This shipment corrects errors in V2.3 of the Dinkum C++ Library
packaged for use with VC++. It now supports three modes of
linking:

statically, single-threaded (as before)
statically, multi-threaded
dynamically, as a DLL

It also corrects errors in the header <xtree>, used by the map
and set containers.


-----------

COPYRIGHT AND LICENSE NOTICE

1.	Dinkum® C++ Library for VC++
2.	Dinkum C++ Library Reference

Developed by P.J. Plauger
Copyright ©1992-1999 by P.J. Plauger

Dinkumware, Ltd.
398 Main Street
Concord MA  01742

The Dinkum® C++ Library for VC++ in machine-readable or printed form
(“Dinkum Library”) and the Dinkum C++ Library Reference in
machine-readable or printed form (“Dinkum Reference”), hereafter
in whole or in part the “Product”, are all copyright © 1992-1999 by
P.J. Plauger. ALL RIGHTS RESERVED. The Product is derived in part
from books copyright © 1992-1999 by P.J. Plauger.

Dinkumware, Ltd. and P.J. Plauger (“Licensor”) retain exclusive
ownership of this Product. It is licensed to you (“Licensee”) in
accordance with the terms specifically stated in this Notice. You
must otherwise treat the Product the same as other copyrighted
material, such as a book or recording. You may also exercise
certain rights peculiar to computer software under copyright law.
In particular:

-- You may use the Product to compile and link with C++ code to
produce executable files.

-- You may freely distribute such executable files for no additional
license fee to Licensor.

-- You may make one or more backup copies of the Product for
archival purposes.

-- You may permanently transfer ownership of the Product to another
party only if the other party agrees to the terms stated in this
Notice and you transfer or destroy all copies of the Product that
are in your posession.

-- You may use the Product only in conjunction with one or more
valid licenses for Microsoft Visual C++, which you must obtain
separately.

-- You must preserve this Notice and all copyright notices with
any copy you make of the Product.

-- You may not loan, rent, or sublicense the Product.

-- You may not copy or distribute, in any form, any part of this
Product for any purpose not specifically permitted by this Notice.

This copy of the Product is licensed for use by a limited number of
developers, which is specified as part of the packaging for this
Product. A license for up to ten users, for example, limits to ten
the number of developers reasonably able to use the Product at any
instant of time. Thus, ten is the maximum number of POSSIBLE
concurrent users, not the number of ACTUAL concurrent users. A
single-user license is for use by just one developer.

Anyone who accesses this software has a moral responsibility not to
aid or abet illegal copying by others. Licensor recognizes that the
machine-readable format of the Product makes it particularly
conducive to sharing within multi-user systems and across networks.
Such use is permitted only so long as Licensee does not exceed the
maximum number of possible concurrent users and takes reasonable
precautions to protect the Product against unauthorized copying and
against public access. In particular, please note that the ability
to ACCESS this copy does not imply permission to USE it or to COPY
it. Please note also that Licensor has expended considerable
professional effort in the production of this Product, and continues
to do so to keep it current.

Licensor warrants that the Product as shipped performs substantially
in accordance with its documented purpose, and that the medium on
which the Product is provided is free from defects in material and
workmanship. To the extent permitted by law, any implied warranties
on the Product are limited to 90 days.

Licensor's entire liability under this warranty shall be, at
Licensor's option, either to refund the license fee paid by
Licensee or to replace the medium on which the Product is provided.
This is also Licensee's exclusive remedy. To qualify for this
remedy, Licensee must demonstrate satisfactory proof of purchase to
Licensor and return the Product in reasonably good condition to
Licensor.

LICENSOR OTHERWISE MAKES NO REPRESENTATIONS OR WARRANTIES ABOUT THE
SUITABILITY OF THIS PRODUCT, EITHER EXPRESS OR IMPLIED, INCLUDING
BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT. LICENSOR
SHALL NOT BE LIABLE FOR ANY DAMAGES SUFFERED BY LICENSEE AS A
RESULT OF USING THIS PRODUCT, EVEN IF LICENSOR HAS BEEN ADVISED OF
THE POSSIBILITY OF SUCH DAMAGES. TO THE EXTENT PERMITTED BY LAW,
LICENSOR SHALL NOT BE LIABLE FOR CONSEQUENTIAL OR INCIDENTAL
DAMAGES.

By using this Product, you agree to abide by the intellectual
property laws and all other applicable laws of the USA, and the
terms described above. You may be held legally responsible for any
infringement that is caused or encouraged by your failure to abide
by the terms of this Notice.

RESTRICTED RIGHTS: Use, duplication, or disclosure by the government
is subject to the restrictions as set forth in subparagraph
(c)(1)(ii) of the Rights in Technical Data and Computer Software
Clause as DFARS 52.227-7013 and FAR 52.227-19. Unpublished rights
are reserved under the Copyright Laws of the USA. Contractor/
Manufacturer is DINKUMWARE, LTD., 398 Main Street, Concord MA 01742.

The terms of this notice shall be governed by the laws of the
Commonwealth of Massachusetts. THE RIGHTS AND OBLIGATIONS OF THE
PARTIES SHALL NOT BE GOVERNED BY THE PROVISIONS OF THE U.N.
CONVENTION FOR THE INTERNATIONAL SALE OF GOODS, 1980.

Dinkumware and Dinkum are registered trademarks of Dinkumware, Ltd.
Visual C++ and Windows are registered trademarks of Microsoft
Corporation.

End of Copyright and License Notice

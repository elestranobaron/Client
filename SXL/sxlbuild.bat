@echo off
rem build %SXLDir%\lib\sxl.lib, trace to %SXLDir%\sxlbuild.log
rem NOTE: YOU MUST RUN THIS SCRIPT ONLY AFTER RUNNING v50setup or v60setup
rem NOTE: YOU MUST RUN THIS SCRIPT ON THE SAME DRIVE AS %SXLDir%
rem takes about five minutes on a 200 MHz Pentium

if /%SXLDir%/ == // goto usage

cd %SXLDir%
if exist sxlbuild.log del sxlbuild.log
if exist lib\sxl.lib del lib\sxl.lib
if exist lib\sxlmt.lib del lib\sxlmt.lib
if exist lib\sxlrt.lib del lib\sxlrt.lib
if exist bin\sxlrt233.dll del bin\sxlrt233.dll

rem add in the SXL components to static single-thread library
cd sxl
%SXLCMD% /c *.c *.cpp >>..\sxlbuild.log
del instances.obj
cd ..

if not exist lib mkdir lib
lib /OUT:lib\sxl.lib /NAME:sxl.lib sxl\*.obj >>sxlbuild.log
if exist sxl\*.obj del sxl\*.obj

rem add in the SXL components to static multi-thread library
cd sxl
%SXLCMD% /MT /c *.c *.cpp >>..\sxlbuild.log
del instances.obj
cd ..

lib /OUT:lib\sxlmt.lib /NAME:sxlmt.lib sxl\*.obj >>sxlbuild.log
if exist sxl\*.obj del sxl\*.obj

rem add in the SXL components to DLL
cd sxl
rc -l 409 -r -Fosxlrt.res sxlrt.rc >>..\sxlbuild.log
%SXLCMD% /MD /LD /DCRTDLL2 /c *.c *.cpp >>..\sxlbuild.log
%SXLCMD% /MD /LD /DCRTDLL2 *.obj sxlrt.res /link /out:sxlrt233.dll /implib:sxlrt.lib /subsystem:console /release /incremental:no >>..\sxlbuild.log
lib sxlrt.lib delaop.obj newaop.obj newaop2.obj newop2.obj >>..\sxlbuild.log
cd ..

move sxl\sxlrt.lib lib
move sxl\sxlrt233.dll bin
if exist sxl\*.obj del sxl\*.obj
if exist sxl\*.exp del sxl\*.exp
if exist sxl\*.res del sxl\*.res

:quit
type sxlbuild.log
goto done

:usage
echo ERROR: must run v50setup.bat or v60setup.bat before building libraries

:done

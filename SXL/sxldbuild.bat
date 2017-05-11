@echo off
rem build %SXLDir%\lib\sxl.lib, trace to %SXLDir%\sxlbuild.log
rem NOTE: YOU MUST RUN THIS SCRIPT ONLY AFTER RUNNING v50setup or v60setup
rem NOTE: YOU MUST RUN THIS SCRIPT ON THE SAME DRIVE AS %SXLDir%
rem takes about five minutes on a 200 MHz Pentium

if /%SXLDir%/ == // goto usage

cd %SXLDir%
if exist sxlbuild.log del sxlbuild.log
if exist lib\sxld.lib del lib\sxld.lib
if exist lib\sxld.pdb del lib\sxld.pdb
if exist lib\sxlmtd.lib del lib\sxlmtd.lib
if exist lib\sxlmtd.pdb del lib\sxlmtd.pdb
if exist lib\sxlrtd.lib del lib\sxlrtd.lib
if exist lib\sxlrt233d.pdb del lib\sxlrt233d.pdb
if exist bin\sxlrt233d.dll del bin\sxlrt233d.dll

rem add in the SXL components to static single-thread library
cd sxl
%SXLCMDD% /Fd..\lib\sxld.pdb /MLd /c *.c *.cpp >>..\sxlbuild.log
del instances.obj
cd ..

if not exist lib mkdir lib
lib /OUT:lib\sxld.lib /NAME:sxld.lib sxl\*.obj >>sxlbuild.log
if exist sxl\*.obj del sxl\*.obj

rem add in the SXL components to static multi-thread library
cd sxl
%SXLCMDD% /Fd..\lib\sxlmtd.pdb /MTd /c *.c *.cpp >>..\sxlbuild.log
del instances.obj
cd ..

lib /OUT:lib\sxlmtd.lib /NAME:sxlmtd.lib sxl\*.obj >>sxlbuild.log
if exist sxl\*.obj del sxl\*.obj

rem add in the SXL components to DLL
cd sxl
rc -l 409 -r -Fosxlrt.res -D_DEBUG sxlrt.rc >>..\sxlbuild.log
%SXLCMDD% /Fdsxlrt233d.pdb /MDd /LDd /DCRTDLL2 /c *.c *.cpp >>..\sxlbuild.log
%SXLCMDD% /Fdsxlrt233d.pdb /MDd /LDd /DCRTDLL2 *.obj sxlrt.res /link /out:sxlrt233d.dll /implib:sxlrtd.lib /subsystem:console /debug /incremental:no >>..\sxlbuild.log
lib sxlrtd.lib delaop.obj newaop.obj newaop2.obj newop2.obj >>..\sxlbuild.log
cd ..

move sxl\sxlrtd.lib lib
move sxl\sxlrt233d.dll bin
move sxl\sxlrt233d.pdb lib
if exist sxl\*.obj del sxl\*.obj
if exist sxl\*.exp del sxl\*.exp
if exist sxl\*.res del sxl\*.res

:quit
type sxlbuild.log
goto done

:usage
echo ERROR: must run v50setup.bat or v60setup.bat before building libraries

:done

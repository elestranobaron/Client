@echo off
rem for Microsoft Visual C++ V5.0
rem set environment for VC++ compiler with SXL
rem NOTE: TAILOR MSDevDir AND SXLDir TO YOUR CONFIGURATION

set MSDevDir=C:\PROGRA~1\DevStudio\SharedIDE
set MSVCDir=C:\PROGRA~1\DevStudio\VC
set VcOsDir=WIN95
set PATH=%MSDevDir%\BIN;%MSVCDir%\BIN;%MSVCDir%\BIN\%VcOsDir%;%PATH%
set INCLUDE=%MSVCDir%\INCLUDE;%MSVCDir%\MFC\INCLUDE;%INCLUDE%
set LIB=%MSVCDir%\LIB;%MSVCDir%\MFC\LIB;%LIB%

set SXLDir=C:\SXL
set INCLUDE=%SXLDir%\INCLUDE;%INCLUDE%
set LIB=%SXLDir%\LIB;%LIB%
set PATH=%SXLDir%\BIN;%PATH%

set  SXLCMD=cl /nologo /W3 /GR /GX /DWIN32 /Oityb1 /Gs
set SXLCMDD=cl /nologo /W4 /GR /GX /DWIN32 /Od /Zi /D_DEBUG

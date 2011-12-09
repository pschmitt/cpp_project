@echo off
rem filename: build.Linux.sh
set LIBNAME=cylinder
set SRC=circle.c cylinder.c
set OBJ=circle.obj cylinder.obj
set BUILD_DIR=..\build
set PUBLIC_HEADER=cylinder.h

cls

cl.exe /c /EHsc /W3 %SRC% /nologo


lib.exe /OUT:cylinder.lib %OBJ%

if not exist "%BUILD_DIR%\inc" (
	mkdir %BUILD_DIR%\inc;
)
if not exist  "%BUILD_DIR%\lib" (
	mkdir %BUILD_DIR%\lib;
)

copy %PUBLIC_HEADER% %BUILD_DIR%\inc
move %LIBNAME%.lib %BUILD_DIR%\lib
del %OBJ%

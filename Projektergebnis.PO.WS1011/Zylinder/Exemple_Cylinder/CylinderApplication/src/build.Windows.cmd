@echo off
rem filename: build.Windows.cmd
set SRC=cylinderIO.c cylinder.main.c
set OBJ=cylinderIO.obj cylinder.main.obj
set EXE=cylinder.exe
set ROOT=..\..\CylinderLibrary\build
set INCDIR=%ROOT%\inc
set LIBDIR=%ROOT%\lib
set LIBNAME=cylinder
set BIN_DIR=..\bin

cls
echo building %EXE%
cl.exe /Fe%EXE% /EHsc /W4 /nologo %SRC% /I%INCDIR% /link /LIBPATH:%LIBDIR% %LIBNAME%.lib

if not exist "%BIN_DIR%" (
	mkdir %BIN_DIR%;
)

if exist "%EXE%" (
	move %EXE% %BIN_DIR%
	del %OBJ%
	echo done
) else (
	echo build failed
)

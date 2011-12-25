#filename: build.Linux.sh
SRC="cylinderIO.c cylinder.main.c"
EXE=cylinder.exe
ROOT=../../CylinderLibrary/build
INCDIR=$ROOT/inc
LIBDIR=$ROOT/lib
LIBNAME=cylinder
BINDIR=../bin

echo building $EXE
gcc -o$EXE -Wall -pedantic $SRC -I$INCDIR -L$LIBDIR -l$LIBNAME

if [ ! -d $BINDIR ]; then
	mkdir -p $BINDIR;
fi
if [ -x $EXE ]; then (
	mv $EXE $BINDIR
	echo done
	)
else
	echo build failed
fi

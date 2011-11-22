#filename: build.Linux.sh
LIBNAME=cylinder
SRC="circle.c cylinder.c"
OBJ="circle.o cylinder.o"
BUILD_DIR="../build"
PUBLIC_HEADER="cylinder.h"


gcc -Wall -pedantic -c $SRC

ar -qc lib$LIBNAME.a $OBJ

if [ ! -d $BUILD_DIR/inc ]; then
	mkdir -p $BUILD_DIR/inc;
fi
if [ ! -d $BUILD_DIR/lib ]; then
	mkdir -p $BUILD_DIR/lib;
fi

cp $PUBLIC_HEADER $BUILD_DIR/inc
mv lib$LIBNAME.a $BUILD_DIR/lib
rm $OBJ

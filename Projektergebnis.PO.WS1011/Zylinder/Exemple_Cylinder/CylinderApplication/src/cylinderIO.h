/*! filename: cylinderIO.h */
#ifndef _CYLINDER_IO_H_INCLUDED_
#define _CYLINDER_IO_H_INCLUDED_

struct Cylinder;

void welcome();
int continuing();
void goodbye();

int getCylinderData(struct Cylinder* c);

void printCylinderSurface(double surface);

void onWrongInput();

#endif /*! #ifndef _CYLINDER_IO_H_INCLUDED_ */

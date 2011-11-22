/*! filename: cylinder.h */
#ifndef _CYLINDER_H_INCLUDED_
#define _CYLINDER_H_INCLUDED_

typedef struct Cylinder
{
	double radius;
	double height;
} Cylinder;

typedef enum { IRON = 1, WOOD, GLAS } CylinderMaterial;

double cylinderCapacity(const Cylinder* c);
double cylinderSurface(const Cylinder* c);
double cylinderLateralArea(const Cylinder* c);

#endif /*! #ifndef _CYLINDER_H_INCLUDED_ */

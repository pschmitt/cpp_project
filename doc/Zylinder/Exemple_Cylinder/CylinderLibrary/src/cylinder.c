/*! filename: cylinder.c */
#include "cylinder.h"
#include "circle.h"

double cylinderCapacity(const Cylinder* c)
{
	if (!c || c->radius < 0 || c->height < 0) { return -1; }
	return circleArea(c->radius) * c->height;
}


double cylinderSurface(const Cylinder* c)
{
	if (!c || c->radius < 0 || c->height < 0) { return -1; }
	return 2 * circleArea(c->radius) + cylinderLateralArea(c);
}


double cylinderLateralArea(const Cylinder* c)
{
	if (!c || c->radius < 0 || c->height < 0) { return -1; }
	return circumference(c->radius) * c->height;
}

#ifdef UNIT_TEST_CYLINDER_C

int main(int argc, char** argv)
{
	int errorCount = 0;
	/*! TODO: test cases */
	return errorCount;
}

#endif

/* filename: circle.c */
#include "circle.h"

double circleArea(double radius)
{
	if (radius < 0) { return -1; }
	return PI * radius * radius;
}

double circumference(double radius)
{
	if (radius < 0) { return -1; }
	return 2 * PI * radius;
}

#ifdef UNIT_TEST_CIRCLE

int main(int argc, char** argv)
{
	int errorCount = 0;
	/* TODO: test cases */
	return errorCount;
}

#endif

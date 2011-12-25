/*! filename: cylinderIO.c */
#include "cylinderIO.h"
#include <cylinder.h>
#include <stdio.h>

static double getCylinderRadius()
{
	double radius = -1.0; 
	printf("Geben Sie bitte den Radius ein: "); 
	scanf("%lf", &radius);
	return radius;
}

static double getCylinderHeight()
{
	double height = -1.0; 
	printf("Geben Sie bitte die Hoehe ein: "); 
	scanf("%lf", &height);
	return height;
}

void welcome()
{
	printf("Oberflaeche eines Zylinders!\n\n");
}

int continuing()
{
	int doit = 0;
	char c = '\0'; 
	printf("Weiter [J, j]: "); scanf("\n%c", &c);
	if (c == 'j' || c == 'J') { doit = 1; }
	return doit;
}

void goodbye()
{
	printf("\nCopyright: HTW des Saarlandes\n");
}

int getCylinderData(Cylinder* c)
{
	int inputOK = 1;
	if (!c) { return 0; }
	c->radius = getCylinderRadius();
	c->height = getCylinderHeight();
	if (c->radius <= 0 || c->height <= 0) { inputOK = 0; }
	return inputOK;
}


void printCylinderSurface(double surface)
{
	printf("Die Oberflaeche des Zylinders betraegt %f\n", surface);
}

void onWrongInput()
{
	printf("FEHLER: Bitte Beachten: Radius und Hoehe positiv! \n");
}

#ifdef UNIT_TEST_CYLINDER_IO

int main(int argc, char** argv)
{
	int errorCount = 0;
	/*! test cases */
	return errorCount;
}

#endif

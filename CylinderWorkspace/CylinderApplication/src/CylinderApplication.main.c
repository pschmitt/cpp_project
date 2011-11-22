/* filename: cylinder.main.c */
#include "cylinderIO.h"	
#include <cylinder.h>

int main()
{
	welcome();

	do
	{
		Cylinder c;
		int inputOK = getCylinderData(&c);
		if (inputOK) 
		{
			double surface = cylinderSurface(&c);
			printCylinderSurface(surface);
		} 
		else 
		{
			onWrongInput();
		}

	} while(continuing());

	goodbye();

	return 0;
}


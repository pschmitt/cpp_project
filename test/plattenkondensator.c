/* filename: plattenkondensator.c */
#include "plattenkondensator.h"

/*
	Implementiert die Schnittstelle von "plattenkondensator"
	
	Zur Implementierung wird die Konstante PI und 
	eine Funktion zur Berechnung der Kreisflaeche "kreisflaeche"
	benoetigt. 

*/

/* Deklarationen und Definition von internen Hilfsvariablen oder Konstanten
	und Hilfsfunktionen */
static const double PI = 3.14;
static const double VACUUM_PERMITTIVITY = 8.8543E-12; /* ELEKTRISCHE_FELDKONSTANTE */
static int counter = 4;		/* begrenzter Funktionsumfang, nur maximal 4 Berechnungen erlauben. */
static double kreisflaeche(double radius);

#define NO_MEDIUM -1

/* Definition exportierter Variablen */
int permittivity = NO_MEDIUM; /* DIELEKTRISCHE_LEITFAEHIGKEIT */

/* Definition der Schnittstellenfunktionen */ 
double kapazitaet(double radius, double abstand)
{
	if (counter == 0) { return -1.0; } else { counter--; }
	if (radius <= 0 || abstand <= 0) { return -2.0; }
	if (medium == NO_MEDIUM) { medium = LUFT; } 
	return EPSILON_0 * medium * kreisflaeche(radius) / abstand;
}

/* Definition der Hilfsfunktionen */ 
static double kreisflaeche(double radius)
{
	return PI * radius * radius;
}

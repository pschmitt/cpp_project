/*! 	
     \file		template.c
	\author	Reinhard Brocks
	\date 	14.10.2009
	\brief Dateikurzbeschreibung
	\section LICENSE
	Hochschule fuer Technik und Wirtschaft des Saarlandes 
	\section BUILD
	gcc -Wall -pedantic -otemplate.exe template.c
	\section DESCRIPTION
	Dateibeschreibung ausfuehrlich
*/
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "doxygenoutput.h"
/*! 
	\fn int main(int argc, char** argv)
	\brief Funktionskurzbeschreibung: Dies ist die Entry-Point Funktion
	
	Funktionsdetailbeschreibung
	
	\param argc Anzahl der Kommandozeilenparameter
	\param argv Vektor der Kommandozeilenparameter
	\return	Benendigungsstatus des Programms
*/
int main(int argc, char** argv)
{
	printf("Example: Class DoxygenOutputFunction\n");
	printf("#########################################\n");
	DoxygenOutputFunction doxygenfunction;
	doxygenfunction.brief="Kurzbeschreibung: Abfrage und Auswertung der Eingaben";
	doxygenfunction.description="Langbeschreibung: Ruft Funktionen zur Eingabe von Hoehe und Radius des Cylinders auf und checkt, ob die Eingaben valide sind";
	doxygenfunction.name="int getCylinderData(Cylinder* c)";
	doxygenfunction.params[0]="c pointer to Cylinder";
	doxygenfunction.returnvalue="inputOK";
	
	doxygenfunction.generateCommentForFunction(doxygenfunction);

	
	printf("Example: Class DoxygenOutputFile\n");
	printf("#########################################\n");
	DoxygenOutputFile doxygenfile;
	doxygenfile.name="cylinderIO.c";
	doxygenfile.author="siam";
	doxygenfile.brief="Kurzbeschreibung: CylinderIO Abfragen";
	doxygenfile.description="Dies und das, was mit Benutzer Eingabe und Ausgabe zur Cylinderberechnung zu tun hat";
	doxygenfile.license="Hochschule fuer Technik und Wirtschaft des Saarlandes";
	doxygenfile.build="gcc -o cylinder -Wall -pedantic cylinderIO.c CylinderApplication.main.c -I../../CylinderLibrary/build/inc -L../../CylinderLibrary/build/lib -lcylinder";
	doxygenfile.generateCommentForFile(doxygenfile);
	
	printf("Example: Class DoxygenOutputVariable\n");
    printf("#########################################\n");
	DoxygenOutputVariable doxygenvar;
	doxygenvar.name="radius";
	doxygenvar.brief="Kurzbeschreibung: Radius eines Cylinders";
	doxygenvar.description="double radius";
	doxygenvar.generateCommentForVariable(doxygenvar);
	
	printf("Example: Class DoxygenOutputEnumeration\n");
	printf("#########################################\n");
	DoxygenOutputEnumeration doxygenenum;
	doxygenenum.name="CylinderMaterial";
	doxygenenum.brief="Kurzbeschreibung: IRON = 1, WOOD, GLAS";
	doxygenenum.description="Langbeschreibung\n\tsehr viel text";
	doxygenenum.generateCommentForEnumeration(doxygenenum);
	
	printf("Example: Class DoxygenOutputStruct\n");
	printf("#########################################\n");
	DoxygenOutputStruct doxygenstruct;
	doxygenstruct.name="Cylinder";
	doxygenstruct.brief="Kurzbeschreibung: Struct fuer Cylinder";
	doxygenstruct.description="Cylinder ist definiert durch Hoehe und Radius";
	doxygenstruct.generateCommentForStruct(doxygenstruct);
	
	
	system("PAUSE");
	return 0;
}

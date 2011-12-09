/* filename: plattenkondesator.h */
#ifndef PLATTENKONDENSATOR_H_INCLUDED
#define PLATTENKONDENSATOR_H_INCLUDED

const int VACUUM  = 0; 
const int LUFT = 1.00059;
const int GLAS = 7;

extern int permittivity;

double kapazitaet(double radius, double abstand);

#endif /* PLATTENKONDENSATOR_H_INCLUDED */

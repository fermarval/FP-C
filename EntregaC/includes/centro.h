/*
 * centro.h
 *
 *  Created on: 26/5/2015
 *      Author: F
 */

#ifndef INCLUDES_CENTRO_H_
#define INCLUDES_CENTRO_H_

#include <stdio.h>
#include "cadena.h"
#include "espacio.h"
#include "logico.h"

typedef struct{
	Cadena nombre;
	Cadena direccion;
	int numeroPlantas;
	int numeroSotanos;
	ArrayEspacios espacios;
	int numEspacios;
}Centro;

typedef Centro* PCentro;
typedef int ArrayInt[5];

int inicializaCentro(PCentro, const Cadena, const Cadena, int, int, const ArrayEspacios, int);
void muestraCentro(Centro);
void getConteosEspacios(const ArrayEspacios, int, ArrayInt);

void copiaEspacios(ArrayEspacios, const ArrayEspacios, int);

Logico compruebaNumPlantas(int);
Logico compruebaNumSotanos(int);


#endif /* INCLUDES_CENTRO_H_ */

/*
 * grado.h
 *
 *  Created on: 22/5/2015
 *      Author: practica
 */

#ifndef GRADO_H_
#define GRADO_H_

#include <stdio.h>

#include "cadena.h"
#include "asignatura.h"

typedef struct {
	Cadena nombre, centro;
	int numObligatorias, numOptativas;
	double minimoCreditosOptativas;
	ArrayAsignaturas obligatorias, optativas;
}Grado;

typedef Grado* PGrado;

int inicializaGrado(PGrado, const Cadena, const Cadena, const ArrayAsignaturas, int, const ArrayAsignaturas, int, double);
void copiaAsignaturas(ArrayAsignaturas res, const ArrayAsignaturas aa, int n);

Logico mismosCreditos(const ArrayAsignaturas, int);
Logico sumaCreditos(double min, const ArrayAsignaturas, int);

void muestraGrado(Grado);

#endif /* GRADO_H_ */

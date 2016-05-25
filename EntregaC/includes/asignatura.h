/*
 * asignatura.h
 *
 *  Created on: 15/5/2015
 *      Author: practica
 */

#ifndef ASIGNATURA_H_
#define ASIGNATURA_H_

#include <stdio.h>
#include <ctype.h>

#include "logico.h"
#include "cadena.h"
#include "tipoAsignatura.h"

#define NUM_MAX_ASIGNATURAS 100

typedef char TipoCodigo[8];

typedef struct{
	Cadena nombre;
	TipoCodigo codigo;
	double creditos;
	TipoAsignatura tipo;
	int curso;
	Cadena departamento;
}Asignatura;

typedef Asignatura* PAsignatura;
typedef Asignatura ArrayAsignaturas[NUM_MAX_ASIGNATURAS];

int inicializaAsignatura(PAsignatura, const Cadena, const TipoCodigo, double, TipoAsignatura, int, const Cadena);
void getAcronimo(Asignatura, Cadena);
int leeAsignaturaTeclado(PAsignatura);
void muestraAsignatura(Asignatura);
int leeAsignaturasTeclado(ArrayAsignaturas);
void muestraAsignaturas(const ArrayAsignaturas, int);
int leeAsignaturasFichero(const Cadena,  ArrayAsignaturas);

void leeAsignaturaFichero(FILE*, PAsignatura);

Logico compruebaCodigo(const TipoCodigo);
Logico compruebaCreditos(double);
Logico compruebaCurso(int);

#endif /* ASIGNATURA_H_ */

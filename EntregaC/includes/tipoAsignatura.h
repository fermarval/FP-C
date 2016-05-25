/*
 * tipoAsignatura.h
 *
 *  Created on: 15/5/2015
 *      Author: practica
 */

#ifndef TIPOASIGNATURA_H_
#define TIPOASIGNATURA_H_

#include"cadena.h"

typedef enum {ANUAL,PRIMER_CUATRIMESTRE,SEGUNDO_CUATRIMESTRE}TipoAsignatura;

void deTipoAsignaturaACadena(Cadena,  TipoAsignatura);
int deCadenaATipoAsignatura(const Cadena, TipoAsignatura *res);

#endif /* TIPOASIGNATURA_H_ */

/*
 * espacio.h
 *
 *  Created on: 26/5/2015
 *      Author: F
 */

#ifndef INCLUDES_ESPACIO_H_
#define INCLUDES_ESPACIO_H_

#include <stdio.h>
#include "cadena.h"
#include "tipoEspacio.h"
#include "logico.h"

#define NUM_MAX_ESPACIOS 200

typedef struct{
	Cadena nombre;
	int planta;
	TipoEspacio tipo;
	int capacidad;
}Espacio;

typedef Espacio* PEspacio;
typedef Espacio ArrayEspacios[NUM_MAX_ESPACIOS];

int inicializaEspacio(PEspacio, const Cadena, int, TipoEspacio, int);
int leeEspacioTeclado(PEspacio);
void muestraEspacio (Espacio);
int leeEspaciosTeclado(ArrayEspacios);
void muestraEspacios(const ArrayEspacios, int);
int leeEspaciosFichero(const Cadena, ArrayEspacios);
void leeEspacioFichero(FILE*, PEspacio);

Logico compruebaCapacidad(int);

#endif /* INCLUDES_ESPACIO_H_ */

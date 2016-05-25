/*
 * tipoEspacio.h
 *
 *  Created on: 24/5/2015
 *      Author: F
 */

#ifndef INCLUDES_TIPOESPACIO_H_
#define INCLUDES_TIPOESPACIO_H_

#include "cadena.h"

typedef enum {TEORIA, LABORATORIO, SEMINARIO, EXAMEN, OTRO}TipoEspacio;

void deTipoEspacioACadena(Cadena, TipoEspacio);
int deCadenaATipoEspacio(const Cadena, TipoEspacio *res);

#endif /* INCLUDES_TIPOESPACIO_H_ */

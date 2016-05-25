/*
 * testCentro.c
 *
 *  Created on: 26/5/2015
 *      Author: F
 */

#include <stdio.h>
#include <string.h>
#include "centro.h"

void testInicializaCentro(const Cadena nombre, const Cadena direccion,
		int numPlantas, int numSotanos, const ArrayEspacios espacios, int numEspacios){

	Centro centro;
	int res = inicializaCentro(&centro, nombre, direccion, numPlantas, numSotanos, espacios, numEspacios);
	if(res==-1)
		printf("Centro no creado por datos incorrectos\n");
	else
		muestraCentro(centro);

	fflush(stdout);
}

int main(void){
	ArrayEspacios ae;
	Espacio e;
	Centro c;
	testInicializaCentro("Centro 1","Calle Andalucia",4,2,ae,0);

	return 0;
}

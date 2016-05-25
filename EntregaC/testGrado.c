/*
 * testGrado.c
 *
 *  Created on: 26/5/2015
 *      Author: F
 */

#include <stdio.h>
#include <string.h>
#include "grado.h"

void testInicializaGrado(const Cadena nombre, const Cadena centro, const ArrayAsignaturas obligatorias, int numObligatorias,
		const ArrayAsignaturas optativas, int numOptativas, double minCredsOptativas){

	Grado grado;
	int res = inicializaGrado(&grado, nombre, centro, obligatorias, numObligatorias, optativas, numOptativas, minCredsOptativas);
	if(res==-1)
		printf("Grado no creado por datos incorrectos\n");
	else
		muestraGrado(grado);

	fflush(stdout);
}

int main(void){
	ArrayAsignaturas ob,op;

	testInicializaGrado("Grado 1","Centro 1",ob,2,op,2,12);
}

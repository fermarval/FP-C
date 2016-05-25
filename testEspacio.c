/*
 * testEspacio.c
 *
 *  Created on: 26/5/2015
 *      Author: F
 */

#include <stdio.h>
#include <string.h>
#include "espacio.h"

void testInicializaEspacio(const Cadena nombre, int planta, TipoEspacio tipo, int capacidad){

	Espacio espa;
	int res = inicializaEspacio(&espa, nombre, planta, tipo, capacidad);
	if(res==-1)
		printf("Espacio no creado por datos incorrectos\n");
	else
		muestraEspacio(espa);

	fflush(stdout);
}

int main(void){
	testInicializaEspacio("Espacio 1",3,EXAMEN,50);

	return 0;
}

/*
 * testTipoAsignatura.c
 *
 *  Created on: 26/5/2015
 *      Author: F
 */

#include <stdio.h>
#include <string.h>
#include "tipoAsignatura.h"

void testConvierteCadena(TipoAsignatura tipo){
	Cadena res;

	deTipoAsignaturaACadena(res, tipo);
	printf("Cadena para %d: %s\n", tipo, res);
	fflush(stdout);
}

void testTipoAsignaturaCadena(const Cadena tipoStr){
	TipoAsignatura tipo;
	int res = deCadenaATipoAsignatura(tipoStr, &tipo);

	if(res==0){
		printf("Tipo %d para cadena %s\n", tipo, tipoStr);
	}else{
		printf("Error convirtiendo cadena\n");
	}
	fflush(stdout);
}

int main(void){
	printf("\nTESTEANDO FUNCIONES TIPO ASIGNATURA...\n");
	testConvierteCadena(ANUAL);
	testTipoAsignaturaCadena("PRIMER_CUATRIMESTRE");
	return 0;
}

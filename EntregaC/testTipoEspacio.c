/*
 * testTipoEspacio.c
 *
 *  Created on: 27/5/2015
 *      Author: F
 */

#include <stdio.h>
#include <string.h>
#include "tipoEspacio.h"

void testConvierteCadena(TipoEspacio tipo){
	Cadena res;

	deTipoEspacioACadena(res, tipo);
	printf("Cadena para %d: %s\n", tipo, res);
	fflush(stdout);
}

void testTipoEspacioCadena(const Cadena tipoStr){
	TipoEspacio tipo;
	int res = deCadenaATipoEspacio(tipoStr, &tipo);

	if(res==0){
		printf("Tipo %d para cadena %s\n", tipo, tipoStr);
	}else{
		printf("Error convirtiendo cadena\n");
	}
	fflush(stdout);
}

int main(void){
	printf("\nTESTEANDO FUNCIONES TIPO ESPACIO...\n");
	testConvierteCadena(LABORATORIO);
	testTipoEspacioCadena("EXAMEN");
	return 0;
}

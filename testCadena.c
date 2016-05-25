/*
 * testCadena.c
 *
 *  Created on: 26/5/2015
 *      Author: F
 */

#include <stdio.h>
#include <string.h>
#include "cadena.h"

void testQuitaSaltoDeLinea(Cadena cad){
	quitaSaltoDeLinea(cad);
	printf("Cadena modificada %s\n", cad);
	fflush(stdout);
}

int main(void){
	printf("\nTESTEANDO FUNCIONES CADENA...\n");
	testQuitaSaltoDeLinea("Prueba");
	return 0;
}

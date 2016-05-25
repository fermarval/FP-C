/*
 * cadena.c
 *
 *  Created on: 15/5/2015
 *      Author: practica
 */

#include <stdio.h>
#include <string.h>
#include "cadena.h"

void quitaSaltoDeLinea(Cadena cad){
	int i=0;
	for(i=0;i<strlen(cad);i++)
		if(cad[i]=='\n'){
			cad[i]='\0';
			break;
		}
}


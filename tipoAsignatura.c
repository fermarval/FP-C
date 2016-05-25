/*
 * tipoAsignatura.c
 *
 *  Created on: 15/5/2015
 *      Author: practica
 */

#include "tipoAsignatura.h"

void deTipoAsignaturaACadena(Cadena res, TipoAsignatura tipo){
	switch(tipo){
	case ANUAL: strcpy(res,"ANUAL");
	break;
	case PRIMER_CUATRIMESTRE: strcpy(res,"PRIMER_CUATRIMESTRE");
	break;
	case SEGUNDO_CUATRIMESTRE: strcpy(res,"SEGUNDO_CUATRIMESTRE");
	}
}

int deCadenaATipoAsignatura(const Cadena cad, TipoAsignatura *res){
	int ok=0;
	if(strcmp(cad,"ANUAL")==0)
		*res = ANUAL;
	else
		if(strcmp(cad,"PRIMER_CUATRIMESTRE")==0)
			*res = PRIMER_CUATRIMESTRE;
		else
			if(strcmp(cad,"SEGUNDO_CUATRIMESTRE")==0)
				*res = SEGUNDO_CUATRIMESTRE;
			else
				ok=-1;
	return ok;
}

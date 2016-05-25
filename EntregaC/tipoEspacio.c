/*
 * tipoEspacio.c
 *
 *  Created on: 26/5/2015
 *      Author: F
 */

#include "tipoEspacio.h"

void deTipoEspacioACadena(Cadena res, TipoEspacio tipo){
	switch(tipo){
	case TEORIA: strcpy(res,"TEORIA");
	break;
	case LABORATORIO: strcpy(res,"LABORATORIO");
	break;
	case SEMINARIO: strcpy(res,"SEMINARIO");
	break;
	case EXAMEN: strcpy(res,"EXAMEN");
	break;
	case OTRO: strcpy(res,"OTRO");
	}
}

int deCadenaATipoEspacio(const Cadena cad, TipoEspacio *res){
	int ok=0;
	if(strcmp(cad,"TEORIA")==0)
		*res = TEORIA;
	else
		if(strcmp(cad,"LABORATORIO")==0)
				*res = LABORATORIO;
		else
			if(strcmp(cad,"SEMINARIO")==0)
					*res = SEMINARIO;
			else
				if(strcmp(cad,"EXAMEN")==0)
						*res = EXAMEN;
				else
					if(strcmp(cad,"OTRO")==0)
							*res = OTRO;
					else
						ok=-1;
	return ok;
}

/*
 * grado.c
 *
 *  Created on: 22/5/2015
 *      Author: practica
 */

#include "grado.h"

int inicializaGrado(PGrado res, const Cadena nombre, const Cadena centro, const ArrayAsignaturas obligatorias, int numObligatorias,
				const ArrayAsignaturas optativas, int numOptativas, double minCredsOptativas){
	int result=0;
	Logico ok = mismosCreditos(optativas, numOptativas) && sumaCreditos(minCredsOptativas, optativas, numOptativas) &&
			minCredsOptativas>=0;

	if(ok==CIERTO){
		strcpy(res->nombre, nombre);
		strcpy(res->centro, centro);

		copiaAsignaturas(res->obligatorias, obligatorias, numObligatorias);
		res->numObligatorias = numObligatorias;

		copiaAsignaturas(res->optativas, optativas, numOptativas);
		res->numOptativas = numOptativas;

		res->minimoCreditosOptativas = minCredsOptativas;
	}else
		result=-1;

	return result;
}

void copiaAsignaturas(ArrayAsignaturas res, const ArrayAsignaturas aa, int n){
	int i=0;
	for(i=0;i<n;i++)
		res[i]=aa[i];
}

Logico mismosCreditos(const ArrayAsignaturas aa, int n){
	int i;
	double aux;
	Logico res = CIERTO;
	for(i=0;res&&i<n;i++){
		if(i==0)
			aux=aa[i].creditos;
		else
			res=(aux==aa[i].creditos);
	}
	return res;
}


Logico sumaCreditos(double min, const ArrayAsignaturas aa, int n){
	int i;
	double sum = 0.0;
	Logico res = CIERTO;
	for(i=0;res&&i<n;i++)
		sum=sum+aa[i].creditos;
	return min<=sum;
}

void muestraGrado(Grado g){
	printf("\nNombre: %s",g.nombre); fflush(stdout);
	printf("\nCentro: %s",g.centro); fflush(stdout);
	puts("= = = = = = Asignaturas obligatorias = = = = = =");
	muestraAsignaturas(g.obligatorias, g.numObligatorias);
	puts("= = = = = = Asignaturas optativas = = = = = =");
	muestraAsignaturas(g.optativas, g.numOptativas);
	printf("\nMínimo nº de créditos optativas: %lf", g.minimoCreditosOptativas); fflush(stdout);

}

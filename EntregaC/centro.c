/*
 * centro.c
 *
 *  Created on: 26/5/2015
 *      Author: F
 */

#include "centro.h"

int inicializaCentro(PCentro res, const Cadena nombre, const Cadena direccion,
		int numPlantas, int numSotanos, const ArrayEspacios espacios, int numEspacios){
	int ok=0;
	if(!compruebaNumPlantas(numPlantas) ||
		!compruebaNumSotanos(numSotanos)){
		printf("inicializaCentro: Error en algún parámetro de entrada\n");
	}
	else{
		strcpy(res->nombre,nombre); //strcpy SOLO para cadenas
		strcpy(res->direccion,direccion);
		res->numeroPlantas=numPlantas;
		res->numeroSotanos=numSotanos;
		copiaEspacios(res->espacios, espacios, numEspacios);
		res->numEspacios=numEspacios;
	}
	return ok;
}

void copiaEspacios(ArrayEspacios res, const ArrayEspacios ae, int n){
	int i=0;
	for(i=0;i<n;i++)
		res[i]=ae[i];
}

Logico compruebaNumPlantas(int numPlantas){
	Logico res=CIERTO;
	if(numPlantas<1)
		res=FALSO;
	return res;
}

Logico compruebaNumSotanos(int numSotanos){
	Logico res=CIERTO;
	if(numSotanos<0)
		res=FALSO;
	return res;
}

void muestraCentro (Centro c){
	printf("Nombre %s\n", c.nombre);fflush(stdout);
	printf("Dirección %s\n", c.direccion);fflush(stdout);
	printf("Numero de plantas %d\n", c.numeroPlantas);fflush(stdout);
	printf("Numero de sótanos %d\n", c.numeroSotanos);fflush(stdout);
	printf("Espacios \n");
	printf("*** \n");
	//muestraEspacios(c.espacios, sizeof(c.espacios));
	printf("*** \n");
}

void getConteosEspacios(const ArrayEspacios espacios, int nEspacios, ArrayInt c){
	int i=0;
	int teo, lab, sem, exa, otr;
	for(i=0;i<nEspacios;i++){
		if(espacios[i].tipo==TEORIA)
			teo++;
		if(espacios[i].tipo==LABORATORIO)
			lab++;
		if(espacios[i].tipo==SEMINARIO)
			sem++;
		if(espacios[i].tipo==EXAMEN)
			exa++;
		if(espacios[i].tipo==OTRO)
			otr++;
	}
	c[0]=teo;c[1]=lab;c[2]=sem;
	c[3]=exa;c[4]=otr;
}

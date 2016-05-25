/*
 * espacio.c
 *
 *  Created on: 26/5/2015
 *      Author: F
 */

#include <stdio.h>
#include <string.h>
#include "espacio.h"
#include "logico.h"

int inicializaEspacio(PEspacio res, const Cadena nombre, int planta, TipoEspacio tipo, int capacidad){
	int ok=0;
	if(!compruebaCapacidad(capacidad)){
		printf("inicializaEspacio: Error en algún parámetro de entrada\n");
		ok=-1;
	}
	else{
		strcpy(res->nombre,nombre); //strcpy SOLO para cadenas
		res->planta=planta;
		res->tipo=tipo;
		res->capacidad=capacidad;
	}
	return ok;
}

Logico compruebaCapacidad(int capacidad){
	Logico res=CIERTO;
	if(capacidad<1)
		res=FALSO;
	return res;
}

int leeEspacioTeclado(PEspacio res){
	Cadena nombre,aux;
	int planta,capacidad,ok;
	TipoEspacio tipo;

	printf("Nombre: ");
	fflush(stdout);
	gets(nombre);

	printf("Planta: ");
	fflush(stdout);
	scanf("%d",&planta);
	fflush(stdin);

	printf("Tipo: ");
	fflush(stdout);
	gets(aux);

	printf("Capacidad: ");
	fflush(stdout);
	scanf("%d",&capacidad);
	fflush(stdin);

	ok=deCadenaATipoEspacio(aux, &tipo);
	if(ok==-1)
		printf("Error en el tipo de espacio\n");
	else
		ok=inicializaEspacio(res,nombre,planta,tipo,capacidad);
	return ok;
}

void muestraEspacio (Espacio e){
	Cadena tipoEspaCad;
	deTipoEspacioACadena(tipoEspaCad,e.tipo);

	printf("Nombre %s\n", e.nombre);fflush(stdout);
	printf("Planta %d\n", e.planta);fflush(stdout);
	printf("Tipo %s\n", tipoEspaCad);fflush(stdout);
	printf("Capacidad %d\n", e.capacidad);fflush(stdout);
}

void muestraEspacios(const ArrayEspacios ae, int nEspacios){
	int i;
	for(i=0;i<nEspacios;i++){
		printf("Espacio nº %d:\n",i+1); fflush(stdout);
		muestraEspacio(ae[i]);
	}
}

int leeEspaciosTeclado(ArrayEspacios res){
	int i, ok, nEspacios=0;

		while(nEspacios<=0 || nEspacios>NUM_MAX_ESPACIOS){
			printf("Introduzca el numero de espacios:");
			scanf("%d", &nEspacios);
		}
		for(i=0;i<nEspacios;i++){
			ok=-1;
			while(ok!=0){
				printf("Leyendo espacio nº %d\n",i+1);fflush(stdout);
				ok = leeEspacioTeclado(&res[i]);
			}
		}
		return nEspacios;
}

int leeEspaciosFichero(const Cadena nombreFichero, ArrayEspacios res){
	int i = 0;
	FILE* f = fopen(nombreFichero, "r");
	if(f==NULL)
		puts("NO SE HA PODIDO ABRIR EL FICHERO");
	else{
		leeEspacioFichero(f,&res[i++]);
		while(i<NUM_MAX_ESPACIOS && !feof(f))
			leeEspacioFichero(f,&res[i++]);
		fclose(f);
	}
	return i;
}

void leeEspacioFichero(FILE* f, PEspacio pe){
	Cadena tipoAux;
	fgets(pe->nombre, NUM_MAX_CAR_CADENAS, f);
	fscanf(f,"%d", pe->planta);
	fscanf(f,"%s", tipoAux); deCadenaATipoEspacio(tipoAux, &pe->tipo);
	fscanf(f,"%d", pe->capacidad);
}

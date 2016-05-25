/*
 * asignatura.c
 *
 *  Created on: 15/5/2015
 *      Author: practica
 */

#include <stdio.h>
#include <string.h>
#include "asignatura.h"
#include "logico.h"

int inicializaAsignatura(PAsignatura res, const Cadena nombre, const TipoCodigo codigo,
		double creditos, TipoAsignatura tipo, int curso, const Cadena departamento){
	int ok=0;
	if(!compruebaCodigo(codigo)||
	   !compruebaCreditos(creditos)||
	   !compruebaCurso(curso)){
			printf("inicializaAsignatura: Error en algún parámetro de entrada\n");
			ok=-1;
	}
	else{
		strcpy(res->nombre,nombre);
		strcpy(res->codigo,codigo); //strcpy SOLO para cadenas
		res->creditos=creditos;
		res->tipo=tipo;
		res->curso=curso;
		strcpy(res->departamento,departamento);
	}
	return ok;
}

Logico compruebaCodigo(const TipoCodigo codigo){
	Logico res=CIERTO;
	int i=0;
	if(strlen(codigo)!=7)
		res=FALSO;
	else
		for(i=0;i<7;i++)
			if(codigo[i]<'0'||codigo[i]>'9'){
				res=FALSO;
				break;
			}
	return res;
}

Logico compruebaCreditos(double creditos){
	Logico res=CIERTO;
	if(creditos<=0)
		res=FALSO;
	return res;
}

Logico compruebaCurso(int curso){
	Logico res=CIERTO;
	if(curso<1||curso>4)
		res=FALSO;
	return res;
}

//void getAcronimo(Asignatura a, Cadena res){
//	int i=0,j=0;
//	for(i=0;i<strlen(a.nombre);i++)
//		if(isupper(a.nombre[i])){
//			res[j]=a.nombre[i];
//			j++;
//		}
//	res[j]='/0';
//}

void getAcronimo(Asignatura a, Cadena res){
	int i, j=0;
	for(i=0; i< strlen(a.nombre);i++){
		if(isupper(a.nombre[i]))
			res[j++]=a.nombre[i];

	}
	res[j] = '\0';
}

int leeAsignaturaTeclado(PAsignatura res){
	Cadena nombre,codigo,aux,departamento;
	double creditos;
	int curso,ok;
	TipoAsignatura tipo;

	printf("Nombre: ");
	fflush(stdout);
	gets(nombre);

	printf("Codigo: ");
	fflush(stdout);
	gets(codigo);

	printf("Creditos: ");
	fflush(stdout);
	scanf("%lf",&creditos);
	fflush(stdin);

	printf("Tipo: ");
	fflush(stdout);
	gets(aux);

	printf("Curso: ");
	fflush(stdout);
	scanf("%d",&curso);
	fflush(stdin);

	printf("Departamento: ");
	fflush(stdout);
	gets(departamento);

	ok=deCadenaATipoAsignatura(aux, &tipo);
	if(ok==-1)
		printf("Error en el tipo de asignatura\n");
	else
		ok=inicializaAsignatura(res,nombre,codigo,creditos,tipo,curso,departamento);
	return ok;
}

void muestraAsignatura(Asignatura a){
	Cadena acron, tipoAsigCad;
	getAcronimo(a, acron);
	deTipoAsignaturaACadena(tipoAsigCad, a.tipo);

	printf("Nombre %s\n", a.nombre);fflush(stdout);
	printf("Acronimo: %s\n", acron);fflush(stdout);
	printf("Codigo: %s\n", a.codigo);fflush(stdout);
	printf("Creditos: %lf", a.creditos);fflush(stdout);
	printf("Tipo %s\n", tipoAsigCad);fflush(stdout);
	printf("Curso: %d", a.curso);fflush(stdout);
	printf("Departamento: %s\n", a.departamento);fflush(stdout);
}

int leeAsignaturasTeclado(ArrayAsignaturas res){
	int i, ok, numAsig=0;

	while(numAsig<=0 || numAsig>NUM_MAX_ASIGNATURAS){
		printf("Introduzca el numero de asignaturas:");
		scanf("%d", &numAsig);
	}
	for(i=0;i<numAsig;i++){
		ok=-1;
		while(ok!=0){
			printf("Leyendo asignatura nº %d\n",i+1);fflush(stdout);
			ok = leeAsignaturaTeclado(&res[i]);
		}
	}
	return numAsig;
}

void muestraAsignaturas(const ArrayAsignaturas aa, int nAsig){
	int i;
	for(i=0;i<nAsig;i++){
		printf("Asignatura nº %d:\n",i+1); fflush(stdout);
		muestraAsignatura(aa[i]);
	}
}

int leeAsignaturasFichero(const Cadena nombreFich, ArrayAsignaturas res){
	int i = 0;
	FILE* f = fopen(nombreFich, "r");
	if(f==NULL)
		puts("NO SE HA PODIDO ABRIR EL FICHERO");
	else{
		leeAsignaturaFichero(f,&res[i++]);
		while(i<NUM_MAX_ASIGNATURAS && !feof(f))
			leeAsignaturaFichero(f,&res[i++]);
		fclose(f);
	}
	return i;
}

void leeAsignaturaFichero(FILE* f, PAsignatura pa){
	Cadena tipoAux;
	fgets(pa->nombre, NUM_MAX_CAR_CADENAS, f);
	fscanf(f,"%s", pa->codigo);
	fscanf(f,"%lf", &pa->creditos);
	fscanf(f,"%s", tipoAux); deCadenaATipoAsignatura(tipoAux, &pa->tipo);
	fscanf(f,"%d",&pa->curso);
	fgets(pa->departamento, NUM_MAX_CAR_CADENAS, f);
}

/*
 * testAsignatura.c
 *
 *  Created on: 22/5/2015
 *      Author: practica
 */

#include <stdio.h>
#include <string.h>

#include "asignatura.h"

void testInicializaAsignatura(const Cadena nombre, const TipoCodigo codigo, double creditos, TipoAsignatura tipo, int curso, const Cadena dpto){

	Asignatura asig;
	int res = inicializaAsignatura(&asig, nombre, codigo, creditos, tipo, curso, dpto);
	if(res==-1)
		printf("Asignatura no creada por datos incorrectos\n");
	else
		muestraAsignatura(asig);

	fflush(stdout);
}

void testGetAcronimo(Asignatura a){
	Cadena res;
	getAcronimo(a,res);
		printf("El acronimo de %s es %s\n", a.nombre, res);
	fflush(stdout);
}

void testLeeAsignaturaTeclado(){
	Asignatura a;
	if(leeAsignaturaTeclado(&a)==0)
		muestraAsignatura(a);
	else
		puts("Error leyendo asignatura.");

	fflush(stdout);
}

void testLeeAsignaturasTeclado(){
	ArrayAsignaturas asignaturas;
	int numAsignatuas;
}

void testLeeAsignaturasFichero(){
	Cadena nomFich = "./res//asignatura.txt";
	ArrayAsignaturas res;
	leeAsignaturasFichero(nomFich, res);
}

void testLeeAsignaturaFichero(FILE* f, PAsignatura pa){

}

int main(void){
	testInicializaAsignatura("Fundamentos de Programacion","2050001",12.0,ANUAL,1,"LSI");
	testInicializaAsignatura("Fundamentos de Programacion","2050",12.0,ANUAL,1,"LSI");
	testInicializaAsignatura("Fundamentos de Programacion","205000001",12.0,ANUAL,1,"LSI");
	testInicializaAsignatura("Fundamentos de Programacion","205000A",12.0,ANUAL,1,"LSI");
	testInicializaAsignatura("Fundamentos de Programacion","2050001",0.0,ANUAL,1,"LSI");
	testInicializaAsignatura("Fundamentos de Programacion","2050001",-10.0,ANUAL,1,"LSI");
	testInicializaAsignatura("Fundamentos de Programacion","2050001",10.0,ANUAL,0,"LSI");
	testInicializaAsignatura("Fundamentos de Programacion","2050001",10.0,ANUAL,5,"LSI");

	Asignatura a;
	strcpy(a.nombre, "Fundamentos de Programacion");
	testGetAcronimo(a);
	strcpy(a.nombre, "Fundamentos de ProgramacioN");
	testGetAcronimo(a);

	testLeeAsignaturaTeclado();
	testLeeAsignaturasTeclado();
	return 0;
}

/*
 ============================================================================
 Name        : Ejercicio24.c
 Author      : Kevin Quevedo
 Version     : 1.0
 Folder		 : TrabajosExtras
 Copyright   : Your copyright notice
 Description : Diseñar en  un programa que permita registrar de los empleados
 	 	 	   de una fábrica (no se sabe cuántos) su peso y saber cuántos
 	 	 	   pesan hasta 80 kg. inclusive y cuantos pesan más de 80 kg.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout, NULL);
	int peso;
	int pMasOchenta=0;
	int pMenosOIgualOchenta=0;
	char respuesta;

	do{
		printf("Ingrese el peso de un empleado: \n");
		fflush(stdin);
		scanf("%d",&peso);

		if(peso>80){
			pMasOchenta++;
		} else if(peso<=80){
			pMenosOIgualOchenta++;
		}

		printf("Desea continuar? Ingrese S/N: \n");
		fflush(stdin);
		scanf("%c",&respuesta);
	} while (respuesta!='N' && respuesta!='n');

	printf("\nLa cantidad de empleados que pesan mas de 80kg es: %d",pMasOchenta);
	printf("\nLa cantidad de empleados que pesan menos o igual a 80kg es: %d",pMenosOIgualOchenta);

	return EXIT_SUCCESS;
}

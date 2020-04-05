/*
 ============================================================================
 Name        : Ejercicio10.c
 Author      : Kevin Quevedo
 Version     : 1.0
 Folder		 : TrabajosExtras
 Copyright   : Your copyright notice
 Description : Escribir en C un programa que muestre los números impares
               entre 0 y 100 y que imprima cuantos impares hay.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout, NULL);
	int numero=1;
	int cantidadImpares=0;

	printf("%d",numero);
	cantidadImpares++;
	do{
		cantidadImpares++;
		numero+=2;
		printf(", %d",numero);
	} while(numero<99);

	printf("\n\nLa cantidad de numeros impares del 1 al 100 es: %d",cantidadImpares);
	return EXIT_SUCCESS;
}

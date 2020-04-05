/*
 ============================================================================
 Name        : Ejercicio13.c
 Author      : Kevin Quevedo
 Version     : 1.0
 Folder		 : TrabajosExtras
 Copyright   : Your copyright notice
 Description : Hacer el programa que imprima los números del 100 al 0 en orden decreciente
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout, NULL);
	int numero=100;

	while(numero>-1){

		printf("%d, ",numero);
		numero--;
	}

	return EXIT_SUCCESS;
}

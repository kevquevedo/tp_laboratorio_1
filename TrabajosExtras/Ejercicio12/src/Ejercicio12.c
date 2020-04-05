/*
 ============================================================================
 Name        : Ejercicio12.c
 Author      : Kevin Quevedo
 Version     : 1.0
 Folder		 : TrabajosExtras
 Copyright   : Your copyright notice
 Description : Hacer el programa que imprima los números del 1 al 100
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout, NULL);
	int numero=1;

	while(numero<101){
		printf("%d, ",numero);
		numero++;
	}

	return EXIT_SUCCESS;
}

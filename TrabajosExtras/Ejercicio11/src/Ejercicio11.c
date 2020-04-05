/*
 ============================================================================
 Name        : Ejercicio11.c
 Author      : Kevin Quevedo
 Version     : 1.0
 Folder		 : TrabajosExtras
 Copyright   : Your copyright notice
 Description : Hacer el programa que imprima los números pares entre el 1 y el 100.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout, NULL);
	int numero=2;

	while(numero<100){

		printf("%d, ",numero);
		numero+=2;
	}

	return EXIT_SUCCESS;
}

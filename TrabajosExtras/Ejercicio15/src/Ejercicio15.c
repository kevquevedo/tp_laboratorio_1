/*
 ============================================================================
 Name        : Ejercicio15.c
 Author      : Kevin Quevedo
 Version     : 1.0
 Folder		 : TrabajosExtras
 Copyright   : Your copyright notice
 Description : Escribir y codificar en C un programa que muestre
 	 	 	   los múltiplos de 6 comprendidos entre 0 y 100
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout, NULL);
	int numero=6;

	while(numero<100){
		printf("%d, ",numero);
		numero+=6;
	}

	return EXIT_SUCCESS;
}

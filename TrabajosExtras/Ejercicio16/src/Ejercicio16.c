/*
 ============================================================================
 Name        : Ejercicio16.c
 Author      : Kevin Quevedo
 Version     : 1.0
 Folder		 : TrabajosExtras
 Copyright   : Your copyright notice
 Description : Hacer el programa que nos permita introducir un número
 	 	 	   por teclado y nos informe si es positivo o negativo.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout, NULL);
	int numero;

	printf("Ingrese un numero: \n");
	fflush(stdin);
	scanf("%d",&numero);

	if(numero>0){
		printf("\nEl numero ingresado es POSITIVO.");
	} else if(numero<0) {
		printf("\nEl numero ingresado es NEGATIVO.");
	}

	return EXIT_SUCCESS;
}

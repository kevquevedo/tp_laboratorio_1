/*
 ============================================================================
 Name        : Ejercicio17.c
 Author      : Kevin Quevedo
 Version     : 1.0
 Folder		 : TrabajosExtras
 Copyright   : Your copyright notice
 Description : Hacer el programa que nos permita introducir un número por
 	 	 	   teclado y nos informe si es par o impar .
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout, NULL);
	int numero;

	printf("Ingrese un numero: ");
	fflush(stdin);
	scanf("%d",&numero);

	if(numero%2==0){
		printf("\n\nEl numero es PAR.");
	} else {
		printf("\n\nEl numero es IMPAR.");
	}

	return EXIT_SUCCESS;
}

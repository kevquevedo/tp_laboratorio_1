/*
 ============================================================================
 Name        : Ejercicio6.c
 Author      : Kevin Quevedo
 Version     : 1.0
 Carpeta	 : TrabajosExtras
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout, NULL);
	int numero;
	int numPositivos=0;
	int numNegativos=0;
	int i;

	for (i=0;i<10;i++){

		printf("Ingrese el %d numero: \n",i+1);
		fflush(stdin);
		scanf("%d",&numero);

		if(numero>0){
			numPositivos++;
		} else if(numero<0){
			numNegativos++;
		}
	}

	printf("\nLa cantidad de numeros positivos es: %d",numPositivos);
	printf("\nLa cantidad de numeros negativos es: %d",numNegativos);
	return EXIT_SUCCESS;
}

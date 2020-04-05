/*
 ============================================================================
 Name        : Ejercicio5.c
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
	int cuadrado;

	do{
		printf("Ingrese un numero mayor a cero: ");
		fflush(stdin);
		scanf("%d",&numero);
		if(numero<1){
			printf("\nERROR, el número debe ser mayor que cero.\n");
		}
	} while(numero<1);

	cuadrado=numero*numero;

	printf("\nEl cuadrado del numero ingresado es: %d",cuadrado);
	return EXIT_SUCCESS;
}

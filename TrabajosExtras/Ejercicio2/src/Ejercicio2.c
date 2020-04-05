/*
 ============================================================================
 Name        : Ejercicio2.c
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
	int numero1;
	int numero2;
	int suma;

	printf("Ingrese el primer numero: \n");
	fflush(stdin);
	scanf("%d",&numero1);

	printf("Ingrese el segundo numero: \n");
	fflush(stdin);
	scanf("%d",&numero2);

	suma=numero1+numero2;

	printf("\nLa suma de los numeros es: %d",suma);
	return EXIT_SUCCESS;
}

/*
 ============================================================================
 Name        : Ejercicio1.c
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
	int contador;
	int acumulador=0;
	float promedio;

	for (contador=0;contador<5;contador++){
		printf("Ingrese el %d numero: ",contador+1);
		fflush(stdin);
		scanf("%d",&numero);
		acumulador+=numero;
	}

	promedio=(float)acumulador/contador;

	printf("\nEl promedio de los numeros es: %.2f",promedio);
	return EXIT_SUCCESS;
}

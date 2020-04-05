/*
 ============================================================================
 Name        : Ejercicio8.c
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

	float altura;
	float base;
	float areaTriangulo;

	do{
		printf("Ingrese la altura del triangulo: \n");
		fflush(stdin);
		scanf("%f",&altura);
	} while(altura<1);
	do{
		printf("Ingrese la base del triangulo: \n");
		fflush(stdin);
		scanf("%f",&base);
	} while(base<1);

	areaTriangulo=(altura*base)/2;

	printf("\nEl area del triangulo es: %.2f",areaTriangulo);
	return EXIT_SUCCESS;
}

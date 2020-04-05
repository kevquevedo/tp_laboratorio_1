/*
 ============================================================================
 Name        : Ejercicio3.c
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
	int producto;
	int cuadradoNum1;

	system("cls");

	printf("Ingrese el primer numero: \n");
	fflush(stdin);
	scanf("%d",&numero1);

	printf("Ingrese el segundo numero: \n");
	fflush(stdin);
	scanf("%d",&numero2);

	producto=numero1*numero2;
	cuadradoNum1=numero1*numero1;

	printf("\nEl producto de los numeros es: %d",producto);
	printf("\nEl cuadrado del primer numero es: %d",cuadradoNum1);
	return EXIT_SUCCESS;
}

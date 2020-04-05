/*
 ============================================================================
 Name        : Ejercicio7.c
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
	float valorRadio;
	float valorCircunferencia;
	float valorArea;
	float pi=3.14;

	printf("Ingrese el radio de un circulo: \n");
	fflush(stdin);
	scanf("%f",&valorRadio);

	valorCircunferencia=valorRadio*2*pi;
	valorArea=valorRadio*valorRadio*pi;

	printf("\nLa circunferencia del circulo es: %.2f",valorCircunferencia);
	printf("\nEl area del circulo es: %.2f",valorArea);
	return EXIT_SUCCESS;
}

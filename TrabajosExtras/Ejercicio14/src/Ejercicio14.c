/*
 ============================================================================
 Name        : Ejercicio14.c
 Author      : Kevin Quevedo
 Version     : 1.0
 Folder		 : TrabajosExtras
 Copyright   : Your copyright notice
 Description : Diseñar un programa que imprima y sume la serie de números 3,6,9,12,...,99
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout, NULL);
	int numero=3;
	int acumuladorNumero=0;

	while(numero<100){
		printf("%d, ",numero);
		acumuladorNumero+=numero;
		numero+=3;
	}

	printf("\n\nLa suma de los numeros es: %d",acumuladorNumero);
	return EXIT_SUCCESS;
}

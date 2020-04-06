/*
 ============================================================================
 Name        : Ejercicio21.c
 Author      : Kevin Quevedo
 Version     : 1.0
 Folder		 : TrabajosExtras
 Copyright   : Your copyright notice
 Description : Hacer el programa que nos permita contar los múltiplos
 	 	 	   de 3 desde la unidad hasta un número que introducimos por teclado .
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout, NULL);
	int numero;
	int multiplo=0;

	printf("Ingrese un numero: ");
	fflush(stdin);
	scanf("%d",&numero);

	multiplo=3;
	while(multiplo<=numero){
		printf("%d,",multiplo);
		multiplo+=3;
	}
	return EXIT_SUCCESS;
}

/*
 ============================================================================
 Name        : Ejercicio4.c
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
	int resultado;

	system("cls");

	printf("Ingrese el primer numero: \n");
	fflush(stdin);
	scanf("%d", &numero1);

	printf("Ingrese el segundo numero: \n");
	fflush(stdin);
	scanf("%d", &numero2);

	resultado=numero1-numero2;
	printf("\nLa resta entre el primer y segundo numero es: %d",resultado);
	if(resultado>0){
		printf("\nEs un resultado positivo");
	} else if(resultado<0){
		printf("\nEs un resultado negativo");
	}
	return EXIT_SUCCESS;
}

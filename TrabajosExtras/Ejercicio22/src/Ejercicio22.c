/*
 ============================================================================
 Name        : Ejercicio22.c
 Author      : Kevin Quevedo
 Version     : 1.0
 Folder		 : TrabajosExtras
 Copyright   : Your copyright notice
 Description : Diseñar el programa necesario para que habiéndose leído el valor
  	  	       de 2 variables NUM1 y NUM2 se intercambien los valores de las variables,
  	  	       es decir que el valor que tenía NUM1 ahora lo contenga NUM2 y viceversa .
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout, NULL);
	int num1;
	int num2;
	int pasaje;

	printf("Ingrese el primer numero: \n");
	fflush(stdin);
	scanf("%d",&num1);

	printf("Ingrese el segundo numero: \n");
	fflush(stdin);
	scanf("%d",&num2);

	pasaje=num2;
	num2=num1;
	num1=pasaje;

	printf("\nEl valor del primer numero es: %d",num1);
	printf("\nEl valor del segundo numero es: %d",num2);
	return EXIT_SUCCESS;
}

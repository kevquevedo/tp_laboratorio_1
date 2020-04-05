/*
 ============================================================================
 Name        : Ejercicio19.c
 Author      : Kevin Quevedo
 Version     : 1.0
 Folder		 : TrabajosExtras
 Copyright   : Your copyright notice
 Description : Ingresar un número entero por consola y efectuar la suma
 	 	 	   de todos los números que le anteceden, comenzando desde 0
 	 	 	   y mostrar el resultado por pantalla .
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout, NULL);

	int numero;
	int suma=0;
	int i;

	printf("Ingrese un numero: \n");
	fflush(stdin);
	scanf("%d",&numero);

	for (i=0;i<numero;i++){
		suma+=i;
	}

	printf("\nLa suma de los numeros que anteceden al ingresado es: %d",suma);
	return EXIT_SUCCESS;
}

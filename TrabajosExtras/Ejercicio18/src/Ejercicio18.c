/*
 ============================================================================
 Name        : Ejercicio17.c
 Author      : Kevin Quevedo
 Version     : 1.0
 Folder		 : TrabajosExtras
 Copyright   : Your copyright notice
 Description : Diseñar en  un programa que permita ingresar 10 números,
 	 	 	   ninguno de ellos igual a cero. Se pide sumar los positivos,
 	 	 	   obtener el producto de los negativos y luego mostrar ambos resultados.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout, NULL);

	int numero;
	int numeroPositivo=0;
	int numeroNegativo=1;
	int i;

	for (i=0;i<10;i++){

		do{
		printf("Ingrese el %d numero: ",i+1);
		fflush(stdin);
		scanf("%d", &numero);
		} while(numero==0);

		if(numero>0){
			numeroPositivo+=numero;
		} else if(numero<0){
			numeroNegativo*=numero;
		}
	}

	printf("\n\nLa suma de los positivos es: %d",numeroPositivo);
	printf("\n\nEl producto de los negativos es: %d",numeroNegativo);
	return EXIT_SUCCESS;
}

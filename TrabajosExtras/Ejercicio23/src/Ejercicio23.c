/*
 ============================================================================
 Name        : Ejercicio23.c
 Author      : Kevin Quevedo
 Version     : 1.0
 Folder		 : TrabajosExtras
 Copyright   : Your copyright notice
 Description : De 3 números ingresados desde el teclado por el usuario, indicar cuál es el mayor.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout, NULL);
	int numero;
	int numeroMax;
	int i;

	for(i=0;i<3;i++){

		printf("Ingrese el %d numero: \n",i+1);
		fflush(stdin);
		scanf("%d",&numero);

		if(i==0){
			numeroMax=numero;
		} else if (numero>numeroMax){
			numeroMax=numero;
		}
	}

	printf("\nEl numero maximo ingresado es: %d",numeroMax);
	return EXIT_SUCCESS;
}

/*
 ============================================================================
 Name        : Ejercicio9.c
 Author      : Kevin Quevedo
 Version     : 1.0
 Folder		 : TrabajosExtras
 Copyright   : Your copyright notice
 Description : Escribir un programa que realice lea por teclado 20 caracteres. Luego de la lectura indicar cuantas "a" se ingresaron, cuantas "e, i, o, u"
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout, NULL);
	char letra;
	int letraA=0;
	int letraEIOU=0;
	int i;

	for (i=0;i<20;i++){

		printf("Ingre el %d caracter: ",i+1);
		fflush(stdin);
		scanf("%c",&letra);

		if(letra=='a'){
			letraA++;
		} if(letra=='e' || letra=='i' || letra=='o' || letra=='u'){
			letraEIOU++;
		}
	}

	printf("\nLa cantidad de letras A es: %d",letraA);
	printf("\nLa cantidad de letras E,I,O,U es: %d",letraEIOU);
	return EXIT_SUCCESS;
}

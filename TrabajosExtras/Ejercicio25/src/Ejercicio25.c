/*
 ============================================================================
 Name        : Ejercicio25.c
 Author      : Kevin Quevedo
 Version     : 1.0
 Folder		 : TrabajosExtras
 Copyright   : Your copyright notice
 Description : En una tienda de artículos para caballeros al final del día se carga
  en la computadora las boletas que confeccionaron los distintos vendedores para saber
  cuánto fue la comisión del día de cada uno de ellos. Los datos que se ingresan
  (por boleta) son: el número de vendedor y el importe. Cuando no hay más boletas para
  cargar se ingresa 0. Teniendo en cuenta que el negocio tiene 3 vendedores y
  que el porcentaje sobre las ventas es del 5%, indicar cuánto ganó cada vendedor en el día.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {

	setbuf(stdout, NULL);
	int numVendedor;
	float importe;
	float acumulador1=0;
	float acumulador2=0;
	float acumulador3=0;
	float ganancia1;
	float ganancia2;
	float ganancia3;
	float comision=0.05;


	do{
		do{
			printf("Ingrese el numero del vendedor: \n");
			fflush(stdin);
			scanf("%d",&numVendedor);
		}while(numVendedor!=0&&numVendedor!=1&&numVendedor!=2&&numVendedor!=3);

		if(numVendedor==0){
			break;
		} else {
			printf("Ingrese el importe de la boleta: \n");
			fflush(stdin);
			scanf("%f",&importe);

			if(numVendedor==1){
				acumulador1+=importe;
			} else if(numVendedor==2){
				acumulador2+=importe;
			} else if(numVendedor==3){
				acumulador3+=importe;
			}
		}
	} while(numVendedor!=0);

	ganancia1=acumulador1*comision;
	ganancia2=acumulador2*comision;
	ganancia3=acumulador3*comision;

	printf("\nLa ganancia del Vendedor1 es: %.2f",ganancia1);
	printf("\nLa ganancia del Vendedor2 es: %.2f",ganancia2);
	printf("\nLa ganancia del Vendedor3 es: %.2f",ganancia3);
	return EXIT_SUCCESS;
}

/******************************************************************
* Programa: Trabajo Practico N°1.
*
* Objetivo:
* Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
*   -1.Ingresar 1er operando (A=x).
*   -2.Ingresar 2do operando (B=y).
*   -3. Calcular todas las operaciones:
*   	a) Calcular la suma (A+B).
*   	b) Calcular la resta (A-B).
*   	c) Calcular la division (A/B).
*   	d) Calcular la multiplicacion (A*B).
*   	e) Calcular el factorial (A!).
*   -4. Informar resultados:
*    	a) “El resultado de A+B es: r”.
*    	b) “El resultado de A-B es: r”.
*    	c) “El resultado de A/B es: r” o “No es posible dividir por cero”.
*    	d) “El resultado de A*B es: r”.
*    	e) “El factorial de A es: r1 y El factorial de B es: r2”.
*   -5. Salir
*   -Documentar las funciones al estilo Doxygen
*
* Aspectos a destacar:
*   -Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
*    que contenga las funciones para realizar las cinco operaciones.
*   -En el menú deberán aparecer los valores actuales cargados en los operandos A y B
*    (donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado).
*   -Deberán contemplarse los casos de error (división por cero, etc).
*    significado de sus parámetros.
*   -Documentar todas las funciones.
*
* Version: 1.0 del 10 de Abril del 2020.
* Autor: Kevin Axel Quevedo.
*
* *******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main(void) {

	setbuf(stdout, NULL);

	float A; //Variable para guardar el primer numero.
	float B; //Variable para guardar el segundo numero.
	char operador; //Variable para guardar el operador seleccionado.
	float valor; //Puntero para escribir los resultados entre funciones.
	float valor2; //Puntero para escribir los resultados entre funciones. Solo utilizado en factorial.
	float resultado; //Variable auxiliar para invocar a las funciones.

	A = utn_getFloat("Ingrese el 1 operando: "); //Funcion para tomar el primer numero.
	B = utn_getFloat("Ingrese el 2 operando: "); //Funcion para tomar el segundo numero.
	operador = utn_getChar("\nPara sumar: +\nPara restar: -\nPara multiplicar: *\nPara dividir: /\nPara el factorial del primer y segundo operando: !\n\nSeleccione su operador, segun lo indicado: "); //Funcion para mostrar las opciones y seleccionar el operador.

	switch(operador) //Sentencia de control de flujo que selecciona la funcion a realizar(Menu), de acuerdo al operador seleccionado.
	{
		case '+':
			resultado=sumar(A,B,&valor); //Invoca a la función "sumar", en caso que el operador sea "+".
			if (resultado==0) //Si el retorno de la función "sumar" no posee errores, devuelve "0" e imprime mensaje con el resultado de la suma.
			{
				printf("\nEl resultado de %.2f + %.2f es: %.2f\n",A,B,valor);
			}
			break;
		case '-':
			resultado=restar(A,B,&valor); //Invoca a la función "restar", en caso que el operador sea "-".
			if (resultado==0) //Si el retorno de la función "restar" no posee errores, devuelve "0" e imprime mensaje con el resultado de la resta.
			{
				printf("\nEl resultado de %.2f - %.2f es: %.2f\n",A,B,valor);
			}
			break;
		case '*':
			resultado=multiplicar(A,B,&valor); //Invoca a la funcion "multiplicar", en caso que el operador sea "*".
			if (resultado==0) //Si el retorno de la funcion "multiplicar" no posee errores, devuelve "0" e imprime mensaje con el resultado de la multiplicación.
			{
				printf("\nEl resultado de %.2f * %.2f es: %.2f\n",A,B,valor);
			}
			break;
		case '/':
			resultado=dividir(A,B,&valor); //Invoca a la funcion "dividir", en caso que el operador sea "/".
			if (resultado==0) //Si el retorno de la funcion "dividir" no posee errores, devuelve "0" e imprime mensaje con el resultado de la división.
			{
				printf("\nEl resultado de %.2f / %.2f es: %.2f\n",A,B,valor);
			}
			else if (resultado!=0) //Si el retorno de la funcion "dividir" tiene un error, devuelve "-1"(Distinto a cero), e imprime el mensaje indicando que no se puede imprimir un numero por cero.
			{
				printf("\nNo se puede dividir un numero por 0 (cero).");
			}
			break;
		case '!':
			resultado=factorializar(A,B,&valor,&valor2); //Invoca a la funcion "factorializar", en caso que el operador sea "!".
			if (resultado==0) //Si el retorno de la funcion "factorializar" no posee errores, devuelve "0", e imprime el mensaje indicando el factorial del primer y segundo numero por separado.
			{
				printf("\nEl factorial de %.2f es: %.2f y El factorial de %.2f es: %.2f",A,valor,B,valor2);
			}
			break;
	}
	return EXIT_SUCCESS; //Fin del programa.
}


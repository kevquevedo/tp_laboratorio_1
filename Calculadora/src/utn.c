/*
 * utn.c
 *
 *  Created on: 10 abr. 2020
 * 	Author: Kevin Quevedo
 */

#include <stdio.h>
#include <stdlib.h>

/** \brief Solicita al usuario  e inicializa una variable de tipo "float".
* \param Mensaje impreso al usuario.
* \return Numero ingresado por el usuario.
*
*/
float utn_getFloat(char* mensaje)
{
	float bufferFloat;
	printf("%s",mensaje);
	fflush(stdin);
	scanf("%f",&bufferFloat);

	return bufferFloat;
}

/** \brief Solicita al usuario e inicializa una variable de tipo "char".
* \param Mensaje impreso al usuario.
* \return Caracter ingresado por el usuario.
*
*/
char utn_getChar(char* mensaje)
{
	char bufferChar;
	printf("%s",mensaje);
	fflush(stdin);
	scanf("%c",&bufferChar);

	return bufferChar;
}

/** \brief Efectua la suma entre dos parametros o argumentos.
* \param float x Primer parametro o argumento.
* \param float y Segundo parametro o argumento.
* \param float* pValor Puntero donde se escribe el resultado de la operacion.
* \return Si la operacion posee errores mediante -1/0.
*
*/
float sumar(float x, float y, float* pValor)
{
	int retorno=-1;
	float operacion;

	if(pValor!=NULL){
		operacion=x+y;
		*pValor=operacion;
		retorno=0;
	}
	return retorno;
}

/** \brief Efectua la resta entre dos parametros o argumentos.
* \param float x Primer parametro o argumento.
* \param float y Segundo parametro o argumento.
* \param float* pValor Puntero donde se escribe el resultado de la operacion.
* \return Si la operacion posee errores mediante -1/0.
*
*/
float restar(float x, float y, float* pValor)
{
	int retorno=-1;
	float operacion;

	if(pValor!=NULL){
		operacion=x-y;
		*pValor=operacion;
		retorno=0;
	}
	return retorno;
}

/** \brief Efectua la multiplicacion entre dos parametros o argumentos.
* \param float x Primer parametro o argumento.
* \param float y Segundo parametro o argumento.
* \param float* pValor Puntero donde se escribe el resultado de la operacion.
* \return Si la operacion posee errores mediante -1/0.
*
*/
float multiplicar(float x, float y, float* pValor)
{
	int retorno=-1;
	float operacion;

	if(pValor!=NULL){
		operacion=x*y;
		*pValor=operacion;
		retorno=0;
	}
	return retorno;
}

/** \brief Efectua la division entre dos parametros o argumentos.
* \param float x Primer parametro o argumento.
* \param float y Segundo parametro o argumento.
* \param float* pValor Puntero donde se escribe el resultado de la operacion.
* \return Si la operacion posee errores mediante -1/0.
*
*/
float dividir(float x, float y, float* pValor)
{
	int retorno=-1;
	float operacion;

	if (pValor!=NULL && y!=0) {
		operacion=x/y;
		*pValor=operacion;
		retorno=0;
	}
	return retorno;
}

/** \brief Efectua el factorial del primer y el segundo parametro y argumento.
* \param float x Primer parametro o argumento.
* \param float y Segundo parametro o argumento.
* \param float* pValor Puntero donde se escribe el resultado del primero argumento.
* \param float* pValor2 Puntero donde se escribe el resultado del segundo argumento.
* \return Si la operacion posee errores mediante -1/0.
*
*/
float factorializar(float x, float y, float* pValor, float* pValor2)
{
	int retorno=-1;
	float operacionX;
	float operacionY;
	int i;

	if (pValor!=NULL && pValor2!=NULL) {

		if(x!=0){
			operacionX=1;
			for (i=1;i<=x;i++){
				operacionX*=i;
				*pValor=operacionX;
			}
		} else if (x==0){
			*pValor=1;
		}

		if(y!=0){
			operacionY=1;
			for (i=1;i<=y;i++){
				operacionY*=i;
				*pValor2=operacionY;
			}
		} else if (y==0){
			*pValor2=1;
		}
		retorno=0;
	}
	return retorno;
}

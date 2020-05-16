/*
 * Informe.c
 *
 *  Created on: 16 may. 2020
 *      Author: VOPKEQUE
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"
#include "Informe.h"

/** \brief Sort the elements in the array of employees, the argument order
 * 		   indicate UP or DOWN order
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [2] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int info_sortEmployees(Employee* list, int len, int order)
{
	int retorno = -1;
	int swap;
	int i;
	Employee auxiliar;
	int auxiliarCmp;
	if(list != NULL && len > 0)//Valida que los datos obtenidos de la funcion sean correctos.
	{
		do
		{
			swap = 0;//Le asigno cero, para creer que NO va a iterar.
			for(i=0;i<len-1;i++)//Recorro el array de empleados.
			{
				if(list[i].isEmpty || list[i+1].isEmpty)//Verifica que los indices no se encuentren vacios.
				{
					continue;//Si los indices estan vacios, genera otra iteracion.
				}
				auxiliarCmp = strncmp(list[i].lastName,list[i+1].lastName,LASTNAME_LEN);//Asigna el valor de la comparacion de los apellido a auxiliarCmp.
				if(	order == 1 && //Si el orden es Ascendente.
					(auxiliarCmp > 0 ||
					(auxiliarCmp == 0 && list[i].sector > list[i+1].sector)) )//Valida si el valor del primer indice es mayor al segundo y si son iguales los ordena por sector en forma ascendente.
				{
					swap = 1;//Cambia el estado, ya que tengo que volver a iterar.
					auxiliar = list[i];
					list[i] = list[i+1];   //Si cumple las validadciones del IF, le asigna los datos de I a I+1 y viceversa.
					list[i+1]=auxiliar;
				}
				else if( order == 2 && //Si el orden es Descendente.
						 (auxiliarCmp < 0 ||
						 (auxiliarCmp == 0 && list[i].sector > list[i+1].sector)) )//Valida si el valor del primer indice es menor al segundo y si son iguales los ordena por sector en forma ascendente.
				{
					swap = 1;//Cambia el estado, ya que tengo que volver a iterar.
					auxiliar = list[i];
					list[i] = list[i+1];    //Si cumple las validadciones del IF, le asigna los datos de I a I+1 y viceversa.
					list[i+1]=auxiliar;
				}
			}
			len--;//Decrementa el largo del array, para generar menos iteraciones.
		}while(swap);//Mientas swap sea verdadero voy a seguir iterando.
		if( !emp_printEmployees(list,len))//Imprime la lista de empledos.
		{
			printf("Lista de empleados ordenada correctamente.\n");//Mensaje a mostrar si cumple con las validaciones del IF.
		}
	}
	return retorno;
}

/** \brief //Obtiene el total de los salarios, junto con el promedio y la cantidad de empledos que superan el salario promedio.
 * \param list Puntero al array de empleados.
 * \param len Longitud del array de empleados.
 * \return int Return 0 si pudo obtener correctamente la informacion y -1 si tuvo algun error.
 *
 */
int info_totalAndAverageSalaryEmployees(Employee* list, int len)
{
	int retorno = -1;
	int i;
	float acumuladorSalary = 0;
	int contEmployee = 0;
	int contSupAverage = 0;
	float averageSalary;

	if(list != NULL && len > 0)//Valida que los datos obtenidos de la funcion sean correctos.
	{
		for(i=0;i<len;i++)//Recorro el array de empleados.
		{
			if(list[i].isEmpty == 0)//Valido que el indice posea un empleado cargado.
			{
				acumuladorSalary += list[i].salary;//Sumo a un acumulador, el valor del salario del empleado encontrado.
				contEmployee++;//Contador de empleados encontrados.
			}
		}

		if(contEmployee > 0)//Valida que la cantidad de empleados encontrados sea mayor a 0.
		{
			averageSalary = acumuladorSalary / (float)contEmployee;//Si cumple con las validaciones del IF, calcula el promedio.
		}

		for(i=0;i<len;i++)//Recorro el array de empleados.
		{
			if( list[i].isEmpty == 0 &&
				list[i].salary > averageSalary)//Valido que el indice posea un empleado cargado y que el salario del empleado encontrado sea mayor al promedio obtenido.
			{
				contSupAverage++;//Contado de empleados que superan el salario promedio.
			}
		}
		retorno = 0;
	}

	printf("El total de los salarios es: %.2f - Y el promedio de los mismos es: %.2f\n",acumuladorSalary,averageSalary);
	printf("La cantidad de empleados que superan el salario promedio es: %d\n",contSupAverage);
	return retorno;
}

/*
 * ArrayEmployees.c
 *
 *  Created on: 14 may. 2020
 *      Author: VOPKEQUE
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"

/** \brief To indicate that all position in the array are empty,
 *         this function put the flag (isEmpty) in TRUE in all
 *         position of the array.
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int emp_initEmployees(Employee* list, int len)
{
	int retorno = -1;
	int i;

	if(list != NULL && len >0)//Valida que los datos obtenidos de la funcion sean correctos.
	{
		for(i=0;i<len;i++)//Recorre el array para inicializar el campo isEmpty de todos los indices.
		{
			list[i].isEmpty = 1;//Cambia el estado a "vacio" a todos los indices del array.
		}
		retorno = 0;
	}
	return retorno;
}

/** \brief Add in a existing list of employees the values received as parameters
 *         in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 *
 */
int emp_addEmployee(Employee* list, int len, int id, char* nombre,char* apellido,float salario,int sector)
{
	int retorno = -1;
	int indice;

	indice = emp_getEmptyIndex(list,len);//Busca un indice vacio.
	if(	list != NULL && len >0 && id > -1 && nombre != NULL && apellido != NULL && salario > 0 && sector > 0 &&
		indice > -1)//Valida si los elementos de la funcion son validos y ademas si encontró un indice vacio.
	{
		retorno = 0;
		strncpy(list[indice].name,nombre,NAME_LEN);//Copia la informacion pasada en la funcion, al primer indice vacio obtenido.
		strncpy(list[indice].lastName,apellido,LASTNAME_LEN);//Copia la informacion pasada en la funcion, al primer indice vacio obtenido.
		list[indice].salary = salario;//Copia la informacion pasada en la funcion, al primer indice vacio obtenido.
		list[indice].sector = sector;//Copia la informacion pasada en la funcion, al primer indice vacio obtenido.
		list[indice].isEmpty = 0;//Le cambia el estado a "cargado" al indice.
		list[indice].id = id;//Copia la informacion pasada en la funcion, al primer indice vacio obtenido.
	}
	return retorno;
}

/**
 * \brief Busca la primer posición vacia en el array de empleados.
 * \param list Puntero al array de empleados.
 * \param len Es la longitud del array.
 * \return Retorna el indice de la posicion vacia si encontró uno y -1 si obtuvo algún error o no existen indices vacios.
 *
 */
int emp_getEmptyIndex(Employee* list, int len)
{
	int retorno = -1;
	int i;
	if(list != NULL && len > 0)//Valida que los datos de la funcion sean correctos.
	{
		for(i=0;i<len;i++)//Recorre el array para buscar el indice vacio.
		{
			if(list[i].isEmpty == 1)//Valida que el indice se encuentre "vacio".
			{
				retorno = i;//Retorna el valor del indice.
				break;
			}
		}
	}
	return retorno;
}

/** \brief Find an Employee by Id and returns the index position in array.
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
 *		   pointer received or employee not found]
 *
 */
int emp_findEmployeeById(Employee* list, int len,int id)
{
	int retorno = -1;
	int i;

	if(list != NULL && len > 0 && id > -1)//Valida que los datos de la funcion sean correctos.
	{
		for(i=0;i<len;i++)//Recorre el array para buscar el id indicado.
		{
			if( list[i].id == id &&
				list[i].isEmpty == 0)//Busca el id, indicado como dato en la funcion y verifica que este "cargado".
			{
				retorno = i;//Retorna el valor del indice.
				break;
			}
		}
	}
	return retorno;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int emp_removeEmployee(Employee* list, int len, int id)
{
	int retorno = -1;
	int i;

	if(list != NULL && len > 0 && id > -1)//Valida que los datos de la funcion sean correctos.
	{
		for(i=0;i<len;i++)//Recorre el array para buscar el id indicado.
		{
			if( list[i].id == id &&
				list[i].isEmpty == 0)//Busca el id, indicado como dato en la funcion y verifica que este "cargado".
			{
				retorno = 0;//Retorna 0, si el indice fue encontrado y a la vez si estaba "cargado".
				list[i].isEmpty = 1;//Cambia el indice del array a "vacio".
				break;
			}
		}
	}
	return retorno;
}

/** \brief print the content of employees array.
 * \param list Employee*
 * \param len int
 * \return int
 *
 */
int emp_printEmployees(Employee* list, int len)
{
	int retorno = -1;
	int i;

	if(list != NULL && len > 0)//Valida que los datos de la funcion sean correctos.
	{
		for(i=0;i<len;i++)//Recorre el array para buscar empleados cargados.
		{
			if(list[i].isEmpty == 0)//Verifica que el indice se encuentre cargado.
			{
				printf("%s, %s - Salario: %.2f - Sector: %d - ID: %d\n",list[i].lastName,list[i].name,list[i].salary,list[i].sector,list[i].id);
			}
		}
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief Cuenta la cantidad de empleados existentes.
 * \param list Puntero al array de empleados.
 * \param len Es la longitud del array.
 * \return Retorna contador Retorna la cantidad de empleados encontrada y -1 si tuvo algún error.
 *
 */
int emp_contEmployee(Employee* list, int len)
{
	int i;
	int contador = 0;

	if(list != NULL && len > 0)//Valida que los datos de la funcion sean correctos.
	{
		for(i=0;i<len;i++)//Recorre el array para buscar cuantos empledos existen.
		{
			if(list[i].isEmpty == 0)//Verifica que el indice se encuentre cargado.
			{
				contador++;//Su cumple con la condicion del IF, incrementa a contador.
			}
		}
	}
	return contador;
}

/**
 * \brief Modifica los datos ingresados de un empleado por ID.
 * \param list Puntero al array de empleados.
 * \param len Es la longitud del array.
 * \param id Identificacion del cliente a modificar.
 * \param option para verificar que campo desea modificar. 1 = Nombre; 2 = Apellido; 3 = Salario; 4 = Sector.
 * \return Retorna 0 si modifico los datos del cliente correctamente y -1 si tuvo algún error.
 *
 */
int emp_modifEmployee(Employee* list, int len, int id, int option)
{
	int retorno = -1;
	int i;
	Employee auxiliar;

	if(list != NULL && len > 0 && id > -1 && option > 0 && option < 5)//Valida que los datos de la funcion sean correctos.
	{
		for(i=0;i<len;i++)//Recorre el array para buscar el ID del empleado a modificar.
		{
			if( list[i].id == id &&
				list[i].isEmpty == 0)//Busca el id, indicado como dato en la funcion y verifica que este "cargado".
			{
				if( option == 1 && //Modifica el nombre.
					!utn_getNameOrSurname(auxiliar.name,NAME_LEN,"Ingrese un nombre: \n","Nombre invalido.\n",2))
				{
					retorno = 0;
					strncpy(list[i].name,auxiliar.name,NAME_LEN);//Copia la informacion pasada en la funcion, al indice obtenido.
					break;
				}
				else if( option == 2 && //Modifica el apellido.
						 !utn_getNameOrSurname(auxiliar.lastName,LASTNAME_LEN,"Ingrese un apellido: \n","Apellido invalido.\n",2))
				{
					retorno = 0;
					strncpy(list[i].lastName,auxiliar.lastName,NAME_LEN);//Copia la informacion pasada en la funcion, al indice obtenido.
					break;
				}
				else if( option == 3 && //Modifica el salario.
						!utn_getNumberFloat(&auxiliar.salary,"Ingrese un salario (Max. 100.000): \n","Salario invalido.\n",0,100000,2))
				{
					retorno = 0;
					list[i].salary = auxiliar.salary;//Copia la informacion pasada en la funcion, al indice obtenido.
					break;
				}
				else if(option == 4 && //Modifica el sector.
						!utn_getNumberInt(&auxiliar.sector,"Ingrese un sector (1 a 10): \n","Sector invalido.\n",1,10,2))
				{
					retorno = 0;
					list[i].sector = auxiliar.sector;//Copia la informacion pasada en la funcion, al indice obtenido.
					break;
				}
			}
		}
	}
	return retorno;
}



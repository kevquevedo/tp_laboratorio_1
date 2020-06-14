#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 * \param path Puntero al archivo recibido.
 * \param pArrayListEmployee Puntero a la lista dinamica.
 * \return Retorna 0 si copió aunque sea 1 archivo correctamente; -1 en caso de error.
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* pEmployee = NULL;
	char auxId[INT_LEN];
	char auxNombre[NOMBRE_LEN];
	char auxHoras[INT_LEN];
	char auxSueldo[INT_LEN];

	if( pFile != NULL && pArrayListEmployee != NULL )//Valida que los punteros recibidos en la funcion sean coherentes.
	{
		do
		{
			if( fscanf( pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxHoras,auxSueldo ) == 4 )//Valida que se hayan copiado correctamente los 4 elementos.
			{
				pEmployee = employee_newParametrosTxt(auxId,auxNombre,auxHoras,auxSueldo);//Si pasa las validaciones del IF, crea y asigna los valores obtenidos a un empleado.
				if( pEmployee != NULL && //Verifica que el empleado se haya cargado correctamente y haya encontrado espacio en memoria.
					!ll_add(pArrayListEmployee,pEmployee) )//Agrega el empleado a la lista dinamica.
				{
					retorno = 0;
				}
			}
		}while(!feof(pFile));//Mientras el archivo sea leyendo filas (empleados) es decir 1 seguira iterando, cuando sea 0 saldra del bucle.
	}
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee auxiliarEmpl;
	Employee* pEmployee;
	char auxId[INT_LEN];
	char auxNombre[NOMBRE_LEN];
	char auxHoras[INT_LEN];
	char auxSueldo[INT_LEN];

	if( pFile != NULL && pArrayListEmployee != NULL )//Valida que los punteros recibidos en la funcion sean coherentes.
	{
		do
		{
			if( fread(&auxiliarEmpl,sizeof(Employee),1,pFile) == 1 )//Lee los registros del archivo binario. Si esta ok lee 1.
			{
				sprintf(auxId,"%d",auxiliarEmpl.id);//Se copia el ID obtenido del auxiliarEmpl a auxId.
				strncpy(auxNombre,auxiliarEmpl.nombre,NOMBRE_LEN);//Se copia el NOMBRE obtenido del auxiliarEmpl a auxNombre.
				sprintf(auxHoras,"%d", auxiliarEmpl.horasTrabajadas);//Se copia las HORAS obtenidas del auxiliarEmpl a auxHoras.
				sprintf(auxSueldo,"%d", auxiliarEmpl.sueldo);//Se copia el SUELDO obtenido del auxiliarEmpl a auxSueldo.
				pEmployee = (Employee*) employee_newParametrosTxt(auxId,auxNombre,auxHoras,auxSueldo);//Si pasa las validaciones del IF, crea y asigna los valores obtenidos a un empleado.
				if( pEmployee != NULL &&//Verifica que el empleado se haya cargado correctamente y haya encontrado espacio en memoria.
					!ll_add(pArrayListEmployee,pEmployee) )//Agrega el empleado a la lista dinamica.
				{
					retorno = 0;
				}
			}
		}while(!feof(pFile));
	}
    return retorno;
}

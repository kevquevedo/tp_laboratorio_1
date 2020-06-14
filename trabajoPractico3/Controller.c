#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"
#include "Controller.h"

#define RESP_LEN 2

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 * \param path Puntero al archivo recibido.
 * \param pArrayListEmployee Puntero a la lista dinamica.
 * \return Retorna 0 en caso de cargar el archivo correctamente; -1 en caso de error.
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* auxFile;
	if( path != NULL && pArrayListEmployee != NULL )//Valida que los punteros recibidos en la funcion sean coherentes.
	{
		auxFile = fopen(path,"r");//Abre el archivo en modo lectura.
		if( auxFile != NULL &&//Valida que el archivo que se busc� abrir no sea NULL.
			!parser_EmployeeFromText(auxFile,pArrayListEmployee) )//Llama a la funcion que parsea los datos del archivo.
		{
			retorno = 0;
		}
		fclose(auxFile);//Se cierra el archivo.
	}
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* auxFile;
	if( path != NULL && pArrayListEmployee != NULL)//Valida que los punteros recibidos en la funcion sean coherentes.
	{
		auxFile = fopen(path,"rb");//Abre el archivo en modo lectura binario.
		if( auxFile != NULL &&//Valida que el archivo que se busc� abrir no sea NULL.
			!parser_EmployeeFromBinary(auxFile,pArrayListEmployee) )//Llama a la funcion que parsea los datos del archivo binario.
		{
			retorno = 0;
		}
		fclose(auxFile);//Cierra el archivo.
	}
    return retorno;
}

/** \brief Alta de empleados.
 * \param pArrayListEmployee Puntero a la lista dinamica.
 * \return Retorna 0 si a�adi� un empleado correctamente; -1 en caso de error.
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	char auxNombre[NOMBRE_LEN];
	int auxHoras;
	int auxSueldo;
	int auxId;
	Employee* pEmpl = NULL;

	if( pArrayListEmployee != NULL &&//Valida que el puntero recibido en la funcion sea coherente.
		!controller_findIdMax(pArrayListEmployee,&auxId) &&//Busca el ID maximo  actualmente en la lista.
		!utn_getNameOrSurname(auxNombre,NOMBRE_LEN,"Ingrese un nombre: \n","Nombre invalido.\n",2) &&//Pide al usuario un nombre para el nuevo empleado.
		!utn_getNumberInt(&auxHoras,"Ingrese horas trabajadas: \n","Horas invalidas.\n",0,400,2) &&//Pide al usuario las horas trabajadas para el nuevo empleado.
		!utn_getNumberInt(&auxSueldo,"Ingrese un sueldo: \n","Sueldo invalido.\n",0,60000,2) )//Pide al usuario un sueldo para el nuevo empleado.
	{
		pEmpl = employee_newParametros(auxId+1,auxNombre,auxHoras,auxSueldo);//Si pasa las validaciones del IF, carga los datos obtenidos desde el usuario y al ID maximo le suma 1 y se lo asigna al empleado.
		if( pEmpl != NULL && //Valida que el empleado nuevo NO sea NULL.
			!ll_add(pArrayListEmployee,pEmpl) )//Agrega el empleado a la lista dinamica.
		{
			retorno = 0;
		}
	}
    return retorno;
}

/** \brief Modificacion de empleados.
 * \param pArrayListEmployee Puntero a la lista dinamica.
 * \return Retorna 0 si modific� un empleado correctamente; -1 en caso de error.
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int auxId;
	int idMaximo;
	int indiceEmpl;
	Employee* auxEmpl;
	char newNombre[NOMBRE_LEN];
	int newHoras;
	int newSueldo;
	char respuesta[RESP_LEN];

	if( pArrayListEmployee != NULL &&//Valida que el puntero recibido en la funcion sea coherente.
		!controller_findIdMax(pArrayListEmployee,&idMaximo) &&//Busca el ID maximo  actualmente en la lista.
		!utn_getNumberInt(&auxId,"Por favor ingrese el ID del usuario a modificar: \n","ID invalido.\n",0,idMaximo,2) &&//Se pide al usuario que ingrese el ID del empleado a modificar.
		!controller_findEmployeeById(pArrayListEmployee,auxId,&indiceEmpl) &&//Valida que el ID ingresado por el usuario exista en la lista dinamica.
		indiceEmpl > -1)
	{
		auxEmpl = (Employee*) ll_get(pArrayListEmployee,indiceEmpl);//Si pasa las validaciones del IF, obtiene el puntero al empleado segun el ID.
		if( auxEmpl != NULL &&//Valida que el empleado sea distinto de NULL.
			!employee_printEmployeeData(auxEmpl) &&//Si pasa las validaciones del IF, obtiene el puntero al empleado segun el ID.
			!utn_getDescription(respuesta,RESP_LEN,"Desea modificar el usuario mostrado? [Ingrese: S/N]","Opcion invalida",2) &&//Se pide al usuario confirmacion para modificar el empleado impreso.
			!strncmp(respuesta,"S",RESP_LEN) )//Si la respuesta es afirmativa, entra el IF.
		{
			if( !utn_getNameOrSurname(newNombre,NOMBRE_LEN,"Ingrese un nombre: \n","Nombre invalido.\n",2) &&//Se solicita al usuario que ingrese un nuevo nombre para el empleado.
				!utn_getNumberInt(&newHoras,"Ingrese horas trabajadas: \n","Horas invalidas.\n",0,400,2) &&//Se solicita al usuario que ingrese una nueva cantidad de horas trabajadas para el empleado.
				!utn_getNumberInt(&newSueldo,"Ingrese un sueldo: \n","Sueldo invalido.\n",0,60000,2) &&//Se solicita al usuario que ingrese un nuevo sueldo para el empleado.
				!employee_setNombre(auxEmpl,newNombre) &&//Setea el nuevo nombre al empleado.
				!employee_setHorasTrabajadas(auxEmpl,newHoras) &&//Setea las nuevas horas trabajadas al empleado.
				!employee_setSueldo(auxEmpl,newSueldo) )//Setea el nuevo sueldo al empleado.
			{
				ll_set(pArrayListEmployee,indiceEmpl,auxEmpl);//Setea los nuevos valores del empleado en la lista dinamica.
				retorno = 0;
			}
		}
	}
    return retorno;
}

/** \brief Baja de empleados.
 * \param pArrayListEmployee Puntero a la lista dinamica.
 * \return Retorna 0 si elimin� un empleado correctamente; -1 en caso de error.
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int auxId;
	int idMaximo;
	int indiceEmpl;
	Employee* auxEmpl;
	char respuesta[RESP_LEN];

	if( pArrayListEmployee != NULL &&//Valida que el puntero recibido en la funcion sea coherente.
		!controller_findIdMax(pArrayListEmployee,&idMaximo) &&//Busca el ID maximo  actualmente en la lista.
		!utn_getNumberInt(&auxId,"Por favor ingrese el ID del usuario a dar de baja: \n","ID invalido.\n",0,idMaximo,2) &&//Se pide al usuario que ingrese el ID del empleado a modificar.
		!controller_findEmployeeById(pArrayListEmployee,auxId,&indiceEmpl) &&//Valida que el ID ingresado por el usuario exista en la lista dinamica.
		indiceEmpl > -1)
	{
		auxEmpl = (Employee*) ll_get(pArrayListEmployee,indiceEmpl);//Si pasa las validaciones del IF, obtiene el puntero al empleado segun el ID.
		if( auxEmpl != NULL &&//Valida que el empleado sea distinto de NULL.
			!employee_printEmployeeData(auxEmpl) &&//Si pasa las validaciones del IF, obtiene el puntero al empleado segun el ID.
			!utn_getDescription(respuesta,RESP_LEN,"Desea eliminar el usuario mostrado? [Ingrese: S/N]","Opcion invalida",2) &&//Se pide al usuario confirmacion para modificar el empleado impreso.
			!strncmp(respuesta,"S",RESP_LEN) )//Si la respuesta es afirmativa, entra el IF.
		{
			ll_remove(pArrayListEmployee,indiceEmpl);//Elimina al empleado de la lista dinamica.
			employee_delete(auxEmpl);//Borra el espacio de memoria que ocupa el empleado obtenido.
			retorno = 0;
		}
	}
    return retorno;
}

/** \brief Lista todos los empleados.
 * \param pArrayListEmployee Puntero a la lista dinamica.
 * \return Retorna 0 si imprimi� los empleados correctamente; -1 en caso de error.
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* auxEmpl;
    int i;

	if( pArrayListEmployee != NULL )//Valida que el puntero recibido en la funcion sea coherente.
	{
		for(i=0;i<ll_len(pArrayListEmployee);i++)//Recorre la lista dinamica de empleados.
		{
			auxEmpl = (Employee*) ll_get(pArrayListEmployee,i);//Obtiene el puntero al empleado segun el ID.
			if( auxEmpl != NULL )//Valida que el empleado sea distinto de NULL.
			{
				employee_printEmployeeData(auxEmpl);//Si pasa la validacion del IF, imprime los datos del empleado.
			}
		}
		retorno = 0;
	}
	return retorno;
}

/** \brief Ordena todos los empleados.
 * \param pArrayListEmployee Puntero a la lista dinamica.
 * \return Retorna 0 si orden� los empleados correctamente; -1 en caso de error.
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int orden;

	if( pArrayListEmployee != NULL &&//Valida que el puntero recibido en la funcion sea coherente.
		!utn_getNumberInt(&orden,"Por favor ingrese el orden: [0=DESC/1=ASC]\n","Opcion invalida.\n",0,1,2) &&//Solicita al usuario la forma de ordenamiento que desea Ascendente o Descendentes.
		!ll_sort(pArrayListEmployee,employee_sortBySueldo,orden) )//Ordena la informacion del usuario segun el criterio de sueldo, pasado en la funcion employee_sortBySueldo.
	{
		retorno = 0;
	}
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 * \param path Puntero al archivo recibido.
 * \param pArrayListEmployee Puntero a la lista dinamica.
 * \return Retorna 0 en caso de guardar el archivo correctamente; -1 en caso de error.
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* auxFile = NULL;
	Employee* auxEmpl = NULL;
	int auxId;
	char auxNombre[NOMBRE_LEN];
	int auxHoras;
	int auxSueldo;
	int i;

	if( path != NULL && pArrayListEmployee != NULL )//Valida que los punteros recibidos en la funcion sean coherentes.
	{
		auxFile = fopen(path,"w");//Abre el archivo en modo escritura.
		if( auxFile != NULL )//Valida que el archivo sea distinto de NULL.
		{
			for(i=0;i<ll_len(pArrayListEmployee);i++)//Recorre el la lista dinamica de empleados.
			{
				auxEmpl = ll_get(pArrayListEmployee,i);//Obtiene la informacion del empleado en la posicion i.
				if( auxEmpl != NULL &&//Valida que el empleado obtenido sea distinto de NULL.
					!employee_getId(auxEmpl,&auxId) &&//Obtiene el id del empleado.
					!employee_getNombre(auxEmpl,auxNombre) &&//Obtiene el nombre del empleado.
					!employee_getHorasTrabajadas(auxEmpl,&auxHoras) &&//Obtiene las horas trabajadas del empleado.
					!employee_getSueldo(auxEmpl,&auxSueldo) )//Obtiene el sueldo del empleado.
				{
					fprintf(auxFile,"%d,%s,%d,%d\n",auxId,auxNombre,auxHoras,auxSueldo);//Si pasa las validaciones del IF, vuelca en el archivo la informacion del empleado.
				}
			}
			retorno = 0;
			fclose(auxFile);//Cierra el archivo.
		}
	}
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* auxFile = NULL;
	Employee* auxEmpl = NULL;
	int i;

	if( path != NULL && pArrayListEmployee != NULL )//Valida que los punteros recibidos en la funcion sean coherentes.
	{
		auxFile = fopen(path,"wb");//Abre el archivo en modo escritura binario.
		if( auxFile != NULL )//Valida que el archivo sea distinto de NULL.
		{
			for(i=0;i<ll_len(pArrayListEmployee);i++)//Recorre el la lista dinamica de empleados.
			{
				auxEmpl = ll_get(pArrayListEmployee,i);//Obtiene la informacion del empleado en la posicion i.
				if( auxEmpl != NULL )//Valida que el empleado obtenido sea distinto de NULL.
				{
					fwrite(auxEmpl,sizeof(Employee),1,auxFile);//Si pasa la validacion del IF, escribe el archivo binario con el tama�o de cada Employee.
				}
			}
			retorno = 0;
			fclose(auxFile);//Cierra el archivo.
		}
	}
    return retorno;
}

/** \brief Busca el ID maximo de los empleados de la lista dinamica
 * \param pArrayListEmployee Puntero a la lista dinamica.
 * \param id Puntero del tipo entero donde se alojar� el ID maximo.
 * \return Retorna 0 en caso de encontrar el ID maximo correctamente; -1 en caso de error.
 *
 */
int controller_findIdMax(LinkedList* pArrayListEmployee, int* id)
{
	int retorno = -1;
	Employee* auxEmpl;
    int i;
    int auxId;
    int auxMaxId;
    int flag = 0;

	if( pArrayListEmployee != NULL )//Valida que el puntero recibido en la funcion sea coherente.
	{
		auxMaxId = 0;
		for(i=0;i<ll_len(pArrayListEmployee);i++)//Recorre el la lista dinamica de empleados.
		{
			auxEmpl = (Employee*) ll_get(pArrayListEmployee,i);//Obtiene la informacion del empleado en la posicion i.
			if( auxEmpl != NULL &&//Valida que el empleado obtenido sea distinto de NULL.
				!employee_getId(auxEmpl,&auxId) )//Obtiene el id del empleado.
			{
				if( flag == 0 || auxId > auxMaxId )//Si es el primer empleado leido o el auxId es mayor a auxMaxId entra al IF.
				{
					flag = 1;//Cambia el estado de la bandera.
					auxMaxId = auxId;//Asigna el valor del id como Id Maximo.
				}
			}
		}
		retorno = 0;
		*id = auxMaxId;//Le asigna al puntero id, el id maximo encontrado.
	}
	return retorno;
}

/** \brief Busca un empleado por el ID.
 * \param pArrayListEmployee Puntero a la lista dinamica.
 * \param id ID a buscar en la lista dinamica.
 * \param gotIndex Puntero del tipo entero donde se alojar� el indice el empleado que coincida con el ID.
 * \return Retorna 0 en caso de encontrar el empleado con el ID brindado; -1 en caso de error.
 *
 */
int controller_findEmployeeById(LinkedList* pArrayListEmployee, int id, int* gotIndex)
{
	int retorno = -1;
	int i;
	Employee* auxEmpl;

	if( pArrayListEmployee != NULL && id > 0 )//Valida que los datos brindados en la funcion sean coherentes.
	{
		for(i=0;i<ll_len(pArrayListEmployee);i++)//Recorre el la lista dinamica de empleados.
		{
			auxEmpl = (Employee*) ll_get(pArrayListEmployee,i);//Obtiene la informacion del empleado en la posicion i.
			if( auxEmpl != NULL &&//Valida que el empleado obtenido sea distinto de NULL.
				auxEmpl->id == id )//Valida que el ID pasado por funci�n sea igual que al id del empleado de la lista dinamica.
			{
				retorno = 0;
				*gotIndex = i;//Si pasa las validaciones del IF, le asigna al puntero gotIndex, el indice del empleado con el ID brindado en la funcion.
			}
		}
	}
	return retorno;
}

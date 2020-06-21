/*
 * Employee.c
 *
 *  Created on: 4 jun. 2020
 *      Author: VOPKEQUE
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "LinkedList.h"

static int isNumericInt(char* cadena, int len);
static int isNameOrSurname(char* cadena, int len);

/**
 * \brief Solicita un espacio en memoria para un empleado.
 * \return Retorna la direccion de memoria encontrada para el empleado 0 NULL en caso de no encontrar.
 *
 */
Employee* employee_new()
{
	return (Employee*) malloc(sizeof(Employee)); //Busca y returna memoria para un empleado.
}

/**
 * \brief Borra de memoria el espacio ocupado por un empleado.
 * \param this Puntero de empleado a borrar.
 *
 */
void employee_delete(Employee* this)
{
	if( this != NULL )//Valida que el puntero al empleado no sea NULL.
	{
		free(this);//Libera espacio en memoria que ocupa el empleado reibido en la funcion.
	}
}

/**
 * \brief Crea un nuevo empleado, recibiendo TODOS los elementos de tipo cadena de caracteres.
 * \param idStr Identificador a ser asignado al usuario.
 * \param nombreStr Nombre a ser asignado al usuario.
 * \param horasTrabajadasStr Horas trabajadas a ser asignadas al usuario.
 * \param sueldoStr Sueldo a ser asignado al usuario.
 * \return Retorna el puntero al empleado en caso de el proceso salga ok, sino devuelve NULL.
 *
 */
Employee* employee_newParametrosTxt(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* auxEmployee = NULL;
	int flag = 0;

	auxEmployee = employee_new();//Asigna espacio en memoria para el empleado.
	if( auxEmployee != NULL && //Valida que esa direccion no sea NULL.
		idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL && //Valida que los parametros sean coherentes.
		!employee_setIdTxt(auxEmployee,idStr) && //Setea en el empleado el ID.
		!employee_setNombre(auxEmployee,nombreStr) && //Setea en el empleado el nombre.
		!employee_setHorasTrabajadasTxt(auxEmployee,horasTrabajadasStr) && //Setea en el empleado las horas trabajadas.
		!employee_setSueldoTxt(auxEmployee,sueldoStr) )//Setea en el empleado el sueldo.
	{
		flag = 1;//Si pasa las validaciones del IF, crea un nuevo empleado y cambia el estado de flag a 1 para que NO entre en el siguiente IF.
	}
	if( flag == 0 )//En caso de que no se hayan pasado las validaciones del IF anterior, va a entrar en este IF.
	{
		employee_delete(auxEmployee);//Si entra en este IF, se va a liberar el espacio en memoria brindado a auxEmployee ya que no se cargaron los datos correctamente.
		auxEmployee = NULL;//Se apunta el auxEmployee a NULL.
	}
	return auxEmployee;
}

/**
 * \brief Crea un nuevo empleado, con los datos recibidos en la funcion.
 * \param idStr Identificador a ser asignado al usuario.
 * \param nombreStr Nombre a ser asignado al usuario.
 * \param horasTrabajadasStr Horas trabajadas a ser asignadas al usuario.
 * \param sueldoStr Sueldo a ser asignado al usuario.
 * \return Retorna el puntero al empleado en caso de el proceso salga ok, sino devuelve NULL.
 *
 */
Employee* employee_newParametros(int idStr, char* nombreStr, int horasTrabajadasStr, int sueldoStr)
{
	Employee* auxEmployee = NULL;
	int flag = 0;

	auxEmployee = employee_new();//Asigna espacio en memoria para el empleado.
	if( auxEmployee != NULL &&//Valida que esa direccion no sea NULL.
		idStr > 0 && nombreStr != NULL && horasTrabajadasStr > 0 && sueldoStr > 0 &&//Valida que los parametros sean coherentes.
		!employee_setId(auxEmployee,idStr) &&//Setea en el empleado el ID.
		!employee_setNombre(auxEmployee,nombreStr) &&//Setea en el empleado el nombre.
		!employee_setHorasTrabajadas(auxEmployee,horasTrabajadasStr) &&//Setea en el empleado las horas trabajadas.
		!employee_setSueldo(auxEmployee,sueldoStr) )//Setea en el empleado el sueldo.
	{
		flag = 1;//Si pasa las validaciones del IF, crea un nuevo empleado y cambia el estado de flag a 1 para que NO entre en el siguiente IF.
	}
	if( flag == 0 )//En caso de que no se hayan pasado las validaciones del IF anterior, va a entrar en este IF.
	{
		employee_delete(auxEmployee);//Si entra en este IF, se va a liberar el espacio en memoria brindado a auxEmployee ya que no se cargaron los datos correctamente.
		auxEmployee = NULL;//Se apunta el auxEmployee a NULL.
	}
	return auxEmployee;
}

/**
 * \brief Setea el ID del empleado, recibiendo un parametro de tipo cadena.
 * \param this Puntero al empleado a setear.
 * \param id ID a ser asignado al usuario.
 * \return Retorna 0 si seteó el sueldo correctamente; -1 en caso de error.
 *
 */
int employee_setIdTxt(Employee* this, char* id)
{
	int retorno = -1;

	if( this != NULL && id != NULL &&//Valida que ambos punteros sean coherentes.
		isNumericInt(id,INT_LEN) )//Valida que la cadena sea numerica entera.
	{
		retorno = 0;
		this->id = atoi(id);//Si pasa las validaciones del IF, convierte a entero la cadena recibida y se la asigna al empleado (this).
	}
	return retorno;
}

/**
 * \brief Setea el ID del empleado, recibiendo un ID de tipo entero.
 * \param this Puntero al empleado a setear.
 * \param id ID a ser asignado al usuario.
 * \return Retorna 0 si seteó el sueldo correctamente; -1 en caso de error.
 *
 */
int employee_setId(Employee* this,int id)
{
	int retorno = -1;

	if( this != NULL && id > 0 )//Valida que ambos punteros sean coherentes.
	{
		this->id = id;//Si pasa las validaciones del IF, le asigna el ID al empleado (this).
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief Setea el NOMBRE del empleado, recibiendo una cadena.
 * \param this Puntero al empleado a setear.
 * \param nombre Nombre a ser asignado al usuario.
 * \return Retorna 0 si seteó el nombre correctamente; -1 en caso de error.
 *
 */
int employee_setNombre(Employee* this, char* nombre)
{
	int retorno = -1;

	if( this != NULL && nombre != NULL &&//Valida que ambos punteros sean coherentes.
		isNameOrSurname(nombre,NOMBRE_LEN) )//Valida que la cadena sea valido como nombre o apellido.
	{
		retorno = 0;
		strncpy(this->nombre,nombre,NOMBRE_LEN);//Si pasa las validaciones del IF, copia lo recibido en la funcion al empleado (this).
	}
	return retorno;
}

/**
 * \brief Setea las HORAS del empleado, recibiendo un parametro de tipo cadena.
 * \param this Puntero al empleado a setear.
 * \param horasTrabajadas Horas a ser asignado al usuario.
 * \return Retorna 0 si seteó las horas correctamente; -1 en caso de error.
 *
 */
int employee_setHorasTrabajadasTxt(Employee* this, char* horasTrabajadas)
{
	int retorno = -1;

	if( this != NULL && horasTrabajadas != NULL &&//Valida que ambos punteros sean coherentes.
		isNumericInt(horasTrabajadas,INT_LEN) )//Valida que la cadena sea numerica entera.
	{
		retorno = 0;
		this->horasTrabajadas = atoi(horasTrabajadas);//Si pasa las validaciones del IF, convierte a entero la cadena recibida y se la asigna al empleado (this).
	}

	return retorno;
}

/**
 * \brief Setea las HORAS del empleado, recibiendo un parametro de tipo entero.
 * \param this Puntero al empleado a setear.
 * \param horasTrabajadas Horas a ser asignado al usuario.
 * \return Retorna 0 si seteó las horas correctamente; -1 en caso de error.
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = -1;

	if( this != NULL && horasTrabajadas > 0 )//Valida que ambos punteros sean coherentes.
	{
		this->horasTrabajadas = horasTrabajadas;//Si pasa las validaciones del IF, le asigna las horas al empleado (this).
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief Setea el SUELDO del empleado, recibiendo un parametro de tipo cadena.
 * \param this Puntero al empleado a setear.
 * \param sueldo Sueldo a ser asignado al usuario.
 * \return Retorna 0 si seteó el sueldo correctamente; -1 en caso de error.
 *
 */
int employee_setSueldoTxt(Employee* this, char* sueldo)
{
	int retorno = -1;

	if( this != NULL && sueldo != NULL &&//Valida que ambos punteros sean coherentes.
		isNumericInt(sueldo,INT_LEN) )//Valida que la cadena sea numerica entera.
	{
		retorno = 0;
		this->sueldo = atoi(sueldo);//Si pasa las validaciones del IF, convierte a entero la cadena recibida y se la asigna al empleado (this).
	}
	return retorno;
}

/**
 * \brief Setea el SUELDO del empleado, recibiendo un parametro de tipo entero.
 * \param this Puntero al empleado a setear.
 * \param sueldo Sueldo a ser asignado al usuario.
 * \return Retorna 0 si seteó el sueldo correctamente; -1 en caso de error.
 *
 */
int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;

	if( this != NULL && sueldo > 0 )//Valida que ambos punteros sean coherentes.
	{
		this->sueldo = sueldo;//Si pasa las validaciones del IF, le asigna las horas al empleado (this).
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief Obtiene el ID del empleado, recibiendo un puntero de tipo entero.
 * \param this Puntero del empleado a obtener informacion.
 * \param id Puntero a la variable para alojar el ID del empleado.
 * \return Retorna 0 si puedo brindar el ID correctamente; -1 en caso de error.
 *
 */
int employee_getId(Employee* this,int* id)
{
	int retorno = -1;

	if( this != NULL && id != NULL )//Valida que ambos punteros sean coherentes.
	{
		*id = this->id;//Asigna al puntero id, el identificador cargado en el empleado.
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief Obtiene el NOMBRE del empleado, recibiendo un puntero de tipo cadena.
 * \param this Puntero del empleado a obtener informacion.
 * \param nombre Puntero a la variable para alojar el nombre del empleado.
 * \return Retorna 0 si puedo brindar el nombre correctamente; -1 en caso de error.
 *
 */
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;

	if( this != NULL && nombre != NULL )//Valida que ambos punteros sean coherentes.
	{
		strncpy(nombre,this->nombre,NOMBRE_LEN);//Asigna al puntero nombre, el nombre cargado en el empleado.
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief Obtiene las HORAS del empleado, recibiendo un puntero de tipo entero.
 * \param this Puntero del empleado a obtener informacion.
 * \param horasTrabajadas Puntero a la variable para alojar las horas del empleado.
 * \return Retorna 0 si puedo brindar las horas correctamente; -1 en caso de error.
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;

	if( this != NULL && horasTrabajadas != NULL)//Valida que ambos punteros sean coherentes.
	{
		*horasTrabajadas = this->horasTrabajadas;//Asigna al puntero horasTrabajadas, las horas cargadas en el empleado.
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief Obtiene el SUELDO del empleado, recibiendo un puntero de tipo entero.
 * \param this Puntero del empleado a obtener informacion.
 * \param sueldo Puntero a la variable para alojar el sueldo del empleado.
 * \return Retorna 0 si puedo brindar el sueldo correctamente; -1 en caso de error.
 *
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;

	if( this != NULL && sueldo != NULL )//Valida que ambos punteros sean coherentes.
	{
		*sueldo = this->sueldo;//Asigna al puntero sueldo, el sueldo cargado en el empleado.
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief Imprime la informacion correspondiente a un empleado.
 * \param pEmployee Puntero del empleado a obtener informacion.
 * \return Retorna 0 si puedo brindar el sueldo correctamente; -1 en caso de error.
 *
 */
int employee_printEmployeeData(Employee* pEmployee)
{
	int retorno = 1;
    int auxId;
    char auxNombre[NOMBRE_LEN];
    int auxHoras;
    int auxSueldo;

	if( pEmployee != NULL &&//Valida que el puntero al empleado sea coherente.
		!employee_getId(pEmployee,&auxId) &&//Obtiene el ID del empleado.
		!employee_getNombre(pEmployee,auxNombre) &&//Obtiene el NOMBRE del empleado.
		!employee_getHorasTrabajadas(pEmployee,&auxHoras) &&//Obtiene las HORAS del empleado.
		!employee_getSueldo(pEmployee,&auxSueldo) )//Obtiene el SUELDO del empleado.
	{
		printf("ID: %d - NOMBRE: %s - HORAS: %d - SUELDO: %d\n",auxId,auxNombre,auxHoras,auxSueldo);//Si pasa las validaciones del IF, imprime la informacion del empleado.
		retorno = 0;
	}
	return retorno;
}

/**
 * \brief Ordena por el criterio de Sueldo a los empleados.
 * \param employee1 Puntero al primer empleado a obtener el sueldo.
 * \param employee2 Puntero al segundo empleado a obtener el sueldo.
 * \return Retorna 0 si el sueldo de los empleados son iguales; 1 si el sueldo del primer empleado es mayor; -1 si el sueldo del segundo empleado es mayor.
 *
 */
int employee_sortBySueldo(void* employee1, void* employee2)
{
	int retorno = 0;
	Employee* emp1 = (Employee*) employee1;//Castea a Employee*, el puntero recibido como void y se lo asigna a emp1.
	Employee* emp2 = (Employee*) employee2;//Castea a Employee*, el puntero recibido como void y se lo asigna a emp2.
	int sueldo1;
	int sueldo2;

	if( employee1 != NULL && employee2 != NULL &&//Valida que ambos punteros sean coherentes.
		!employee_getSueldo(emp1,&sueldo1) &&//Obtiene el sueldo del primer empleado.
		!employee_getSueldo(emp2,&sueldo2) )//Obtiene el sueldo del segundo empleado.
	{
		if( sueldo1 > sueldo2 )//Pregunta si el sueldo del primer empleado es mayor que el segundo.
		{
			retorno = 1;
		}
		else if( sueldo1 < sueldo2 )//Pregunta si el sueldo del segundo empleado es mayor que el segundo.
		{
			retorno = -1;
		}
	}
	return retorno;
}

//*********************************************************************************************

/**
 * \brief Verifica si la cadena ingresada es un numero entero válido.
 * \param cadena Cadena de caracteres a analizar.
 * \param \param len Define el tamaño de la cadena.
 * \return Retorna 1 si la cadena es un numero entero y 0 si no lo es.
 *
 */
static int isNumericInt(char* cadena, int len)
{
	int retorno = 0;
	int i;
	if(cadena != NULL && len > 0)//Valida que el puntero sea valido y que el tamañano de cadena sea razonable.
	{
		retorno = 1;
		for(i=0;i<len && cadena[i] != '\0';i++)
		{
			if(i==0 && (cadena[i] == '+' || cadena[i] == '-'))//Valida que la primer posicion de la cadena pueda ser - o +
			{
				continue;//Itera una vez mas.
			}
			if(cadena[i] < '0'||cadena[i] > '9')//Valida que el contenido sea numerico.
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es un nombre o apellido válido.
 * \param cadena Cadena de caracteres a analizar.
 * \param \param len Define el tamaño de la cadena.
 * \return Retorna 1 si la cadena es válida y 0 si no lo es.
 *
 */
static int isNameOrSurname(char* cadena, int len)
{
	int retorno = 0;
	int i=0;

	if(cadena != NULL && len > 0)//Valida que el puntero sea valido y que el tamañano de cadena sea razonable.
	{
		retorno = 1;
		for(i=0 ; cadena[i] != '\0' && i < len; i++)//Itera 'i' hasta mientras sea distinta de '\0' y respetando el tamaño del array.
		{
			if( cadena[i] != ' ' && cadena[i] != '-' &&//Valida que se acepten nombres o apellidos compuestos.
				(cadena[i] < 'A' || cadena[i] > 'Z' ) &&//Valida que cadena sea solo letras(Mayus).
				(cadena[i] < 'a' || cadena[i] > 'z' ) )//Valida que cadena sea solo letras(Minus).
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}



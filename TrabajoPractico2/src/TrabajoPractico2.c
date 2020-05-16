/*
 ============================================================================
 Name        : TrabajoPractico2.c
 Author      : Kevin Quevedo
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Trabajo Practico N°2 - Programacion I
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"
#include "Informe.h"

#define EMP_LEN 1000

int main(void) {

	setbuf(stdout, NULL);

	Employee arrayEmpleados[EMP_LEN];
	int opcion;
	int idEmpleado = 0;
	char auxName[NAME_LEN];
	char auxLastName[LASTNAME_LEN];
	float auxSalario;
	int auxSector;
	int auxId;
	int auxModif;
	int auxInf;

	if(!emp_initEmployees(arrayEmpleados,EMP_LEN))//Inicializa el campo .isEmpty = 1 de los indices del array de empleados, indicando que estan "vacios".
	{
		printf("Array de empleados, inicializado correctamente!\n\n");//Si los inicializa correctamente imprime mensaje.
	}
	do
	{
		if(!utn_getNumberInt(&opcion,"\nPor favor, ingrese una opción:"//Obtiene un numero, que se le asigna a "opcion" para que el pgm prosiga segun el numero indicado.
								     "\n\t1. Cargar un empleado."
								     "\n\t2. Modificar un empleado."
								     "\n\t3. Dar de baja un empleado."
								     "\n\t4. Informar:"					//Menu de opciones desplegado al usuario.
									 "\n\t\t1.-Listado de los empleados ordenados alfabéticamente por Apellido y Sector."
									 "\n\t\t2.-Total y promedio de los salarios, y cuántos empleados superan el salario promedio."
								     "\n\t5. Salir.\n","La opcion ingresada es invalida.\n",1,5,3))
		{
			switch(opcion)
			{

			case 1: //Cargar un empleado.

				if ( !utn_getNameOrSurname(auxName,NAME_LEN,"Ingrese un nombre: \n","Nombre invalido.\n",2) &&//Obtiene un nombre para el empleado.
					 !utn_getNameOrSurname(auxLastName,LASTNAME_LEN,"Ingrese un apellido: \n","Apellido invalido.\n",2) &&//Obtiene un apellido para el empleado.
					 !utn_getNumberFloat(&auxSalario,"Ingrese un salario (Max. 100.000): \n","Salario invalido.\n",0,100000,2) &&//Obtiene un salario para el empleado.
					 !utn_getNumberInt(&auxSector,"Ingrese un sector (1 a 10): \n","Sector invalido.\n",1,10,2) &&//Obtiene un sector para el empleado.
					 !emp_addEmployee(arrayEmpleados,EMP_LEN,idEmpleado,auxName,auxLastName,auxSalario,auxSector))//Da de alta un cliente con los datos obtenidos y si encuentra un indice vacio..
				{
					idEmpleado++;//Incrementa el ID de empleado, para que ésta y los proximos empleados cargados, posean un identificar unico.
					printf("Alta de empleado, exitosa!\n\n");//Mensaje a mostrar si se dio de alta un empleado correctamente.
				}
				else
				{
					printf("No se pudo dar de alta un nuevo empleado.\n");//Mensaje a mostrar si NO se pudo dar de alta un empleado.
				}
				break;

			case 2://Modificar un empleado.

				if( emp_contEmployee(arrayEmpleados,EMP_LEN) > 0 &&//Valida que al menos existe un empleado a modificar.
					!utn_getNumberInt(&auxId,"Por favor, ingrese el ID del cliente: \n","ID invalido",0,idEmpleado,2) &&//Le solicita al usuario un ID de empleado a modificar.
					emp_findEmployeeById(arrayEmpleados,EMP_LEN,auxId) > -1 &&//Valida que el ID exista en el array de empleados.
					!utn_getNumberInt(&auxModif,"Por favor, ingrese el campo que desea modificar: \n"//Obtiene un numero, que funciona como seleccionador.
												"\t1.-Nombre.\n"
												"\t2.-Apellido.\n"  //Menu desplegado al usuario, para proceder segun lo conveniente a modificar.
												"\t3.-Salario.\n"
												"\t4.-Sector.\n","Opcion invalida.\n",1,4,2) &&
					!emp_modifEmployee(arrayEmpleados,EMP_LEN,auxId,auxModif) )//Modifica los datos del empleado, segun los datos obtenidos.
				{
					printf("Modificacion de empleado exitosa!\n");//Mensaje a mostrar si se pudo modificar un empleado correctamente.
				}
				else
				{
					printf("No existen empleados o ha superado la cantidad de intentos permitidos.\n");//Mensaje a mostrar si NO pudo modificar la informacion de un empleado.
				}
				break;

			case 3://Dar de baja un empleado.

				if( emp_contEmployee(arrayEmpleados,EMP_LEN) > 0 &&//Valida que al menos existe un empleado a dar de baja.
					!utn_getNumberInt(&auxId,"Ingrese el ID del cliente: \n","ID invalido",0,idEmpleado,2) &&//Le solicita al usuario un ID de empleado a dar de baja.
					emp_findEmployeeById(arrayEmpleados,EMP_LEN,auxId) > -1 &&//Valida que el ID exista en el array de empleados.
					!emp_removeEmployee(arrayEmpleados,EMP_LEN,auxId))//Da de baja el usuario, segun el ID obtenido.
				{
					printf("Baja de empleado exitosa!\n");//Mensaje a mostrar si se dio de baja un empleado correctamente.
				}
				else
				{
					printf("No existen empleados o ha superado la cantidad de intentos permitidos.\n");//Mensaje a mostrar si NO se pudo dar de baja un empleado.
				}
				break;

			case 4://Informar:

				if( emp_contEmployee(arrayEmpleados,EMP_LEN) > 0 &&//Valida que al menos existe un empleado para informar.
					!utn_getNumberInt(&auxInf,"Por favor, ingrese la opcion que desee: \n"//Obtiene un numero, que funciona como seleccionador.
												"\t1.-Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n"//Menu desplegado al usuario, para proceder segun lo conveniente a visualizar.
												"\t2.-Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\n"
												,"Opcion invalida.\n",1,2,2))
				{
					if( auxInf == 1 &&
						!utn_getNumberInt(&auxModif,"Por favor, ingrese el orden: \n"//Obtiene un numero, que funciona como seleccionador.
													"\t1. Ascendente.\n"//Menu desplegado al usuario, para proceder segun lo conveniente a visualizar.
													"\t2.-Descendente.\n"
													,"Opcion invalida.\n",1,2,2) &&
						!info_sortEmployees(arrayEmpleados,EMP_LEN,auxModif))//Ordena el array de empleados de forma ascendente(1) o descendente(2).
					{
						printf("Ordenamiento exitoso!\n");//Mensaje a mostrar, si cumple con las validaciones del IF.
					}
					else if( auxInf == 2 &&
							 !info_totalAndAverageSalaryEmployees(arrayEmpleados,EMP_LEN))//Obtiene el total de los salarios, junto con el promedio y la cantidad de empledos que superan el salario promedio.
					{
						printf("Promedio e informes exitoso!\n\n");//Mensaje a mostrar, si cumple con las validaciones del IF.
					}
				}
				else
				{
					printf("No existen empleados o ha superado la cantidad de intentos permitidos.\n");//Mensaje a mostrar si NO se pudo generar informes.
				}
				break;
			}
		}
	}while(opcion != 5);
	return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main(void)
{
	setbuf(stdout, NULL);
    int opcion;
    LinkedList* listaEmpleados = ll_newLinkedList();//Crea una lista dinamica.

	do
	{
		if( !utn_getNumberInt(&opcion, "Por favor, ingrese una opción: " // Obtiene un numero, que le asigna una "opción" para que el pgm prosiga segun el numero indicado.
											 "\n\t 1. Cargar los datos de los empleados desde el archivo data.csv. "
											 "\n\t 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)."
											 "\n\t 3. Alta de empleado."
											 "\n\t 4. Modificar datos de empleado." 	// Menú de opciones desplegado al usuario.
											 "\n\t 5. Baja de empleado."
											 "\n\t 6. Listar empleados."
											 "\n\t 7. Ordenar empleados."
											 "\n\t 8. Guardar los datos de los empleados en el archivo data.csv (modo texto)."
											 "\n\t 9. Guardar los datos de los empleados en el archivo data.csv (modo binario)."
											 "\n\t 10. Salir.\n","La opción ingresada es invalida.\n",1,10,2) )
		{
				switch(opcion)
				{
					case 1:

						if( !controller_loadFromText("data.csv",listaEmpleados) )//Carga los datos desde un archivo en modo texto.
						{
							printf("Carga realizada con exito!.\n\n");//Mensaje a mostrar si pudo cargar la lista correctamente.
						}
						else
						{
							printf("No se pudo cargar el archivo!.\n\n");//Mensaje a mostrar si ocurrio un error al cargar la lista.
						}
						break;

					case 2:

						if( !controller_loadFromBinary("data.dat",listaEmpleados) )//Carga los datos desde un archivo en modo binario.
						{
							printf("Lista binario cargada con exito!.\n\n");//Mensaje a mostrar si pudo cargar la lista correctamente.
						}
						else
						{
							printf("No se pudo cargar la lista binaria!.\n\n");//Mensaje a mostrar si ocurrio un error al cargar la lista.
						}
						break;

					case 3:

						if( !controller_addEmployee(listaEmpleados) )//Agrega un empleado a la lista dinamica.
						{
							printf("Alta de empleado exitosa!.\n\n");//Mensaje a mostrar si pudo añadir un nuevo empleado a la lista dinamica.
						}
						else
						{
							printf("No se pudo dar de alta el empleado!.\n\n");//Mensaje a mostrar si ocurrió un error al añadir un nuevo empleado a la lista dinamica.
						}
						break;

					case 4:

						if( !controller_editEmployee(listaEmpleados) )//Modifica un empleado de la lista dinamica.
						{
							printf("Modificacion de empleado exitosa!.\n\n");//Mensaje a mostrar si pudo modificar un empleado de la lista dinamica.
						}
						else
						{
							printf("No se pudo modificar el empleado!.\n\n");//Mensaje a mostrar si ocurrió un error al modificar un empleado de la lista dinamica.
						}
						break;

					case 5:

						if( !controller_removeEmployee(listaEmpleados) )//Elimina un empleado de la lista dinamica.
						{
							printf("Baja de empleado exitosa!.\n\n");//Mensaje a mostrar si pudo eliminar un empleado de la lista dinamica.
						}
						else
						{
							printf("No se pudo dar de baja el empleado!.\n\n");//Mensaje a mostrar si ocurrió un error al eliminar un empleado de la lista dinamica.
						}
						break;

					case 6:

						if( !controller_ListEmployee(listaEmpleados) )//Lista la informacion de todos los empleados de la lista dinamica.
						{
							printf("Lista impresa con exito!.\n\n");//Mensaje a mostrar si puedo imprimir la lista correctamente.
						}
						else
						{
							printf("No se pudo imprimir lista!.\n\n");//Mensaje a mostrar si ocurrió un error al imprimir la lista.
						}
						break;

					case 7:

						if( !controller_sortEmployee(listaEmpleados) )//Ordena a los empleados por un criterio.
						{
							printf("Lista ordenada con exito!.\n\n");//Mensaje a mostrar si puedo ordenar la lista correctamente.
						}
						else
						{
							printf("No se pudo ordenar la lista!.\n\n");//Mensaje a mostrar si ocurrió un error al imprimir la lista.
						}
						break;

					case 8:

						if( !controller_saveAsText("data.csv",listaEmpleados) )//Guarda los datos en un archivo en modo texto.
						{
							printf("Lista guardada en archivo con exito!.\n\n");//Mensaje a mostrar si pudo guardar la lista correctamente.
						}
						else
						{
							printf("No se pudo guardar la lista en el archivo!.\n\n");//Mensaje a mostrar si ocurrio un error al guardar la lista.
						}
						break;

					case 9:

						if( !controller_saveAsBinary("data.dat",listaEmpleados) )//Guarda los datos en un archivo en modo binario.
						{
							printf("Lista guardada en binario con exito!.\n\n");//Mensaje a mostrar si pudo guardar la lista correctamente.
						}
						else
						{
							printf("No se pudo guardar la lista en modo binario!.\n\n");//Mensaje a mostrar si ocurrio un error al guardar la lista.
						}
						break;
				}
		}
	}while(opcion != 10);//Si la opcion es igual a 10, finaliza el programa.
    return EXIT_SUCCESS;
}


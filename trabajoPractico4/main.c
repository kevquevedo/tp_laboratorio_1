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
     10. Clonar lista original como 'Lista Clonada'. - Uso de ll_clone.
	 11. Listar empleados (Lista Clonada).
	 12. Vaciar Lista Clonada. - Uso de ll_clear.
	 13. Eliminar Lista Clonada. - Uso de ll_deleteLinkedList.
	 14. Verificar si la 'Lista Clonada' tiene informacion, está vacia o no existe. - Uso de ll_isEmpty.
	 15. Generar sublista de 'Lista Original' indicando los indices (desde y hasta). - Uso de ll_subList.
	 16. Listar empleados(Sublista de 'Lista Original').
	 17. Extraer un empleado de 'Lista Original' y pasar a 'SubLista'. - Uso de ll_pop & ll_push.
	 18. Verificar si los elementos de la 'SubLista' se encuentran en la lista original. - Uso de ll_containsAll"
*****************************************************/

int main(void)
{
	setbuf(stdout, NULL);
    int opcion;
    int auxiliar;
    void* pElementAuxiliar = NULL;
    LinkedList* listaEmpleados = ll_newLinkedList();//Crea una lista dinamica.
    LinkedList* listaClonada = NULL;
    LinkedList* subLista = ll_newLinkedList();//Crea una lista dinamica.
	do
	{
		if( !utn_getNumberInt(&opcion, "Por favor, ingrese una opción: " // Obtiene un numero, que le asigna una "opción" para que el pgm prosiga segun el numero indicado.
											 "\n\t 1. Cargar los datos de los empleados desde el archivo data.csv. "
											 "\n\t 2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)."
											 "\n\t 3. Alta de empleado."
											 "\n\t 4. Modificar datos de empleado." 	// Menú de opciones desplegado al usuario.
											 "\n\t 5. Baja de empleado."
											 "\n\t 6. Listar empleados(Lista Original)."
											 "\n\t 7. Ordenar empleados."
											 "\n\t 8. Guardar los datos de los empleados en el archivo data.csv (modo texto)."
											 "\n\t 9. Guardar los datos de los empleados en el archivo data.csv (modo binario)."
											 "\n\n\t -------------------------------------------------------------------"
											 "\n\n\t 10. Clonar lista original como 'Lista Clonada'. - Uso de ll_clone."
											 "\n\t 11. Listar empleados (Lista Clonada)."
											 "\n\t 12. Vaciar Lista Clonada. - Uso de ll_clear."
											 "\n\t 13. Eliminar Lista Clonada. - Uso de ll_deleteLinkedList."
											 "\n\t 14. Verificar si la 'Lista Clonada' tiene informacion, está vacia o no existe. - Uso de ll_isEmpty."
											 "\n\t 15. Generar sublista de 'Lista Original' indicando los indices (desde y hasta). - Uso de ll_subList"
											 "\n\t 16. Listar empleados(Sublista de 'Lista Original')."
											 "\n\t 17. Extraer un empleado de 'Lista Original' y pasar a 'SubLista'. - Uso de ll_pop & ll_push"
											 "\n\t 18. Verificar si los elementos de la 'SubLista' se encuentran en la lista original. - Uso de ll_containsAll"
											 "\n\t 19. SALIR.\n","La opción ingresada es invalida.\n",1,19,2) )
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

					case 10:

						listaClonada = controller_clonList(listaEmpleados);
						if( listaClonada != NULL ) //Clona la lista original de empleados.
						{
							printf("Lista clonada con exito!.\n\n");//Mensaje a mostrar si pudo clonar la lista correctamente.
						}
						else
						{
							printf("No se pudo clonar la lista!.\n\n");//Mensaje a mostrar si ocurrio un error al clonar la lista.
						}
						break;

					case 11:

						if( !controller_ListEmployee(listaClonada) )//Lista la informacion de todos los empleados de la "listaClonada".
						{
							printf("Lista clonada impresa con exito!.\n\n");//Mensaje a mostrar si puedo imprimir la lista clonada correctamente.
						}
						else
						{
							printf("No se pudo imprimir lista clonada!.\n\n");//Mensaje a mostrar si ocurrió un error al imprimir la lista clonada.
						}
						break;

					case 12:

						if( !controller_clearList(listaClonada) )//Vacía la "listaClonada".
						{
							printf("Se vació la lista clonada con exito!.\n\n");//Mensaje a mostrar si puedo varciar la lista clonada correctamente.
						}
						else
						{
							printf("No se pudo vaciar la lista clonada!.\n\n");//Mensaje a mostrar si ocurrió un error al imprimir la lista clonada.
						}
						break;

					case 13:

						if( !controller_deleteLinkedList(listaClonada) )//Elimina la lista clonada.
						{
							listaClonada = NULL;
							printf("Se eliminó la lista clonada con exito!.\n\n");//Mensaje a mostrar si puedo eliminar la lista correctamente.
						}
						else
						{
							printf("No se pudo eliminar la lista clonada!.\n\n");//Mensaje a mostrar si ocurrió un error al eliminar la lista.
						}

						break;

					case 14:

						if ( controller_isEmptyList(listaClonada) == -1 )//Invoca a la función que determina si se encuentra con informacion, vacia o no existe.
						{
							printf("La lista no existe!.\n\n");//Mensaje a mostrar en caso, de la lista no exista.
						}
						break;

					case 15:

						subLista = controller_generateSubList(listaEmpleados);//Genera una sublista a partir de la lista original.
						if( subLista != NULL )//Verifica que la sublista no apunte a NULL.
						{
							printf("Se generó la sublista clonada con exito!.\n\n");//Mensaje a mostrar si se generó la SubLista correctamente.
						}
						else
						{
							printf("No se pudo eliminar la sublista clonada!.\n\n");//Mensaje a mostrar si ocurrió un error al generar la sublista.
						}

						break;

					case 16:

						if( !controller_ListEmployee(subLista) )//Lista la informacion de todos los empleados de la subLista dinamica.
						{
							printf("Sublista impresa con exito!.\n\n");//Mensaje a mostrar si puedo imprimir la subLista correctamente.
						}
						else
						{
							printf("No se pudo imprimir Sublista!.\n\n");//Mensaje a mostrar si ocurrió un error al imprimir la subLista.
						}
						break;

					case 17:

						if( !controller_insertElementSublist(listaEmpleados,subLista) )//Extrae un empleado de la lista original y lo incorpora en la sublista.
						{
							printf("Elemento agregado a SubLista con exito!.\n\n");//Mensaje a mostrar, si puedo generar la operacion.
						}
						else
						{
							printf("No se pudo agregar el elemento a SubLista!.\n\n");//Mensaje a mostrar, si hubo un error al querer extrar o incoporar el empleado.
						}
						break;

					case 18:

						auxiliar = controller_containsAllList(listaEmpleados,subLista);//Invoca a la funcion, que verifica que todos elementos de la 'sublista' se encuentren en la 'lista original'.
						if( auxiliar == 1 )
						{
							printf("Los elementos de la SubLista, se encuentran en la Lista Original!.\n\n");//Mensaje a mostrar si todos los elementos de la 'sublista', se encuentran en la 'lista original'.
						}
						else if( auxiliar == 0 )
						{
							printf("Los elementos de la SubLista, NO se encuentran en su totalidad en la Lista Original!.\n\n");//Mensaje a mostrar si algunos de los elementos de la 'sublista', no estan en la 'lista original'.
						}
						else
						{
							printf("Una de las listas no existe!\n\n");//Mensaje a mostrar si algunos de los puntero apunta a NULL.
						}
						break;
				}
		}
	}while(opcion != 19);//Si la opcion es igual a 19, finaliza el programa.
    return EXIT_SUCCESS;
}


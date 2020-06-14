/*
 ============================================================================
 Name        : trabajoPractico3.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


#include <LinkedList.h>
#include "Controller.h"

int main(void) {

	setbuf(stdout, NULL);

    int option = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
        }
    }while(option != 10);

	return EXIT_SUCCESS;
}

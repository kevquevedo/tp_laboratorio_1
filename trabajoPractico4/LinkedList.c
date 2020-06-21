#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
//#include "../testing/inc/Employee.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = NULL;

    this = (LinkedList*)malloc(sizeof(LinkedList));//Asigna memoria memoria para una lista.
    if( this != NULL )//Verifica que la lista no sea NULL.
    {
    	this->pFirstNode = NULL;
    	this->size = 0;//Si pasa las validaciones, inicializa la lista apuntando a NULL, ya que no tiene nodos asignados y el tamaño a cero.
    }
    return this;//Retorna el puntero a la lista.
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if( this != NULL )//Verifica que la lista no sea NULL.
    {
    	returnAux = this->size;//Si pasa las validaciones del IF, devuelve el tamaño de la lista.
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* nodeActual = NULL;
	int ind = 0;
	if( this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this) )//Valida que el puntero a la lista no sea NULL y que el indice sea coherente.
	{
		nodeActual = this->pFirstNode;//Le asigna al nodeActual, el primer nodo que apunta la lista.
		do
		{
			if( ind == nodeIndex )//Valida si el indice pasado como argumento es igual a la variable ind.
			{
				break;//Si son iguales, sale del bucle.
			}
			else
			{
				nodeActual = nodeActual->pNextNode;//Si no entra al IF, le asigna al nodeActual,
				ind++; 							   //la direccion de memoria que apunta mi nodeActual,
			}									   //Es decir, el nodo siguiente.
		}while( nodeActual != NULL );//Mientras siga encontrando direcciones de memoria de nodos o hasta
	}								 //que el ind coincida con el index pasado por referencia, seguirá iterando.
    return nodeActual;//Retorna el nodo del indice, pasado como argumento en la funcion.
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
	return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* nodoNew = NULL;
    Node* nodoAux = NULL;
    if( this != NULL && nodeIndex >= 0 )//Verifica que el puntero a la lista no sea NULL y que el index sea coherente.
    {
    	nodoNew = (Node*) malloc(sizeof(Node));//Asigna un espacio en la memoria a nodoNew.
    	if( nodoNew != NULL )//Verifica que el nodoNew se haya creado correctamente.
    	{
    		nodoNew->pElement = pElement;//Le asigna al nodo el puntero al elemento pasado en la funcion.
			if( nodeIndex == 0 )//Valida si el indice pasado en la funcion es el primero.
			{
				nodoNew->pNextNode = this->pFirstNode;//Si es el primero hace que este nodo nuevo, apunte a la direccion de memoria que apuntaba la lista.
				this->pFirstNode = nodoNew;//Hace que la lista apunte al nodo nuevo.
			}
			else//Si no es el primer nodo.
			{
				nodoAux = getNode(this,nodeIndex-1);//Obtiene el nodo anterior al pasado como indice.
				nodoNew->pNextNode = nodoAux->pNextNode;//Hago que el nodo nuevo, apunte a la direccion de memoria que estaba apuntando el nodo anterior. (Puede ser otro nodo o NULL).
				nodoAux->pNextNode = nodoNew;//Hago que el nodo anterior, apunte a el nodo nuevo.
			}
			this->size++;//Incrementa el tamaño de la lista.
			returnAux = 0;
		}
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if( this != NULL &&//Verifica que el puntero a la lista no sea NULL.
    	!addNode(this,this->size,pElement) )//Valida que addNode, haya agregado el nodo correctamente.
    {
    	returnAux = 0;//Retorna 0, estan ok las validaciones del IF.
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* nodoAux = NULL;

    if( this != NULL && index >= 0 && index < this->size )//Verifica que el puntero a la lista no sea NULL y que el indice sea valido.
    {
    	nodoAux = getNode(this,index);//Obtiene el nodo del indice pasado como parametro.
    	returnAux = nodoAux->pElement;//Le asigna a retorno, el puntero al elemento del nodo.
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* auxNodo = NULL;

    if( this != NULL && index >= 0 && index < this->size )//Verifica que el puntero a la lista no sea NULL y que el indice sea coherente.
    {
    	auxNodo = getNode(this,index);//Obtiene el nodo del indice pasado como parametro.
    	if( auxNodo != NULL )//Verifica que se haya obtenido el nodo correctamente.
    	{
    		auxNodo->pElement = pElement;//Asigna al nodo el puntero al elemento pasado como parametro.
    		returnAux = 0;
    	}
    }
    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* auxNodo = NULL;
    Node* auxNodo2 = NULL;
    if( this != NULL && index >= 0 && index < this->size )//Verifica que el puntero a la lista no sea NULL y que el indice sea coherente.
    {
    	auxNodo = getNode(this,index);//Obtengo el nodo del indice a eliminar.
    	auxNodo2 = getNode(this,index-1);//Obtengo el nodo del indice anterior a ser eliminado.
    	if( index == 0 )//Valida si es el primer nodo.
    	{
    		this->pFirstNode = auxNodo->pNextNode;//Hace que la lista apunte a la direccion de memoria,
    	}									    //donde apunta el nodo a eliminar (Puede ser otro nodo o NULL).
    	else//Si no es el primer nodo.
    	{
    		auxNodo2->pNextNode = auxNodo->pNextNode;//Hace que el nodo anterior a eliminar,
    	}											//apunte a la direccion de memoria donde apunta el nodo a eliminar (Puede ser otro nodo o NULL).
    	free(auxNodo);//Libera el espacio de memoria del nodo eliminado.
    	this->size--;//Decrementa el size, ya que se eliminó un nodo.
    	returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int flag;

    if( this != NULL )//Verifica la lista no apunte a NULL.
    {
    	do
    	{
    		flag = ll_remove(this,ll_len(this)-1);//Borra desde el ultimo nodo al primero. Le asigna a la variable flag el resultado de la funcion.
    	}
    	while(flag != -1);//Mientras la funcion elimine nodos, seguirá iterando.
		this->pFirstNode = NULL;//Hace que la lista no apunte a ningun nodo.
		returnAux = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if( this != NULL &&//Verifica la lista no apunte a NULL.
    	!ll_clear(this) )//Elimina todos los elementos de la lista.
    {
    	free(this);//Libera el espacio en memoria que ocupaba la lista.
    	returnAux = 0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    void* auxElement = NULL;
    if( this != NULL )//Verifica la lista no apunte a NULL.
    {
    	for(i=0;i<ll_len(this);i++)//Recorre la lista pasada como parametro.
    	{
    		auxElement = ll_get(this,i);//Obtiene el elemento que se encuenta en la variable i.
    		if( auxElement == pElement )//Verifica si el elemento obtenido, es igual al pasado como parametro.
    		{
    			returnAux = i;//Si pasa el IF, devuelve el indice del elemento que es igual al pasado como parametro.
    			break;
    		}
    	}
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if( this != NULL )//Verifica la lista no apunte a NULL.
    {
    	if( this->size == 0 )//Verifica si el tamaño de la lista es 0, si es así, retorna 1.
    	{
    		returnAux = 1;
    	}
    	else//Si no está vacia, retorna 0.
    	{
    		returnAux = 0;
    	}
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if( this != NULL && index >= 0 && index <= this->size )//Verifica que el puntero a la lista no sea NULL y que el indice sea coherente.
    {
    	if( !addNode(this,index,pElement) )//Agrega el elemento pasado como parametro, en la lista e indice tambien pasadas como parametro.
    	{
    		returnAux = 0;
    	}
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    Node* auxNodo;

    if( this != NULL && index >= 0 )//Verifica que el puntero a la lista no sea NULL y que el indice sea coherente.
    {
    	auxNodo = getNode(this,index);//Obtiene el nodo, correspondiente al indice pasado como parametro.
    	if( auxNodo != NULL )//Verifica que el nodo se haya ontenido correctamente.
    	{
    		returnAux = auxNodo->pElement;//Retorna el puntero al elemento.
    		ll_remove(this,index);//Elimina el nodo del indice pasado como parametro.
    	}
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int i;
    int flag = 0;
    void* auxElement = NULL;
    if( this != NULL )//Verifica la lista no apunte a NULL.
    {
    	for(i=0;i<ll_len(this);i++)//Recorre la lista pasada como parametro.
    	{
    		auxElement = ll_get(this,i);//Obtiene el elemento que se encuenta en la variable i.
    		if( auxElement == pElement )//Verifica si el elemento obtenido, es igual al pasado como parametro.
    		{
    			flag = 1;//Asigna 1 a flag si encontró el elemento en la lista pasada como parametro.
    		}
    	}
    	returnAux = flag;//Asigna a returnAux el valor de la bandera. 0 si no lo encontró en la lista y 1 si lo encontró.
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i;
    void* auxElement = NULL;

    if( this != NULL && this2 != NULL )//Verifica las listas no apunten a NULL.
    {
    	returnAux = 1;//Antes de iterar confia en que va a encontrar todos los elementos de la lista 2 en la lista 1.
    	for(i=0;i<ll_len(this2);i++)//Recorre la lista 2.
    	{
    		auxElement = ll_get(this2,i);//Obtiene los elementos de la lista 2.
    		if( !ll_contains(this,auxElement) )//Busca si el elemento obtenido de la lista 2, se encuentra en la lista 1.
    		{
    			returnAux = 0;//Si no lo encuentra, entra al IF y se retorna 0.
    			break;
    		}
    	}
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int i;
    void* auxElement = NULL;
    if( this != NULL && from >= 0 && to <= this->size && from <= to )//Verifica la lista no apunte a NULL y que el desde/hasta sean coherentes.
    {
    	cloneArray = ll_newLinkedList();//Crea un espacio de memoria para la lista clon.
    	for(i=from;i<to;i++)//Recorre el array desde y hasta los parametros pasados por parametro.
    	{
    		auxElement = ll_get(this,i);//Obtiene el puntero al elemento que posee el nodo del indice indicado.
    		ll_add(cloneArray,auxElement);//Lo agrega a la lista clon.
    	}
    }
    return cloneArray;//Devuelve la lista clonada.
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int i;
    void* auxElement = NULL;
    if( this != NULL )//Verifica que la lista no sea NULL.
    {
    	cloneArray = ll_newLinkedList();//Crea una nueva lista, clon de la lista pasada como parametro en la funcion.
    	for(i=0;i<ll_len(this);i++)//Recorre la lista a clonar.
    	{
    		auxElement = ll_get(this,i);//Obtiene el elemento de todas las posiciones de la lista a clonar.
    		ll_add(cloneArray,auxElement);//Agrega los elementos obtenidos a la lista clon.
    	}
    }
    return cloneArray;//Retorna el puntero a la lista clonada.
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    void* auxElement1 = NULL;
    void* auxElement2 = NULL;
    void* auxiliarSwap = NULL;
    int resultadoFunc;
    int i;
    int swap;
    int lenLista;

    if( this != NULL && order >= 0 && order <= 1 && pFunc != NULL )//Valida que la lista y la funcion no apunten a NULL y que la variable order sea 0 o 1.
    {
    	lenLista = ll_len(this)-1;
    	do
    	{
    		swap = 0;//Pongo el swap en 0, pensando que no voy a iterar.
			for(i=0;i<lenLista;i++)//Recorro la lista pasada como parametro.
			{
				auxElement1 = ll_get(this,i);//Obtengo el primer elemento a comparar.
				auxElement2 = ll_get(this,i+1);//Obtengo el segundo elemento a comparar.
				resultadoFunc = pFunc(auxElement1,auxElement2);//Le paso los dos elementos a la funcion criterio.
				if( (resultadoFunc == -1 && order == 0) ||//Valida, si el retorno de la funcion es -1 (Segundo elemento mayor al primero) y el orden descendente (0) ó
					(resultadoFunc == 1 && order == 1) )// retorno de la funcion es 1 (Primer elemento mayor al segundo) y el orden ascendente (1)
				{
					swap = 1;//Asigna 1 para que vuelva a iterar.
					auxiliarSwap = auxElement1;//Guarda en el auxiliar el elemento en la primer posicion.
					ll_set(this,i,auxElement2);//Setea el elemento de la segunda posicion en la primera.
					ll_set(this,i+1,auxiliarSwap);//Setea el primer elemento en la segunda posicion.
				}
			}
			lenLista--;//Disminuye la cantidad de iteraciones, una vez ordenado o no.
    	}while(swap);//Mientras el swap sea 1, es decir, mientras tenga que ordenar va a seguir iterando.
    	returnAux = 0;//Retorna 0, si ordenó correctamente.
    }
    return returnAux;
}


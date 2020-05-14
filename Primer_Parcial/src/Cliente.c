#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Cliente.h"
#include "Publicidad.h"
#include "utn.h"

/**
 * \brief Imprime los datos de un cliente
 * \param pElemento Puntero al producto que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_imprimir(Cliente* pElemento)
{
	int retorno=-1;
	if(pElemento != NULL && pElemento->isEmpty == 0)
	{
		retorno=0;
		printf("\nID: %d - Nombre: %s - Apellido: %s - Cuit: %s",pElemento->id,
				pElemento->nombre,pElemento->apellido,pElemento->cuit);
	}
	return retorno;
}

/**
 * \brief Imprime el array de clientes
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_imprimirArray(Cliente* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			cli_imprimir(&array[i]);
		}
	}
	return respuesta;
}

/**
 * \brief Inicializa el array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_inicializarArray(Cliente* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			array[i].isEmpty = 1;
		}
	}
	return respuesta;
}

/**
 * \brief Da de alta un cliente en una posicion del array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado al cliente
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_altaArray(Cliente* array,int limite, int indice, int* id)
{
	int respuesta = -1;
	Cliente bufferCliente;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && id != NULL)
	{
		if(	utn_getNombre(bufferCliente.nombre,NOMBRE_LEN,"\nNombre del cliente\n","\nError en el nombre\n",2) == 0 &&
			utn_getNombre(bufferCliente.apellido,APELLIDO_LEN,"\nApellido del cliente\n","\nError en el apellido\n",2) == 0 &&
			utn_getCuit(bufferCliente.cuit,CUIT_LEN,"\nNumero de CUIT\n","\nCuit incorrecto\n",2) == 0)
		{
			respuesta = 0;
			bufferCliente.id = *id;
			bufferCliente.isEmpty = 0;
			array[indice] = bufferCliente;
			(*id)++;
		}
	}
	return respuesta;
}

/**
 * \brief Actualiza los datos de un cliente en una posicion del array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_modificarArray(Cliente* array,int limite, int indice)
{
	int respuesta = -1;
	Cliente bufferCliente;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		if(	utn_getNombre(bufferCliente.nombre,NOMBRE_LEN,"\nNombre?\n","\nERROR\n",2) == 0 &&
			utn_getNombre(bufferCliente.apellido,APELLIDO_LEN,"\nApellido del cliente\n","\nError en el apellido\n",2) == 0 &&
			utn_getCuit(bufferCliente.cuit,CUIT_LEN,"\nNumero de CUIT\n","\nCuit incorrecto\n",2) == 0)
		{
			respuesta = 0;
			bufferCliente.id = array[indice].id;
			bufferCliente.isEmpty = 0;
			array[indice] = bufferCliente;
		}
	}
	return respuesta;
}

/**
 * \brief Actualiza una posicion del array
 * \param array Array de clientes a ser actualizado
 * \param limite Limite del array de clientes
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int cli_bajaArray(Cliente* array,int limite, int indice)
{
	int respuesta = -1;
	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		array[indice].isEmpty = 1;
		respuesta = 0;
	}
	return respuesta;
}


/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array cliente Array de cliente
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int cli_buscarId(Cliente array[], int limite, int valorBuscado)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0 && valorBuscado >= 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			if(array[i].id == valorBuscado)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

/**
 * \brief Buscar primer posicion vacia
 * \param array Array de clientes
 * \param limite Limite del array de clientes
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int cli_getEmptyIndex(Cliente* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			if(array[i].isEmpty == 1)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}

/**
 * \brief Ordenar el array de clientes por nombre
 * \param array Array de clientes
 * \param limite Limite del array de clientes
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int cli_ordenarPorNombre(Cliente* array,int limite)
{
	int respuesta = -1;
	int flagSwap;
	int i;
	Cliente buffer;
	if(array != NULL && limite > 0)
	{
		do
		{
			flagSwap = 0;
			for(i=0;i<limite-1;i++)
			{
				if(array[i].isEmpty || array[i+1].isEmpty)
				{
					continue;
				}
				if(strncmp(array[i].nombre,array[i+1].nombre,NOMBRE_LEN) > 0)
				{
					flagSwap = 1;
					buffer = array[i];
					array[i] = array[i+1];
					array[i+1]=buffer;
				}
			}
			limite--;
		}while(flagSwap);
	}
	return respuesta;
}


/**
 * \brief Ordenar el array de clientes por nombre y altura
 * \param array Array de clientes
 * \param limite Limite del array de clientes
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
/*int cli_ordenarPorNombreAltura(Cliente* array,int limite)
{
	int respuesta = -1;
	int flagSwap;
	int i;
	Cliente buffer;
	int auxiliarCmp;
	if(array != NULL && limite > 0)
	{
		do
		{
			flagSwap = 0;
			for(i=0;i<limite-1;i++)
			{

				if(array[i].isEmpty || array[i+1].isEmpty)
				{
					continue;
				}
				if(strncmp(array[i].nombre,array[i+1].nombre,NOMBRE_LEN) > 0)
				{
					flagSwap = 1;
					buffer = array[i];
					array[i] = array[i+1];
					array[i+1]=buffer;
				}
				else if(strncmp(array[i].nombre,array[i+1].nombre,NOMBRE_LEN) == 0)
				{
					if(array[i].altura < array[i+1].altura)
					{
						flagSwap = 1;
						buffer = array[i];
						array[i] = array[i+1];
						array[i+1]=buffer;
					}
				}
*/
/*				if(array[i].isEmpty || array[i+1].isEmpty)
				{
					continue;
				}
				auxiliarCmp = strncmp(array[i].nombre,array[i+1].nombre,NOMBRE_LEN);
				if(	 auxiliarCmp > 0 ||
					(auxiliarCmp == 0 && array[i].altura < array[i+1].altura) )
				{
					flagSwap = 1;
					buffer = array[i];
					array[i] = array[i+1];
					array[i+1]=buffer;
				}
			}
			limite--;
		}while(flagSwap);
	}
	return respuesta;
}
*/
/*Brief Da de alta clientes de modo forzado para TEST
 * param array es el array de clientes donde se genera el alta
 * param limite es el limite del array
 * param indice es el indice donde se va a dar de alta el cliente
 * param id es el id ùnico del cliente
 * param nombre es el nombre ficticio del cliente
 * param apellido es el apellido ficticio del cliente
 * param cuit es el cuit ficticio del cliente
 * return Retorna 0 (EXITO) y -1 (ERROR)
 */
int cli_altaForzada(Cliente* array,int limite, int indice, int* id,char* nombre,char* apellido,char* cuit)
{
	int respuesta = -1;
	Cliente auxiliar;
	if(array != NULL && limite > 0 && indice < limite)
	{

			strncpy(auxiliar.nombre,nombre,NOMBRE_LEN);
			strncpy(auxiliar.apellido,apellido,APELLIDO_LEN);
			strncpy(auxiliar.cuit,cuit,CUIT_LEN);

			respuesta = 0;
			array[indice] = auxiliar;
			array[indice].isEmpty = 0;
			array[indice].id = *id;
			*id = *id + 1;

	}
	return respuesta;
}
/*Brief Da de baja a un cliente y todas sus publicidades
 * param array es el array de clientes
 * param limite es el limite maximo de busqueda en el array de clientes
 * param indice es el ID del cliente a dar de baja y buscar en el array de publicidades
 * param arrayPub es el array de publicidades
 * param limitePub es el limite maximo de busqueda en el array de publicidades
 * return Retorna 0 (EXITO) y -1 (ERROR)
 */
int cli_BajaClienteConPublicidades(Cliente* array,int limite, int indice,Publicidad* arrayPub,int limitePub)
{
	int respuesta = -1;
	int i;
	int opcion;

	if(array != NULL && limite > 0 && indice > 0 && arrayPub != NULL && limitePub > 0)
	{
	utn_getNumero(&opcion,"\n\n¿Desea dar de baja al Cliente y sus Publicidades?\n1-Si\n2-No","Opcion incorrecta",1,2,2);

	if(opcion==1)
	{

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
			array[indice].isEmpty = 1;

	}
	for(i=0;i<limitePub;i++)
	{
		if(arrayPub[i].idCliente == indice)
		{
				arrayPub[i].isEmpty = 1;
		}
	}
		printf("\nBajas generadas con exito\n");
	}
	if(opcion==2)
	{
		printf("\nSalida sin modificaciones\n");
	}
	respuesta = 0;
	}
	return respuesta;
	}














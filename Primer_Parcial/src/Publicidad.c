#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Publicidad.h"
#include "utn.h"
#include "Cliente.h"



/**
 * \brief Imprime los datos de un publicidad
 * \param pElemento Puntero al producto que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_imprimir(Publicidad* pElemento)
{
	int retorno=-1;
	if(pElemento != NULL && pElemento->isEmpty == 0)
	{
		retorno=0;
		printf("\nID: %d -El texto del aviso es: %s -Rubro %s -Estado de la Publicacion: %d -Id CLiente: %d",pElemento->id,
				pElemento->textoAviso,pElemento->rubro,pElemento->estado,pElemento->idCliente);
	}
	return retorno;
}

/*
 * \brief Imprime el array de publicidades
 * \param array Array de publicidades a ser actualizado
 * \param limite Limite del array de publicidades
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_imprimirArray(Publicidad* array,int limite)
{
	int respuesta = -1;
	int i;
	if(array != NULL && limite > 0)
	{
		respuesta = 0;
		for(i=0;i<limite;i++)
		{
			pub_imprimir(&array[i]);
		}
	}
	return respuesta;
}

/*
 * \brief Inicializa el array
 * \param array Array de publicidades a ser actualizado
 * \param limite Limite del array de publicidades
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_inicializarArray(Publicidad* array,int limite)
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
 * \brief Da de alta una publicidad en una posicion del array
 * \param array Array de publicidades a ser actualizado
 * \param limite Limite del array de publicidades
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado al publicidad
 * \param indiceCliente indica el ID del cliente a asignar
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_altaArray(Publicidad* array,int limite, int indice, int* id,int* indiceCliente)
{
	int respuesta = -1;
	Publicidad bufferCliente;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && id != NULL)
	{
		if(	//utn_getNombre(bufferCliente.textoAviso,GHOST_LEN,"\nNombre?\n","\nERROR\n",2) == 0 &&
			utn_getDescripcion(bufferCliente.textoAviso,AVISO_LEN,"\nIndique el texto del aviso\n","Error, inválido",2) == 0 &&
			//utn_getNumero(bufferCliente.rubro,"Indique Rubro","Rubro Incorrecto",0,1000000,2) == 0 &&
			utn_getDescripcion(bufferCliente.rubro,20,"\nIndique Rubro\n","Error, inválido",2) == 0 &&
			utn_getNumero(&bufferCliente.estado,"Indique Estado: 1 Activa y 0 Pausada","Estado Incorrecto",0,1,2) == 0
			//utn_getDni(bufferCliente.rubro,GHOST1_LEN,"\nDNI?\n","\nERROR\n",2) == 0 &&
			//utn_getNumeroFlotante(&bufferCliente.altura,"\nAltura?\n","\nERROR\n",0,5,2) == 0)
			)
		{
			respuesta = 0;
			bufferCliente.idCliente = *indiceCliente;
			bufferCliente.id = *id;
			bufferCliente.isEmpty = 0;
			array[indice] = bufferCliente;
			(*id)++;
		}
	}
	return respuesta;
}

/**
 * \brief Actualiza los datos de un publicidad en una posicion del array
 * \param array Array de publicidades a ser actualizado
 * \param limite Limite del array de publicidades
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
/*int pub_modificarArray(Publicidad* array,int limite, int indice)
{
	int respuesta = -1;
	Publicidad bufferCliente;

	if(array != NULL && limite > 0 && indice < limite && indice >= 0 && array[indice].isEmpty == 0)
	{
		if(	utn_getNombre(bufferCliente.textoAviso,GHOST_LEN,"\nNombre?\n","\nERROR\n",2) == 0 &&
			utn_getDni(bufferCliente.rubro,GHOST1_LEN,"\nDNI?\n","\nERROR\n",2) == 0 &&
			utn_getNumeroFlotante(&bufferCliente.altura,"\nAltura?\n","\nERROR\n",0,5,2) == 0)
		{
			respuesta = 0;
			bufferCliente.id = array[indice].id;
			bufferCliente.isEmpty = 0;
			array[indice] = bufferCliente;
		}
	}
	return respuesta;
}
*/

/**
 * \brief Actualiza una posicion del array
 * \param array Array de publicidades a ser actualizado
 * \param limite Limite del array de publicidades
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int pub_bajaArray(Publicidad* array,int limite, int indice)
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
* \param array publicidad Array de publicidad
* \param limite int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int pub_buscarId(Publicidad array[], int limite, int valorBuscado)
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
 * \param array Array de publicidads
 * \param limite Limite del array de publicidades
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int pub_getEmptyIndex(Publicidad* array,int limite)
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
 * \brief Ordenar el array de publicidades por nombre
 * \param array Array de publicidades
 * \param limite Limite del array de publicidades
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
int pub_ordenarPorNombre(Publicidad* array,int limite)
{
	int respuesta = -1;
	int flagSwap;
	int i;
	Publicidad buffer;
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
				if(strncmp(array[i].textoAviso,array[i+1].textoAviso,AVISO_LEN) > 0)
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
 * \brief Ordenar el array de publicidades por nombre y altura
 * \param array Array de publicidades
 * \param limite Limite del array de publicidades
 * \return Retorna el incice de la posicion vacia y -1 (ERROR)
 *
 */
/*int pub_ordenarPorNombreAltura(Publicidad* array,int limite)
{
	int respuesta = -1;
	int flagSwap;
	int i;
	Publicidad buffer;
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
/*			if(array[i].isEmpty || array[i+1].isEmpty)
				{
					continue;
				}
				auxiliarCmp = strncmp(array[i].textoAviso,array[i+1].textoAviso,GHOST_LEN);
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
int pub_altaForzada(Publicidad* array,int limite, int indice, int* id,char* aviso,char* rubro,int estado,int idCliente)
{
	int respuesta = -1;
	Publicidad auxiliar;
	if(array != NULL && limite > 0 && indice < limite)
	{

			strncpy(auxiliar.textoAviso,aviso,AVISO_LEN);
			strncpy(auxiliar.rubro,rubro,RUBRO_LEN);

			respuesta = 0;
			auxiliar.idCliente = idCliente;
			auxiliar.estado = estado;
			array[indice] = auxiliar;
			array[indice].isEmpty = 0;
			array[indice].id = *id;
			*id = *id + 1;

	}
	return respuesta;
}
/*
 * Brief Modifica el estado de activo a pausado de una publicacion
 * param array Es el array donde està la publicacion
 * param limite Es el limite hasta donde busca la funcion
 * param indice Es el indice que busca en el array
 * return respuesta 0 (EXITO) -1 (ERROR)
 */
int pub_pausarPublicidad(Publicidad* array,int limite, int indice)
{
	int respuesta = -1;
	int opcion;

	utn_getNumero(&opcion,"\n¿Desea pausar la publicacion?\n1-Si\n2-No\n","Opcion invalida",1,2,2);
	if(opcion == 1 && array[indice].estado!=0)
	{
		array[indice].estado = 0;
		printf("\nPublicacion pausada exitosamente\n");
		respuesta = 0;
	}
	else if(opcion == 2)
	{
		printf("\nSalida sin modificaciones\n");
		respuesta = 0;
	}
	else if(array[indice].estado ==0)
	{
		printf("\nNo se puede pausar una publicacion ya en pausa\n");
	}


	return respuesta;
}
/*
 * Brief Modifica el estado de pausado a activo de una publicacion
 * param array Es el array donde està la publicacion
 * param limite Es el limite hasta donde busca la funcion
 * param indice Es el indice que busca en el array
 * return respuesta 0 (EXITO) -1 (ERROR)
 */
int pub_reanudarPublicidad(Publicidad* array,int limite, int indice)
{
	int respuesta = -1;
	int opcion;

	utn_getNumero(&opcion,"\n¿Desea reanudar la publicacion?\n1-Si\n2-No\n","Opcion invalida",1,2,2);
	if(opcion == 1 && array[indice].estado !=1)
	{
		array[indice].estado = 1;
		printf("\nPublicacion reanudada exitosamente\n");
		respuesta = 0;
	}
	else if(opcion == 2)
	{
		printf("\nSalida sin modificaciones\n");
		respuesta = 0;
	}
	else if(array[indice].estado == 1)
	{
		printf("\nPublicacion activa, no se puede reanudar\n");
	}


	return respuesta;
}
/*
 * Brief Lista las publicaciones de un cliente a traves del ID
 * param array es el array de las publicidades
 * param limite es el maximo numero posible del array
 * param valorBuscado es el ID del cliente que se busca en el array de publicidades
 * return respuesta 0 (EXITO) -1 (ERROR)
 */
int pub_listaPublicacionesCliente(Publicidad* array,int limite,int valorBuscado)
{
	int retorno = -1;
	int i;

	if(array != NULL && limite > 0 && valorBuscado >= 0)
	{
	for(i=0;i<limite;i++)
	{
		if(array[i].idCliente == valorBuscado && array[i].isEmpty!=1)
		{
			printf("\nID: %d -El texto del aviso es: %s -Rubro %s -Estado de la Publicacion: %d"
					,array[i].id,array[i].textoAviso,array[i].rubro,array[i].estado);
		}
	}
	retorno = 0;
	}
	return retorno;
}
















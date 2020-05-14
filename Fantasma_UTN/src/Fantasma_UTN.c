/*
 ============================================================================
 Name        : Fantasma_UTN.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

/*
 * >>>> CLASE 10 <<<<
 *
 * Desarrollar una aplicacion que permita gestionar una array de Ghosts
 *
 * Se debera poder realizar
 * 	ALTAS
 * 	BAJAS
 * 	MODIFICACIONES
 *
 * La aplicacion debera permitir ordenar el array por Nombre del cliente
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include "Ghost.h"
#include "utn.h"

#define CANTIDAD_GHOST 4

int main(void) {

	Ghost arrayGhosts[CANTIDAD_GHOST];
	int idGhosts=0;
	int opcion;
	int auxiliarIndice;
	int auxiliarId;

	if(gho_inicializarArray(arrayGhosts,CANTIDAD_GHOST) == 0)
	{
		printf("Array inicializado correctamente. \n\n");
	}
	do
	{
		if(!utn_getNumero(	&opcion,
							"\n\n1.Cargar un Ghost"
							"\n2.Modificar un Ghosts"
							"\n3.Eliminar un Ghost"
							"\n4.Ordenar lista de Ghosts por nombre"
							"\n5.Imprimir lista Ghosts"
							"\n4.Ordenar lista de Ghosts por nombre y altura"
							"\n7.Salir\n\n",
							"\nError opcion invalida",1,7,2) )
		{
			switch(opcion)
			{
			case 1:
				auxiliarIndice = gho_getEmptyIndex(arrayGhosts,CANTIDAD_GHOST);
				if(auxiliarIndice >= 0)
				{
					if(gho_altaArray(arrayGhosts,CANTIDAD_GHOST,auxiliarIndice,&idGhosts) == 0)
					{
						printf("\nCarga realizada con exito\n");
					}
				}
				else
				{
					printf("\nNO HAY MAS LUGAR");
				}
				break;
			case 2:
				gho_imprimirArray(arrayGhosts,CANTIDAD_GHOST);
				if(utn_getNumero(&auxiliarId,"\nIndique el ID del cliente a modificar","\nID invalido",0,idGhosts,0) == 0)
				{
					auxiliarIndice = gho_buscarId(arrayGhosts,CANTIDAD_GHOST,auxiliarId);
					if(	auxiliarIndice >= 0 &&
						gho_modificarArray(arrayGhosts,CANTIDAD_GHOST,auxiliarIndice) == 0)
					{
						printf("\nModificacion realizada con exito\n");
					}
				}
				break;

			case 3:
				gho_imprimirArray(arrayGhosts,CANTIDAD_GHOST);
				if(utn_getNumero(&auxiliarId,"\nIndique el ID del cliente a eliminar","\nID invalido",0,idGhosts,0)==0)
				{
					auxiliarIndice = gho_buscarId(arrayGhosts,CANTIDAD_GHOST,auxiliarId);
					if(	auxiliarIndice >= 0 &&
						gho_bajaArray(arrayGhosts,CANTIDAD_GHOST,auxiliarIndice)== 0)
					{
						printf("\nBaja realizada con exito\n");
					}
				}
				break;
			case 4:
				gho_ordenarPorNombre(arrayGhosts,CANTIDAD_GHOST);
				break;

			case 5:
				gho_imprimirArray(arrayGhosts,CANTIDAD_GHOST);
				break;

			case 6:
				gho_ordenarPorNombre(arrayGhosts,CANTIDAD_GHOST);
				break;

			}
		}
	}while(opcion != 7);

	return EXIT_SUCCESS;
}

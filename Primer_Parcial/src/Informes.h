/*
 * Informes.h
 *
 *  Created on: 10 may. 2020
 *      Author: maximiliano
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include "Cliente.h"
#include "Publicidad.h"

int info_imprimirClientePublicacion(Publicidad* array,int limitePubli, int idPublicidad,Cliente* arrayCli, int limiteCli);
int info_imprimirClientesConPublicacionesActivas(Cliente* arrayCliente,int limiteCli,Publicidad* arrayPubli,int limitePubli);
int info_imprimirPublicacionesConCuit(Publicidad* arrayPub,int limitePub,Cliente* arrayCli,int limiteCli);
int info_clienteConMasPublicidadesActivas(Cliente* arrayCliente,int limiteCli,Publicidad* arrayPubli,int limitePubli);
int info_clienteConMasPublicidadesPausadas(Cliente* arrayCliente,int limiteCli,Publicidad* arrayPubli,int limitePubli);
int info_clienteConMasPublicidades(Cliente* arrayCliente,int limiteCli,Publicidad* arrayPubli,int limitePubli);
int info_cantidadDePublicacionesPorRubro(Publicidad* array, int limite);
int info_rubroConMasPublicidades(Publicidad* array,int limite);
int info_rubroConMenosPublicidades(Publicidad* array,int limite);

#endif /* INFORMES_H_ */

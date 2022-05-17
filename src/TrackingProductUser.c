/*
 * 		Tracking-Product.c
 *      Author: Martin Delgado
 */




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn_input.h"
#include "utn_operations.h"
#include "Product.h"
#include "Tracking.h"
#include "User.h"





int tpu_altaTrancking(int idProducto, int cantProduct,User* arrayUser, Tracking* arrayTrack)
{
	int rtn = -1;
	int indexTrack = -1;
	float segundosFloat;
	int segundosInt;

	if (idProducto >= 0 && arrayUser != NULL ){

		indexTrack = track_getEmptyIndex(arrayTrack, QTY_TRACKING);

		if (indexTrack >= 0) {

			utn_ruleofthree(10, 20, arrayTrack[indexTrack].distanciaKM, &segundosFloat);

			segundosInt = (int) segundosFloat;


			arrayTrack[indexTrack].distanciaKM = track_calcularKM(arrayUser->codPostal);
			arrayTrack[indexTrack].idUserFK = arrayUser->idUser;
			arrayTrack[indexTrack].idProductFK = idProducto;
			arrayTrack[indexTrack].cantComprar = cantProduct;
			arrayTrack[indexTrack].horaLlegada = utn_timeAdd(segundosInt);

			rtn = 0;


			track_print(arrayTrack, indexTrack);

		}
	}
	return rtn;
}
























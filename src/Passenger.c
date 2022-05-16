/*
 * 		Passenger.c
 *      Author: Martin Delgado
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Passenger.h"
#include "utn_input.h"
#include "utn_operations.h"


#define FALSE 0
#define TRUE 1

#define TYPE_1 0
#define TYPE_2 1



//	GET NEW ID
static int id = 1000;
static int addId(void);
static int addId(void) {
	return id++;
}


static const char TYPE_PASSENGER [][12] = {"", "JOVEN", "ADOLECENTE", "ADULTO"};
static const char STATUS_FLIGHT [][12] = {"", "ACTIVO", "INACTIVO"};



static void printHeader();




static void printHeader()
{
	printf("\n==============================================================================================");
	printf("\n %4s | %-15s | %-15s | %-15s | %10s | %8s | %8s", "ID", "LAST NAME", "NAME", "TYPE", "PRICE","FLYCODE", "STATUS");
	printf("\n==============================================================================================");
}


int printMenuYesOrNot(void)
{
	int rtn = 0;
	int option;

	if (!utn_getNumberInt(&option, "\n1. YES \n2. NO \n", ">> ERROR", 1, 2, 2)) {

		if (option == 1) {
			rtn = 1;
		}
	}
	return rtn;
}


int pass_getTypeString(Passenger* prod, char* pString)
{
	int rtn = -1;
	if (prod != NULL && prod->isEmpty == FALSE) {

		switch (prod->typePassenger) {

			case TYPE_1:
				strncpy(pString, "TYPE_1", 64);
				break;

			case TYPE_2:
				strncpy(pString, "TYPE_2", 64);
				break;
		}
		rtn = 0;
	}
	return rtn;
}


int pass_print(Passenger* prod, int indice)
{
	int rtn = -1;
//	char tipo[64];

	if (prod != NULL && prod->isEmpty == FALSE) {

//		prod_getTypeString(prod, tipo);
//		printf("\n%04d | %04d | %-15.*s | %-30.*s | %10.2f | %s",
//				indice,
//				prod->id,
//				15, prod->namePassenger,
//				30, prod->lastnamePassenger,
//				prod->pricePassenger,
//				TYPE_PASSENGER[prod->typePassenger]);



		printf("\n %04d | %-15.*s | %-15.*s | %-15.*s | %10.2f | %-8.*s | %-8.*s",
				prod->id,
				15, prod->lastnamePassenger,
				15, prod->namePassenger,
				15, TYPE_PASSENGER[prod->typePassenger],
				prod->pricePassenger,
				8, prod->flycode,
				8, STATUS_FLIGHT[prod->statusFlight]);


		rtn = 0;
	}
	return rtn;
}


int pass_printArray(Passenger* prod, int LEN)
{
	int rtn = -1;
	int i;

	if (prod != NULL && LEN > 0) {
		printHeader();
		for (i = 0; i < LEN; i++) {
			pass_print(&prod[i], i);
		}
		rtn = 0;
	}
	return rtn;
}


int pass_initArray(Passenger* arrayProductos, int LEN)
{
	int rtn = -1;
	int i;

	if (arrayProductos != NULL && LEN > 0) {
		for (i = 0; i < LEN; i++) {
			arrayProductos[i].isEmpty = TRUE;
		}
		rtn = 0;
	}
	return rtn;
}


int pass_createArray(Passenger* prod, int LEN, int index)
{
	int rtn = -1;
	Passenger buffer;

	if (prod != NULL && LEN > 0 && 0 <= index && index < LEN && prod[index].isEmpty == TRUE) {
		if (!pass_getDataCreate(&buffer, sizeof(buffer))) {
			//prod_print(buffer);
			buffer.isEmpty = FALSE;
			buffer.id = addId();
			prod[index] = buffer;
			rtn = 0;
		}
	}
	return rtn;
}

/**
 * \brief Actualiza un Cliente
 * \param prod Array de Producto a ser actualizado
 * \param LEN Limite del array
 * \param index Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int pass_updateArray(Passenger* prod, int LEN, int index)
{
	int rtn = -1;
	Passenger buffer;


	if (prod != NULL && LEN > 0 && 0 <= index && index < LEN && prod[index].isEmpty == FALSE) {
		buffer = prod[index];
		if (!pass_getDataUpdate(&buffer, sizeof(buffer))) {

			pass_print(&buffer, index);
			buffer.isEmpty = FALSE;
			buffer.id = prod[index].id;
			prod[index] = buffer;
			rtn = 0;
		}
	}
	return rtn;
}


int pass_deleteArray(Passenger* prod, int LEN, int index)
{
	int rtn = -1;

	if (prod != NULL && LEN > 0 && 0 <= index && index < LEN && prod[index].isEmpty == FALSE) {
		pass_print(&prod[index], index);
		prod[index].isEmpty = TRUE;
		rtn = 0;
	}
	return rtn;
}


int pass_getDataCreate(Passenger* prod, int LEN)
{
	int rtn = -1;
	Passenger buffer;

	if (prod != NULL && LEN > 0) {
		if (   !utn_getName(buffer.lastnamePassenger, "\nApellido: ", ">> ERROR", 2)
			&& !utn_getName(buffer.namePassenger, "Nombre: ", ">> ERROR", 2)
			&& !utn_getNumberInt(&buffer.typePassenger, "Tipo [1: JOVEN - 2: ADOLECENTE - 3: ADULTO]: ", ">> ERROR", 1, 3, 2)
			&& !utn_getNumberFloat(&buffer.pricePassenger, "Precio: ", ">> ERROR", 0, 1000000, 2)
			&& !utn_getDescription(buffer.flycode, "FlyCode: ", ">> ERROR", 2)
			&& !utn_getNumberInt(&buffer.statusFlight, "Status [1: ACTIVO - 2: INACTIVO]: ", ">> ERROR", 1, 2, 2)) {


			printf("\nAPELLIDO>> %s", buffer.lastnamePassenger);

			*prod = buffer;
			rtn = 0;
		}
	}
	return rtn;
}


int pass_getDataUpdate(Passenger* prod, int LEN)
{
	int rtn = -1;
	Passenger buffer;
	int option;
	int add = 0;

	if (prod != NULL && LEN > 0) {

		buffer = *prod;

		do {
			if (!utn_getNumberInt(&option, "\nINGRESE UNA OPCION: "
					"\n1. MODIFICAR APELLIDO"
					"\n2. MODIFICAR NOMBRE"
					"\n3. MODIFICAR TIPO"
					"\n4. MODIFICAR PRECIO"
					"\n5. MODIFICAR FLYCODE"
					"\n6. MODIFICAR STATUS\n", "OPCION INVALIDA", 1, 6, 2))
			{
				switch (option) {

					case 1:
						add++;
						if (!utn_getName(buffer.lastnamePassenger, "\nApellido: ", ">> ERROR", 2)) {
							add--;
						}
					break;


					case 2:
						add++;
						if (!utn_getName(buffer.namePassenger, "\nNombre: ", ">> ERROR", 2)) {
							add--;
						}
					break;


					case 3:
						add++;
						if (!utn_getNumberInt(&buffer.typePassenger, "\nTipo [1: JOVEN - 2: ADOLECENTE - 3: ADULTO]: ", ">> ERROR", 1, 3, 2)) {
							add--;
						}
					break;


					case 4:
						add++;
						if (!utn_getNumberFloat(&buffer.pricePassenger, "\nPrecio: ", ">> ERROR", 0, 1000000, 2)) {
							add--;
						}
					break;


					case 5:
						add++;
						if (!utn_getDescription(buffer.flycode, "\nFlyCode: ", "ERROR", 2)) {
							add--;
						}
					break;


					case 6:
						add++;
						if (!utn_getNumberInt(&buffer.statusFlight, "\nStatus [1: ACTIVO - 2: INACTIVO]: ", ">> ERROR", 1, 2, 2)) {
							add--;
						}
					break;




				}
			}
			printf("\nDESEA MODIFICAR UN CAMPO MAS? \n");


		} while (printMenuYesOrNot());



		if (add == 0) {
			*prod = buffer;
			rtn = 0;
		}

	}
	return rtn;
}


int pass_getEmptyIndex(Passenger* prod, int LEN)
{
	int rtn = -1;
	int i;

	if (prod != NULL && LEN > 0) {
		for (i = 0; i < LEN; i++) {
			if (prod[i].isEmpty == TRUE) {
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}


int pass_searchId(Passenger* prod, int LEN, int searchId)
{
	int rtn = -1;
	int i;

	if (prod != NULL && LEN > 0) {
		for (i = 0; i < LEN; i++) {
			if (prod[i].id == searchId) {
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}


int pass_loadForced(Passenger* prod, int LEN)
{
	int rtn = -1;
	Passenger buffer;

	if (prod != NULL && LEN > 0) {

		strncpy(buffer.lastnamePassenger, "Alderson", sizeof(buffer.lastnamePassenger));
		strncpy(buffer.namePassenger, "Elliot", sizeof(buffer.namePassenger));
		strncpy(buffer.flycode, "AA23201B", sizeof(buffer.flycode));
		buffer.typePassenger = 1;
		buffer.statusFlight = 1;
		buffer.pricePassenger = 10;
		buffer.isEmpty = FALSE;
		buffer.id = addId();
		prod[2] = buffer;

		strncpy(buffer.lastnamePassenger, "Alderson", sizeof(buffer.lastnamePassenger));
		strncpy(buffer.namePassenger, "Darlene", sizeof(buffer.namePassenger));
		strncpy(buffer.flycode, "AB23201B", sizeof(buffer.flycode));
		buffer.typePassenger = 2;
		buffer.statusFlight = 2;
		buffer.pricePassenger = 23;
		buffer.isEmpty = FALSE;
		buffer.id = addId();
		prod[3] = buffer;

		strncpy(buffer.lastnamePassenger, "Moss", sizeof(buffer.lastnamePassenger));
		strncpy(buffer.namePassenger, "Angela", sizeof(buffer.namePassenger));
		strncpy(buffer.flycode, "AC23201B", sizeof(buffer.flycode));
		buffer.typePassenger = 3;
		buffer.statusFlight = 1;
		buffer.pricePassenger = 75;
		buffer.isEmpty = FALSE;
		buffer.id = addId();
		prod[5] = buffer;

		strncpy(buffer.lastnamePassenger, "Wellick", sizeof(buffer.lastnamePassenger));
		strncpy(buffer.namePassenger, "Tyrell", sizeof(buffer.namePassenger));
		strncpy(buffer.flycode, "AD23201B", sizeof(buffer.flycode));
		buffer.typePassenger = 1;
		buffer.statusFlight = 2;
		buffer.pricePassenger = 15;
		buffer.isEmpty = FALSE;
		buffer.id = addId();
		prod[6] = buffer;

		strncpy(buffer.lastnamePassenger, "Price", sizeof(buffer.lastnamePassenger));
		strncpy(buffer.namePassenger, "Philip", sizeof(buffer.namePassenger));
		strncpy(buffer.flycode, "BA23201B", sizeof(buffer.flycode));
		buffer.typePassenger = 2;
		buffer.statusFlight = 1;
		buffer.pricePassenger = 44;
		buffer.isEmpty = FALSE;
		buffer.id = addId();
		prod[7] = buffer;

		strncpy(buffer.lastnamePassenger, "Goddard", sizeof(buffer.lastnamePassenger));
		strncpy(buffer.namePassenger, "Gideon", sizeof(buffer.namePassenger));
		strncpy(buffer.flycode, "BA23201B", sizeof(buffer.flycode));
		buffer.typePassenger = 3;
		buffer.statusFlight = 2;
		buffer.pricePassenger = 87;
		buffer.isEmpty = FALSE;
		buffer.id = addId();
		prod[8] = buffer;

		rtn = 0;
	}
	return rtn;
}


int pass_arrayBubbleShortOneField(Passenger* pArray, int LEN, char ASC_OR_DESC)
{
	int rtn = 1;
	int i = 0;
	int flagSwap;
	int newLen;
	Passenger buffer;

	if (pArray != NULL && LEN > 0) {
		rtn = 0;
		newLen = LEN - 1;


		switch (ASC_OR_DESC){


			case '<':	//DESCENDENTE
				do {
					flagSwap = 0;
					for (i = 0; i < newLen; i++) {

						if (pArray[i].isEmpty || pArray[i+1].isEmpty) continue;

						if (strncmp(pArray[i].namePassenger, pArray[i+1].namePassenger, NAME_LEN) < 0) {
							flagSwap = 1;
							buffer = pArray[i];
							pArray[i] = pArray[i+1];
							pArray[i+1] = buffer;
						}
					}
					newLen--;
				} while (flagSwap);
			break;


			case '>':	//ASCENDENTE
				do {
					flagSwap = 0;
					for (i = 0; i < newLen; i++) {

						if (pArray[i].isEmpty || pArray[i+1].isEmpty) continue;

						if (strncmp(pArray[i].namePassenger, pArray[i+1].namePassenger, NAME_LEN) > 0) {
							flagSwap = 1;
							buffer = pArray[i];
							pArray[i] = pArray[i+1];
							pArray[i+1] = buffer;
						}
					}
					newLen--;
				} while (flagSwap);
			break;
		}
	}
	return rtn;
}


int pass_arrayBubbleShortTwoField(Passenger* pArray, int LEN, char ASC_OR_DESC)
{
	int rtn = 1;
	int i = 0;
	int flagSwap;
	int newLen;
	Passenger buffer;

	if (pArray != NULL && LEN > 0) {
		rtn = 0;
		newLen = LEN - 1;


		switch (ASC_OR_DESC){


			case '<':	//DESCENDENTE
				do {
					flagSwap = 0;
					for (i = 0; i < newLen; i++) {

//						if (pArray[i].isEmpty || pArray[i+1].isEmpty) continue;											//NO USAR

						if (    strncmp(pArray[i].lastnamePassenger, pArray[i+1].lastnamePassenger, NAME_LEN) < 0

//							|| (strncmp(pArray[i].lastnamePassenger, pArray[i+1].lastnamePassenger, NAME_LEN) == 0		//OP1
//	 						&&  strncmp(pArray[i].namePassenger, pArray[i+1].namePassenger, NAME_LEN) < 0)				//OP1

	 						|| (strncmp(pArray[i].lastnamePassenger, pArray[i+1].lastnamePassenger, NAME_LEN) == 0		//OP2
							&&  pArray[i].typePassenger < pArray[i+1].typePassenger)									//OP2

							) {
							flagSwap = 1;
							buffer = pArray[i];
							pArray[i] = pArray[i+1];
							pArray[i+1] = buffer;
						}
					}
					newLen--;
				} while (flagSwap);
			break;


			case '>':	//ASCENDENTE
				do {
					flagSwap = 0;
					for (i = 0; i < newLen; i++) {

//						if (pArray[i].isEmpty || pArray[i+1].isEmpty) continue;											//NO USAR

						if (    strncmp(pArray[i].lastnamePassenger, pArray[i+1].lastnamePassenger, NAME_LEN) > 0

//							|| (strncmp(pArray[i].lastnamePassenger, pArray[i+1].lastnamePassenger, NAME_LEN) == 0		//OP1
//	 						&&  strncmp(pArray[i].namePassenger, pArray[i+1].namePassenger, NAME_LEN) > 0)				//OP1

	 						|| (strncmp(pArray[i].lastnamePassenger, pArray[i+1].lastnamePassenger, NAME_LEN) == 0		//OP2
							&&  pArray[i].typePassenger > pArray[i+1].typePassenger)									//OP2

							) {
							flagSwap = 1;
							buffer = pArray[i];
							pArray[i] = pArray[i+1];
							pArray[i+1] = buffer;
						}
					}
					newLen--;
				} while (flagSwap);
			break;
		}
	}
	return rtn;
}





//_____________________________________________________________________________________




float pass_priceTotal(Passenger* arrayProductos, int LEN)
{
	int rtn = -1;
	int i;
	float acc = 0;

	if (arrayProductos != NULL && LEN > 0) {
		for (i = 0; i < LEN; i++) {
			if (arrayProductos[i].isEmpty == FALSE) {
				acc = acc + arrayProductos[i].pricePassenger;
			}
		}
		rtn = acc;
	}
	return rtn;
}


int pass_contPromedioPassenger(Passenger* arrayProductos, int LEN, float promedio)
{
	int rtn = -1;
	int i;
	int acc = 0;

	if (arrayProductos != NULL && LEN > 0) {
		for (i = 0; i < LEN; i++) {
			if (arrayProductos[i].isEmpty == FALSE) {
				if (arrayProductos[i].pricePassenger >= promedio) {
					acc++;
				}
			}
		}
		rtn = acc;
	}
	return rtn;
}


int pass_arrayBubbleShortTwoFieldFlight(Passenger* pArray, int LEN, char ASC_OR_DESC)
{
	int rtn = 1;
	int i = 0;
	int flagSwap;
	int newLen;
	Passenger buffer;

	if (pArray != NULL && LEN > 0) {
		rtn = 0;
		newLen = LEN - 1;


		switch (ASC_OR_DESC){


			case '<':	//DESCENDENTE
				do {
					flagSwap = 0;
					for (i = 0; i < newLen; i++) {

//						if (pArray[i].isEmpty || pArray[i+1].isEmpty) continue;											//NO USAR

						if (    strncmp(pArray[i].flycode, pArray[i+1].flycode, NAME_LEN) < 0

//							|| (strncmp(pArray[i].lastnamePassenger, pArray[i+1].lastnamePassenger, NAME_LEN) == 0		//OP1
//	 						&&  strncmp(pArray[i].namePassenger, pArray[i+1].namePassenger, NAME_LEN) < 0)				//OP1

	 						|| (strncmp(pArray[i].flycode, pArray[i+1].flycode, NAME_LEN) == 0		//OP2
							&&  pArray[i].statusFlight < pArray[i+1].statusFlight)									//OP2

							) {
							flagSwap = 1;
							buffer = pArray[i];
							pArray[i] = pArray[i+1];
							pArray[i+1] = buffer;
						}
					}
					newLen--;
				} while (flagSwap);
			break;


			case '>':	//ASCENDENTE
				do {
					flagSwap = 0;
					for (i = 0; i < newLen; i++) {

//						if (pArray[i].isEmpty || pArray[i+1].isEmpty) continue;											//NO USAR

						if (    strncmp(pArray[i].flycode, pArray[i+1].flycode, NAME_LEN) > 0

//							|| (strncmp(pArray[i].lastnamePassenger, pArray[i+1].lastnamePassenger, NAME_LEN) == 0		//OP1
//	 						&&  strncmp(pArray[i].namePassenger, pArray[i+1].namePassenger, NAME_LEN) > 0)				//OP1

	 						|| (strncmp(pArray[i].flycode, pArray[i+1].flycode, NAME_LEN) == 0		//OP2
							&&  pArray[i].statusFlight > pArray[i+1].statusFlight)									//OP2

							) {
							flagSwap = 1;
							buffer = pArray[i];
							pArray[i] = pArray[i+1];
							pArray[i+1] = buffer;
						}
					}
					newLen--;
				} while (flagSwap);
			break;
		}
	}
	return rtn;
}














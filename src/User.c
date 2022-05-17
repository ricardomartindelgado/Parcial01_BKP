/*
 * 		User.c
 *      Author: Martin Delgado
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn_input.h"
#include "utn_operations.h"
#include "User.h"


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


static const char TYPE_USER_OR_ADMIN [][10] = {"", "ADMIN", "USER"};
//static const char COD_POSTAL [][12] = {"", "0001-1000", "1001-3000"};



static void printHeader();




static void printHeader()
{
	printf("\n=================================================================================================");
	printf("\n %4s | %-30s | %-30s | %-6s | %6s | %-20s", "ID", "ADDRESS", "EMAIL","TYPE", "POSTAL", "PASS");
	printf("\n=================================================================================================");
}


int user_printMenuYesOrNot(char* MSG)
{
	int rtn = 0;
	int option;

	printf("\n%s", MSG);
	if (!utn_getNumberInt(&option, "\n1. YES \n2. NO \n", ">> ERROR", 1, 2, 2)) {

		if (option == 1) {
			rtn = 1;
		}
	}
	return rtn;
}


int user_getTypeString(User* prod, char* pString)
{
	int rtn = -1;
	if (prod != NULL && prod->isEmpty == FALSE) {

		switch (prod->typeUserOrAdmin) {

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


int user_print(User* prod, int indice)
{
	int rtn = -1;

	if (prod != NULL && prod->isEmpty == FALSE) {

		printf("\n %04d | %-30.*s | %-30.*s | %-6.*s | %06d | %-20.*s",
				prod->idUser,
				30, prod->address,
				30, prod->email,
				6, TYPE_USER_OR_ADMIN[prod->typeUserOrAdmin],
				prod->codPostal,
				20, prod->password);

		rtn = 0;
	}
	return rtn;
}


int user_printArray(User* prod, int LEN)
{
	int rtn = -1;
	int i;

	if (prod != NULL && LEN > 0) {
		printHeader();
		for (i = 0; i < LEN; i++) {
			user_print(&prod[i], i);
		}
		rtn = 0;
	}
	return rtn;
}


int user_initArray(User* arrayProductos, int LEN)
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


int user_createArray(User* prod, int LEN, int index)
{
	int rtn = -1;
	User buffer;

	if (prod != NULL && LEN > 0 && 0 <= index && index < LEN && prod[index].isEmpty == TRUE) {
		if (!user_getDataCreate(&buffer, sizeof(buffer))) {
			//prod_print(buffer);
			buffer.isEmpty = FALSE;
			buffer.idUser = addId();
			prod[index] = buffer;
			rtn = 0;
		}
	}
	return rtn;
}


int user_updateArray(User* prod, int LEN, int index)
{
	int rtn = -1;
	User buffer;


	if (prod != NULL && LEN > 0 && 0 <= index && index < LEN && prod[index].isEmpty == FALSE) {
		buffer = prod[index];
		if (!user_getDataUpdate(&buffer, sizeof(buffer))) {

			user_print(&buffer, index);
			buffer.isEmpty = FALSE;
			buffer.idUser = prod[index].idUser;
			prod[index] = buffer;
			rtn = 0;
		}
	}
	return rtn;
}


int user_deleteArray(User* prod, int LEN, int index)
{
	int rtn = -1;

	if (prod != NULL && LEN > 0 && 0 <= index && index < LEN && prod[index].isEmpty == FALSE) {
		user_print(&prod[index], index);

		if (user_printMenuYesOrNot("DESEA CONTINUAR?")) {

			prod[index].isEmpty = TRUE;
			rtn = 0;
		}
	}
	return rtn;
}


int user_getDataCreate(User* prod, int LEN)
{
	int rtn = -1;
	User buffer;

	if (prod != NULL && LEN > 0) {
		if (   !utn_getDescription(buffer.address, "Direccion: ", ">> ERROR", 2)
			&& !utn_getNumberInt(&buffer.codPostal, "Cod Postal: ", ">> ERROR", 1, 9999, 2)) {


			*prod = buffer;
			rtn = 0;
		}
	}
	return rtn;
}


int user_getDataUpdate(User* prod, int LEN)
{
	int rtn = -1;
	User buffer;
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
						if (!utn_getName(buffer.address, "\nApellido: ", ">> ERROR", 2)) {
							add--;
						}
					break;


					case 2:
						add++;
						if (!utn_getName(buffer.email, "\nNombre: ", ">> ERROR", 2)) {
							add--;
						}
					break;


					case 3:
						add++;
						if (!utn_getNumberInt(&buffer.typeUserOrAdmin, "\nTipo [1: JOVEN - 2: ADOLECENTE - 3: ADULTO]: ", ">> ERROR", 1, 3, 2)) {
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
						if (!utn_getNumberInt(&buffer.codPostal, "\nStatus [1: ACTIVO - 2: INACTIVO]: ", ">> ERROR", 1, 2, 2)) {
							add--;
						}
					break;




				}
			}
			printf("\nDESEA MODIFICAR UN CAMPO MAS? \n");


		} while (user_printMenuYesOrNot(""));



		if (add == 0) {
			*prod = buffer;
			rtn = 0;
		}

	}
	return rtn;
}


int user_getEmptyIndex(User* prod, int LEN)
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


int user_searchId(User* prod, int LEN, int searchId)
{
	int rtn = -1;
	int i;

	if (prod != NULL && LEN > 0) {
		for (i = 0; i < LEN; i++) {
			if (prod[i].idUser == searchId) {
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}


int user_loadForced(User* prod, int LEN)
{
	int rtn = -1;
	User buffer;

	if (prod != NULL && LEN > 0) {

		strncpy(buffer.address, "California 23", sizeof(buffer.address));
		strncpy(buffer.email, "elliot@ecorp.com", sizeof(buffer.email));
		strncpy(buffer.password, "1234", sizeof(buffer.password));
		buffer.typeUserOrAdmin = 1;
		buffer.codPostal = 500;
		buffer.isEmpty = FALSE;
		buffer.idUser = addId();
		prod[2] = buffer;

		strncpy(buffer.address, "Uruguay 785", sizeof(buffer.address));
		strncpy(buffer.email, "darlene@ecorp.com", sizeof(buffer.email));
		strncpy(buffer.password, "5678", sizeof(buffer.password));
		buffer.typeUserOrAdmin = 2;
		buffer.codPostal = 1500;
		buffer.isEmpty = FALSE;
		buffer.idUser = addId();
		prod[4] = buffer;


		strncpy(buffer.address, "Madero 2345", sizeof(buffer.address));
		strncpy(buffer.email, "m@gmail.com", sizeof(buffer.email));
		strncpy(buffer.password, "1234", sizeof(buffer.password));
		buffer.typeUserOrAdmin = 2;
		buffer.codPostal = 3500;
		buffer.isEmpty = FALSE;
		buffer.idUser = addId();
		prod[6] = buffer;
//
//		strncpy(buffer.address, "Wellick", sizeof(buffer.address));
//		strncpy(buffer.email, "Tyrell", sizeof(buffer.email));
//		strncpy(buffer.flycode, "AD23201B", sizeof(buffer.flycode));
//		buffer.typeUserOrAdmin = 1;
//		buffer.codPostal = 2;
//		buffer.pricePassenger = 15;
//		buffer.isEmpty = FALSE;
//		buffer.idUser = addId();
//		prod[6] = buffer;
//
//		strncpy(buffer.address, "Price", sizeof(buffer.address));
//		strncpy(buffer.email, "Philip", sizeof(buffer.email));
//		strncpy(buffer.flycode, "BA23201B", sizeof(buffer.flycode));
//		buffer.typeUserOrAdmin = 2;
//		buffer.codPostal = 1;
//		buffer.pricePassenger = 44;
//		buffer.isEmpty = FALSE;
//		buffer.idUser = addId();
//		prod[7] = buffer;
//
//		strncpy(buffer.address, "Goddard", sizeof(buffer.address));
//		strncpy(buffer.email, "Gideon", sizeof(buffer.email));
//		strncpy(buffer.flycode, "BA23201B", sizeof(buffer.flycode));
//		buffer.typeUserOrAdmin = 3;
//		buffer.codPostal = 2;
//		buffer.pricePassenger = 87;
//		buffer.isEmpty = FALSE;
//		buffer.idUser = addId();
//		prod[8] = buffer;

		rtn = 0;
	}
	return rtn;
}


int user_arrayBubbleShortOneField(User* pArray, int LEN, char ASC_OR_DESC)
{
	int rtn = 1;
	int i = 0;
	int flagSwap;
	int newLen;
	User buffer;

	if (pArray != NULL && LEN > 0) {
		rtn = 0;
		newLen = LEN - 1;


		switch (ASC_OR_DESC){


			case '<':	//DESCENDENTE
				do {
					flagSwap = 0;
					for (i = 0; i < newLen; i++) {

						if (pArray[i].isEmpty || pArray[i+1].isEmpty) continue;

						if (strncmp(pArray[i].email, pArray[i+1].email, EMAIL_LEN) < 0) {
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

						if (strncmp(pArray[i].email, pArray[i+1].email, EMAIL_LEN) > 0) {
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


int user_arrayBubbleShortTwoField(User* pArray, int LEN, char ASC_OR_DESC)
{
	int rtn = 1;
	int i = 0;
	int flagSwap;
	int newLen;
	User buffer;

	if (pArray != NULL && LEN > 0) {
		rtn = 0;
		newLen = LEN - 1;


		switch (ASC_OR_DESC){


			case '<':	//DESCENDENTE
				do {
					flagSwap = 0;
					for (i = 0; i < newLen; i++) {

//						if (pArray[i].isEmpty || pArray[i+1].isEmpty) continue;											//NO USAR

						if (    strncmp(pArray[i].address, pArray[i+1].address, EMAIL_LEN) < 0

//							|| (strncmp(pArray[i].lastnamePassenger, pArray[i+1].lastnamePassenger, NAME_LEN) == 0		//OP1
//	 						&&  strncmp(pArray[i].namePassenger, pArray[i+1].namePassenger, NAME_LEN) < 0)				//OP1

	 						|| (strncmp(pArray[i].address, pArray[i+1].address, EMAIL_LEN) == 0		//OP2
							&&  pArray[i].typeUserOrAdmin < pArray[i+1].typeUserOrAdmin)									//OP2

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

						if (    strncmp(pArray[i].address, pArray[i+1].address, EMAIL_LEN) > 0

//							|| (strncmp(pArray[i].lastnamePassenger, pArray[i+1].lastnamePassenger, NAME_LEN) == 0		//OP1
//	 						&&  strncmp(pArray[i].namePassenger, pArray[i+1].namePassenger, NAME_LEN) > 0)				//OP1

	 						|| (strncmp(pArray[i].address, pArray[i+1].address, EMAIL_LEN) == 0		//OP2
							&&  pArray[i].typeUserOrAdmin > pArray[i+1].typeUserOrAdmin)									//OP2

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




float user_priceTotal(User* arrayProductos, int LEN)
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


int user_contPromedioPassenger(User* arrayProductos, int LEN, float promedio)
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


int user_arrayBubbleShortTwoFieldFlight(User* pArray, int LEN, char ASC_OR_DESC)
{
	int rtn = 1;
	int i = 0;
	int flagSwap;
	int newLen;
	User buffer;

	if (pArray != NULL && LEN > 0) {
		rtn = 0;
		newLen = LEN - 1;


		switch (ASC_OR_DESC){


			case '<':	//DESCENDENTE
				do {
					flagSwap = 0;
					for (i = 0; i < newLen; i++) {

//						if (pArray[i].isEmpty || pArray[i+1].isEmpty) continue;											//NO USAR

						if (    strncmp(pArray[i].flycode, pArray[i+1].flycode, EMAIL_LEN) < 0

//							|| (strncmp(pArray[i].lastnamePassenger, pArray[i+1].lastnamePassenger, NAME_LEN) == 0		//OP1
//	 						&&  strncmp(pArray[i].namePassenger, pArray[i+1].namePassenger, NAME_LEN) < 0)				//OP1

	 						|| (strncmp(pArray[i].flycode, pArray[i+1].flycode, EMAIL_LEN) == 0		//OP2
							&&  pArray[i].codPostal < pArray[i+1].codPostal)									//OP2

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

						if (    strncmp(pArray[i].flycode, pArray[i+1].flycode, EMAIL_LEN) > 0

//							|| (strncmp(pArray[i].lastnamePassenger, pArray[i+1].lastnamePassenger, NAME_LEN) == 0		//OP1
//	 						&&  strncmp(pArray[i].namePassenger, pArray[i+1].namePassenger, NAME_LEN) > 0)				//OP1

	 						|| (strncmp(pArray[i].flycode, pArray[i+1].flycode, EMAIL_LEN) == 0		//OP2
							&&  pArray[i].codPostal > pArray[i+1].codPostal)									//OP2

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
//
//	REGISTRO - LOGIN
//
//_____________________________________________________________________________________



int user_logInRegister(User* prod, int LEN, char* pEmail, char* pPass)
{
	int rtn = -1;
	int index;

	if (prod != NULL && LEN > 0 && pEmail != NULL && pPass != NULL) {

		if (!user_logInValidateRegister(prod, LEN, pEmail, pPass)) {

			index = user_getEmptyIndex(prod, LEN);

			if (index >= 0 ){

				if (!user_createArray(prod, LEN, index)){

					strncpy(prod[index].email, pEmail, sizeof(prod[index].email));
					strncpy(prod[index].password, pPass, sizeof(prod[index].password));

					rtn = 0;
				}
			}
		}
	}
	return rtn;
}


int user_logInValidateRegister(User* prod, int LEN, char* pEmail, char* pPass)
{
	int rtn = -1;
	int index;

	if (prod != NULL && LEN > 0 && pEmail != NULL && pPass != NULL) {

		if (!user_logInData(pEmail, pPass)) {

			if (user_validateEmail(prod, LEN, pEmail, &index)) {

					rtn = 0;
			}
		}
	}
	return rtn;
}


int user_logInValidateUser(User* prod, int LEN, char* pEmail, char* pPass)
{
	int rtn = -1;
	int index;

	if (prod != NULL && LEN > 0 && pEmail != NULL && pPass != NULL) {

		if (!user_logInData(pEmail, pPass)) {

			if (!user_validateEmail(prod, LEN, pEmail, &index)) {

				if (!user_validatePass(prod, LEN, pPass, index)) {

					rtn = 0;
				}

			} else printf("\n no salio bien");
		}
	}
	return rtn;
}


int user_logInData(char* pEmail,  char* pPass)
{
	int rtn = -1;

	if (pEmail != NULL && pPass != NULL) {

		if (   !utn_getEmail(pEmail, "\nINGRESE EMAIL: ", ">>ERROR: EMAIL INVALIDO", 2)
			&& !utn_getPass(pPass, "\nINGRESE PASS: ", ">>ERROR: PASS INVALIDA", 2)) {

			rtn = 0;
		}
	}
	return rtn;
}


int user_validateEmail(User* prod, int LEN, char* pEmail, int* index)
{
	int rtn = -1;
	int i;

	if (prod != NULL && LEN > 0 && pEmail != NULL && index > 0) {

		for (i = 0; i < LEN; i++) {

			if (prod[i].isEmpty == FALSE){

				if (!strcmp(prod[i].email, pEmail)) {

					*index = i;
					rtn = 0;
					break;
				}
			}
		}
	}
	return rtn;
}


int user_validatePass(User* prod, int LEN, char* pPass, int index)
{
	int rtn = -1;


	if (prod != NULL && LEN > 0 && pPass != NULL && index > 0) {

		if (!strcmp(prod[index].password, pPass)) {

			rtn = 0;
		}
	}
	return rtn;
}














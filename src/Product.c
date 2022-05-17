/*
 * 		User.c
 *      Author: Martin Delgado
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Product.h"
#include "User.h"
#include "utn_input.h"
#include "utn_operations.h"
#include "TrackingProductUser.h"


#define FALSE 0
#define TRUE 1

#define TYPE_1 0
#define TYPE_2 1



//	GET NEW ID
static int id = 1000;
static int addIdProduct(void);
static int addIdProduct(void) {
	return id++;
}



static const char TYPE_CATEGORY [][20] = {"", "1. VIDEOGAMES", "2. SMARTPHONE", "3. NOTEBOOK", "4. PC", "5. AUDIO", "6. VIDEO", "7. HOGAR", "8. SALUD"};
//static const char COD_POSTAL [][12] = {"", "0001-1000", "1001-3000"};



static void printHeader();




static void printHeader()
{
	printf("\n==========================================================================================");
	printf("\n %5s | %-15s | %-30s | %12s | %4s | %6s", "ID", "CATEGORY", "NOMBRE", "PRECIO","CANT", "VENDEDOR");
	printf("\n==========================================================================================");
}


int prod_printMenuYesOrNot(char* MSG)
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


int prod_print(Product* prod, int indice)
{
	int rtn = -1;

	if (prod != NULL && prod->isEmpty == FALSE) {

		printf("\n %05d | %-15.*s | %-30.*s | %12.2f | %4d | %6d",
				prod->idProduct,
				15, TYPE_CATEGORY[prod->typeCategory],
				30, prod->nameProduct,
				prod->priceProduct,
				prod->stockProduct,
				prod->idUserFK);

		rtn = 0;
	}
	return rtn;
}


int prod_printCategory(void)
{
	int rtn = -1;
	int i;

	printf("\n|    CATEGORY     |");
	printf("\n|-----------------|");
	for (i = 1; i <= QTY_CATEGORY; i++) {

		printf("\n| %-15s | ", TYPE_CATEGORY[i]);
		rtn = 0;
	}
	printf("\n");

	return rtn;
}


int prod_getTypeString(Product* prod, char* pString)
{
	int rtn = -1;
	if (prod != NULL && prod->isEmpty == FALSE) {

		switch (prod->typeCategory) {

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


int prod_printArray(Product* prod, int LEN)
{
	int rtn = -1;
	int i;

	if (prod != NULL && LEN > 0) {
		printHeader();
		for (i = 0; i < LEN; i++) {
			prod_print(&prod[i], i);
		}
		rtn = 0;
	}
	return rtn;
}


int prod_initArray(Product* arrayProductos, int LEN)
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


int prod_createArray(Product* prod, int LEN, int index)
{
	int rtn = -1;
	Product buffer;

	if (prod != NULL && LEN > 0 && 0 <= index && index < LEN && prod[index].isEmpty == TRUE) {
		if (!prod_getDataCreate(&buffer, sizeof(buffer))) {
			//prod_print(buffer);
			buffer.isEmpty = FALSE;
			buffer.idProduct = addIdProduct();
			prod[index] = buffer;
			rtn = 0;
		}
	}
	return rtn;
}


int prod_updateArray(Product* prod, int LEN, int index)
{
	int rtn = -1;
	Product buffer;


	if (prod != NULL && LEN > 0 && 0 <= index && index < LEN && prod[index].isEmpty == FALSE) {
		buffer = prod[index];
		if (!prod_getDataUpdate(&buffer, sizeof(buffer))) {

			prod_print(&buffer, index);
			buffer.isEmpty = FALSE;
			buffer.idProduct = prod[index].idProduct;
			prod[index] = buffer;
			rtn = 0;
		}
	}
	return rtn;
}


int prod_deleteArray(Product* prod, int LEN, int index)
{
	int rtn = -1;

	if (prod != NULL && LEN > 0 && 0 <= index && index < LEN && prod[index].isEmpty == FALSE) {
		prod_print(&prod[index], index);

		if (prod_printMenuYesOrNot("DESEA CONTINUAR?")) {

			prod[index].isEmpty = TRUE;
			rtn = 0;
		}
	}
	return rtn;
}


int prod_getDataCreate(Product* prod, int LEN)
{
	int rtn = -1;
	Product buffer;

	if (prod != NULL && LEN > 0) {
		if (   !utn_getNumberInt(&buffer.typeCategory, "\nCATEGORIA: ", ">>ERROR NO EXISTE LA CATEGORIA", 1, QTY_CATEGORY, 2)
			&& !utn_getDescription(buffer.nameProduct, "\nNOMBRE DEL PRODUCTO: ", ">> ERROR", 2)
			&& !utn_getNumberFloat(&buffer.priceProduct, "\nPRECIO: ", ">> ERROR", 1, PRICE_LEN, 2)
			&& !utn_getNumberInt(&buffer.stockProduct, "\nCANTIDAD: ", ">> ERROR", 1, STOCK_LEN, 2)) {


			*prod = buffer;
			rtn = 0;
		}
	}
	return rtn;
}


int prod_getDataUpdate(Product* prod, int LEN)
{
	int rtn = -1;
	Product buffer;
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
						if (!utn_getName(buffer.nameProduct, "\nApellido: ", ">> ERROR", 2)) {
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
						if (!utn_getNumberInt(&buffer.typeCategory, "\nTipo [1: JOVEN - 2: ADOLECENTE - 3: ADULTO]: ", ">> ERROR", 1, 3, 2)) {
							add--;
						}
					break;


					case 4:
						add++;
						if (!utn_getNumberFloat(&buffer.priceProduct, "\nPrecio: ", ">> ERROR", 0, 1000000, 2)) {
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
						if (!utn_getNumberInt(&buffer.stockProduct, "\nStatus [1: ACTIVO - 2: INACTIVO]: ", ">> ERROR", 1, 2, 2)) {
							add--;
						}
					break;




				}
			}
			printf("\nDESEA MODIFICAR UN CAMPO MAS? \n");


		} while (prod_printMenuYesOrNot(""));



		if (add == 0) {
			*prod = buffer;
			rtn = 0;
		}

	}
	return rtn;
}


int prod_getEmptyIndex(Product* prod, int LEN)
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


int prod_searchId(Product* prod, int LEN, int searchId)
{
	int rtn = -1;
	int i;

	if (prod != NULL && LEN > 0) {
		for (i = 0; i < LEN; i++) {
			if (prod[i].idProduct == searchId) {
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}


int prod_buyProduct(Product* prod, int LEN, int* idProduct, User* user, Tracking* track)
{
	int rtn = -1;

	int searchIdProduct = -1;
	int indexProduct = -1;
	int stockProduct = -1;
	int cantProduct = -1;
	float priceProductUnitario;
	float priceProductTotal;

	if (prod != NULL && LEN > 0) {

		if (!utn_getNumberInt(&searchIdProduct, "\n\nINGRESE ID DE PRODUCTO: ", ">>ERROR ID INVALIDO", 1000, 5000, 2)) {

			indexProduct = prod_searchId(prod, LEN, searchIdProduct);

			if (indexProduct >= 0) {

				stockProduct = prod[indexProduct].stockProduct;

				prod_print(&prod[indexProduct], indexProduct);
				printf("\nSTOCK %d", prod[indexProduct].stockProduct);

				if (stockProduct > 0) {
					if (!utn_getNumberInt(&cantProduct, "\nINGRESE CANT: ", ">>ERROR CANT", 1, stockProduct, 2)) {


						priceProductUnitario = prod[indexProduct].priceProduct;
						priceProductTotal = prod[indexProduct].priceProduct * cantProduct;

						printf("$%.2f [UNITARIO] x %d CANT = $%.2f PRECIO TOTAL", priceProductUnitario, cantProduct, priceProductTotal);



						if (prod_printMenuYesOrNot("DESEA CONTINUAR?")) {

							if (!tpu_altaTrancking(searchIdProduct, cantProduct,user, track)){

								prod[indexProduct].stockProduct = stockProduct - cantProduct;

								printf("\nSU COMPRA FUE REALIZADA CON EXITO");

								*idProduct = searchIdProduct;
								rtn = 0;

							}
						}
					}
				} else printf("\nNO QUEDA MAS STOCK");
			}
		}
	}
	return rtn;
}


float prod_buyProductPrice(Product* arrayProductos, int LEN)
{
	int rtn = -1;
	int i;
	float acc = 0;

	if (arrayProductos != NULL && LEN > 0) {
		for (i = 0; i < LEN; i++) {
			if (arrayProductos[i].isEmpty == FALSE) {
				acc = acc + arrayProductos[i].priceProduct;
			}
		}
		rtn = acc;
	}
	return rtn;
}


int prod_loadForced(Product* prod, int LEN)
{
	int rtn = -1;
	Product buffer;

	if (prod != NULL && LEN > 0) {


		//"1 VIDEOGAMES", "2 SMARTPHONE", "3 NOTEBOOK", "4 PC", "5 AUDIO", "6 VIDEO", "7 HOGAR", "8 SALUD"


		strncpy(buffer.nameProduct, "TV SMART 50", sizeof(buffer.nameProduct));
		buffer.typeCategory = 6;
		buffer.priceProduct = 50000;
		buffer.stockProduct = 2;
		buffer.isEmpty = FALSE;
		buffer.idProduct = addIdProduct();
		buffer.idUserFK = 1000;
		prod[2] = buffer;

		strncpy(buffer.nameProduct, "SAMSUNG S22 ULTRA", sizeof(buffer.nameProduct));
		buffer.typeCategory = 2;
		buffer.priceProduct = 150000;
		buffer.stockProduct = 4;
		buffer.isEmpty = FALSE;
		buffer.idProduct = addIdProduct();
		buffer.idUserFK = 1001;
		prod[4] = buffer;

		strncpy(buffer.nameProduct, "LENOVO YOGA 2", sizeof(buffer.nameProduct));
		buffer.typeCategory = 3;
		buffer.priceProduct = 130000;
		buffer.stockProduct = 3;
		buffer.isEmpty = FALSE;
		buffer.idProduct = addIdProduct();
		buffer.idUserFK = 1000;
		prod[6] = buffer;

		strncpy(buffer.nameProduct, "PC INTEL I5", sizeof(buffer.nameProduct));
		buffer.typeCategory = 4;
		buffer.priceProduct = 70000;
		buffer.stockProduct = 6;
		buffer.isEmpty = FALSE;
		buffer.idProduct = addIdProduct();
		buffer.idUserFK = 1001;
		prod[8] = buffer;

		strncpy(buffer.nameProduct, "SENNHEISER HD 202", sizeof(buffer.nameProduct));
		buffer.typeCategory = 5;
		buffer.priceProduct = 13000;
		buffer.stockProduct = 5;
		buffer.isEmpty = FALSE;
		buffer.idProduct = addIdProduct();
		buffer.idUserFK = 1002;
		prod[10] = buffer;

		strncpy(buffer.nameProduct, "COMODA 1.40X0.80", sizeof(buffer.nameProduct));
		buffer.typeCategory = 7;
		buffer.priceProduct = 50000;
		buffer.stockProduct = 3;
		buffer.isEmpty = FALSE;
		buffer.idProduct = addIdProduct();
		buffer.idUserFK = 1000;
		prod[12] = buffer;

		strncpy(buffer.nameProduct, "BARBIJO ADULTO", sizeof(buffer.nameProduct));
		buffer.typeCategory = 8;
		buffer.priceProduct = 70.50;
		buffer.stockProduct = 13;
		buffer.isEmpty = FALSE;
		buffer.idProduct = addIdProduct();
		buffer.idUserFK = 1001;
		prod[14] = buffer;

		strncpy(buffer.nameProduct, "TV SMART 42", sizeof(buffer.nameProduct));
		buffer.typeCategory = 6;
		buffer.priceProduct = 35000;
		buffer.stockProduct = 4;
		buffer.isEmpty = FALSE;
		buffer.idProduct = addIdProduct();
		buffer.idUserFK = 1002;
		prod[16] = buffer;

		strncpy(buffer.nameProduct, "SONY 1000XM4", sizeof(buffer.nameProduct));
		buffer.typeCategory = 5;
		buffer.priceProduct = 32000;
		buffer.stockProduct = 2;
		buffer.isEmpty = FALSE;
		buffer.idProduct = addIdProduct();
		buffer.idUserFK = 1000;
		prod[18] = buffer;

		strncpy(buffer.nameProduct, "TV SMART 60", sizeof(buffer.nameProduct));
		buffer.typeCategory = 6;
		buffer.priceProduct = 75000;
		buffer.stockProduct = 2;
		buffer.isEmpty = FALSE;
		buffer.idProduct = addIdProduct();
		buffer.idUserFK = 1001;
		prod[20] = buffer;

		strncpy(buffer.nameProduct, "SAMSUNG S20 FE", sizeof(buffer.nameProduct));
		buffer.typeCategory = 2;
		buffer.priceProduct = 78000;
		buffer.stockProduct = 4;
		buffer.isEmpty = FALSE;
		buffer.idProduct = addIdProduct();
		buffer.idUserFK = 1000;
		prod[22] = buffer;

		strncpy(buffer.nameProduct, "SAMSUNG S21 PLUS", sizeof(buffer.nameProduct));
		buffer.typeCategory = 2;
		buffer.priceProduct = 120000;
		buffer.stockProduct = 4;
		buffer.isEmpty = FALSE;
		buffer.idProduct = addIdProduct();
		buffer.idUserFK = 1002;
		prod[24] = buffer;

		strncpy(buffer.nameProduct, "ROCKET LEAGUE PC STEAM", sizeof(buffer.nameProduct));
		buffer.typeCategory = 1;
		buffer.priceProduct = 200;
		buffer.stockProduct = 4;
		buffer.isEmpty = FALSE;
		buffer.idProduct = addIdProduct();
		buffer.idUserFK = 1001;
		prod[26] = buffer;



		rtn = 0;
	}
	return rtn;
}


int prod_arrayBubbleShortOneField(Product* pArray, int LEN, char ASC_OR_DESC)
{
	int rtn = 1;
	int i = 0;
	int flagSwap;
	int newLen;
	Product buffer;

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


int prod_arrayBubbleShortTwoField(Product* pArray, int LEN, char ASC_OR_DESC)
{
	int rtn = 1;
	int i = 0;
	int flagSwap;
	int newLen;
	Product buffer;

	if (pArray != NULL && LEN > 0) {
		rtn = 0;
		newLen = LEN - 1;


		switch (ASC_OR_DESC){


			case '<':	//DESCENDENTE
				do {
					flagSwap = 0;
					for (i = 0; i < newLen; i++) {

//						if (pArray[i].isEmpty || pArray[i+1].isEmpty) continue;											//NO USAR

						if (    strncmp(pArray[i].nameProduct, pArray[i+1].nameProduct, EMAIL_LEN) < 0

//							|| (strncmp(pArray[i].lastnamePassenger, pArray[i+1].lastnamePassenger, NAME_LEN) == 0		//OP1
//	 						&&  strncmp(pArray[i].namePassenger, pArray[i+1].namePassenger, NAME_LEN) < 0)				//OP1

	 						|| (strncmp(pArray[i].nameProduct, pArray[i+1].nameProduct, EMAIL_LEN) == 0		//OP2
							&&  pArray[i].typeCategory < pArray[i+1].typeCategory)									//OP2

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

						if (    strncmp(pArray[i].nameProduct, pArray[i+1].nameProduct, EMAIL_LEN) > 0

//							|| (strncmp(pArray[i].lastnamePassenger, pArray[i+1].lastnamePassenger, NAME_LEN) == 0		//OP1
//	 						&&  strncmp(pArray[i].namePassenger, pArray[i+1].namePassenger, NAME_LEN) > 0)				//OP1

	 						|| (strncmp(pArray[i].nameProduct, pArray[i+1].nameProduct, EMAIL_LEN) == 0		//OP2
							&&  pArray[i].typeCategory > pArray[i+1].typeCategory)									//OP2

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




float prod_priceTotal(Product* arrayProductos, int LEN)
{
	int rtn = -1;
	int i;
	float acc = 0;

	if (arrayProductos != NULL && LEN > 0) {
		for (i = 0; i < LEN; i++) {
			if (arrayProductos[i].isEmpty == FALSE) {
				acc = acc + arrayProductos[i].priceProduct;
			}
		}
		rtn = acc;
	}
	return rtn;
}


int prod_contPromedioProduct(Product* arrayProductos, int LEN, float promedio)
{
	int rtn = -1;
	int i;
	int acc = 0;

	if (arrayProductos != NULL && LEN > 0) {
		for (i = 0; i < LEN; i++) {
			if (arrayProductos[i].isEmpty == FALSE) {
				if (arrayProductos[i].priceProduct >= promedio) {
					acc++;
				}
			}
		}
		rtn = acc;
	}
	return rtn;
}


int prod_arrayBubbleShortTwoFieldProduct(Product* pArray, int LEN, char ASC_OR_DESC)
{
	int rtn = 1;
	int i = 0;
	int flagSwap;
	int newLen;
	Product buffer;

	if (pArray != NULL && LEN > 0) {
		rtn = 0;
		newLen = LEN - 1;


		switch (ASC_OR_DESC){


			case '<':	//DESCENDENTE
				do {
					flagSwap = 0;
					for (i = 0; i < newLen; i++) {

//						if (pArray[i].isEmpty || pArray[i+1].isEmpty) continue;											//NO USAR

						if (    pArray[i].typeCategory < pArray[i+1].typeCategory

//							|| (strncmp(pArray[i].lastnamePassenger, pArray[i+1].lastnamePassenger, NAME_LEN) == 0		//OP1
//	 						&&  strncmp(pArray[i].namePassenger, pArray[i+1].namePassenger, NAME_LEN) < 0)				//OP1

	 						|| (pArray[i].typeCategory == pArray[i+1].typeCategory		//OP2
							&&  pArray[i].priceProduct < pArray[i+1].priceProduct)									//OP2

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

						if (    pArray[i].typeCategory > pArray[i+1].typeCategory

//							|| (strncmp(pArray[i].lastnamePassenger, pArray[i+1].lastnamePassenger, NAME_LEN) == 0		//OP1
//	 						&&  strncmp(pArray[i].namePassenger, pArray[i+1].namePassenger, NAME_LEN) < 0)				//OP1

	 						|| (pArray[i].typeCategory == pArray[i+1].typeCategory		//OP2
							&&  pArray[i].priceProduct > pArray[i+1].priceProduct)									//OP2

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



int prod_logInRegister(Product* prod, int LEN, char* pEmail, char* pPass)
{
	int rtn = -1;
	int index;

	if (prod != NULL && LEN > 0 && pEmail != NULL && pPass != NULL) {

		if (!prod_logInValidateRegister(prod, LEN, pEmail, pPass)) {

			index = prod_getEmptyIndex(prod, LEN);

			if (index >= 0 ){

				if (!prod_createArray(prod, LEN, index)){

					strncpy(prod[index].email, pEmail, sizeof(prod[index].email));
					strncpy(prod[index].password, pPass, sizeof(prod[index].password));

					rtn = 0;
				}
			}
		}
	}
	return rtn;
}


int prod_logInValidateRegister(Product* prod, int LEN, char* pEmail, char* pPass)
{
	int rtn = -1;
	int index;

	if (prod != NULL && LEN > 0 && pEmail != NULL && pPass != NULL) {

		if (!prod_logInData(pEmail, pPass)) {

			if (prod_validateEmail(prod, LEN, pEmail, &index)) {

					rtn = 0;
			}
		}
	}
	return rtn;
}


int prod_logInValidateUser(Product* prod, int LEN, char* pEmail, char* pPass)
{
	int rtn = -1;
	int index;

	if (prod != NULL && LEN > 0 && pEmail != NULL && pPass != NULL) {

		if (!prod_logInData(pEmail, pPass)) {

			if (!prod_validateEmail(prod, LEN, pEmail, &index)) {

				if (!prod_validatePass(prod, LEN, pPass, index)) {

					rtn = 0;
				}

			} else printf("\n no salio bien");
		}
	}
	return rtn;
}


int prod_logInData(char* pEmail,  char* pPass)
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


int prod_validateEmail(Product* prod, int LEN, char* pEmail, int* index)
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


int prod_validatePass(Product* prod, int LEN, char* pPass, int index)
{
	int rtn = -1;


	if (prod != NULL && LEN > 0 && pPass != NULL && index > 0) {

		if (!strcmp(prod[index].password, pPass)) {

			rtn = 0;
		}
	}
	return rtn;
}














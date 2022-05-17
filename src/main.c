/*
 ============================================================================
 Name        : Parcial 1 - MELI.c
 Author      : Martin Delgado
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "utn_operations.h"
#include "utn_input.h"
#include "User.h"
#include "Product.h"
#include "Tracking.h"
#include "TrackingProductUser.h"


int main(void) {
	setbuf(stdout, NULL); //Windows

//	system("title ADMINISTRACION DE PASAJEROS"); //Windows Console
//	system("mode 95,30"); //Windows Console




	User arrayUser[QTY_USERS];
	Product arrayProduct[QTY_PRODUCT];
	Tracking arrayTracking[QTY_TRACKING];


	int option;

	int typeUser;
	char pArrayEmail[50];
	char pArrayPass[50];


	int idUser = -1;
	int indexUser = -1;

	int idProduct = -1;
	int indexProduct = -1;

//	int idTracking = -1;
	int indexTracking = -1;


	printf("\n < SYSTEM MELI > \n");

	//	INICIALIZO USERS
	if (!user_initArray(arrayUser, QTY_USERS)) {
		printf("\n\nINICIALIZO USERS\n");
		user_loadForced(arrayUser, QTY_USERS);	//	DEBUG CARGA FORZADA
		user_printArray(arrayUser, QTY_USERS);
	} else printf("\nERROR - CONTACTE CON SOPORTE");



	//	INICIALIZO PRODUCT
	if (!prod_initArray(arrayProduct, QTY_PRODUCT)) {
		printf("\n\nINICIALIZO PRODUCT\n");
		prod_loadForced(arrayProduct, QTY_PRODUCT);	//	DEBUG CARGA FORZADA
		prod_printArray(arrayProduct, QTY_PRODUCT);
	} else printf("\nERROR - CONTACTE CON SOPORTE");



	//	INICIALIZO TRACKING
	if (!track_initArray(arrayTracking, QTY_TRACKING)) {
		printf("\n\nINICIALIZO PRODUCT\n");
		//prod_loadForced(arrayTracking, QTY_TRACKING);	//	DEBUG CARGA FORZADA
		//prod_printArray(arrayTracking, QTY_TRACKING);
	} else printf("\nERROR - CONTACTE CON SOPORTE");





	//	MENU LOGGING
	do {
		//REINTENTO SETEO EN 0 PORQUE EL DO-WHILE YA ME DA ESTE SERVICIO
		//SI NO VALIDO OPCION Y NO LA INICIALIZE PUEDE VENIR CARGADA CON BASURA
		if (!utn_getNumberInt(&option, "\n\n---MENU--- "
								"\n0. SALIR"
								"\n1. INGRESAR"
								"\n2. REGISTRARSE\n", ">>ERROR OPCION INVALIDA", 0, 2, 0)) {

			switch (option)	{


				case 1: // INGRESAR
					if (!user_logInValidateUser(arrayUser, QTY_USERS, pArrayEmail, pArrayPass)) {
						printf("\nINGRESAR OK\n");
//						printf("\nEMAIL: %s", pArrayEmail);
//						printf("\nEMAIL: %s", pArrayPass);

						// NO VALIDO PORQUE YA LO HICE EN user_logInValidateUser(), SOLO NECESITO EL INDEXUSER
						user_validateEmail(arrayUser, QTY_USERS, pArrayEmail, &indexUser);

						idUser = arrayUser[indexUser].idUser;
						typeUser = arrayUser[indexUser].typeUserOrAdmin;

//						printf("\nTipo %d: ", arrayUser[indexUser].typeUserOrAdmin);
//						printf("\nindexUser %d: ", indexUser);




						//===============================================================================================================
						//	VALIDO TIPO DE USUARIO USER
//						if (1) { //HARDCODEO USER
						if (typeUser == TYPE_USER) {

							printf("\nSOY USER TIPO %d", typeUser);

							//	MENU LOGGING
							do {
								if (!utn_getNumberInt(&option, "\n\n---MENU USUARIO--- "
														"\n0. SALIR"
														"\n1. COMPRAR"
														"\n2. VENDER"
														"\n3. ESTADO DE COMPRAS"
														"\n4. ESTADO DE VENTAS\n", ">>ERROR OPCION INVALIDA", 0, 4, 0)) {


									switch (option)	 {


										case 1: // COMPRAR - DESCONTAR DEL STOCK

											// ORDENO POR CATEGORIA Y PRECIO - IMPRIMO
											prod_arrayBubbleShortTwoFieldProduct(arrayProduct, QTY_PRODUCT, '>');
											prod_printArray(arrayProduct, QTY_PRODUCT);


											indexTracking = track_getEmptyIndex(arrayTracking, QTY_TRACKING);

											if (indexTracking >= 0) {


												if (!prod_buyProduct(arrayProduct, QTY_PRODUCT, &idProduct, &arrayUser[indexUser], &arrayTracking[indexTracking])) {

													printf("\nID PRODUCTO: %d", idProduct);

													track_printArray(arrayTracking, QTY_TRACKING);


												} else printf("\nERROR NO SE PUDO COMPLETAR LA OPERACION");
											}
										break;



										case 2: // VENDER - DAR DE ALTA UN PRODUCTO
											indexProduct = -1; // INICIALIZO EN UN VALOR DE ERROR POR SI SEARCH ID NO ENCUENTRA Y ME QUEDO EL INDEX CARGADO DE ANTES
											prod_printCategory();
											indexProduct = prod_getEmptyIndex(arrayProduct, QTY_PRODUCT);

											if (indexProduct >= 0) {
												prod_createArray(arrayProduct, QTY_PRODUCT, indexProduct);

												arrayProduct[indexProduct].idUserFK = idUser;

											} else printf("\nNO SE ENCONTRO ESE ID");
										break;



										case 3: // ESTADO DE COMPRAS

										break;



										case 4: // ESTADO DE VENTAS

										break;



									} // END SWITCH USER

								} // END OPTION MENU USER
							} while (option != 0);
						} // END IF TYPE_USER


						//	OPTION LE CAMBIO EL 0 POR OTRO VALOR PARA QUE NO SALGA DEL MENU INGRESAR - REGISTRARSE
						option = 11;

						//===============================================================================================================
						//	VALIDO TIPO DE USUARIO ADMIN
//						if (1) { //HARDCODEO USER
						if (typeUser == TYPE_ADMIN) {

							printf("\nSOY ADMIN TIPO %d", typeUser);

							//	MENU LOGGING
							do {
								if (!utn_getNumberInt(&option, "\n\n---MENU ADMIN--- "
														"\n0. SALIR"
														"\n1. LISTAR ESTADO DE TODOS LOS USUARIOS"
														"\n2. LISTAR TODOS LOS PRODUCTOS POR CATEGORIA"
														"\n3. BAJA DE PRODUCTO"
														"\n4. BAJA DE UN USUARIO"
														"\n5. VER TRACKING GLOBAL\n", ">>ERROR OPCION INVALIDA", 0, 4, 0)) {


									switch (option)	 {


//									A. LISTAR ESTADO DE TODOS LOS USUARIOS: Listar ID - CORREO - ESTADO de todos los
//									usuarios.
//									B. LISTAR TODOS LOS PRODUCTOS POR CATEGORÍA: Listado de todos los productos dados de
//									alta que se encuentran con stock en nuestro sistema. Ordenados por categoría y nombre.
//									C. BAJA DE UN PRODUCTO: Se listan los productos activos en nuestro sistema y por medio del ID se
//									dará de baja.
//									D. BAJA DE UN USUARIO: Se listan los usuarios activos en nuestro sistema y por medio del ID se dará
//									de baja.
//									E. VER TRACKING GLOBAL: Se listará la siguiente información: ID de tracking - ESTADO en el que
//									se encuentra - ID de comprador - ID de vendedor.




										case 1: // LISTAR ESTADO DE TODOS LOS USUARIOS
											user_printArray(arrayUser, QTY_USERS);


										break;



										case 2: // LISTAR TODOS LOS PRODUCTOS POR CATEGORIA
											prod_arrayBubbleShortTwoFieldProduct(arrayProduct, QTY_PRODUCT, '>');
											prod_printArray(arrayProduct, QTY_PRODUCT);

										break;


										case 3: // BAJA DE PRODUCTO
											indexProduct = -1; // INICIALIZO EN UN VALOR DE ERROR POR SI SEARCH ID NO ENCUENTRA Y ME QUEDO EL INDEX CARGADO DE ANTES
											if (!utn_getNumberInt(&idProduct, "\n\nINGRESE ID DE PRODUCTO: ", ">>ERROR ID INVALIDO", 1000, 5000, 2)) {

												indexProduct = prod_searchId(arrayProduct, QTY_PRODUCT, idProduct);

												if (indexProduct >= 0) {
													if (!prod_deleteArray(arrayProduct, QTY_PRODUCT, indexProduct)) {
														printf("\nSE BORRO EL PRODUCTO CON ID %d", idProduct);

													} else printf("\nNO SE BORRO EL PRODUCTO CON ID %d", idProduct);
												} else printf("\nNO SE ENCONTRO ESE ID");
											}
										break;



										case 4: // BAJA DE UN USUARIO
											indexUser = -1; // INICIALIZO EN UN VALOR DE ERROR POR SI SEARCH ID NO ENCUENTRA Y ME QUEDO EL INDEX CARGADO DE ANTES
											if (!utn_getNumberInt(&idUser, "\n\nINGRESE ID DE USUARIO: ", ">>ERROR ID INVALIDO", 1000, 5000, 2)) {

												indexUser = user_searchId(arrayUser, QTY_USERS, idUser);

												//	ANTES VALIDO QUE NO SE PUEDA AUTO BORRAR UN ADMIN
												if (indexUser >= 0 && arrayUser[indexUser].typeUserOrAdmin != TYPE_ADMIN) {
													if (!user_deleteArray(arrayUser, QTY_USERS, indexUser)) {
														printf("\nSE BORRO EL USUARIO CON ID %d", idUser);

													} else printf("\nNO SE BORRO EL USUARIO CON ID %d", idUser);
												} else printf("\nNO SE ENCONTRO ESE ID O ES UN ADMIN");
											}




										break;

										case 5: // VER TRACKING GLOBAL

										break;


									} // END SWITCH ADMIN

								} // END OPTION MENU ADMIN

							} while (option != 0);

						} // END IF TYPE_ADMIN

						//	OPTION LE CAMBIO EL 0 POR OTRO VALOR PARA QUE NO SALGA DEL MENU INGRESAR - REGISTRARSE
						option = 11;

					} // END INGRESAR

					else printf("\nINGRESAR ERROR\n");
				break;



				case 2: // REGISTRARSE
					if (!user_logInRegister(arrayUser, QTY_USERS, pArrayEmail, pArrayPass)) {
						printf("\nREGISTRO OK\n");
						printf("\nEMAIL: %s", pArrayEmail);
						printf("\nEMAIL: %s", pArrayPass);
					}
					else printf("\nYA EXISTE ESTE USUARIO\n");
				break;

			} // END SWITCH INGRESAR - REGISTRARSE

			//user_printArray(arrayUser, QTY_USERS);

		} // END IF OPTION MENU INGRESAR - REGISTRARSE


	} while (option != 0);


	return EXIT_SUCCESS;
}



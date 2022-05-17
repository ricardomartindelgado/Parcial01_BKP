/*
 * 		User.h
 *      Author: Martin Delgado
 */

#ifndef PRODUCT_H_
#define PRODUCT_H_



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Product.h"
#include "Tracking.h"
#include "User.h"
#include "utn_input.h"
#include "utn_operations.h"
#include "TrackingProductUser.h"




#define QTY_PRODUCT 30
#define ID_PRODUCT_LEN 5000	//DEBERIA VALIDAR CANTIDAD DE PRODCUTOS
#define EMAIL_LEN 25
#define PASS_LEN_MAX 10
#define NAME_PRODUCT_LEN 51



#define FLYCODE_LEN 10		//NO NECESITO
#define QTY_CATEGORY 8
#define PRICE_LEN 10000000
#define STOCK_LEN 100



typedef struct {
	char email[EMAIL_LEN];//
	char password[PASS_LEN_MAX];//
	char flycode[FLYCODE_LEN];	//NO NECESITO
	
	
	int idUserFK;

	char nameProduct[NAME_PRODUCT_LEN];
	int typeCategory;
	float priceProduct;
	int stockProduct;

	int isEmpty;
	int idProduct;
}Product;



int prod_printMenuYesOrNot(char* MSG);


/**
 * \brief Imprime las categorias
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int prod_printCategory(void);

/**
 * \brief Imprime un prodente del array
 * \param prod Array de Producto a ser actualizado
 * \param LEN Limite del array
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int prod_print(Product* prod, int indice);

/**
 * \brief Imprime una lista de Producto del array
 * \param prod Array de Producto a ser actualizado
 * \param LEN Limite del array
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int prod_printArray(Product* prod, int LEN);

/**
 * \brief Inicializa el campo isEmpty en vacio (TRUE)
 * \param prod Array de Producto a ser inicializado
 * \param LEN Limite del array
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int prod_initArray(Product* arrayProducto, int LEN);

/**
 * \brief Crea un Cliente
 * \param prod Array de Producto a ser creado
 * \param LEN Limite del array
 * \param index Posicion a ser creada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int prod_createArray(Product* prod, int LEN, int index);

/**
 * \brief Actualiza un Cliente
 * \param prod Array de Producto a ser actualizado
 * \param LEN Limite del array
 * \param index Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int prod_updateArray(Product* prod, int LEN, int index);

/**
 * \brief Borrar un Cliente
 * \param prod Array de Producto a ser borrado
 * \param LEN Limite del array
 * \param index Posicion a ser borrada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int prod_deleteArray(Product* prod, int LEN, int index);

/**
 * \brief Obtiene campos de una posicion del array
 * \param prod Array de Producto a ser actualizado
 * \param LEN Limite del array
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int prod_getDataCreate(Product* prod, int LEN);

/**
 * \brief Obtiene campos de una posicion del array
 * \param prod Array de Producto a ser actualizado
 * \param LEN Limite del array
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int prod_getDataUpdate(Product* prod, int LEN);

/**
 * \brief Devueve por referencia un string del tipo
 * \param prod Producto para acceder al campo tipo
 * \param char Devuelve un string del tipo
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int prod_getTypeString(Product* prod, char* pString);

/**
 * \brief Buscar primer posicion vacia del array
 * \param prod Array de Producto
 * \param LEN Limite del array
 * \return Retorna el indice de la posicion vacia >= 0 (EXITO) y -1 (ERROR)
 */
int prod_getEmptyIndex(Product* prod, int LEN);

/**
 * \brief Buscar un ID
 * \param prod Array de Producto
 * \param LEN Limite del array
 * \return Retorna el indice del ID >= 0 (EXITO) y -1 (ERROR)
 */
int prod_searchId(Product* prod, int LEN, int searchId);

/**
 * \brief Compra un producto
 * \param prod Array de Producto
 * \param LEN Limite del array
 * \return Retorna el indice del ID >= 0 (EXITO) y -1 (ERROR)
 */
int prod_buyProduct(Product* prod, int LEN, int* idProduct, User* user, Tracking* track);

/**
 * \brief Carga forzada de Producto
 * \param prod Array de Producto
 * \param LEN Limite del array
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int prod_loadForced(Product* prod, int LEN);

/**
 * \brief Ordena por campo Nombre
 * \param pArray Array de Producto
 * \param LEN Limite del array
 * \param ASC_OR_DESC Ordena por criterio ('>') Ascendente o ('<') Descendente
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int prod_arrayBubbleShortOneField(Product* pArray, int LEN, char ASC_OR_DESC);

/**
 * \brief Ordena por campo Nombre, en caso de ser igual por el siguiente campo
 * \param pArray Array de Producto
 * \param LEN Limite del array
 * \param ASC_OR_DESC Ordena por criterio ('>') Ascendente o ('<') Descendente
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int prod_arrayBubbleShortTwoField(Product* pArray, int LEN, char ASC_OR_DESC);




//_____________________________________________________________________________________



/**
 * \brief Calcula la suma de precio de todos los pasajeros
 * \param prod Array de Producto a calcular
 * \param LEN Limite del array
 * \return Retorna la suma de precios de todos los pasajero >= 0 (EXITO) y -1 (ERROR)
 */
float prod_priceTotal(Product* arrayProductos, int LEN);

/**
 * \brief Calcula la cantidad de pasajeros que superan el promedio de precio
 * \param prod Array de Producto a calcular
 * \param LEN Limite del array
 * \return Retorna la cantidad de pasajeros que superan el promedio de precio >= 0 (EXITO) y -1 (ERROR)
 */
int prod_contPromedioProduct(Product* arrayProductos, int LEN, float promedio);

/**
 * \brief Ordena por campo Nombre, en caso de ser igual por el siguiente campo
 * \param pArray Array de Producto
 * \param LEN Limite del array
 * \param ASC_OR_DESC Ordena por criterio ('>') Ascendente o ('<') Descendente
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int prod_arrayBubbleShortTwoFieldProduct(Product* pArray, int LEN, char ASC_OR_DESC);


//_____________________________________________________________________________________
//	USER


int prod_logInRegister(Product* prod, int LEN, char* pEmail, char* pPass);
int prod_logInValidateRegister(Product* prod, int LEN, char* pEmail, char* pPass);
int prod_logInValidateUser(Product* prod, int LEN, char* pEmail, char* pPass);
int prod_logInData(char* pEmail,  char* pPass);

int prod_validateEmail(Product* prod, int LEN, char* pEmail, int* index);
int prod_validatePass(Product* prod, int LEN, char* pPass, int index);













#endif /* PRODUCT_H_ */



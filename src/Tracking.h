/*
 * 		Tracking.h
 *      Author: Martin Delgado
 */

#ifndef TRACKING_H_
#define TRACKING_H_

#define QTY_TRACKING 30
#define ID_TRACKING_LEN 5000		//DEBERIA VALIDAR CANTIDAD DE TRACKING
#define EMAIL_LEN 25				//NO NECESITO
#define PASS_LEN_MAX 10			//NO NECESITO
#define NAME_TRACKING_LEN 51		//NO NECESITO



#define FLYCODE_LEN 10		//NO NECESITO
#define QTY_CATEGORY 8		//NO NECESITO
#define PRICE_LEN 10000000	//NO NECESITO
#define STOCK_LEN 100			//NO NECESITO



typedef struct {
	char email[EMAIL_LEN];					//NO NECESITO
	char password[PASS_LEN_MAX];			//NO NECESITO
	char flycode[FLYCODE_LEN];				//NO NECESITO
	char nameProduct[NAME_TRACKING_LEN]; 	//NO NECESITO
	


	float priceProduct;		//NO NECESITO
	int typeCategory;		//NO NECESITO



	int cantComprar;
	int distanciaKM;
	long int horaLlegada;


	int idUserFK;//
	int idProductFK;


	int isEmpty;
	int idTracking;
}Tracking;



int track_printMenuYesOrNot(char* MSG);


/**
 * \brief Imprime las categorias
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int track_printCategory(void);

/**
 * \brief Imprime un prodente del array
 * \param prod Array de Producto a ser actualizado
 * \param LEN Limite del array
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int track_print(Tracking* prod, int indice);

/**
 * \brief Imprime una lista de Producto del array
 * \param prod Array de Producto a ser actualizado
 * \param LEN Limite del array
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int track_printArray(Tracking* prod, int LEN);

/**
 * \brief Inicializa el campo isEmpty en vacio (TRUE)
 * \param prod Array de Producto a ser inicializado
 * \param LEN Limite del array
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int track_initArray(Tracking* arrayProducto, int LEN);

/**
 * \brief Crea un Cliente
 * \param prod Array de Producto a ser creado
 * \param LEN Limite del array
 * \param index Posicion a ser creada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int track_createArray(Tracking* prod, int LEN, int index);

/**
 * \brief Actualiza un Cliente
 * \param prod Array de Producto a ser actualizado
 * \param LEN Limite del array
 * \param index Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int track_updateArray(Tracking* prod, int LEN, int index);

/**
 * \brief Borrar un Cliente
 * \param prod Array de Producto a ser borrado
 * \param LEN Limite del array
 * \param index Posicion a ser borrada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int track_deleteArray(Tracking* prod, int LEN, int index);

/**
 * \brief Obtiene campos de una posicion del array
 * \param prod Array de Producto a ser actualizado
 * \param LEN Limite del array
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int track_getDataCreate(Tracking* prod, int LEN);

/**
 * \brief Obtiene campos de una posicion del array
 * \param prod Array de Producto a ser actualizado
 * \param LEN Limite del array
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int track_getDataUpdate(Tracking* prod, int LEN);

/**
 * \brief Devueve por referencia un string del tipo
 * \param prod Producto para acceder al campo tipo
 * \param char Devuelve un string del tipo
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int track_getTypeString(Tracking* prod, char* pString);

/**
 * \brief Buscar primer posicion vacia del array
 * \param prod Array de Producto
 * \param LEN Limite del array
 * \return Retorna el indice de la posicion vacia >= 0 (EXITO) y -1 (ERROR)
 */
int track_getEmptyIndex(Tracking* prod, int LEN);

/**
 * \brief Buscar un ID
 * \param prod Array de Producto
 * \param LEN Limite del array
 * \return Retorna el indice del ID >= 0 (EXITO) y -1 (ERROR)
 */
int track_searchId(Tracking* prod, int LEN, int searchId);

/**
 * \brief Compra un producto
 * \param prod Array de Producto
 * \param LEN Limite del array
 * \return Retorna el indice del ID >= 0 (EXITO) y -1 (ERROR)
 */
int track_buyProduct(Tracking* prod, int LEN, int* idProduct);

/**
 * \brief Compra un producto Precio
 * \param prod Array de Producto
 * \param LEN Limite del array
 * \return Retorna el indice del ID >= 0 (EXITO) y -1 (ERROR)
 */
float track_buyProductPrice(Tracking* arrayProductos, int LEN);
/**
 * \brief Carga forzada de Producto
 * \param prod Array de Producto
 * \param LEN Limite del array
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int track_loadForced(Tracking* prod, int LEN);

/**
 * \brief Ordena por campo Nombre
 * \param pArray Array de Producto
 * \param LEN Limite del array
 * \param ASC_OR_DESC Ordena por criterio ('>') Ascendente o ('<') Descendente
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int track_arrayBubbleShortOneField(Tracking* pArray, int LEN, char ASC_OR_DESC);

/**
 * \brief Ordena por campo Nombre, en caso de ser igual por el siguiente campo
 * \param pArray Array de Producto
 * \param LEN Limite del array
 * \param ASC_OR_DESC Ordena por criterio ('>') Ascendente o ('<') Descendente
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int track_arrayBubbleShortTwoField(Tracking* pArray, int LEN, char ASC_OR_DESC);




//_____________________________________________________________________________________



/**
 * \brief Calcula la suma de precio de todos los pasajeros
 * \param prod Array de Producto a calcular
 * \param LEN Limite del array
 * \return Retorna la suma de precios de todos los pasajero >= 0 (EXITO) y -1 (ERROR)
 */
float track_priceTotal(Tracking* arrayProductos, int LEN);

/**
 * \brief Calcula la cantidad de pasajeros que superan el promedio de precio
 * \param prod Array de Producto a calcular
 * \param LEN Limite del array
 * \return Retorna la cantidad de pasajeros que superan el promedio de precio >= 0 (EXITO) y -1 (ERROR)
 */
int track_contPromedioProduct(Tracking* arrayProductos, int LEN, float promedio);

/**
 * \brief Ordena por campo Nombre, en caso de ser igual por el siguiente campo
 * \param pArray Array de Producto
 * \param LEN Limite del array
 * \param ASC_OR_DESC Ordena por criterio ('>') Ascendente o ('<') Descendente
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int track_arrayBubbleShortTwoFieldTracking(Tracking* pArray, int LEN, char ASC_OR_DESC);


//_____________________________________________________________________________________
//	USER


int track_logInRegister(Tracking* prod, int LEN, char* pEmail, char* pPass);
int track_logInValidateRegister(Tracking* prod, int LEN, char* pEmail, char* pPass);
int track_logInValidateUser(Tracking* prod, int LEN, char* pEmail, char* pPass);
int track_logInData(char* pEmail,  char* pPass);

int track_validateEmail(Tracking* prod, int LEN, char* pEmail, int* index);
int track_validatePass(Tracking* prod, int LEN, char* pPass, int index);






int track_calcularKM(int codpostal);






#endif /* TRACKING_H_ */



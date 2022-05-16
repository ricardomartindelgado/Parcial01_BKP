/*
 * 		Passenger.h
 *      Author: Martin Delgado
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

#define QTY_PASSENGER 2000
#define ID_LEN 5000
#define NAME_LEN 51
#define LASTNAME_LEN 51
#define FLYCODE_LEN 10


typedef struct {
	char namePassenger[NAME_LEN];
	char lastnamePassenger[LASTNAME_LEN];
	float pricePassenger;
	int typePassenger;
	char flycode[FLYCODE_LEN];
	int statusFlight;

	int isEmpty;
	int id;
}Passenger;



int printMenuYesOrNot(void);
/**
 * \brief Imprime un prodente del array
 * \param prod Array de Producto a ser actualizado
 * \param LEN Limite del array
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int pass_print(Passenger* prod, int indice);

/**
 * \brief Imprime una lista de Producto del array
 * \param prod Array de Producto a ser actualizado
 * \param LEN Limite del array
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int pass_printArray(Passenger* prod, int LEN);

/**
 * \brief Inicializa el campo isEmpty en vacio (TRUE)
 * \param prod Array de Producto a ser inicializado
 * \param LEN Limite del array
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int pass_initArray(Passenger* arrayProducto, int LEN);

/**
 * \brief Crea un Cliente
 * \param prod Array de Producto a ser creado
 * \param LEN Limite del array
 * \param index Posicion a ser creada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int pass_createArray(Passenger* prod, int LEN, int index);

/**
 * \brief Actualiza un Cliente
 * \param prod Array de Producto a ser actualizado
 * \param LEN Limite del array
 * \param index Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int pass_updateArray(Passenger* prod, int LEN, int index);

/**
 * \brief Borrar un Cliente
 * \param prod Array de Producto a ser borrado
 * \param LEN Limite del array
 * \param index Posicion a ser borrada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int pass_deleteArray(Passenger* prod, int LEN, int index);

/**
 * \brief Obtiene campos de una posicion del array
 * \param prod Array de Producto a ser actualizado
 * \param LEN Limite del array
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int pass_getDataCreate(Passenger* prod, int LEN);

/**
 * \brief Obtiene campos de una posicion del array
 * \param prod Array de Producto a ser actualizado
 * \param LEN Limite del array
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int pass_getDataUpdate(Passenger* prod, int LEN);

/**
 * \brief Devueve por referencia un string del tipo
 * \param prod Producto para acceder al campo tipo
 * \param char Devuelve un string del tipo
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int pass_getTypeString(Passenger* prod, char* pString);

/**
 * \brief Buscar primer posicion vacia del array
 * \param prod Array de Producto
 * \param LEN Limite del array
 * \return Retorna el indice de la posicion vacia >= 0 (EXITO) y -1 (ERROR)
 */
int pass_getEmptyIndex(Passenger* prod, int LEN);

/**
 * \brief Buscar un ID
 * \param prod Array de Producto
 * \param LEN Limite del array
 * \return Retorna el indice del ID >= 0 (EXITO) y -1 (ERROR)
 */
int pass_searchId(Passenger* prod, int LEN, int searchId);

/**
 * \brief Carga forzada de Producto
 * \param prod Array de Producto
 * \param LEN Limite del array
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int pass_loadForced(Passenger* prod, int LEN);

/**
 * \brief Ordena por campo Nombre
 * \param pArray Array de Producto
 * \param LEN Limite del array
 * \param ASC_OR_DESC Ordena por criterio ('>') Ascendente o ('<') Descendente
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int pass_arrayBubbleShortOneField(Passenger* pArray, int LEN, char ASC_OR_DESC);

/**
 * \brief Ordena por campo Nombre, en caso de ser igual por el siguiente campo
 * \param pArray Array de Producto
 * \param LEN Limite del array
 * \param ASC_OR_DESC Ordena por criterio ('>') Ascendente o ('<') Descendente
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int pass_arrayBubbleShortTwoField(Passenger* pArray, int LEN, char ASC_OR_DESC);




//_____________________________________________________________________________________



/**
 * \brief Calcula la suma de precio de todos los pasajeros
 * \param prod Array de Producto a calcular
 * \param LEN Limite del array
 * \return Retorna la suma de precios de todos los pasajero >= 0 (EXITO) y -1 (ERROR)
 */
float pass_priceTotal(Passenger* arrayProductos, int LEN);

/**
 * \brief Calcula la cantidad de pasajeros que superan el promedio de precio
 * \param prod Array de Producto a calcular
 * \param LEN Limite del array
 * \return Retorna la cantidad de pasajeros que superan el promedio de precio >= 0 (EXITO) y -1 (ERROR)
 */
int pass_contPromedioPassenger(Passenger* arrayProductos, int LEN, float promedio);

/**
 * \brief Ordena por campo Nombre, en caso de ser igual por el siguiente campo
 * \param pArray Array de Producto
 * \param LEN Limite del array
 * \param ASC_OR_DESC Ordena por criterio ('>') Ascendente o ('<') Descendente
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int pass_arrayBubbleShortTwoFieldFlight(Passenger* pArray, int LEN, char ASC_OR_DESC);
#endif /* PASSENGER_H_ */



/*
 * 		User.h
 *      Author: Martin Delgado
 */

#ifndef USER_H_
#define USER_H_

#define QTY_USERS 10
#define ID_LEN 5000
#define EMAIL_LEN 25
#define PASS_LEN_MAX 10
#define ADDRESS_LEN 51


#define TYPE_ADMIN 1
#define TYPE_USER 2




#define FLYCODE_LEN 10		//NO NECESITO




typedef struct {
	char email[EMAIL_LEN];
	char password[PASS_LEN_MAX];
	char address[ADDRESS_LEN];
	
	
	float pricePassenger;		//NO NECESITO
	char flycode[FLYCODE_LEN];	//NO NECESITO
	
	
	int typeUserOrAdmin;
	int codPostal;

	int isEmpty;
	int idUser;
}User;



int user_printMenuYesOrNot(char* MSG);
/**
 * \brief Imprime un prodente del array
 * \param prod Array de Producto a ser actualizado
 * \param LEN Limite del array
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int user_print(User* prod, int indice);

/**
 * \brief Imprime una lista de Producto del array
 * \param prod Array de Producto a ser actualizado
 * \param LEN Limite del array
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int user_printArray(User* prod, int LEN);

/**
 * \brief Inicializa el campo isEmpty en vacio (TRUE)
 * \param prod Array de Producto a ser inicializado
 * \param LEN Limite del array
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int user_initArray(User* arrayProducto, int LEN);

/**
 * \brief Crea un Cliente
 * \param prod Array de Producto a ser creado
 * \param LEN Limite del array
 * \param index Posicion a ser creada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int user_createArray(User* prod, int LEN, int index);

/**
 * \brief Actualiza un Cliente
 * \param prod Array de Producto a ser actualizado
 * \param LEN Limite del array
 * \param index Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int user_updateArray(User* prod, int LEN, int index);

/**
 * \brief Borrar un Cliente
 * \param prod Array de Producto a ser borrado
 * \param LEN Limite del array
 * \param index Posicion a ser borrada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int user_deleteArray(User* prod, int LEN, int index);

/**
 * \brief Obtiene campos de una posicion del array
 * \param prod Array de Producto a ser actualizado
 * \param LEN Limite del array
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int user_getDataCreate(User* prod, int LEN);

/**
 * \brief Obtiene campos de una posicion del array
 * \param prod Array de Producto a ser actualizado
 * \param LEN Limite del array
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int user_getDataUpdate(User* prod, int LEN);

/**
 * \brief Devueve por referencia un string del tipo
 * \param prod Producto para acceder al campo tipo
 * \param char Devuelve un string del tipo
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int user_getTypeString(User* prod, char* pString);

/**
 * \brief Buscar primer posicion vacia del array
 * \param prod Array de Producto
 * \param LEN Limite del array
 * \return Retorna el indice de la posicion vacia >= 0 (EXITO) y -1 (ERROR)
 */
int user_getEmptyIndex(User* prod, int LEN);

/**
 * \brief Buscar un ID
 * \param prod Array de Producto
 * \param LEN Limite del array
 * \return Retorna el indice del ID >= 0 (EXITO) y -1 (ERROR)
 */
int user_searchId(User* prod, int LEN, int searchId);

/**
 * \brief Carga forzada de Producto
 * \param prod Array de Producto
 * \param LEN Limite del array
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int user_loadForced(User* prod, int LEN);

/**
 * \brief Ordena por campo Nombre
 * \param pArray Array de Producto
 * \param LEN Limite del array
 * \param ASC_OR_DESC Ordena por criterio ('>') Ascendente o ('<') Descendente
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int user_arrayBubbleShortOneField(User* pArray, int LEN, char ASC_OR_DESC);

/**
 * \brief Ordena por campo Nombre, en caso de ser igual por el siguiente campo
 * \param pArray Array de Producto
 * \param LEN Limite del array
 * \param ASC_OR_DESC Ordena por criterio ('>') Ascendente o ('<') Descendente
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int user_arrayBubbleShortTwoField(User* pArray, int LEN, char ASC_OR_DESC);




//_____________________________________________________________________________________



/**
 * \brief Calcula la suma de precio de todos los pasajeros
 * \param prod Array de Producto a calcular
 * \param LEN Limite del array
 * \return Retorna la suma de precios de todos los pasajero >= 0 (EXITO) y -1 (ERROR)
 */
float user_priceTotal(User* arrayProductos, int LEN);

/**
 * \brief Calcula la cantidad de pasajeros que superan el promedio de precio
 * \param prod Array de Producto a calcular
 * \param LEN Limite del array
 * \return Retorna la cantidad de pasajeros que superan el promedio de precio >= 0 (EXITO) y -1 (ERROR)
 */
int user_contPromedioPassenger(User* arrayProductos, int LEN, float promedio);

/**
 * \brief Ordena por campo Nombre, en caso de ser igual por el siguiente campo
 * \param pArray Array de Producto
 * \param LEN Limite del array
 * \param ASC_OR_DESC Ordena por criterio ('>') Ascendente o ('<') Descendente
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 */
int user_arrayBubbleShortTwoFieldFlight(User* pArray, int LEN, char ASC_OR_DESC);


//_____________________________________________________________________________________
//	USER


int user_logInRegister(User* prod, int LEN, char* pEmail, char* pPass);
int user_logInValidateRegister(User* prod, int LEN, char* pEmail, char* pPass);
int user_logInValidateUser(User* prod, int LEN, char* pEmail, char* pPass);
int user_logInData(char* pEmail,  char* pPass);

int user_validateEmail(User* prod, int LEN, char* pEmail, int* index);
int user_validatePass(User* prod, int LEN, char* pPass, int index);













#endif /* USER_H_ */



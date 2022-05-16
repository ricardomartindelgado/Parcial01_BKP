/*
 * 		utn_input.h
 *      Author: Martin Delgado
 */

#ifndef UTN_INPUT_H_
#define UTN_INPUT_H_


int isNumberInt(char* pString);
int isNumberFloat(char* pString);

//#################################################################################
// VALIDATE

/**
 * \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
 * \param pArray Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param MSG mensaje Es el mensaje a ser mostrado
 * \param MSG_ERROR mensajeError Es el mensaje de Error a ser mostrado
 * \param MIN minimo Es el numero maximo a ser aceptado
 * \param MAX maximo Es el minimo minimo a ser aceptado
 * \param RETRY reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_getNumberInt(int* pArray, char* MSG, char* MSG_ERROR, int MIN, int MAX, int RETRY);

/**
 * \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
 * \param pArray Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param MSG mensaje Es el mensaje a ser mostrado
 * \param MSG_ERROR mensajeError Es el mensaje de Error a ser mostrado
 * \param MIN minimo Es el numero maximo a ser aceptado
 * \param MAX maximo Es el minimo minimo a ser aceptado
 * \param RETRY reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_getNumberFloat(float* pArray, char* MSG, char* MSG_ERROR, float MIN, float MAX, int RETRY);

/**
 * \brief Solicita un nombre al usuario, luego de verificarlo devuelve el resultado
 * \param pArray Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param MSG mensaje Es el mensaje a ser mostrado
 * \param MSG_ERROR mensajeError Es el mensaje de Error a ser mostrado
 * \param RETRY reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_getName(char* pArray, char* MSG, char* MSG_ERROR, int RETRY);

/**
 * \brief Solicita una descripcion, luego de verificarlo devuelve el resultado
 * \param pArray Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param MSG mensaje Es el mensaje a ser mostrado
 * \param MSG_ERROR mensajeError Es el mensaje de Error a ser mostrado
 * \param RETRY reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_getDescription(char* pArray, char* MSG, char* MSG_ERROR, int RETRY);

/**
 * \brief Solicita un email, luego de verificarlo devuelve el resultado
 * \param pArray Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param MSG mensaje Es el mensaje a ser mostrado
 * \param MSG_ERROR mensajeError Es el mensaje de Error a ser mostrado
 * \param RETRY reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_getEmail(char* pArray, char* MSG, char* MSG_ERROR, int RETRY);

/**
 * \brief Solicita un password, luego de verificarlo devuelve el resultado
 * \param pArray Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param MSG mensaje Es el mensaje a ser mostrado
 * \param MSG_ERROR mensajeError Es el mensaje de Error a ser mostrado
 * \param RETRY reintentos Cantidad de reintentos
 * \return Retorna 0 si se obtuvo el numero y -1 si no
 */
int utn_getPass(char* pArray, char* MSG, char* MSG_ERROR, int RETRY);

//#################################################################################
//	IMPRIMIR











//#################################################################################
//	ARRAY







#endif /* UTN_INPUT_H_ */

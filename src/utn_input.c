/*
 * 		utn_input.c
 *      Author: Martin Delgado
 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define FALSE 1
#define TRUE 0


#define NAME_BUFFER_LEN 51
#define DESCRIPTION_BUFFER_LEN 101
#define EMAIL_BUFFER_LEN 51
#define MYGETS_BUFFER_LEN 4096


static int getInt(int* pArray);
static int getFloat(float* pArray);
static int getName(char* pArray);
static int getDescription(char* pArray);
static int getEmail(char* pArray);
static int getPass(char* pArray);

static int isNumberInt(char* pString);
static int isNumberFloat(char* pString);
static int isName(char* pString);
static int isDescription(char* pString);
static int isEmail(char* pString);
static int isPass(char* pString);

static int myGets(char* pString, int LEN);



int utn_getNumberInt(int* pArray, char* MSG, char* MSG_ERROR, int MIN, int MAX, int RETRY)
{
	int rtn = -1;
	int buffer;

	if (pArray != NULL && MSG != NULL && MSG_ERROR != NULL && MIN < MAX && RETRY >= 0) {
		do {
			printf("%s", MSG);

			if (!getInt(&buffer) && MIN <= buffer && buffer <= MAX) {
				*pArray = buffer;
				rtn = 0;
				break;
			}
			printf("%s >> Retry = %d \n", MSG_ERROR, RETRY);
			RETRY--;

		} while(RETRY >= 0);
	}
	return rtn;
}


static int getInt(int* pArray)
{
	int rtn = -1;
	char buffer[64];

	if (pArray != NULL) {
		if (!myGets(buffer,sizeof(buffer)) && isNumberInt(buffer)) {
			*pArray = atoi(buffer);
			rtn = 0;
		}
	}
	return rtn;
}


static int isNumberInt(char* pString)
{
	int rtn = 1;
	int i = 0;

	if (pString != NULL && strlen(pString) > 0) {
		if (pString[0] == '-' || pString[0] == '+') {
			i = 1;
		}
		for (	; pString[i] != '\0'; i++) {
			if (pString[i] < '0' || '9' < pString[i]) {
				rtn = 0;
				break;
			}
		}
	}
	return rtn;
}


int utn_getNumberFloat(float* pArray, char* MSG, char* MSG_ERROR, float MIN, float MAX, int RETRY)
{
	int rtn = -1;
	float buffer;

	if (pArray != NULL && MSG != NULL && MSG_ERROR != NULL && MIN < MAX && RETRY >= 0) {
		do {
			printf("%s", MSG);

			if (!getFloat(&buffer) && MIN <= buffer && buffer <= MAX) {
				*pArray = buffer;
				rtn = 0;
				break;
			}
			printf("%s >> Retry = %d \n", MSG_ERROR, RETRY);
			RETRY--;

		} while(RETRY >= 0);
	}
	return rtn;
}


static int getFloat(float* pArray)
{
	int rtn = -1;
	char buffer[64];

	if (pArray != NULL) {
		if (!myGets(buffer,sizeof(buffer)) && isNumberFloat(buffer)) {
			*pArray = atof(buffer);
			rtn = 0;
		}
	}
	return rtn;
}


static int isNumberFloat(char* pString)
{
	int rtn = 1;
	int i = 0;
	int stringLen = strlen(pString);
	int flagPoint = FALSE;

	if (pString != NULL && stringLen > 0) {

		/*
		 * CASOS:
		 * "." SOLO UNO Y NO AL FINAL = OK
		 * "ENTER"
		 * "-ENTER"
		 * "+ENTER"
		 * ".ENTER"
		 * "+.ENTER"
		 * "-.ENTER" = OK
		 * " " verificar espacio
		 * verificar la longitud i < stringLen - 1
		 */

		if (pString[0] == '-' || pString[0] == '+') {
			i = 1;
		}

		if (pString[0] == '\0') {
			rtn = 0;
		} else {
			for (	; pString[i] != '\0'; i++) {
				//	PREGUNTO POR FUERA DEL RANGO
				if (pString[i] < '0' || '9' < pString[i]) {
					if (pString[i] == '.' && i < stringLen - 1 && flagPoint == FALSE) {
						flagPoint = TRUE;
					} else {
						rtn = 0;
						break;
					}
				}
			}
		}
	}
	return rtn;
}


int utn_getName(char* pArray, char* MSG, char* MSG_ERROR, int RETRY)
{
	int rtn = -1;
	char buffer[64];

	if (pArray != NULL && MSG != NULL && MSG_ERROR != NULL && RETRY >= 0) {
		do {
			printf("%s", MSG);

			if (!getName(buffer)) {
				strcpy(pArray, buffer);
				rtn = 0;
				break;
			}
			printf("%s >> Retry = %d \n", MSG_ERROR, RETRY);
			RETRY--;

		} while(RETRY >= 0);
	}
	return rtn;
}


static int getName(char* pArray)
{
	int rtn = -1;
	char buffer[64];

	if (pArray != NULL) {
		if (!myGets(buffer,sizeof(buffer)) && isName(buffer)) {
			strcpy(pArray, buffer);
			rtn = 0;
		}
	}
	return rtn;
}



static int isName(char* pString)
{
	int rtn = 1;
	int i;

	if (pString != NULL && strlen(pString) > 0) {

		if (pString[0] < 'A' || 'Z' < pString[0] ) {
			return 0;
		}
		for (i = 1; pString[i] != '\0'; i++) {
			if (pString[i] < 'a' || 'z' < pString[i] ) {
				rtn = 0;
				break;
			}
		}
	}
	return rtn;
}


//static int isWord(char* pString)
//{
//	int rtn = 1;
//	int i;
//
//	if (pString != NULL && strlen(pString) > 0) {
//		for (i = 0; pString[i] != '\0'; i++) {
//			if ((pString[i] < 'a' || 'z' < pString[i]) && (pString[i] < 'A' || 'Z' < pString[i])) {
//				rtn = 0;
//				break;
//			}
//		}
//	}
//	return rtn;
//}


int utn_getDescription(char* pArray, char* MSG, char* MSG_ERROR, int RETRY)
{
	int rtn = -1;
	char buffer[64];

	if (pArray != NULL && MSG != NULL && MSG_ERROR != NULL && RETRY >= 0) {
		do {
			printf("%s", MSG);

			if (!getDescription(buffer)){
				strcpy(pArray, buffer);
				rtn = 0;
				break;
			}
			printf("%s >> Retry = %d \n", MSG_ERROR, RETRY);
			RETRY--;

		} while(RETRY >= 0);
	}
	return rtn;
}


static int getDescription(char* pArray)
{
	int rtn = -1;
	char buffer[64];

	if (pArray != NULL) {
		if (!myGets(buffer,sizeof(buffer)) && isDescription(buffer)) {
			strcpy(pArray, buffer);
			rtn = 0;
		}
	}
	return rtn;
}


static int isDescription(char* pString)
{
	int rtn = 1;
	int i;

	//	OPTION 1 ONLY CHARACTERS
	if (pString != NULL && strlen(pString) > 0) {
		for (i = 0; pString[i] != '\0'; i++){
			if (	(pString[i] < 'a' || 'z' < pString[i])
				&& 	(pString[i] < 'A' || 'Z' < pString[i])
				&& 	(pString[i] < '0' || '9' < pString[i])
				&&	pString[i] != ' '
				&& 	pString[i] != '.'
				&& 	pString[i] != ','
				&& 	pString[i] != ';'
				&& 	pString[i] != '-' ) {
				rtn = 0;
				break;
			}
		}
	}


//	//	OPTION 2 ALL CHARACTERS
//	if (pString != NULL && strlen(pString) > 0) {
//		for (i = 0; pString[i] != '\0'; i++){
//			if (	(pString[i] < 32 || 126 < pString[i]) ) {
//				rtn = 0;
//				break;
//			}
//		}
//	}
//


	return rtn;
}


int utn_getEmail(char* pArray, char* MSG, char* MSG_ERROR, int RETRY)
{
	int rtn = -1;
	char buffer[64];

	if (pArray != NULL && MSG != NULL && MSG_ERROR != NULL && RETRY >= 0) {
		do {
			printf("%s", MSG);

			if (!getEmail(buffer)){
				strcpy(pArray, buffer);
				rtn = 0;
				break;
			}
			printf("%s >> Retry = %d \n", MSG_ERROR, RETRY);
			RETRY--;

		} while(RETRY >= 0);
	}
	return rtn;
}


static int getEmail(char* pArray)
{
	int rtn = -1;
	char buffer[64];

	if (pArray != NULL) {
		if (!myGets(buffer,sizeof(buffer)) && isEmail(buffer)) {
			strcpy(pArray, buffer);
			rtn = 0;
		}
	}
	return rtn;
}


//	VERSION 4.1 ACEPTA NUMEROS ANTES DEL @ [VERSIONES ANTERIORES EN NOTE.H]
//	NOTA: SI VOLVISTE HASTA ACA ES PORQUE ALGO NO FUNCIONO
//	EN ESE CASO SOLO RECUERDA LA CANTIDAD DE HORAS QUE INVERTISTE EN ESTO
//	NO VALE LA PENA SEGUIR, CONFIA EN TU YO FUSTRADO DEL PASADO
static int isEmail(char* pString)
{
	int rtn = 1;
	int i;
	int saveIndexI;


	int punto = 0;
	int guionMedio = 0;
	int guionBajo = 0;
	int arroba = 0;


	char auxArray[65];


	//	INICIALIZO AUXARRAY CON ' '
	for (i = 0; i <= 64; i++)
	{
		auxArray[i] = ' ';
	}
	i = 0;

//	for (i = 0; i <= 64; i++)
//	{
//		printf("\nI: %d - C: %c", i, auxArray[i]);
//	}


	//	FORMATOS EMAIL A CONSIDERAR: . - _ @ <=1L . >=3L . >=2L

	if (pString != NULL && strlen(pString) > 0)
	{
		//	EVALUO PRIMERA POSICION QUE SEA UNA LETRA
		if ('a' <= pString[i]  && pString[i] <= 'z')
		{
			i++;

			//	CUENTO OCURRENCIAS ANTES DEL @
			for (	; pString[i] != '\0'; i++)
			{
				if ((pString[i] < 'a' || 'z' < pString[i]) && (pString[i] < '0' || '9' < pString[i]))
				{
					if (pString[i] == '.') {
						auxArray[i] = pString[i];
						punto++;
					}
					else if (pString[i] == '-')	 {
						auxArray[i] = pString[i];
						guionMedio++;

					}
					else if (pString[i] == '_')	 {
						auxArray[i] = pString[i];
						guionBajo++;
					}
					else if (pString[i] == '@')	 {
						auxArray[i] = pString[i];
						arroba++;
						break;
					}
					else {
						rtn = 0;
						break;
					}
				}
			}

//			printf("\n>>RTN: %d | I: %d | C: %c -- FOR 1 FUERA", rtn, i, pString[i]);
//			printf("\n>>P: %d | GM: %d | GB: %d | A: %d", punto, guionMedio, guionBajo, arroba);

			//	CUENTO OCURRENCIAS DESPUES DEL @ SOLO SI RTN SIGUE EN 1
			if (rtn == 1)
			{
				i++;
				for (	; pString[i] != '\0'; i++)
				{
					if (pString[i] < 'a' || 'z' < pString[i] )
					{
						if (pString[i] == '.') {
							auxArray[i] = pString[i];
							punto++;
						}
						else {
							rtn = 0;
							break;
						}
					}
				}
			}
			saveIndexI = i;
			auxArray[i] = '\0';


//			printf("\n>>RTN: %d | I: %d | C: %c -- FOR 2 FUERA", rtn, i, pString[i]);
//			printf("\n>>P: %d | GM: %d | GB: %d | A: %d", punto, guionMedio, guionBajo, arroba);
//			for (i = 0; auxArray[i] != '\0'; i++)
//			{
//				printf("\nI: %d - C: %c", i, auxArray[i]);
//			}



			//	EVALUO OCURRENCIAS
			if (rtn == 1
				&& 1 <= punto && punto <= 3
				&& guionMedio <= 1
				&& guionBajo <= 1
				&& arroba == 1)
			{

				for (i = 0; auxArray[i] != '\0'; i++)
				{
					//	EVALUO SI HAY UN . - _ @ QUE HAYA UNA LETRA ANTES Y DESPUES
					if (auxArray[i] != ' '){
						if ( 	((pString[i-1] < 'a' || 'z' < pString[i-1]) && (pString[i-1] < '0' || '9' < pString[i-1]))
							||	((pString[i+1] < 'a' || 'z' < pString[i+1]) && (pString[i+1] < '0' || '9' < pString[i+1]))	)
						{

							rtn = 0;
//							printf("\n>>RTN: %d | I: %d | C: %c -- I-1 - I+1", rtn, i, pString[i]);
//							printf("\n>>P: %d | GM: %d | GB: %d | A: %d", punto, guionMedio, guionBajo, arroba);
							break;
						}
					}
				}

				//	VALIDAR  gmail.com  gmail.com.ar
				//	CUENTO CANTIDAD DE PUNTOS DESDE EL FINAL HASTA @
				punto = 0;
				for (	; pString[saveIndexI] != '@'; saveIndexI--)
				{
					if (pString[saveIndexI] == '.'){
						punto++;
					}
				}


				i--;
				//	BUSCO .AR CON I-3 Y .COM.AR CON I-2 && I-6
				if (punto == 1 && pString[i-3] == '.')
				{

				} else if (punto == 2 && pString[i-2] == '.' && pString[i-6] == '.') {

				} else {
					rtn = 0;
				}


			}	//	EVALUO OCURRENCIAS
			else rtn = 0;

		}	//	EVALUO PRIMERA POSICION
		else rtn = 0;

	}	//	EVALUO STRING DISTINO DE NULL
	return rtn;
}


int utn_getPass(char* pArray, char* MSG, char* MSG_ERROR, int RETRY)
{
	int rtn = -1;
	char buffer[64];

	if (pArray != NULL && MSG != NULL && MSG_ERROR != NULL && RETRY >= 0) {
		do {
			printf("%s", MSG);

			if (!getPass(buffer)){
				strcpy(pArray, buffer);
				rtn = 0;
				break;
			}
			printf("%s >> Retry = %d \n", MSG_ERROR, RETRY);
			printf(">>PERMITIDOS: 'a-z', 'A-Z', '0-9', '!', '.', '-', '_', '@' , '#', '*', '/', '&' \n");
			RETRY--;

		} while(RETRY >= 0);
	}
	return rtn;
}


static int getPass(char* pArray)
{
	int rtn = -1;
	char buffer[64];

	if (pArray != NULL) {
		if (!myGets(buffer,sizeof(buffer)) && isPass(buffer)) {
			strcpy(pArray, buffer);
			rtn = 0;
		}
	}
	return rtn;
}


static int isPass(char* pString)
{
	int rtn = 1;
	int i;

	//printf("\n>>PERMITIDOS: 'a-z', 'A-Z', '0-9', '!', '.', '-', '_', '@' , '#', '*', '/', '&'");

	if (pString != NULL && strlen(pString) > 0) {
		for (i = 0; pString[i] != '\0'; i++){
			if (	(pString[i] < 'a' || 'z' < pString[i])
				&& 	(pString[i] < 'A' || 'Z' < pString[i])
				&& 	(pString[i] < '0' || '9' < pString[i])
				&&	pString[i] != '!'
				&& 	pString[i] != '.'
				&& 	pString[i] != '-'
				&& 	pString[i] != '_'
				&& 	pString[i] != '@'
				&& 	pString[i] != '#'
				&& 	pString[i] != '*'
				&& 	pString[i] != '/'
				&& 	pString[i] != '&') {
				rtn = 0;
				break;
			}
		}
	}
	return rtn;
}





static int myGets(char* pString, int LEN)
{
	int rtn = -1;
	char buffer[4096];

	fflush(stdin); //Windows
	//fpurge(stdin); //Mac
	//__fpurge(stdin); //Linux >> #include <stdio_ext.h>

	if (pString != NULL && LEN > 0 && fgets(buffer, sizeof(buffer), stdin) != NULL) {
		if (buffer[strnlen(buffer, sizeof(buffer))-1] == '\n') {
			buffer[strnlen(buffer, sizeof(buffer))-1] = '\0';
		}
		//printf("\n>>STRNLEN: %d  \n>>LEN: %d\n", strnlen(buffer, sizeof(buffer)),LEN);
		if (strnlen(buffer, sizeof(buffer)) <= LEN) {
			strncpy(pString, buffer, LEN);
			rtn = 0;
		}
	}
	return rtn;
}







//int menuYesOrNot(char* MSG, char* MSG_ERROR, int RETRY)
//{
//	int rtn = -1;
//	char buffer[64];
//
//	if (MSG != NULL && MSG_ERROR != NULL && RETRY >= 0) {
//		do {
//			printf("%s", MSG);
//
//			if (!getName(buffer)) {
//				buffer = toupper(buffer);
//
//				if (!strcmp("Y", buffer)) {
//					rtn = 1;
//					break;
//				}
//				if (!strcmp("N", buffer)) {
//					rtn = 0;
//					break;
//				}
//			}
//			printf("%s >> Retry = %d \n", MSG_ERROR, RETRY);
//			RETRY--;
//
//		} while(RETRY >= 0);
//	}
//	return rtn;
//}













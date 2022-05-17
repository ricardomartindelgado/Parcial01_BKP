/*
 * 		note.h
 *      Author: Smaythink
 */

#ifndef NOTE_H_
#define NOTE_H_



#endif /* NOTE_H_ */

/*

	TODO DEBUG TP02 FLYCODE EXPLOTA, no puedo restringir la cantidad de caractares
	no esta funcionando el myGet F*CK!!

		if (strnlen(buffer, sizeof(buffer)) <= LEN) {
			strncpy(pString, buffer, LEN);
			rtn = 0;


 	TODO prod_createArray DEBERIA TENER ADENTRO EL INDEX?
 	 https://youtu.be/VcU6cl1zqNU?t=4269

 	TODO prod_print
 	- PODRIA AGREGAR EL CAMPO IS EMPTY COMO PARAMETRO DE CRITERIO A FILTRAR
 	- PREGUNTAR SI ESTA SEGURO DE CARGAR LOS DATOS, PRINTEAR ANTES?

	TODO funcion validar email

	TODO isName validar primer elemento sea mayuscula OK
	TODO FALTAN DESARROLLAR
 	TODO CARGAR ARRAY
	TODO INICIALIZAR ARRAY EN UN VALOR
	TODO GENERAR UN SUBCONJUNTO DE ASCII CON EL RANGO QUE LE PASO
 	TODO FUNCION GET
	TODO FUNCION VALIDAR NUMERO FLOAT

	TODO FUNCION BURBUJEO CHECK CONTINUE
	TODO FUNCIONES VALIDAR CUIT, SOLO LETRAS
	TODO CONTAR PALABRAS
	TODO INGRESO EL RANGO Y ME DEVUELVE UN ARRAY CARGADO CON LOS ELEMENTOS




//		typedef struct {
//			int idUsuario;
//			int isEmpty;
//
//
//			char email[25];
//			char password[10];
//			char direccion[50];
//			int codigoPostal;
//		} Usuario;
//
//
//		typedef struct {
//			int idProducto;
//			int isEmpty;
//
//			int idUsuarioVentaFK;
//
//
//			char nameProduct[25];
//			float precio;
//			int categoria;
//			int stock;
//		} Producto;
//
//
//		typedef struct {
//			int idTracking;
//			int isEmpty;
//
//
//			int idProductoFK;
//			int idUsuarioCompraFK;
//			int idUsuarioVentaFK;
//
//
//			int cantidad;
//			int distanciaKM;
//			int horaLlegada;
//		} Tracking;




//		switch (option)	{
//
//
//			case 1: // COMPRAR
//
//			break;
//
//
//
//			case 2: // VENDER
//
//			break;
//
//
//			case 3: // ESTADO DE COMPRAS
//
//			break;
//
//
//
//			case 4: // ESTADO DE VENTAS
//
//			break;
//
//
//
//		} // END SWITCH




-------------------------------------------------------------------------

	REFACTORIZAR / REFACTORY

	SHORCUT: CTRL+SHIFT+R refactor rename>open rename dialog


	IMPORTANTE: siempre hacer refactor con un codigo que compile antes

	//	PASO 1
	copiar proyecto abierto con el main
	pegar proyecto
	cambiar nombre
	cerrar proyecto anterior
	buildear proyecto nuevo corrrer

	//	PASO 2
	cambiar nombre de entidad.h
	cambiar nombre de entidad.c

	//	PASO 3
	dentro de Cliente.h

	IMPORTANTE:
	verificar el preview que no cambie algo de la otra biblioteca

	renombrar la estructura
	cambiar campos
	cambiar el prefijo de la funcion una por una
	int cli_printArray(Cliente* cli, int LEN);

	cambiar nombre de los argumentos una por una
	ej arrayCliente por arrayProducto

	cambiar el nombre de la documentacion de la funcion
	es preferible usar reemplazar crtl+f


	//	PASO 5
	verificar el main
	cambiar nombre las variables, define



	//	OBSERVACIONES
	Name        : Clase11-Publicidades.c

	#include "Cliente.h"

	int cli_printArray(Cliente* cli, int LEN)
	int cli_initArray(Cliente* arrayClientes, int LEN)
	Cliente buffer;


-------------------------------------------------------------------------

CHEQUEAR
#ifdef _linux_
#define SO "Linux"
#define LIMPIAR_CONSOLA system("clear");
#define LIMPIAR_BUFFER __fpurge(stdin);
#include <stdio_ext.h>
#elif _WIN32
#define SO "Windows"
#define LIMPIAR_CONSOLA system("cls");
#define LIMPIAR_BUFFER fflush(stdin);
#define LIMPIAR_SALIDA	setbuf(stdout,NULL);
#elif _APPLE_
#define SO "OSX"
#define LIMPIAR_CONSOLA system("clear");
#define LIMPIAR_BUFFER fpurge(stdin);
#endif



 	FUNCION VALIDAR NUMERO FLOAT
	FOMATOS VALIDOS
	VALIDAR: -3.14; +3.14; .14;
 	NO VALIDAR: 3.1.3; ..2; 3a3; 314.


	'+'	PREGUNTO POR LA POSICION
	'.'	PREGUNTO POR LA CANTIDAD DE OCURRENCIAS



	utn_getTelefono
	utn_getDNI
	utn_getCUIT
	utn_getEmail
	utn_getTexto (letras y numeros)
	utn_getTexto (letras > nombre)


	isEmpty = 1;
	esta vacio? = verdadero


	ABM ALTA BAJA MDODIFICACION = (CRUD) create, read, update, and delete

 * ++VARIABLES
 * numero number num
 * acumulador accumulator acc
 * contador counter count
 * retorno return rtn
 * filtro filter
 * reintentos retry rtr
 * resultado output
 * cadena string str
 * inicializar initialize*
 * criterio criterion*
 * rango range
 * ordenar sort
 * regla de tres rule of three
 * campo field
 *
 *
 * ++FUNCIONES
 * Validate_OnlyNumberint()
 * Validate_OnlyAlphabet()
 * isDigit()
 * isNumber()
 * isChar()
 *
 * ++DEFINE
 * tamaño de buffer SIZE_BUFFER
 * largo lenght LEN
 * mensaje message MSG
 * mensaje de error error MSG_ERROR
 * cantidad quantity QTY



//#################################################################################



usuario
getNumerica numero razonble
{
getInt reemplaza el scanf
}


esNumerica valida numero
// llevan como nombre una pregunta devuelven verdadero o falso, no me indica error

getInt int valida
myGets string












//#################################################################################


//	NOTA MENTAL: CONSIDERAR SI TIENE SENTIDO
//	NO VALIDO NADA Y PUEDO HACER ESTO DIRECTAMENTE EN EL MAIN
//	DEBERIA VALIDAR QUE EL INGRESO Y EL RESULTADO DE LAS
//	OPERACIONES NO DESBORDE MI VARIABLE
//	int utn_sumarInt(int operador1, int operador2)
//	{
//		return operador1+operador2;
//	}
//
//	int utn_restarInt(int operador1, int operador2)
//	{
//		return operador1-operador2;
//	}
//
//	int utn_multiplicarInt(int operador1, int operador2)
//	{
//		return operador1*operador2;
//	}
 *
 *
 *


int utn_getInt(	int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo < maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			scanf("%d", &bufferInt);

			if(minimo <= bufferInt && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s >> Reintentos = %d \n", mensajeError, reintentos);
				reintentos --;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}



int utn_getFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno = -1;
	float bufferFloat;

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo < maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			scanf("%f", &bufferFloat);
			if(minimo <= bufferFloat && bufferFloat <= maximo)
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s >> Reintentos = %d \n", mensajeError, reintentos);
				reintentos --;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}



int utn_getChar(char* pResultado, char* mensaje, char* mensajeError, char minimo, int maximo, int reintentos)
{
	int retorno = -1;
	char bufferChar;

	if (pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo < maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin); //Windows
			//fpurge(stdin); //Mac
			//__fpurge(stdin); //Linux >> #include <stdio_ext.h>
			scanf("%c", &bufferChar);

			if(minimo <= bufferChar && bufferChar <= maximo)
			{
				*pResultado = bufferChar;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s >> Reintentos = %d \n", mensajeError, reintentos);
				reintentos --;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}





//#################################################################################
//	DEBUG

void utn_arrayCharPrint(char* pArray, int len, char* nameArray);
void utn_arrayCharInicializarUnValor(char* pArray, int len, char valor);
void utn_arrayIntPrint(int* pArray, int len, char* nameArray);
void utn_arrayIntInicializarUnValor(int* pArray, int len, int valor);
void utn_arrayIntInicializarUnValorAscendente(int* pArray, int len);
void utn_arrayFloatInicializarUnValor(float* pArray, int len, int valor);
void utn_arrayFloatInicializarUnValorAscendente(float* pArray, int len);





void utn_arrayCharPrint(char* pArray, int len, char* nameArray)
{
	for (int i = 0; i < len; i++)
	{
		printf("\n%s [%04d] = %c", nameArray, i, pArray[i]);
	}
	printf("\n");
}

void utn_arrayCharInicializarUnValor(char* pArray, int len, char valor)
{
	for (int i = 0; i < len; i++)
	{
		pArray[i] = valor;
	}
}


void utn_arrayIntPrint(int* pArray, int len, char* nameArray)
{
	for (int i = 0; i < len; i++)
	{
		printf("\n%s [%04d] = %d", nameArray, i, pArray[i]);
	}
	printf("\n");
}


void utn_arrayFloatPrint(float* pArray, int len, char* nameArray)
{
	for (int i = 0; i < len; i++)
	{
		printf("\n%s [%04d] = %f", nameArray, i, pArray[i]);
	}
	printf("\n");
}


void utn_arrayIntInicializarUnValor(int* pArray, int len, int valor)
{
	for (int i = 0; i < len; i++)
	{
		pArray[i] = valor;
	}
}


void utn_arrayIntInicializarUnValorAscendente(int* pArray, int len)
{
	for (int i = 0; i < len; i++)
	{
		pArray[i] = i;
	}
}

void utn_arrayFloatInicializarUnValor(float* pArray, int len, int valor)
{
	for (int i = 0; i < len; i++)
	{
		pArray[i] = valor;
	}
}


void utn_arrayFloatInicializarUnValorAscendente(float* pArray, int len)
{
	for (int i = 0; i < len; i++)
	{
		pArray[i] = i;
	}
}



















VALIDAR EMAIL


//	VERSION 4.0 NO FUNCIONA NO CARGA AUX ARRAY COMPLETAMENTE - ACEPTA NUMEROS ANTES DEL @
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


	fflush(stdin); //Windows
	//fpurge(stdin); //Mac
	//__fpurge(stdin); //Linux >> #include <stdio_ext.h>

	int i;
	for (i = 0; i <=64; i++)
	{
		printf("\n>>I: %02d - C: %c", i, auxArray[i]);
	}

	for (i = 0; i <= 64; i++)
	{

		auxArray[i] = '=';
		printf("\n>>I: %02d - C: %c", i, auxArray[i]);
	}

	for (i = 0; i <= 64; i++)
	{
		printf("\nI: %d - C: %c", i, auxArray[i]);
	}





	//	FORMATO EMAIL: . - _ @ <=1L . >=3L . >=2L

	if (pString != NULL && strlen(pString) > 0)
	{

		//	EVALUO PRIMERA POSICION
		if ('a' <= pString[i]  && pString[i] <= 'z')
		{
			i++;
			printf("\nESTOYYYYYYY");
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



			//	CUENTO OCURRENCIAS DESPUES DEL @
			for (	; pString[i] != '\0'; i++)
			{
				if (pString[i] < 'a' || 'z' < pString[i] )
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

			saveIndexI = i;
			auxArray[i+1] = '\0';


			for (i = 0; auxArray[i] != '\0'; i++)
			{
				printf("\nI: %d - C: %c", i, auxArray[i]);
			}



			//	EVALUO OCURRENCIAS
			if (rtn == 1
				&& 1 <= punto && punto <= 3
				&& guionMedio <= 1
				&& guionBajo <= 1
				&& arroba == 1)
			{
				for (; auxArray[i] != '\0'; i++)
				{
					if (auxArray[i] != '='){
						if ( 	(pString[i-1] < 'a' || 'z' < pString[i-1]) || (pString[i+1] < 'a' || 'z' < pString[i+1])
							||	(pString[i-1] < '0' || '9' < pString[i-1]) || (pString[i+1] < '0' || '9' < pString[i+1])	)
						{
							rtn = 0;
							break;
						}
					}
				}
			}
			else rtn = 0;
		}
		else rtn = 0;




		//	VALIDAR  gmail.com  gmail.com.ar
		//	CUENTO CANTIDAD DE PUNTOS HASTA @
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

	}
	return rtn;
}


//	VERSION 3.1 SIN PRINTF DEBUG FUNCIONA PERO TE VALIDA _ DESPUES DEL ARROBA Y NO ACEPTA NUMEROS
static int isEmail(char* pString)
{
	int rtn = 1;
	int i = 0;

	int punto = 0;
	int guionMedio = 0;
	int guionBajo = 0;
	int arroba = 0;

	//	FORMATO EMAIL: . - _ @ <=1L . >=3L . >=2L

	if (pString != NULL && strlen(pString) > 0)
	{

		//	EVALUO PRIMERA POSICION
		if ('a' <= pString[i]  && pString[i] <= 'z')
		{
			i++;

			//	CUENTO OCURRENCIAS
			for (	; pString[i] != '\0'; i++)
			{
				if (pString[i] < 'a' || 'z' < pString[i])
				{
					if (pString[i] == '.')
					{
						if ( (pString[i-1] < 'a' || 'z' < pString[i-1]) || (pString[i+1] < 'a' || 'z' < pString[i+1]))
						{
							rtn = 0;
							break;
						} else punto++;
					}
					else if (pString[i] == '-')
					{
						if ( (pString[i-1] < 'a' || 'z' < pString[i-1]) || (pString[i+1] < 'a' || 'z' < pString[i+1]))
						{
							rtn = 0;
							break;
						} else guionMedio++;

					}
					else if (pString[i] == '_')
					{
						if ( (pString[i-1] < 'a' || 'z' < pString[i-1]) || (pString[i+1] < 'a' || 'z' < pString[i+1]))
						{
							rtn = 0;
							break;
						} else guionBajo++;
					}
					else if (pString[i] == '@')
					{
						if ( (pString[i-1] < 'a' || 'z' < pString[i-1]) || (pString[i+1] < 'a' || 'z' < pString[i+1]))
						{
							rtn = 0;
							break;
						} else arroba++;
					}
					else {

						rtn = 0;
					}

				}
			}



			//	EVALUO OCURRENCIAS
			if (rtn == 1
				&& 1 <= punto && punto <= 3
				&& guionMedio <= 1
				&& guionBajo <= 1
				&& arroba == 1)
			{


			}
			else {
				rtn = 0;

			}

		}
		else {
			rtn = 0;
		}


		//	VALIDAR  gmail.com  gmail.com.ar
		//	CUENTO CANTIDAD DE PUNTOS HASTA @
		punto = 0;
		int j = i;
		for (	; pString[j] != '@'; j--)
		{
			if (pString[j] == '.'){
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

	}
	return rtn;
}







//	VERSION 3.0
static int isEmail(char* pString)
{
	int rtn = 1;
	int i = 0;

	int punto = 0;
	int guionMedio = 0;
	int guionBajo = 0;
	int arroba = 0;


	if (pString != NULL && strlen(pString) > 0)
	{
		//	FORMATO EMAIL: . - _ @ <=1L . >=3L . >=2L



		//	EVALUO PRIMERA POSICION
		if ('a' <= pString[i]  && pString[i] <= 'z')
		{
			i++;



			printf("\n>>RTN: %d | I: %d | C: %c -- FOR 1 ANTES", rtn, i, pString[i]);
			//	CUENTO OCURRENCIAS
			for (	; pString[i] != '\0'; i++)
			{
				printf("\n>>RTN: %d | I: %d | C: %c -- FOR 1 DENTRO", rtn, i, pString[i]);

				if (pString[i] < 'a' || 'z' < pString[i])
				{
					printf("\n>>RTN: %d | I: %d | C: %c -- FOR 1 DENTRO + IF", rtn, i, pString[i]);

					if (pString[i] == '.')
					{
						if ( (pString[i-1] < 'a' || 'z' < pString[i-1]) || (pString[i+1] < 'a' || 'z' < pString[i+1]))
						{
							rtn = 0;
							printf("\n>>RTN: %d | I: %d | C: %c -- '.' ", rtn, i, pString[i]);
							break;
						} else punto++;
					}
					else if (pString[i] == '-')
					{
						if ( (pString[i-1] < 'a' || 'z' < pString[i-1]) || (pString[i+1] < 'a' || 'z' < pString[i+1]))
						{
							rtn = 0;
							printf("\n>>RTN: %d | I: %d | C: %c -- '-' ", rtn, i, pString[i]);
							break;
						} else guionMedio++;

					}
					else if (pString[i] == '_')
					{
						if ( (pString[i-1] < 'a' || 'z' < pString[i-1]) || (pString[i+1] < 'a' || 'z' < pString[i+1]))
						{
							rtn = 0;
							printf("\n>>RTN: %d | I: %d | C: %c -- '-' ", rtn, i, pString[i]);
							break;
						} else guionBajo++;
					}
					else if (pString[i] == '@')
					{
						if ( (pString[i-1] < 'a' || 'z' < pString[i-1]) || (pString[i+1] < 'a' || 'z' < pString[i+1]))
						{
							rtn = 0;
							printf("\n>>RTN: %d | I: %d | C: %c -- '@' ", rtn, i, pString[i]);
							break;
						} else arroba++;
					}
					else {
						printf("\n>>RTN: %d | I: %d | C: %c -- IF 1 ELSE", rtn, i, pString[i]);
						rtn = 0;
					}

				}
			}


			printf("\n>>P: %d | GM: %d | GB: %d | A: %d", punto, guionMedio, guionBajo, arroba);

			//	EVALUO OCURRENCIAS
			if (rtn == 1
				&& 1 <= punto && punto <= 3
				&& guionMedio <= 1
				&& guionBajo <= 1
				&& arroba == 1)
			{


			}
			else {
				rtn = 0;
				printf("\n>>RTN: %d | I: %d | C: %c -- IF 2 ELSE", rtn, i, pString[i]);
			}


			printf("\n>>P: %d | GM: %d | GB: %d | A: %d", punto, guionMedio, guionBajo, arroba);
		}
		else {
			rtn = 0;
		}





		//	VALIDAR  gmail.com  gmail.com.ar
		//	CUENTO CANTIDAD DE PUNTOS HASTA @
		punto = 0;
		int j = i;
		for (	; pString[j] != '@'; j--)
		{
			if (pString[j] == '.'){
				punto++;
			}
		}

		printf("\n>>P: %d | GM: %d | GB: %d | A: %d VALIDAR CANT PUNTOS", punto, guionMedio, guionBajo, arroba);





		for (i = 0; pString[i] != '\0'; i++) {
			printf("\n>>RTN: %d | I: %d | C: %c", rtn, i, pString[i]);
		}

		printf("\nI: %d  C: %c ", i, pString[i]);
		printf("\nI-2: %d | C: %c \nI-6: %d | C: %c ", i-2, pString[i-2], i-6, pString[i-6]);



		i--;

		//	BUSCO .AR CON I-3 Y .COM.AR CON I-2 && I-6
		if (punto == 1 && pString[i-3] == '.')
		{
			printf("\n>>RTN: %d | I: %d | C: %c -- VALIDAR 1 PUNTO", rtn, i-2, pString[i]);

		} else if (punto == 2 && pString[i-2] == '.' && pString[i-6] == '.') {
			printf("\n>>RTN: %d | I: %d | C: %c -- VALIDAR 2 PUNTO", rtn, i-6, pString[i]);
		} else {
			rtn = 0;
			printf("\n>>RTN: %d | I: %d | C: %c -- VALIDAR RTN 0", rtn, i, pString[i]);
		}











	}
	printf("\n>>RTN: %d | I: %d | C: %c -- END", rtn, i, pString[i]);
	return rtn;
}













//	VERSION 2.0
//static int isEmail(char* pString)
//{
//	int rtn = 1;
//	int i = 0;
//
//	int punto = 0;
//	int guionMedio = 0;
//	int guionBajo = 0;
//	int arroba = 0;
//
//
//	if (pString != NULL && strlen(pString) > 0)
//	{
//
//
//		//	FORMATO EMAIL: . - _ @ <=1L . >=3L . >=2L
//
//
//		//	EVALUO PRIMERA POSICION
//		if (pString[i] < 'a' || 'z' < pString[i])
//		{
//			i++;
//
//			printf("\n>>CUENTO RTN = %d --- I: %d", rtn, i);
//			//	CUENTO OCURRENCIAS
//			for (	; pString[i] != '\0'; i++)
//			{
//				printf("\n>>FOR 1 RTN = %d --- I: %d", rtn, i);
//
//				if (pString[i] < 'a' || 'z' < pString[i])
//				{
//					if (pString[i] == '.') punto++;
//					else if (pString[i] == '-') guionMedio++;
//					else if (pString[i] == '_') guionBajo++;
//					else if (pString[i] == '@') arroba++;
//					else {
//						printf("\n>>OCURRENCIAS RTN = %d --- I: %d: ", rtn, i);
//						rtn = 0;
//
//					}
//				}
//			}
//
//			//	EVALUO OCURRENCIAS
//			if (rtn == 1
//				&& 1 <= punto && punto < 3
//				&& guionMedio <= 1
//				&& guionBajo <= 1
//				&& arroba == 1)
//			{
//				//	EVALUO RELACION
//				for (i = 0; pString[i] != '\0'; i++)
//				{
//					if (pString[i] < 'a' || 'z' < pString[i])
//					{
//						if ( ! (pString[i-1] <= 'a' && pString[i+1] <= 'z'))
//						{
//							rtn = 0;
//							printf("\n>>RELACION RTN = %d --- I: %d:", rtn, i);
//							break;
//						}
//					}
//				}
//			}
//
//
//		}
//	}
//	printf("\n>>END RTN = %d --- I: %d:", rtn, i);
//	return rtn;
//}







//	VERSION 1.0
//static int isEmail(char* pString)
//{
//	int rtn = 1;
//	int i = 0;
//
//	int punto = 0;
//	int guionMedio = 0;
//	int guionBajo = 0;
//	int arroba = 0;
//
//
//	if (pString != NULL && strlen(pString) > 0) {
//
//
//		//	FORMATO EMAIL: . - _ @ <=1L . >=3L . >=2L
//
//
//		//	EVALUO PRIMERA POSICION
//		if (pString[i] < 'a' || 'z' < pString[i])
//		{
//			i++;
//
//
//			//	ANTES DEL ARROBA
//			for (	; pString[i] != '\0'; i++)
//			{
//				if (pString[i] < 'a' || 'z' < pString[i])
//				{
//					if (pString[i] == '@') {
//						arroba++;
//						break;
//
//					} else if (pString[i] == '.')
//						{
//							punto++;
//							if (punto >1){
//								rtn = 0;
//								break;
//							}
//
//						}
//
//
//
//				}
//			}
//
//			if (rtn == 1 && arroba == 1)
//			{
//				//	PREGUNTO POR LA POSICION ANTERIOR Y POSTERIOR QUE HAYA UNA LETRA
//				// 	O DICHO DE OTRA FORMA QUE NO HAYA '.' '-' '_' '@'
//				if (	(pString[i-1] < 'a' || 'z' < pString[i-1])
//					 && (pString[i+1] < 'a' || 'z' < pString[i+1]) )
//				{
//					rtn = 0;
//				}
//			}
//			i++;
//
//
//			//	DESPUES DEL ARROBA
//			for (	; pString[i] != '\0'; i++)
//			{
//
//				if (pString[i] < 'a' || 'z' < pString[i])
//				{
//
//
//
//
//				}
//			}
//
//
//
//
//
//
//
//
//
//		} else rtn = 0;
//
//
//	}
//
//	return rtn;
//}



//
//
//
//if (	pString[i] != '.'
//	&& 	pString[i] != '-'
//	&& 	pString[i] != '_'
//	&& 	pString[i] != '@') {
//
//		rtn = 0;
//		break;
//
//} else {
//
//	if (pString[i] == '@') {
//		arroba++;
//
//		if (arroba > 1) {	//ENCONTRE DOS ARROBAS
//			rtn = 0;
//			break;
//
//		}
//	}
//
//	if (pString[i] == '.') punto++;
//	if (pString[i] == '-') guionMedio++;
//	if (pString[i] == '_') guionBajo++;
//	if (pString[i] == '@') arroba++;
//
//}
//
//if (){
//
//}



















































*/

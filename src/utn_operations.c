/*
 * 		utn_operations.c
 *      Author: Martin Delgado
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


//#########################################################################################
//									OPERACIONES
//#########################################################################################


int utn_splitInt(float* pResultado, int operator1, int operator2)
{
	int rtn = -1;
	if (pResultado != NULL && operator2 != 0){
		*pResultado = (float) operator1 / operator2;
		rtn = 0;
	}
	return rtn;
}


//	CHEQUEAR
int utn_splitFloat(float* pResultado, float operator1, float operator2)
{
	int rtn = -1;
	if (pResultado != NULL && operator2 != 0){
		*pResultado = operator1 / operator2;
		rtn = 0;
	}
	return rtn;
}



//	RESTAR VALOR ABSOLUTO
int utn_subtractAbsoluteValue(float* pResultado, float operator1, float operator2)
{
	int rtn = -1;

	if (pResultado != NULL){
		if (operator1 > operator2){
			*pResultado = operator1 - operator2;
			rtn = 1;
		} else if (operator1 < operator2){
			*pResultado = operator2 - operator1;
			rtn = 2;
		} else {
			*pResultado = 0;
			rtn = 3;
		}
	}
	return rtn;
}


int utn_ruleofthree(float operatorA, float operatorB, float operatorC, float* pResultado)
{
	int rtn = -1;
	if (pResultado != NULL && operatorA != 0){
		*pResultado = (operatorB / operatorA) * operatorC;
		rtn = 0;
	}
	return rtn;
}


//#########################################################################################
//								OPERACIONES CON ARRAYS
//#########################################################################################


//	RECIBE UN ARRAY, CALCULA EL PROMEDIO Y LO DEVUELVE POR SU VALOR DE RETORNO
float utn_arrayAverageInt(int* pArray, int LEN)
{
	float resultado;
	int acc = 0;

	if (pArray != NULL && LEN > 0){
		for (int i = 0; i < LEN; ++i){
			acc = acc + pArray[i];
		}
		resultado = (float) acc / LEN;
	}
	return resultado;
}


float utn_arrayAverageFloat(float* pArray, int LEN)
{
	float resultado;
	float acc = 0;

	if (pArray != NULL && LEN > 0){
		for (int i = 0; i < LEN; ++i){
			acc = acc + pArray[i];
		}
		resultado = acc / LEN;
	}
	return resultado;
}

int utn_arrayBubbleShortInt(int* pArray, int LEN, char ASC_OR_DESC)
{
	int rtn = 1;
	int i = 0;
	int flagSwap;
	int newLen;
	int buffer;

	if (pArray != NULL && LEN > 0) {
		rtn = 0;
		newLen = LEN - 1;


		switch (ASC_OR_DESC){

			case '<':	//DESCENDENTE
				do {
					flagSwap = 0;
					for (i = 0; i < newLen; i++) {
						if (pArray[i] < pArray[i+1]) {
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
						if (pArray[i] > pArray[i+1]) {
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


int utn_arrayBubbleShortFloat(float* pArray, int LEN, char ASC_OR_DESC)
{
	int rtn = -1;
	int i = 0;
	int flagSwap;
	int newLen;
	float buffer;

	if (pArray != NULL && LEN > 0) {
		rtn = 0;
		newLen = LEN - 1;


		switch (ASC_OR_DESC){


			case '<':	//DESCENDENTE
				do {
					flagSwap = 0;
					for (i = 0; i < newLen; i++) {
						if (pArray[i] < pArray[i+1]) {
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
						if (pArray[i] > pArray[i+1]) {
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




long int utn_timeCurrent(void){
	return time(NULL);
}

//	RECIBE SEGUNDOS
long int utn_timeAdd(double segAdd){
	return segAdd + utn_timeCurrent();
}







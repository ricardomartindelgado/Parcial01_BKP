/*
 * 		utn_operations.h
 *      Author: Martin Delgado
 */

#ifndef UTN_OPERATIONS_H_
#define UTN_OPERATIONS_H_

#include <stdio.h>
#include <stdlib.h>


//	OPERACIONES MATEMATICAS
int utn_splitInt(float* pResultado, int operator1, int operator2);
int utn_splitFloat(float* pResultado, float operator1, float operator2);
int utn_subtractAbsoluteValue(float* pResultado, float operator1, float operator2);
int utn_ruleofthree(float operatorA, float operatorB, float operatorC, float* pResultado);


//	ARRAYS
float utn_arrayAverageInt(int* pArray, int LEN);
float utn_arrayAverageFloat(float* pArray, int LEN);
int utn_arrayBubbleShortInt(int* pString, int LEN, char ASC_OR_DESC);
int utn_arrayBubbleShortFloat(float* pArray, int LEN, char ASC_OR_DESC);


//	TIME
long int utn_timeCurrent(void);
long int utn_timeAdd(double segAdd);



#endif /* UTN_OPERATIONS_H_ */

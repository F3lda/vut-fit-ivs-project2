#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "basic_math.h"


const int ZERO_DIVISION = 1;
const int INVALID_FACTORIAL = 2;
const int ROOT_BASE = 3;
const int ROOT_NEGATIVE = 4;
const int EXPONENT_NEG_BASE_FRAC_POW = 5;
const int LOG_DF_BASE = 6;
const int LOG_DF_NUM = 7;



double add(double num1, double num2)
{
	return num1+num2;
}


double sub(double num1, double num2)
{
	return num1-num2;
}


double multiply(double num1, double num2)
{
	return num1*num2;
}


double divide(double num1, double num2, int *err)
{
	if(err != NULL) *err = 0;

	if (num2 == 0)
	{
		if(err != NULL) *err = ZERO_DIVISION;
		return -69;
	}
	else return num1/num2;
}







#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "basic_math.h"


const int ZERO_DIVISION = 1;
const int INVALID_FACTORIAL = 2;
const int FACTORIAL_OVERFLOW = 3;
const int ROOT_NEGATIVE = 4;
const int EXPONENT_NEG_BASE_FRAC_POW = 5;
const int LOG_DF_BASE = 6;
const int LOG_DF_NUM = 7;
const int LOG_BASE_1 = 8;


/**
 * Funkce pro sčítání dvou čísel
 *
 * @param num1 První číslo sčítání
 * @param num2 Druhé číslo sčítání
 * @return Výsledek sčítání
 */
double add(double num1, double num2)
{
	return num1+num2;
}

/**
 * Funkce pro odečítání dvou čísel
 *
 * @param num1 První číslo odečítání (menšenec)
 * @param num2 Druhé číslo odečítání (menšitel)
 * @return Výsledek odčítání
 */
double sub(double num1, double num2)
{
	return num1-num2;
}

/**
 * Funkce pro násobení dvou čísel
 *
 * @param num1 První číslo násobení
 * @param num2 Druhé číslo násobení
 * @return Výsledek násobení
 */
double multiply(double num1, double num2)
{
	return num1*num2;
}

/**
 * Funkce pro dělení dvou čísel
 *
 * @param num1 První číslo k dělení (dělenec)
 * @param num2 Druhé číslo k dělení (dělitel)
 * @param err Proměnná určená k chybě
 * @return Výsledek dělení
 */
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







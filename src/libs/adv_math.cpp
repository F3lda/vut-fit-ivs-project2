/**
 * @file adv_math.cpp
 * 
 * @brief Implementace pokročilých matematických funkcí
 * @author Michal Pyšík
 */

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>    //pouze pro pomoc u logaritmu a pro funkci sqrt
#include "adv_math.h"
#include "basic_math.h"



/**
 * @brief Funkce pro výpočet absolutní hodnoty
 *
 * @param num Číslo k určení absolutní hodnoty
 * @return Výsledek v absolutní hodnotě
 */
double absVal(double num)
{
	if(num >= 0) return num;
	else return (-num);
}


/**
 * @brief Pomocná funkce pro výpočet faktoriálu. Volaná funkcí factorial()
 *
 * @param n Základ k určení faktoriálu
 * @return Výsledek faktoriálu
 */
int IntFactorial(int n)
{
	if(n == 0 || n == 1) return 1;

	else return n*(IntFactorial(n-1));
}


/**
 * @brief Hlavní funkce k výpočtu faktoriálu
 * 
 * @param num Číslo k určení faktoriálu
 * @param err Chybová proměnná
 * @return Výsledek faktoriálu
 */
double factorial(double num, int *err)
{
	if(err != NULL) *err = 0;

	if(num > 16 && err != NULL)
	{
		*err = FACTORIAL_OVERFLOW;
		return -69;
	}
	
	int tmp = static_cast<int>(num);

	if(num != tmp || num < 0)
	{
		if(err != NULL) *err = INVALID_FACTORIAL;
		return -69;
	}
	else
	{
		tmp = IntFactorial(tmp);
		num = static_cast<double>(tmp);
		return num;
	}
}


/**
 * @brief Pomocná funkce pro výpočet mocniny, pokud základem je celé číslo
 *
 * @param cislo Číslo k určení mocniny
 * @param power Základ k určení mocniny
 * @return Výsledek mocniny
 */
double IntExp(double cislo, int power)
{
	if(! power) return 1.0;

	double num = 1.0;

	for(int i = 0; i < power; i++)
	{
		num *= cislo;
	}
	
	return num;
}


/**
 * @brief Hlavní funkce k výpočtu n-té mocniny
 * 
 * @param num Číslo k určení mocniny
 * @param power Základ mocniny
 * @param eps Epsilon k měření přesnosti
 * @param err Chybová proměnná
 * @return Výsledek mocniny
 */
double Exponent(double num, double power, double eps, int *err)
{
	if(err != NULL) *err = 0;

	
	if(num == 0 && power < 0)
	{
		if(err != NULL) *err = ZERO_DIVISION;
		return -69;
	}

	if(power == static_cast<int>(power))    //exponent je cele cislo (pro optimalizaci castych pripadu)
	{
		int temp = static_cast<int>(power);
		if(temp >= 0) return IntExp(num, temp);
		else return 1/(IntExp(num, -temp));  //exponent je zaporne cele cislo
	}
	else if(num < 0)
	{
		if(err != NULL) *err = EXPONENT_NEG_BASE_FRAC_POW;
		return -69;
	}


	if(power < 0) return 1/Exponent(num, -power, eps, err);
	if(power >= 10) return (Exponent(num, power/2, eps/2, err)*Exponent(num, power/2, eps/2, err));
	if(power >= 1) return num * Exponent(num, power-1, eps, err);
	if(eps >= 1) return sqrt(num);
	return sqrt(Exponent(num, power*2, eps*2, err));
}


/**
 * @brief Hlavní funkce k výpočtu n-té odmocniny
 * 
 * @param num Číslo k určení n-té odmocniny
 * @param base Základ odmocniny
 * @param eps Epsilon k měření přesnosti
 * @param err Chybová proměnná
 * @return Výsledek n-té odmocniny
 */
double NthRoot(double num, double base, double eps, int *err)
{
	if(err != NULL) *err = 0;

	if(base == 2 && num >= 0) return sqrt(num);

	if(base == 1) return num;

	if(num < 0)
	{
		if(err != NULL) *err = ROOT_NEGATIVE;	
		return -69;
	}
	
	if(base == 0 && num == 0) return 0;

	if(base == 0)
	{
		*err = ZERO_DIVISION;
		return -69;
	}
	
	return Exponent(num, 1/base, eps, err);
}


/**
 * @brief Hlavní funkce k výpočtu n-té odmocniny
 * 
 * @todo Prohodit parametry base a num kvůli konzistenci
 *
 * @param base Základ odmocniny
 * @param num Číslo k určení n-té odmocniny
 * @param err Chybová proměnná
 * @return Výsledek n-té odmocniny
 */
double logab(double base, double num, int *err)
{
	if(err != NULL) *err = 0;

	if(num == 1) return 0;

	if(num == base) return 1;

	if(base <= 0)
	{
		if(err != NULL) *err = LOG_DF_BASE;
		return -69;
	}
	       
	if(num <= 0)
	{
		if(err != NULL) *err = LOG_DF_NUM;
		return -69;
	}

	if(base == 1 && num != 1)
	{
		if(err != NULL) *err = LOG_BASE_1;
		return -69;
	}

	
	if(num < 1 && base > 1) return -logab(base, 1/num, err);
	if(num > 1 && base < 1) return -logab(1/base, num, err);
	if(num < 1 && base < 1) return logab(1/base, 1/num, err);
	
	return log(num)/log(base);	
}



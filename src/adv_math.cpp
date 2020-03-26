#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "adv_math.h"
#include "basic_math.h"



//absolutni hodnota
double absVal(double num)
{
	if(num >= 0) return num;
	else return (-num);
}


//faktorial prirozenych cisel
int IntFactorial(int n)
{
	if(n == 0 || n == 1) return 1;

	else return n*(IntFactorial(n-1));
}


//hotovy faktorial (osetreny chyby)
double factorial(double num, int *err)
{
	if(err != NULL) *err = 0;
	
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


//mocnina s prirozenym exponentem
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


//druha odmocnina pro zjednoduseni Exponent funkce
double sqrt(double num, double eps)
{
	if(num == 0 || num == 1) return num;
	
	double vysledek, guess;
	double horni = num;
	double spodni = guess = vysledek = 0;
	
	while(absVal(num - guess) > eps)
	{
		vysledek = (horni+spodni)/2;

		guess = vysledek*vysledek;

		
		if(guess > num) horni = vysledek;
		else spodni = vysledek;
	}

	return vysledek;
}


//obecna mocnina, kdyz je exponent cele cislo prepne na funkci pro prirozeny exponent
double Exponent(double num, double power, double eps, int *err)
{
	if(err != NULL) *err = 0;

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

	if(num == 0 && power < 0)
	{
		if(err != NULL) *err = ZERO_DIVISION;
		return -69;
	}

	if(power < 0) return 1/Exponent(num, -power, eps, err);
	if(power >= 10) return (Exponent(num, power/2, eps/2, err)*Exponent(num, power/2, eps/2, err));
	if(power >= 1) return num * Exponent(num, power-1, eps, err);
	if(eps >= 1) return sqrt(num, 0.000000000001);
	return sqrt(Exponent(num, power*2, eps*2, err), 0.000000000001);
}


//n-ta odmocnina
double NthRoot(double num, double base, double eps, int *err)
{
	if(err != NULL) *err = 0;

	if(base == 2 && num >= 0) return sqrt(num, eps);

	if(base == 1) return num;

	if(base <= 0)
	{
		if(err != NULL) *err = ROOT_BASE;
	}	return -69;

	int power = static_cast<int>(base);

	if(base != power) return Exponent(num, 1/base, eps, err);
	
	
	double vysledek, guess;
	double horni = num;
	double spodni = guess = vysledek = 0;
	
	while(absVal(num - guess) > eps)
	{
		guess = (horni+spodni)/2;

		vysledek = guess;
		
		for(int i = 1; i < power; i++)
		{
			guess *= vysledek;
		}
		
		if(guess > num) horni = vysledek;
		else spodni = vysledek;
	}

	return vysledek;
}


//obecne logaritmy
double log(double base, double num, double eps, int *err)
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

	double spodni = 0;
	double horni = num;
	double guess = (horni+spodni)/2;
	double vysledek = guess;

	while(absVal(num - vysledek) > eps)
	{
		guess = (horni+spodni)/2;
		vysledek = Exponent(base, guess, eps/100000, err);
		
		//DEBUG std::cout << "guess a vysledek: " << guess << "   " << vysledek << "\n";

		if(vysledek > num) horni = guess;
		else spodni = guess;
	}

	return guess;
}



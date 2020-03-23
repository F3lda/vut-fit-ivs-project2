#include <stdio.h>
#include <stdbool.h>
#include <iostream>


//absolutni hodnota
double absVal(double num)
{
	if(num >= 0) return num;
	else return (-num);
}


//faktorial prirozenych cisel
int factorial(int n)
{
	if(n == 0 || n == 1) return 1;

	else return n*(factorial(n-1));
}


//mocnina s prirozenym exponentem
double exponent(double cislo, int power) 
{
	if(! power) return 1.0;

	double num = 1.0;

	for(int i = 0; i < power; i++)
	{
		num *= cislo;
	}	
}


//n-ta odmocnina
double NthRoot(double cislo, int power, double eps)
{
	if(power == 1) return cislo;
	
	double vysledek, guess;
	double horni = cislo;
	double spodni = guess = 0;
	
	while(absVal(cislo - guess) > eps)
	{
		guess = (horni+spodni)/2;

		vysledek = guess;
		
		for(int i = 1; i < power; i++)
		{
			guess *= vysledek;
		}
		
		if(guess > cislo) horni = vysledek;
		else spodni = vysledek;
	}

	return vysledek;
}




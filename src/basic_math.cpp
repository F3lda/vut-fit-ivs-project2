#include <stdio.h>
#include <stdbool.h>
#include <iostream>
#include "basic_math.h"

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


double divide(double num1, double num2)
{
	if (num2 == 0) return 69696969; // TODO HODIT ERROR
	else return num1/num2;
}







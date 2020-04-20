/**
 * @file adv_math.h
 * 
 * @brief Hlavička pokročilých matematických funkcí
 */

#ifndef ADV_MATH_H_
#define ADV_MATH_H_



double absVal(double num);

double factorial(double num, int *err);

double Exponent(double num, double power, double eps, int *err);

double NthRoot(double num, double base, double eps, int *err);

double logab(double base, double num, int *err);

#endif



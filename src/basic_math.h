/**
 * @file basic_math.h
 * 
 * @brief Hlavička základních matematických funkcí
 */

#ifndef BASIC_MATH_H_
#define BASIC_MATH_H_

extern const int ZERO_DIVISION;
extern const int INVALID_FACTORIAL;
extern const int FACTORIAL_OVERFLOW;
extern const int ROOT_NEGATIVE;
extern const int EXPONENT_NEG_BASE_FRAC_POW;
extern const int LOG_DF_BASE;
extern const int LOG_DF_NUM;
extern const int LOG_BASE_1;

double add(double num1, double num2);

double sub(double num1, double num2);

double multiply(double num1, double num2);

double divide(double num1, double num2, int *err);

#endif


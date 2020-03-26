#ifndef BASIC_MATH_H_
#define BASIC_MATH_H_

extern const int ZERO_DIVISION;
extern const int INVALID_FACTORIAL;
extern const int ROOT_BASE;
extern const int ROOT_NEGATIVE;
extern const int EXPONENT_NEG_BASE_FRAC_POW;
extern const int LOG_DF_BASE;
extern const int LOG_DF_NUM;

double add(double num1, double num2);

double sub(double num1, double num2);

double multiply(double num1, double num2);

double divide(double num1, double num2, int *err);

#endif


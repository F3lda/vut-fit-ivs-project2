#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../libs/basic_math.h"
#include "../libs/adv_math.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

int error = 0;
double temp = 0;
double eps = 0.000000000001;

//vyhledem k praci s typem double nevyjdou vysledky uplne presne, proto pro aproximace casto pouzimam promennou temp a podminky nerovnosti

TEST_CASE( "Function add" )
{
	REQUIRE( add(200, 31) == 231);
	REQUIRE( add(-6900001, -2889) == -6902890);
	REQUIRE( add(0,0) == 0);
	REQUIRE( add(-687, 23.3) == -663.7);
}


TEST_CASE( "Function sub" )
{
	REQUIRE( sub(2000, 2) == 1998);
	REQUIRE( sub(0, -20) == 20);
	REQUIRE( sub(-30.69, -29.69) == -1);
	REQUIRE( sub(896,0) == 896);
}


TEST_CASE( "Function multiply" )
{
	REQUIRE( multiply(9,8) == 72);
	REQUIRE( multiply(0,446464) == 0);
	REQUIRE( multiply(-36, -8.23) == multiply(36, 8.23) );
	REQUIRE( multiply(398, -2) == multiply(-398, 2) );
	REQUIRE( multiply(0.1, 0.002) == 0.0002 );
}


TEST_CASE( "Function divide" )
{
	REQUIRE( divide(23, 0.02, &error) == 1150);
	REQUIRE( divide(64, 8, &error) == 8);
	REQUIRE( divide(420.1337, 420.1337, &error) == 1);
	REQUIRE( error == 0);

	divide(23.5, 0, &error);
	REQUIRE( error == ZERO_DIVISION);

	REQUIRE( divide(0.0, 0.01, &error) == 0);
	REQUIRE( error == 0);

	divide(0.0, 0.0, &error);
	REQUIRE( error == ZERO_DIVISION);
}


TEST_CASE( "Function factorial" )
{
	REQUIRE( factorial(0, &error) == 1);
	REQUIRE( error == 0);

	REQUIRE( factorial(1, &error) == 1);
	REQUIRE( factorial(3, &error) == 6);
	REQUIRE( error == 0);

	REQUIRE( factorial(5, &error) == 120);
	REQUIRE( factorial(7, &error) == 5040);
	REQUIRE( error == 0);

	temp = factorial(3.3, &error);
	REQUIRE( error == INVALID_FACTORIAL);
	temp = factorial(-8, &error);
	REQUIRE( error == INVALID_FACTORIAL);
	temp = factorial(18,&error);
	REQUIRE( error == FACTORIAL_OVERFLOW);
}


TEST_CASE( "Function Exponent, special Squared case" )
{
	temp = Exponent(3.3, 2, eps, &error);
	REQUIRE( temp > 10.88);
	REQUIRE( temp < 10.9);	
	REQUIRE( Exponent(-8.24, 2, eps, &error) == 67.8976);
	REQUIRE( Exponent(0, 2, eps, &error) == 0);
	REQUIRE( Exponent(-0.5, 2, eps, &error) == 0.25);
	REQUIRE( error == 0);

	REQUIRE( Exponent(0.32, 2, eps, &error) == 0.1024);
	REQUIRE( Exponent(0, 2, eps, &error) == 0);
	REQUIRE( error == 0);

	REQUIRE( Exponent(3.3, 2, eps, &error) == 3.3*3.3);
}


TEST_CASE( "Function Exponent" )
{
	REQUIRE( Exponent(-3, 3, eps, &error) == -27);
	REQUIRE( error == 0);
	REQUIRE( Exponent(-3.9, 0, eps, &error) == 1);
       	REQUIRE( Exponent(0.012, 0, eps, &error) == 1);

	temp = Exponent(-0.32, 4, eps, &error);
	REQUIRE( temp > 0.0098);
	REQUIRE( temp < 0.011);
	REQUIRE( error == 0);

	temp = Exponent(0.32, -5, eps, &error);
	REQUIRE( temp > 297.8);
	REQUIRE( temp < 298.2);
	REQUIRE( error == 0);

	temp = Exponent(-3.6, -3, eps, &error);
	REQUIRE( temp > -0.028);
	REQUIRE( temp < -0.016);
	REQUIRE( error == 0);

	temp = Exponent(1.98, -5.3, eps, &error);
	REQUIRE( temp > 0.026);
	REQUIRE( temp < 0.027);
	REQUIRE( error == 0);

	REQUIRE( Exponent(5, -1, eps, &error) == 0.2);
	REQUIRE( Exponent(1,19, eps, &error) == 1);
	REQUIRE( Exponent(568, 0, eps, &error) == 1);
	REQUIRE( Exponent(58.12, 1, eps, &error) == 58.12);

	temp = Exponent(-28, 1.9, eps, &error);
	REQUIRE( error == EXPONENT_NEG_BASE_FRAC_POW);

	temp = Exponent(-0.01, 0.003, eps, &error);
	REQUIRE( error == EXPONENT_NEG_BASE_FRAC_POW);

	REQUIRE( Exponent(4, 0.5, eps, &error) == 2);
	REQUIRE( error == 0);

	temp = Exponent(0, -3, eps, &error);
	REQUIRE( error == ZERO_DIVISION);
}


TEST_CASE( "Function NthRoot, special square root case" )
{
	REQUIRE( NthRoot(4, 2, eps, &error) == 2);
	REQUIRE( NthRoot(28068804, 2, eps, &error) == 5298);
	
	temp = NthRoot(2, 2, eps, &error);
	REQUIRE( temp > 1.413);
	REQUIRE( temp < 1.415);
	
	REQUIRE( NthRoot(0.01, 2, eps, &error) == 0.1);
	REQUIRE( NthRoot(9, 2, eps, &error) == 3);

	temp = NthRoot(-6, 2, eps, &error);
	REQUIRE( error == ROOT_NEGATIVE);
}


TEST_CASE( "Function NthRoot" )
{
	temp = NthRoot(27, 3, eps, &error);
	REQUIRE( temp >= 2.999);
	REQUIRE( temp <= 3.001);
	REQUIRE( error == 0);

	REQUIRE( NthRoot(36.2, 1, eps, &error) == 36.2);
	REQUIRE( NthRoot(0, 8, eps, &error) == 0);
	
	temp = NthRoot(-1, 2, eps, &error);
	REQUIRE( error == ROOT_NEGATIVE);

	REQUIRE( NthRoot(2, -1, eps, &error) == 0.5);

	temp = NthRoot(1000000, 6, eps, &error);
	REQUIRE( temp >= 9.99999);
	REQUIRE( temp <= 10.0001);
	
	temp = NthRoot(589.9, 3.7, eps, &error);
	REQUIRE( error == 0);
	REQUIRE( temp <= 5.62);
	REQUIRE( temp >= 5.58);

	temp = NthRoot(32768, 15, eps, &error);
	REQUIRE( temp > 1.99999999);
	REQUIRE( temp < 2.00000001);

	temp = NthRoot( 32768, -15, eps, &error);
	REQUIRE( temp >= 0.499999);
	REQUIRE( temp <= 0.500001);

	REQUIRE( NthRoot(0, 0, eps, &error) == 0.0);
	REQUIRE( error == 0);
	REQUIRE( NthRoot(69.4201337, 1, eps, &error) == 69.4201337);
	
	temp = NthRoot(23, 0, eps, &error);
	REQUIRE( error == ZERO_DIVISION);
}


TEST_CASE( "Function Logarithm of base a (logab)" )
{
	REQUIRE( logab(2, 8, &error) == 3);
	REQUIRE( error == 0);

	temp = logab(3, 243, &error);
	REQUIRE( temp >= 4.99999);
	REQUIRE( temp <= 5.00001);

	temp = logab(0, 3, &error);
	REQUIRE( error == LOG_DF_BASE);
	temp = logab( -6.9, 54, &error);
	REQUIRE( error == LOG_DF_BASE);

	temp = logab( 3, 0, &error);
	REQUIRE( error == LOG_DF_NUM);
	temp = logab(9.7, -0.01, &error);
	REQUIRE( error == LOG_DF_NUM);

	temp = logab(1, 3, &error);
	REQUIRE( error == LOG_BASE_1);

	REQUIRE( logab(5, 1, &error) == 0);
	REQUIRE( error == 0);

	temp = logab(6, 46656, &error);
	REQUIRE( temp >= 5.999999);
	REQUIRE( temp <= 6.000001);

	REQUIRE( logab(2, 2, &error) == 1);

	temp = logab(65.8, 533.7511705, &error);
	REQUIRE( temp > 1.48);
	REQUIRE( temp < 1.52);

	REQUIRE( logab(0.01, 10000, &error) == -2);
	REQUIRE( logab(0.5, 2, &error) == -1);
	REQUIRE( error == 0);

	temp = logab(0.58, 3.0052, &error);
	REQUIRE( temp > -2.03);
	REQUIRE( temp < -2.01);
	REQUIRE( error == 0);
}



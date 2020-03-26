#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../basic_math.h"
#include "../adv_math.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

int error = 0;
double temp = 0;
double eps = 0.000000000001;

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


	temp = Exponent(-28, 1.9, eps, &error);
	REQUIRE( error == EXPONENT_NEG_BASE_FRAC_POW);

	temp = Exponent(-0.01, 0.003, eps, &error);
	REQUIRE( error == EXPONENT_NEG_BASE_FRAC_POW);

	REQUIRE( Exponent(4, 0.5, eps, &error) == 2);
	REQUIRE( error == 0);

	temp = Exponent(0, -3, eps, &error);
	REQUIRE( error == ZERO_DIVISION);
}



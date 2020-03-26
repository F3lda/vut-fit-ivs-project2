#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../basic_math.h"
#include "../adv_math.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

int error = 0;

TEST_CASE( "Testing factorial, type double" , "[factorial]" )
{
	REQUIRE( factorial(0, &error) == 1);
	REQUIRE( factorial(1, &error) == 1);
	REQUIRE( factorial(2, &error) == 2);
	REQUIRE( factorial(3, &error) == 6);
	REQUIRE( factorial(4, &error) == 24);
	REQUIRE( factorial(5, &error) == 120);
	REQUIRE( factorial(7, &error) == 5040);
}



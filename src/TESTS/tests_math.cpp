#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "../basic_math.h"
#include "../adv_math.h"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"


TEST_CASE( "Testing factorial, type double" , "[factorial]" )
{
	REQUIRE( factorial(0) == 1);
	REQUIRE( factorial(1) == 1);
	REQUIRE( factorial(2) == 2);
	REQUIRE( factorial(3) == 6);
	REQUIRE( factorial(4) == 24);
	REQUIRE( factorial(5) == 120);
	REQUIRE( factorial(7) == 5040);
}



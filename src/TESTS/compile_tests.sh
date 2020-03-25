#!/usr/bin/env bash

c++ $(cd .. ; pwd)/basic_math.cpp $(cd .. ; pwd)/adv_math.cpp $(cd .. ; pwd)/basic_math.h $(cd .. ; pwd)/adv_math.h tests_math.cpp

exit 0

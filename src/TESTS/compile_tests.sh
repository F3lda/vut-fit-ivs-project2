#!/usr/bin/env bash

c++ -o run_tests $(cd .. ; pwd)/basic_math.cpp $(cd .. ; pwd)/adv_math.cpp tests_math.cpp

exit 0

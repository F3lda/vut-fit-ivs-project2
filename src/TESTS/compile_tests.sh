#!/usr/bin/env bash

c++ $(cd .. ; pwd)/basic_math.cpp $(cd .. ; pwd)/adv_math.cpp tests_math.cpp

exit 0

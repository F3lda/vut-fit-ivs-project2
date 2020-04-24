#Makefile pro IVS Projekt 2

CC=g++


.PHONY: All

All: buildcal buildprof buildtests clean

buildcal:
	cd CALCULATOR && $(CC) -o calculator *.cpp ../libs/*.cpp 
profile:
	cd profiling && $(CC) -o profiling *.cpp ../libs/*.cpp
buildtests:
	cd TESTS && make
pack:

clean:

test: buildtests
	cd TESTS && ./run_tests

doc:
	doxygen Doxyfile && rm -f warning_doxygen.txt
run:

cleanOfiles:


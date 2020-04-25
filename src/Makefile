#Makefile pro IVS Projekt 2

CC=g++


.PHONY: All

All: buildcal profile

buildcal:
	cd CALCULATOR && cmake . && make 
profile:
	cd profiling && $(CC) -o profiling *.cpp ../libs/*.cpp
test:
	cd TESTS && make && ./run_tests
pack:

clean:

doc:
	doxygen Doxyfile && rm -f warning_doxygen.txt
run:
	cd CALCULATOR && ./calculator


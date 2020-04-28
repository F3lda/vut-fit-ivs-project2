#Makefile pro IVS Projekt 2

CC=g++
TEAM=xtrant02_xjirgl01_xpysik00

.PHONY: All

All: buildcal profile

buildcal:
	cd CALCULATOR && cmake . && make 
profile:
	cd profiling && $(CC) -o profiling *.cpp ../libs/*.cpp
test:
	cd TESTS && make && ./run_tests
pack: doc
	mkdir ../../repo && cp -r ../ ../../repo && mkdir ../../install && cp ./installer/*.deb ../../install && mv doc ../.. && cd ../.. && mkdir $(TEAM) && mv repo doc install $(TEAM) && zip -r $(TEAM).zip $(TEAM) && rm -fr $(TEAM) 
clean:
	rm -rf doc ./TESTS/run_tests ./profiling/profiling && cd CALCULATOR && rm -f calculator CMakeCache.txt cmake_install.cmake Makefile
doc:
	doxygen Doxyfile && rm -f warning_doxygen.txt
run:
	cd CALCULATOR && ./calculator


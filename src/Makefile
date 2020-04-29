#Makefile pro IVS Projekt 2
#pro instalaci knihoven potrebnych pro GUI slouzi prikaz: make getlibs
#pokud kalkulacka nejde nainstalovat, spustte nejprve prikaz: make unlock

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
getlibs:
	sudo apt-get install pkg-config && sudo apt-get install libgtk-3-dev
unlock:
	sudo rm /var/lib/apt/lists/lock /var/cache/apt/archives/lock /var/lib/dpkg/lock*

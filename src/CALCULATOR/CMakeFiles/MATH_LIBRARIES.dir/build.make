# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/cmake/323/bin/cmake

# The command to remove a file.
RM = /snap/cmake/323/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/michal/Desktop/vut-fit-ivs-project2/src/CALCULATOR

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/michal/Desktop/vut-fit-ivs-project2/src/CALCULATOR

# Include any dependencies generated for this target.
include CMakeFiles/MATH_LIBRARIES.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MATH_LIBRARIES.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MATH_LIBRARIES.dir/flags.make

CMakeFiles/MATH_LIBRARIES.dir/home/michal/Desktop/vut-fit-ivs-project2/src/libs/basic_math.cpp.o: CMakeFiles/MATH_LIBRARIES.dir/flags.make
CMakeFiles/MATH_LIBRARIES.dir/home/michal/Desktop/vut-fit-ivs-project2/src/libs/basic_math.cpp.o: /home/michal/Desktop/vut-fit-ivs-project2/src/libs/basic_math.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/michal/Desktop/vut-fit-ivs-project2/src/CALCULATOR/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MATH_LIBRARIES.dir/home/michal/Desktop/vut-fit-ivs-project2/src/libs/basic_math.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MATH_LIBRARIES.dir/home/michal/Desktop/vut-fit-ivs-project2/src/libs/basic_math.cpp.o -c /home/michal/Desktop/vut-fit-ivs-project2/src/libs/basic_math.cpp

CMakeFiles/MATH_LIBRARIES.dir/home/michal/Desktop/vut-fit-ivs-project2/src/libs/basic_math.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MATH_LIBRARIES.dir/home/michal/Desktop/vut-fit-ivs-project2/src/libs/basic_math.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/michal/Desktop/vut-fit-ivs-project2/src/libs/basic_math.cpp > CMakeFiles/MATH_LIBRARIES.dir/home/michal/Desktop/vut-fit-ivs-project2/src/libs/basic_math.cpp.i

CMakeFiles/MATH_LIBRARIES.dir/home/michal/Desktop/vut-fit-ivs-project2/src/libs/basic_math.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MATH_LIBRARIES.dir/home/michal/Desktop/vut-fit-ivs-project2/src/libs/basic_math.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/michal/Desktop/vut-fit-ivs-project2/src/libs/basic_math.cpp -o CMakeFiles/MATH_LIBRARIES.dir/home/michal/Desktop/vut-fit-ivs-project2/src/libs/basic_math.cpp.s

CMakeFiles/MATH_LIBRARIES.dir/home/michal/Desktop/vut-fit-ivs-project2/src/libs/adv_math.cpp.o: CMakeFiles/MATH_LIBRARIES.dir/flags.make
CMakeFiles/MATH_LIBRARIES.dir/home/michal/Desktop/vut-fit-ivs-project2/src/libs/adv_math.cpp.o: /home/michal/Desktop/vut-fit-ivs-project2/src/libs/adv_math.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/michal/Desktop/vut-fit-ivs-project2/src/CALCULATOR/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MATH_LIBRARIES.dir/home/michal/Desktop/vut-fit-ivs-project2/src/libs/adv_math.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MATH_LIBRARIES.dir/home/michal/Desktop/vut-fit-ivs-project2/src/libs/adv_math.cpp.o -c /home/michal/Desktop/vut-fit-ivs-project2/src/libs/adv_math.cpp

CMakeFiles/MATH_LIBRARIES.dir/home/michal/Desktop/vut-fit-ivs-project2/src/libs/adv_math.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MATH_LIBRARIES.dir/home/michal/Desktop/vut-fit-ivs-project2/src/libs/adv_math.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/michal/Desktop/vut-fit-ivs-project2/src/libs/adv_math.cpp > CMakeFiles/MATH_LIBRARIES.dir/home/michal/Desktop/vut-fit-ivs-project2/src/libs/adv_math.cpp.i

CMakeFiles/MATH_LIBRARIES.dir/home/michal/Desktop/vut-fit-ivs-project2/src/libs/adv_math.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MATH_LIBRARIES.dir/home/michal/Desktop/vut-fit-ivs-project2/src/libs/adv_math.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/michal/Desktop/vut-fit-ivs-project2/src/libs/adv_math.cpp -o CMakeFiles/MATH_LIBRARIES.dir/home/michal/Desktop/vut-fit-ivs-project2/src/libs/adv_math.cpp.s

# Object files for target MATH_LIBRARIES
MATH_LIBRARIES_OBJECTS = \
"CMakeFiles/MATH_LIBRARIES.dir/home/michal/Desktop/vut-fit-ivs-project2/src/libs/basic_math.cpp.o" \
"CMakeFiles/MATH_LIBRARIES.dir/home/michal/Desktop/vut-fit-ivs-project2/src/libs/adv_math.cpp.o"

# External object files for target MATH_LIBRARIES
MATH_LIBRARIES_EXTERNAL_OBJECTS =

libMATH_LIBRARIES.a: CMakeFiles/MATH_LIBRARIES.dir/home/michal/Desktop/vut-fit-ivs-project2/src/libs/basic_math.cpp.o
libMATH_LIBRARIES.a: CMakeFiles/MATH_LIBRARIES.dir/home/michal/Desktop/vut-fit-ivs-project2/src/libs/adv_math.cpp.o
libMATH_LIBRARIES.a: CMakeFiles/MATH_LIBRARIES.dir/build.make
libMATH_LIBRARIES.a: CMakeFiles/MATH_LIBRARIES.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/michal/Desktop/vut-fit-ivs-project2/src/CALCULATOR/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libMATH_LIBRARIES.a"
	$(CMAKE_COMMAND) -P CMakeFiles/MATH_LIBRARIES.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MATH_LIBRARIES.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MATH_LIBRARIES.dir/build: libMATH_LIBRARIES.a

.PHONY : CMakeFiles/MATH_LIBRARIES.dir/build

CMakeFiles/MATH_LIBRARIES.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MATH_LIBRARIES.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MATH_LIBRARIES.dir/clean

CMakeFiles/MATH_LIBRARIES.dir/depend:
	cd /home/michal/Desktop/vut-fit-ivs-project2/src/CALCULATOR && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/michal/Desktop/vut-fit-ivs-project2/src/CALCULATOR /home/michal/Desktop/vut-fit-ivs-project2/src/CALCULATOR /home/michal/Desktop/vut-fit-ivs-project2/src/CALCULATOR /home/michal/Desktop/vut-fit-ivs-project2/src/CALCULATOR /home/michal/Desktop/vut-fit-ivs-project2/src/CALCULATOR/CMakeFiles/MATH_LIBRARIES.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MATH_LIBRARIES.dir/depend

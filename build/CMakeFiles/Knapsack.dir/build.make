# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.28.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.28.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/antoniablanco/Desktop/DD_optimization_c_plusplus

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/antoniablanco/Desktop/DD_optimization_c_plusplus/build

# Include any dependencies generated for this target.
include CMakeFiles/Knapsack.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Knapsack.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Knapsack.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Knapsack.dir/flags.make

CMakeFiles/Knapsack.dir/Examples/Knapsack/KnapsackMain.cpp.o: CMakeFiles/Knapsack.dir/flags.make
CMakeFiles/Knapsack.dir/Examples/Knapsack/KnapsackMain.cpp.o: /Users/antoniablanco/Desktop/DD_optimization_c_plusplus/Examples/Knapsack/KnapsackMain.cpp
CMakeFiles/Knapsack.dir/Examples/Knapsack/KnapsackMain.cpp.o: CMakeFiles/Knapsack.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/antoniablanco/Desktop/DD_optimization_c_plusplus/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Knapsack.dir/Examples/Knapsack/KnapsackMain.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Knapsack.dir/Examples/Knapsack/KnapsackMain.cpp.o -MF CMakeFiles/Knapsack.dir/Examples/Knapsack/KnapsackMain.cpp.o.d -o CMakeFiles/Knapsack.dir/Examples/Knapsack/KnapsackMain.cpp.o -c /Users/antoniablanco/Desktop/DD_optimization_c_plusplus/Examples/Knapsack/KnapsackMain.cpp

CMakeFiles/Knapsack.dir/Examples/Knapsack/KnapsackMain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Knapsack.dir/Examples/Knapsack/KnapsackMain.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/antoniablanco/Desktop/DD_optimization_c_plusplus/Examples/Knapsack/KnapsackMain.cpp > CMakeFiles/Knapsack.dir/Examples/Knapsack/KnapsackMain.cpp.i

CMakeFiles/Knapsack.dir/Examples/Knapsack/KnapsackMain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Knapsack.dir/Examples/Knapsack/KnapsackMain.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/antoniablanco/Desktop/DD_optimization_c_plusplus/Examples/Knapsack/KnapsackMain.cpp -o CMakeFiles/Knapsack.dir/Examples/Knapsack/KnapsackMain.cpp.s

CMakeFiles/Knapsack.dir/Examples/Knapsack/KnapsackProblem.cpp.o: CMakeFiles/Knapsack.dir/flags.make
CMakeFiles/Knapsack.dir/Examples/Knapsack/KnapsackProblem.cpp.o: /Users/antoniablanco/Desktop/DD_optimization_c_plusplus/Examples/Knapsack/KnapsackProblem.cpp
CMakeFiles/Knapsack.dir/Examples/Knapsack/KnapsackProblem.cpp.o: CMakeFiles/Knapsack.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/antoniablanco/Desktop/DD_optimization_c_plusplus/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Knapsack.dir/Examples/Knapsack/KnapsackProblem.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Knapsack.dir/Examples/Knapsack/KnapsackProblem.cpp.o -MF CMakeFiles/Knapsack.dir/Examples/Knapsack/KnapsackProblem.cpp.o.d -o CMakeFiles/Knapsack.dir/Examples/Knapsack/KnapsackProblem.cpp.o -c /Users/antoniablanco/Desktop/DD_optimization_c_plusplus/Examples/Knapsack/KnapsackProblem.cpp

CMakeFiles/Knapsack.dir/Examples/Knapsack/KnapsackProblem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Knapsack.dir/Examples/Knapsack/KnapsackProblem.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/antoniablanco/Desktop/DD_optimization_c_plusplus/Examples/Knapsack/KnapsackProblem.cpp > CMakeFiles/Knapsack.dir/Examples/Knapsack/KnapsackProblem.cpp.i

CMakeFiles/Knapsack.dir/Examples/Knapsack/KnapsackProblem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Knapsack.dir/Examples/Knapsack/KnapsackProblem.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/antoniablanco/Desktop/DD_optimization_c_plusplus/Examples/Knapsack/KnapsackProblem.cpp -o CMakeFiles/Knapsack.dir/Examples/Knapsack/KnapsackProblem.cpp.s

# Object files for target Knapsack
Knapsack_OBJECTS = \
"CMakeFiles/Knapsack.dir/Examples/Knapsack/KnapsackMain.cpp.o" \
"CMakeFiles/Knapsack.dir/Examples/Knapsack/KnapsackProblem.cpp.o"

# External object files for target Knapsack
Knapsack_EXTERNAL_OBJECTS =

Knapsack: CMakeFiles/Knapsack.dir/Examples/Knapsack/KnapsackMain.cpp.o
Knapsack: CMakeFiles/Knapsack.dir/Examples/Knapsack/KnapsackProblem.cpp.o
Knapsack: CMakeFiles/Knapsack.dir/build.make
Knapsack: libClass.a
Knapsack: libExceptions.a
Knapsack: CMakeFiles/Knapsack.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/antoniablanco/Desktop/DD_optimization_c_plusplus/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Knapsack"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Knapsack.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Knapsack.dir/build: Knapsack
.PHONY : CMakeFiles/Knapsack.dir/build

CMakeFiles/Knapsack.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Knapsack.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Knapsack.dir/clean

CMakeFiles/Knapsack.dir/depend:
	cd /Users/antoniablanco/Desktop/DD_optimization_c_plusplus/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/antoniablanco/Desktop/DD_optimization_c_plusplus /Users/antoniablanco/Desktop/DD_optimization_c_plusplus /Users/antoniablanco/Desktop/DD_optimization_c_plusplus/build /Users/antoniablanco/Desktop/DD_optimization_c_plusplus/build /Users/antoniablanco/Desktop/DD_optimization_c_plusplus/build/CMakeFiles/Knapsack.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Knapsack.dir/depend


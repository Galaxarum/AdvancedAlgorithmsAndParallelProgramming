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
CMAKE_COMMAND = /snap/clion/139/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/139/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/matteo/Shared/University/Advanced Algorithms and Parallel Programming/Challenge42/1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/matteo/Shared/University/Advanced Algorithms and Parallel Programming/Challenge42/1/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/COMPLEXITY.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/COMPLEXITY.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/COMPLEXITY.dir/flags.make

CMakeFiles/COMPLEXITY.dir/strassen.cpp.o: CMakeFiles/COMPLEXITY.dir/flags.make
CMakeFiles/COMPLEXITY.dir/strassen.cpp.o: ../strassen.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/matteo/Shared/University/Advanced Algorithms and Parallel Programming/Challenge42/1/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/COMPLEXITY.dir/strassen.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/COMPLEXITY.dir/strassen.cpp.o -c "/home/matteo/Shared/University/Advanced Algorithms and Parallel Programming/Challenge42/1/strassen.cpp"

CMakeFiles/COMPLEXITY.dir/strassen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/COMPLEXITY.dir/strassen.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/matteo/Shared/University/Advanced Algorithms and Parallel Programming/Challenge42/1/strassen.cpp" > CMakeFiles/COMPLEXITY.dir/strassen.cpp.i

CMakeFiles/COMPLEXITY.dir/strassen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/COMPLEXITY.dir/strassen.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/matteo/Shared/University/Advanced Algorithms and Parallel Programming/Challenge42/1/strassen.cpp" -o CMakeFiles/COMPLEXITY.dir/strassen.cpp.s

# Object files for target COMPLEXITY
COMPLEXITY_OBJECTS = \
"CMakeFiles/COMPLEXITY.dir/strassen.cpp.o"

# External object files for target COMPLEXITY
COMPLEXITY_EXTERNAL_OBJECTS =

COMPLEXITY: CMakeFiles/COMPLEXITY.dir/strassen.cpp.o
COMPLEXITY: CMakeFiles/COMPLEXITY.dir/build.make
COMPLEXITY: benchmark/src/libbenchmark.a
COMPLEXITY: /usr/lib/x86_64-linux-gnu/librt.so
COMPLEXITY: CMakeFiles/COMPLEXITY.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/matteo/Shared/University/Advanced Algorithms and Parallel Programming/Challenge42/1/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable COMPLEXITY"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/COMPLEXITY.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/COMPLEXITY.dir/build: COMPLEXITY

.PHONY : CMakeFiles/COMPLEXITY.dir/build

CMakeFiles/COMPLEXITY.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/COMPLEXITY.dir/cmake_clean.cmake
.PHONY : CMakeFiles/COMPLEXITY.dir/clean

CMakeFiles/COMPLEXITY.dir/depend:
	cd "/home/matteo/Shared/University/Advanced Algorithms and Parallel Programming/Challenge42/1/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/matteo/Shared/University/Advanced Algorithms and Parallel Programming/Challenge42/1" "/home/matteo/Shared/University/Advanced Algorithms and Parallel Programming/Challenge42/1" "/home/matteo/Shared/University/Advanced Algorithms and Parallel Programming/Challenge42/1/cmake-build-debug" "/home/matteo/Shared/University/Advanced Algorithms and Parallel Programming/Challenge42/1/cmake-build-debug" "/home/matteo/Shared/University/Advanced Algorithms and Parallel Programming/Challenge42/1/cmake-build-debug/CMakeFiles/COMPLEXITY.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/COMPLEXITY.dir/depend


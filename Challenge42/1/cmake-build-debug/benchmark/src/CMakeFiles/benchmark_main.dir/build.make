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
include benchmark/src/CMakeFiles/benchmark_main.dir/depend.make

# Include the progress variables for this target.
include benchmark/src/CMakeFiles/benchmark_main.dir/progress.make

# Include the compile flags for this target's objects.
include benchmark/src/CMakeFiles/benchmark_main.dir/flags.make

benchmark/src/CMakeFiles/benchmark_main.dir/benchmark_main.cc.o: benchmark/src/CMakeFiles/benchmark_main.dir/flags.make
benchmark/src/CMakeFiles/benchmark_main.dir/benchmark_main.cc.o: ../benchmark/src/benchmark_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/matteo/Shared/University/Advanced Algorithms and Parallel Programming/Challenge42/1/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object benchmark/src/CMakeFiles/benchmark_main.dir/benchmark_main.cc.o"
	cd "/home/matteo/Shared/University/Advanced Algorithms and Parallel Programming/Challenge42/1/cmake-build-debug/benchmark/src" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/benchmark_main.dir/benchmark_main.cc.o -c "/home/matteo/Shared/University/Advanced Algorithms and Parallel Programming/Challenge42/1/benchmark/src/benchmark_main.cc"

benchmark/src/CMakeFiles/benchmark_main.dir/benchmark_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/benchmark_main.dir/benchmark_main.cc.i"
	cd "/home/matteo/Shared/University/Advanced Algorithms and Parallel Programming/Challenge42/1/cmake-build-debug/benchmark/src" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/matteo/Shared/University/Advanced Algorithms and Parallel Programming/Challenge42/1/benchmark/src/benchmark_main.cc" > CMakeFiles/benchmark_main.dir/benchmark_main.cc.i

benchmark/src/CMakeFiles/benchmark_main.dir/benchmark_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/benchmark_main.dir/benchmark_main.cc.s"
	cd "/home/matteo/Shared/University/Advanced Algorithms and Parallel Programming/Challenge42/1/cmake-build-debug/benchmark/src" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/matteo/Shared/University/Advanced Algorithms and Parallel Programming/Challenge42/1/benchmark/src/benchmark_main.cc" -o CMakeFiles/benchmark_main.dir/benchmark_main.cc.s

# Object files for target benchmark_main
benchmark_main_OBJECTS = \
"CMakeFiles/benchmark_main.dir/benchmark_main.cc.o"

# External object files for target benchmark_main
benchmark_main_EXTERNAL_OBJECTS =

benchmark/src/libbenchmark_main.a: benchmark/src/CMakeFiles/benchmark_main.dir/benchmark_main.cc.o
benchmark/src/libbenchmark_main.a: benchmark/src/CMakeFiles/benchmark_main.dir/build.make
benchmark/src/libbenchmark_main.a: benchmark/src/CMakeFiles/benchmark_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/matteo/Shared/University/Advanced Algorithms and Parallel Programming/Challenge42/1/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libbenchmark_main.a"
	cd "/home/matteo/Shared/University/Advanced Algorithms and Parallel Programming/Challenge42/1/cmake-build-debug/benchmark/src" && $(CMAKE_COMMAND) -P CMakeFiles/benchmark_main.dir/cmake_clean_target.cmake
	cd "/home/matteo/Shared/University/Advanced Algorithms and Parallel Programming/Challenge42/1/cmake-build-debug/benchmark/src" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/benchmark_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
benchmark/src/CMakeFiles/benchmark_main.dir/build: benchmark/src/libbenchmark_main.a

.PHONY : benchmark/src/CMakeFiles/benchmark_main.dir/build

benchmark/src/CMakeFiles/benchmark_main.dir/clean:
	cd "/home/matteo/Shared/University/Advanced Algorithms and Parallel Programming/Challenge42/1/cmake-build-debug/benchmark/src" && $(CMAKE_COMMAND) -P CMakeFiles/benchmark_main.dir/cmake_clean.cmake
.PHONY : benchmark/src/CMakeFiles/benchmark_main.dir/clean

benchmark/src/CMakeFiles/benchmark_main.dir/depend:
	cd "/home/matteo/Shared/University/Advanced Algorithms and Parallel Programming/Challenge42/1/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/matteo/Shared/University/Advanced Algorithms and Parallel Programming/Challenge42/1" "/home/matteo/Shared/University/Advanced Algorithms and Parallel Programming/Challenge42/1/benchmark/src" "/home/matteo/Shared/University/Advanced Algorithms and Parallel Programming/Challenge42/1/cmake-build-debug" "/home/matteo/Shared/University/Advanced Algorithms and Parallel Programming/Challenge42/1/cmake-build-debug/benchmark/src" "/home/matteo/Shared/University/Advanced Algorithms and Parallel Programming/Challenge42/1/cmake-build-debug/benchmark/src/CMakeFiles/benchmark_main.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : benchmark/src/CMakeFiles/benchmark_main.dir/depend

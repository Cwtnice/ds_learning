# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /cygdrive/c/Users/admin/AppData/Local/JetBrains/CLion2021.1/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/admin/AppData/Local/JetBrains/CLion2021.1/cygwin_cmake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/admin/CLionProjects/ds_learning

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/admin/CLionProjects/ds_learning/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/0_file1_to_file2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/0_file1_to_file2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/0_file1_to_file2.dir/flags.make

CMakeFiles/0_file1_to_file2.dir/0_C/0_file1_to_file2.c.o: CMakeFiles/0_file1_to_file2.dir/flags.make
CMakeFiles/0_file1_to_file2.dir/0_C/0_file1_to_file2.c.o: ../0_C/0_file1_to_file2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/admin/CLionProjects/ds_learning/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/0_file1_to_file2.dir/0_C/0_file1_to_file2.c.o"
	/usr/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/0_file1_to_file2.dir/0_C/0_file1_to_file2.c.o -c /cygdrive/c/Users/admin/CLionProjects/ds_learning/0_C/0_file1_to_file2.c

CMakeFiles/0_file1_to_file2.dir/0_C/0_file1_to_file2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/0_file1_to_file2.dir/0_C/0_file1_to_file2.c.i"
	/usr/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /cygdrive/c/Users/admin/CLionProjects/ds_learning/0_C/0_file1_to_file2.c > CMakeFiles/0_file1_to_file2.dir/0_C/0_file1_to_file2.c.i

CMakeFiles/0_file1_to_file2.dir/0_C/0_file1_to_file2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/0_file1_to_file2.dir/0_C/0_file1_to_file2.c.s"
	/usr/bin/gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /cygdrive/c/Users/admin/CLionProjects/ds_learning/0_C/0_file1_to_file2.c -o CMakeFiles/0_file1_to_file2.dir/0_C/0_file1_to_file2.c.s

# Object files for target 0_file1_to_file2
0_file1_to_file2_OBJECTS = \
"CMakeFiles/0_file1_to_file2.dir/0_C/0_file1_to_file2.c.o"

# External object files for target 0_file1_to_file2
0_file1_to_file2_EXTERNAL_OBJECTS =

0_file1_to_file2.exe: CMakeFiles/0_file1_to_file2.dir/0_C/0_file1_to_file2.c.o
0_file1_to_file2.exe: CMakeFiles/0_file1_to_file2.dir/build.make
0_file1_to_file2.exe: CMakeFiles/0_file1_to_file2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/admin/CLionProjects/ds_learning/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable 0_file1_to_file2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/0_file1_to_file2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/0_file1_to_file2.dir/build: 0_file1_to_file2.exe

.PHONY : CMakeFiles/0_file1_to_file2.dir/build

CMakeFiles/0_file1_to_file2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/0_file1_to_file2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/0_file1_to_file2.dir/clean

CMakeFiles/0_file1_to_file2.dir/depend:
	cd /cygdrive/c/Users/admin/CLionProjects/ds_learning/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/admin/CLionProjects/ds_learning /cygdrive/c/Users/admin/CLionProjects/ds_learning /cygdrive/c/Users/admin/CLionProjects/ds_learning/cmake-build-debug /cygdrive/c/Users/admin/CLionProjects/ds_learning/cmake-build-debug /cygdrive/c/Users/admin/CLionProjects/ds_learning/cmake-build-debug/CMakeFiles/0_file1_to_file2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/0_file1_to_file2.dir/depend

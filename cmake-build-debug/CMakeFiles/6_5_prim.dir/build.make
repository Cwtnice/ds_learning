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
include CMakeFiles/6_5_Prim.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/6_5_Prim.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/6_5_Prim.dir/flags.make

CMakeFiles/6_5_Prim.dir/6_graph/6_5_Prim.cpp.o: CMakeFiles/6_5_Prim.dir/flags.make
CMakeFiles/6_5_Prim.dir/6_graph/6_5_Prim.cpp.o: ../6_graph/6_5_Prim.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/admin/CLionProjects/ds_learning/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/6_5_Prim.dir/6_graph/6_5_Prim.cpp.o"
	/usr/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/6_5_Prim.dir/6_graph/6_5_Prim.cpp.o -c /cygdrive/c/Users/admin/CLionProjects/ds_learning/6_graph/6_5_Prim.cpp

CMakeFiles/6_5_Prim.dir/6_graph/6_5_Prim.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/6_5_Prim.dir/6_graph/6_5_Prim.cpp.i"
	/usr/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/admin/CLionProjects/ds_learning/6_graph/6_5_Prim.cpp > CMakeFiles/6_5_Prim.dir/6_graph/6_5_Prim.cpp.i

CMakeFiles/6_5_Prim.dir/6_graph/6_5_Prim.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/6_5_Prim.dir/6_graph/6_5_Prim.cpp.s"
	/usr/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/admin/CLionProjects/ds_learning/6_graph/6_5_Prim.cpp -o CMakeFiles/6_5_Prim.dir/6_graph/6_5_Prim.cpp.s

# Object files for target 6_5_Prim
6_5_Prim_OBJECTS = \
"CMakeFiles/6_5_Prim.dir/6_graph/6_5_Prim.cpp.o"

# External object files for target 6_5_Prim
6_5_Prim_EXTERNAL_OBJECTS =

6_5_Prim.exe: CMakeFiles/6_5_Prim.dir/6_graph/6_5_Prim.cpp.o
6_5_Prim.exe: CMakeFiles/6_5_Prim.dir/build.make
6_5_Prim.exe: CMakeFiles/6_5_Prim.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/admin/CLionProjects/ds_learning/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 6_5_Prim.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/6_5_Prim.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/6_5_Prim.dir/build: 6_5_Prim.exe

.PHONY : CMakeFiles/6_5_Prim.dir/build

CMakeFiles/6_5_Prim.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/6_5_Prim.dir/cmake_clean.cmake
.PHONY : CMakeFiles/6_5_Prim.dir/clean

CMakeFiles/6_5_Prim.dir/depend:
	cd /cygdrive/c/Users/admin/CLionProjects/ds_learning/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/admin/CLionProjects/ds_learning /cygdrive/c/Users/admin/CLionProjects/ds_learning /cygdrive/c/Users/admin/CLionProjects/ds_learning/cmake-build-debug /cygdrive/c/Users/admin/CLionProjects/ds_learning/cmake-build-debug /cygdrive/c/Users/admin/CLionProjects/ds_learning/cmake-build-debug/CMakeFiles/6_5_Prim.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/6_5_Prim.dir/depend


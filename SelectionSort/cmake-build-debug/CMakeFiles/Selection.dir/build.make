# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.7

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Development\CLion 2017.1\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Development\CLion 2017.1\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\AlgorithmByCpp\SelectionSort

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\AlgorithmByCpp\SelectionSort\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Selection.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Selection.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Selection.dir/flags.make

CMakeFiles/Selection.dir/main.cpp.obj: CMakeFiles/Selection.dir/flags.make
CMakeFiles/Selection.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\AlgorithmByCpp\SelectionSort\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Selection.dir/main.cpp.obj"
	D:\DevelopEnviro\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Selection.dir\main.cpp.obj -c E:\AlgorithmByCpp\SelectionSort\main.cpp

CMakeFiles/Selection.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Selection.dir/main.cpp.i"
	D:\DevelopEnviro\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\AlgorithmByCpp\SelectionSort\main.cpp > CMakeFiles\Selection.dir\main.cpp.i

CMakeFiles/Selection.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Selection.dir/main.cpp.s"
	D:\DevelopEnviro\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\AlgorithmByCpp\SelectionSort\main.cpp -o CMakeFiles\Selection.dir\main.cpp.s

CMakeFiles/Selection.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/Selection.dir/main.cpp.obj.requires

CMakeFiles/Selection.dir/main.cpp.obj.provides: CMakeFiles/Selection.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Selection.dir\build.make CMakeFiles/Selection.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/Selection.dir/main.cpp.obj.provides

CMakeFiles/Selection.dir/main.cpp.obj.provides.build: CMakeFiles/Selection.dir/main.cpp.obj


# Object files for target Selection
Selection_OBJECTS = \
"CMakeFiles/Selection.dir/main.cpp.obj"

# External object files for target Selection
Selection_EXTERNAL_OBJECTS =

Selection.exe: CMakeFiles/Selection.dir/main.cpp.obj
Selection.exe: CMakeFiles/Selection.dir/build.make
Selection.exe: CMakeFiles/Selection.dir/linklibs.rsp
Selection.exe: CMakeFiles/Selection.dir/objects1.rsp
Selection.exe: CMakeFiles/Selection.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\AlgorithmByCpp\SelectionSort\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Selection.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Selection.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Selection.dir/build: Selection.exe

.PHONY : CMakeFiles/Selection.dir/build

CMakeFiles/Selection.dir/requires: CMakeFiles/Selection.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/Selection.dir/requires

CMakeFiles/Selection.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Selection.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Selection.dir/clean

CMakeFiles/Selection.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\AlgorithmByCpp\SelectionSort E:\AlgorithmByCpp\SelectionSort E:\AlgorithmByCpp\SelectionSort\cmake-build-debug E:\AlgorithmByCpp\SelectionSort\cmake-build-debug E:\AlgorithmByCpp\SelectionSort\cmake-build-debug\CMakeFiles\Selection.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Selection.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/yuan/XSpace/Study/DataStructureCpp/01-DynamicArray

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yuan/XSpace/Study/DataStructureCpp/01-DynamicArray/build

# Include any dependencies generated for this target.
include CMakeFiles/sharedLib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sharedLib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sharedLib.dir/flags.make

CMakeFiles/sharedLib.dir/DynamicArray.cpp.o: CMakeFiles/sharedLib.dir/flags.make
CMakeFiles/sharedLib.dir/DynamicArray.cpp.o: ../DynamicArray.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yuan/XSpace/Study/DataStructureCpp/01-DynamicArray/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sharedLib.dir/DynamicArray.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sharedLib.dir/DynamicArray.cpp.o -c /home/yuan/XSpace/Study/DataStructureCpp/01-DynamicArray/DynamicArray.cpp

CMakeFiles/sharedLib.dir/DynamicArray.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sharedLib.dir/DynamicArray.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yuan/XSpace/Study/DataStructureCpp/01-DynamicArray/DynamicArray.cpp > CMakeFiles/sharedLib.dir/DynamicArray.cpp.i

CMakeFiles/sharedLib.dir/DynamicArray.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sharedLib.dir/DynamicArray.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yuan/XSpace/Study/DataStructureCpp/01-DynamicArray/DynamicArray.cpp -o CMakeFiles/sharedLib.dir/DynamicArray.cpp.s

CMakeFiles/sharedLib.dir/DynamicArray.cpp.o.requires:

.PHONY : CMakeFiles/sharedLib.dir/DynamicArray.cpp.o.requires

CMakeFiles/sharedLib.dir/DynamicArray.cpp.o.provides: CMakeFiles/sharedLib.dir/DynamicArray.cpp.o.requires
	$(MAKE) -f CMakeFiles/sharedLib.dir/build.make CMakeFiles/sharedLib.dir/DynamicArray.cpp.o.provides.build
.PHONY : CMakeFiles/sharedLib.dir/DynamicArray.cpp.o.provides

CMakeFiles/sharedLib.dir/DynamicArray.cpp.o.provides.build: CMakeFiles/sharedLib.dir/DynamicArray.cpp.o


# Object files for target sharedLib
sharedLib_OBJECTS = \
"CMakeFiles/sharedLib.dir/DynamicArray.cpp.o"

# External object files for target sharedLib
sharedLib_EXTERNAL_OBJECTS =

libsharedLib.so: CMakeFiles/sharedLib.dir/DynamicArray.cpp.o
libsharedLib.so: CMakeFiles/sharedLib.dir/build.make
libsharedLib.so: CMakeFiles/sharedLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yuan/XSpace/Study/DataStructureCpp/01-DynamicArray/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libsharedLib.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sharedLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sharedLib.dir/build: libsharedLib.so

.PHONY : CMakeFiles/sharedLib.dir/build

CMakeFiles/sharedLib.dir/requires: CMakeFiles/sharedLib.dir/DynamicArray.cpp.o.requires

.PHONY : CMakeFiles/sharedLib.dir/requires

CMakeFiles/sharedLib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sharedLib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sharedLib.dir/clean

CMakeFiles/sharedLib.dir/depend:
	cd /home/yuan/XSpace/Study/DataStructureCpp/01-DynamicArray/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yuan/XSpace/Study/DataStructureCpp/01-DynamicArray /home/yuan/XSpace/Study/DataStructureCpp/01-DynamicArray /home/yuan/XSpace/Study/DataStructureCpp/01-DynamicArray/build /home/yuan/XSpace/Study/DataStructureCpp/01-DynamicArray/build /home/yuan/XSpace/Study/DataStructureCpp/01-DynamicArray/build/CMakeFiles/sharedLib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sharedLib.dir/depend


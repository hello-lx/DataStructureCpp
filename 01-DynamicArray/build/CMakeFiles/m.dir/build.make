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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/yuan/XSpace/Study/DataStructure/01-DynamicArray

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yuan/XSpace/Study/DataStructure/01-DynamicArray/build

# Include any dependencies generated for this target.
include CMakeFiles/m.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/m.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/m.dir/flags.make

CMakeFiles/m.dir/main.cpp.o: CMakeFiles/m.dir/flags.make
CMakeFiles/m.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yuan/XSpace/Study/DataStructure/01-DynamicArray/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/m.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/m.dir/main.cpp.o -c /home/yuan/XSpace/Study/DataStructure/01-DynamicArray/main.cpp

CMakeFiles/m.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/m.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yuan/XSpace/Study/DataStructure/01-DynamicArray/main.cpp > CMakeFiles/m.dir/main.cpp.i

CMakeFiles/m.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/m.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yuan/XSpace/Study/DataStructure/01-DynamicArray/main.cpp -o CMakeFiles/m.dir/main.cpp.s

CMakeFiles/m.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/m.dir/main.cpp.o.requires

CMakeFiles/m.dir/main.cpp.o.provides: CMakeFiles/m.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/m.dir/build.make CMakeFiles/m.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/m.dir/main.cpp.o.provides

CMakeFiles/m.dir/main.cpp.o.provides.build: CMakeFiles/m.dir/main.cpp.o


# Object files for target m
m_OBJECTS = \
"CMakeFiles/m.dir/main.cpp.o"

# External object files for target m
m_EXTERNAL_OBJECTS =

m : CMakeFiles/m.dir/main.cpp.o
m : CMakeFiles/m.dir/build.make
m : libsharedLib.so
m : CMakeFiles/m.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yuan/XSpace/Study/DataStructure/01-DynamicArray/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable m"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/m.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/m.dir/build: m

.PHONY : CMakeFiles/m.dir/build

CMakeFiles/m.dir/requires: CMakeFiles/m.dir/main.cpp.o.requires

.PHONY : CMakeFiles/m.dir/requires

CMakeFiles/m.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/m.dir/cmake_clean.cmake
.PHONY : CMakeFiles/m.dir/clean

CMakeFiles/m.dir/depend:
	cd /home/yuan/XSpace/Study/DataStructure/01-DynamicArray/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yuan/XSpace/Study/DataStructure/01-DynamicArray /home/yuan/XSpace/Study/DataStructure/01-DynamicArray /home/yuan/XSpace/Study/DataStructure/01-DynamicArray/build /home/yuan/XSpace/Study/DataStructure/01-DynamicArray/build /home/yuan/XSpace/Study/DataStructure/01-DynamicArray/build/CMakeFiles/m.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/m.dir/depend


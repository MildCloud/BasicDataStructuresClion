# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /home/tian-shu/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/212.4746.93/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/tian-shu/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/212.4746.93/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/tian-shu/Documents/C&C++Projects/SearchingBST"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/tian-shu/Documents/C&C++Projects/SearchingBST/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/SearchingBST.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/SearchingBST.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SearchingBST.dir/flags.make

CMakeFiles/SearchingBST.dir/main.cpp.o: CMakeFiles/SearchingBST.dir/flags.make
CMakeFiles/SearchingBST.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/tian-shu/Documents/C&C++Projects/SearchingBST/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SearchingBST.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SearchingBST.dir/main.cpp.o -c "/home/tian-shu/Documents/C&C++Projects/SearchingBST/main.cpp"

CMakeFiles/SearchingBST.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SearchingBST.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/tian-shu/Documents/C&C++Projects/SearchingBST/main.cpp" > CMakeFiles/SearchingBST.dir/main.cpp.i

CMakeFiles/SearchingBST.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SearchingBST.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/tian-shu/Documents/C&C++Projects/SearchingBST/main.cpp" -o CMakeFiles/SearchingBST.dir/main.cpp.s

# Object files for target SearchingBST
SearchingBST_OBJECTS = \
"CMakeFiles/SearchingBST.dir/main.cpp.o"

# External object files for target SearchingBST
SearchingBST_EXTERNAL_OBJECTS =

SearchingBST: CMakeFiles/SearchingBST.dir/main.cpp.o
SearchingBST: CMakeFiles/SearchingBST.dir/build.make
SearchingBST: CMakeFiles/SearchingBST.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/tian-shu/Documents/C&C++Projects/SearchingBST/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SearchingBST"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SearchingBST.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SearchingBST.dir/build: SearchingBST
.PHONY : CMakeFiles/SearchingBST.dir/build

CMakeFiles/SearchingBST.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SearchingBST.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SearchingBST.dir/clean

CMakeFiles/SearchingBST.dir/depend:
	cd "/home/tian-shu/Documents/C&C++Projects/SearchingBST/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/tian-shu/Documents/C&C++Projects/SearchingBST" "/home/tian-shu/Documents/C&C++Projects/SearchingBST" "/home/tian-shu/Documents/C&C++Projects/SearchingBST/cmake-build-debug" "/home/tian-shu/Documents/C&C++Projects/SearchingBST/cmake-build-debug" "/home/tian-shu/Documents/C&C++Projects/SearchingBST/cmake-build-debug/CMakeFiles/SearchingBST.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/SearchingBST.dir/depend

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
CMAKE_SOURCE_DIR = "/home/tian-shu/Documents/C&C++Projects/LinkStack"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/tian-shu/Documents/C&C++Projects/LinkStack/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/LinkStack.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/LinkStack.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LinkStack.dir/flags.make

CMakeFiles/LinkStack.dir/main.cpp.o: CMakeFiles/LinkStack.dir/flags.make
CMakeFiles/LinkStack.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/tian-shu/Documents/C&C++Projects/LinkStack/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LinkStack.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LinkStack.dir/main.cpp.o -c "/home/tian-shu/Documents/C&C++Projects/LinkStack/main.cpp"

CMakeFiles/LinkStack.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LinkStack.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/tian-shu/Documents/C&C++Projects/LinkStack/main.cpp" > CMakeFiles/LinkStack.dir/main.cpp.i

CMakeFiles/LinkStack.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LinkStack.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/tian-shu/Documents/C&C++Projects/LinkStack/main.cpp" -o CMakeFiles/LinkStack.dir/main.cpp.s

# Object files for target LinkStack
LinkStack_OBJECTS = \
"CMakeFiles/LinkStack.dir/main.cpp.o"

# External object files for target LinkStack
LinkStack_EXTERNAL_OBJECTS =

LinkStack: CMakeFiles/LinkStack.dir/main.cpp.o
LinkStack: CMakeFiles/LinkStack.dir/build.make
LinkStack: CMakeFiles/LinkStack.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/tian-shu/Documents/C&C++Projects/LinkStack/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable LinkStack"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LinkStack.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LinkStack.dir/build: LinkStack
.PHONY : CMakeFiles/LinkStack.dir/build

CMakeFiles/LinkStack.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LinkStack.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LinkStack.dir/clean

CMakeFiles/LinkStack.dir/depend:
	cd "/home/tian-shu/Documents/C&C++Projects/LinkStack/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/tian-shu/Documents/C&C++Projects/LinkStack" "/home/tian-shu/Documents/C&C++Projects/LinkStack" "/home/tian-shu/Documents/C&C++Projects/LinkStack/cmake-build-debug" "/home/tian-shu/Documents/C&C++Projects/LinkStack/cmake-build-debug" "/home/tian-shu/Documents/C&C++Projects/LinkStack/cmake-build-debug/CMakeFiles/LinkStack.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/LinkStack.dir/depend


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
CMAKE_COMMAND = /snap/clion/164/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/164/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/uliana/Neuron_Network

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/uliana/Neuron_Network/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Neuron_Network.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Neuron_Network.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Neuron_Network.dir/flags.make

CMakeFiles/Neuron_Network.dir/main.cpp.o: CMakeFiles/Neuron_Network.dir/flags.make
CMakeFiles/Neuron_Network.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uliana/Neuron_Network/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Neuron_Network.dir/main.cpp.o"
	/usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Neuron_Network.dir/main.cpp.o -c /home/uliana/Neuron_Network/main.cpp

CMakeFiles/Neuron_Network.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Neuron_Network.dir/main.cpp.i"
	/usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/uliana/Neuron_Network/main.cpp > CMakeFiles/Neuron_Network.dir/main.cpp.i

CMakeFiles/Neuron_Network.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Neuron_Network.dir/main.cpp.s"
	/usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/uliana/Neuron_Network/main.cpp -o CMakeFiles/Neuron_Network.dir/main.cpp.s

CMakeFiles/Neuron_Network.dir/Functions.cpp.o: CMakeFiles/Neuron_Network.dir/flags.make
CMakeFiles/Neuron_Network.dir/Functions.cpp.o: ../Functions.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uliana/Neuron_Network/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Neuron_Network.dir/Functions.cpp.o"
	/usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Neuron_Network.dir/Functions.cpp.o -c /home/uliana/Neuron_Network/Functions.cpp

CMakeFiles/Neuron_Network.dir/Functions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Neuron_Network.dir/Functions.cpp.i"
	/usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/uliana/Neuron_Network/Functions.cpp > CMakeFiles/Neuron_Network.dir/Functions.cpp.i

CMakeFiles/Neuron_Network.dir/Functions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Neuron_Network.dir/Functions.cpp.s"
	/usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/uliana/Neuron_Network/Functions.cpp -o CMakeFiles/Neuron_Network.dir/Functions.cpp.s

CMakeFiles/Neuron_Network.dir/ExpressionTree.cpp.o: CMakeFiles/Neuron_Network.dir/flags.make
CMakeFiles/Neuron_Network.dir/ExpressionTree.cpp.o: ../ExpressionTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uliana/Neuron_Network/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Neuron_Network.dir/ExpressionTree.cpp.o"
	/usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Neuron_Network.dir/ExpressionTree.cpp.o -c /home/uliana/Neuron_Network/ExpressionTree.cpp

CMakeFiles/Neuron_Network.dir/ExpressionTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Neuron_Network.dir/ExpressionTree.cpp.i"
	/usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/uliana/Neuron_Network/ExpressionTree.cpp > CMakeFiles/Neuron_Network.dir/ExpressionTree.cpp.i

CMakeFiles/Neuron_Network.dir/ExpressionTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Neuron_Network.dir/ExpressionTree.cpp.s"
	/usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/uliana/Neuron_Network/ExpressionTree.cpp -o CMakeFiles/Neuron_Network.dir/ExpressionTree.cpp.s

CMakeFiles/Neuron_Network.dir/Operations.cpp.o: CMakeFiles/Neuron_Network.dir/flags.make
CMakeFiles/Neuron_Network.dir/Operations.cpp.o: ../Operations.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uliana/Neuron_Network/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Neuron_Network.dir/Operations.cpp.o"
	/usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Neuron_Network.dir/Operations.cpp.o -c /home/uliana/Neuron_Network/Operations.cpp

CMakeFiles/Neuron_Network.dir/Operations.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Neuron_Network.dir/Operations.cpp.i"
	/usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/uliana/Neuron_Network/Operations.cpp > CMakeFiles/Neuron_Network.dir/Operations.cpp.i

CMakeFiles/Neuron_Network.dir/Operations.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Neuron_Network.dir/Operations.cpp.s"
	/usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/uliana/Neuron_Network/Operations.cpp -o CMakeFiles/Neuron_Network.dir/Operations.cpp.s

# Object files for target Neuron_Network
Neuron_Network_OBJECTS = \
"CMakeFiles/Neuron_Network.dir/main.cpp.o" \
"CMakeFiles/Neuron_Network.dir/Functions.cpp.o" \
"CMakeFiles/Neuron_Network.dir/ExpressionTree.cpp.o" \
"CMakeFiles/Neuron_Network.dir/Operations.cpp.o"

# External object files for target Neuron_Network
Neuron_Network_EXTERNAL_OBJECTS =

Neuron_Network: CMakeFiles/Neuron_Network.dir/main.cpp.o
Neuron_Network: CMakeFiles/Neuron_Network.dir/Functions.cpp.o
Neuron_Network: CMakeFiles/Neuron_Network.dir/ExpressionTree.cpp.o
Neuron_Network: CMakeFiles/Neuron_Network.dir/Operations.cpp.o
Neuron_Network: CMakeFiles/Neuron_Network.dir/build.make
Neuron_Network: CMakeFiles/Neuron_Network.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/uliana/Neuron_Network/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Neuron_Network"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Neuron_Network.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Neuron_Network.dir/build: Neuron_Network
.PHONY : CMakeFiles/Neuron_Network.dir/build

CMakeFiles/Neuron_Network.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Neuron_Network.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Neuron_Network.dir/clean

CMakeFiles/Neuron_Network.dir/depend:
	cd /home/uliana/Neuron_Network/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/uliana/Neuron_Network /home/uliana/Neuron_Network /home/uliana/Neuron_Network/cmake-build-debug /home/uliana/Neuron_Network/cmake-build-debug /home/uliana/Neuron_Network/cmake-build-debug/CMakeFiles/Neuron_Network.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Neuron_Network.dir/depend


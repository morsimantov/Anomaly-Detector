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
CMAKE_COMMAND = /usr/bin/cmake.exe

# The command to remove a file.
RM = /usr/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/adifi/CLionProjects/mor-shai-project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/adifi/CLionProjects/mor-shai-project/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/anomaly_detection_util.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/anomaly_detection_util.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/anomaly_detection_util.dir/flags.make

CMakeFiles/anomaly_detection_util.dir/anomaly_detection_util.cpp.o: CMakeFiles/anomaly_detection_util.dir/flags.make
CMakeFiles/anomaly_detection_util.dir/anomaly_detection_util.cpp.o: ../anomaly_detection_util.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/adifi/CLionProjects/mor-shai-project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/anomaly_detection_util.dir/anomaly_detection_util.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/anomaly_detection_util.dir/anomaly_detection_util.cpp.o -c /cygdrive/c/Users/adifi/CLionProjects/mor-shai-project/anomaly_detection_util.cpp

CMakeFiles/anomaly_detection_util.dir/anomaly_detection_util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/anomaly_detection_util.dir/anomaly_detection_util.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/adifi/CLionProjects/mor-shai-project/anomaly_detection_util.cpp > CMakeFiles/anomaly_detection_util.dir/anomaly_detection_util.cpp.i

CMakeFiles/anomaly_detection_util.dir/anomaly_detection_util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/anomaly_detection_util.dir/anomaly_detection_util.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/adifi/CLionProjects/mor-shai-project/anomaly_detection_util.cpp -o CMakeFiles/anomaly_detection_util.dir/anomaly_detection_util.cpp.s

# Object files for target anomaly_detection_util
anomaly_detection_util_OBJECTS = \
"CMakeFiles/anomaly_detection_util.dir/anomaly_detection_util.cpp.o"

# External object files for target anomaly_detection_util
anomaly_detection_util_EXTERNAL_OBJECTS =

anomaly_detection_util.exe: CMakeFiles/anomaly_detection_util.dir/anomaly_detection_util.cpp.o
anomaly_detection_util.exe: CMakeFiles/anomaly_detection_util.dir/build.make
anomaly_detection_util.exe: CMakeFiles/anomaly_detection_util.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/adifi/CLionProjects/mor-shai-project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable anomaly_detection_util.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/anomaly_detection_util.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/anomaly_detection_util.dir/build: anomaly_detection_util.exe

.PHONY : CMakeFiles/anomaly_detection_util.dir/build

CMakeFiles/anomaly_detection_util.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/anomaly_detection_util.dir/cmake_clean.cmake
.PHONY : CMakeFiles/anomaly_detection_util.dir/clean

CMakeFiles/anomaly_detection_util.dir/depend:
	cd /cygdrive/c/Users/adifi/CLionProjects/mor-shai-project/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/adifi/CLionProjects/mor-shai-project /cygdrive/c/Users/adifi/CLionProjects/mor-shai-project /cygdrive/c/Users/adifi/CLionProjects/mor-shai-project/cmake-build-debug /cygdrive/c/Users/adifi/CLionProjects/mor-shai-project/cmake-build-debug /cygdrive/c/Users/adifi/CLionProjects/mor-shai-project/cmake-build-debug/CMakeFiles/anomaly_detection_util.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/anomaly_detection_util.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Projects\anomalyDetector

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Projects\anomalyDetector\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/anomalyDetector.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/anomalyDetector.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/anomalyDetector.dir/flags.make

CMakeFiles/anomalyDetector.dir/anomaly_detection_util.cpp.obj: CMakeFiles/anomalyDetector.dir/flags.make
CMakeFiles/anomalyDetector.dir/anomaly_detection_util.cpp.obj: ../anomaly_detection_util.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Projects\anomalyDetector\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/anomalyDetector.dir/anomaly_detection_util.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\anomalyDetector.dir\anomaly_detection_util.cpp.obj -c C:\Projects\anomalyDetector\anomaly_detection_util.cpp

CMakeFiles/anomalyDetector.dir/anomaly_detection_util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/anomalyDetector.dir/anomaly_detection_util.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Projects\anomalyDetector\anomaly_detection_util.cpp > CMakeFiles\anomalyDetector.dir\anomaly_detection_util.cpp.i

CMakeFiles/anomalyDetector.dir/anomaly_detection_util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/anomalyDetector.dir/anomaly_detection_util.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Projects\anomalyDetector\anomaly_detection_util.cpp -o CMakeFiles\anomalyDetector.dir\anomaly_detection_util.cpp.s

CMakeFiles/anomalyDetector.dir/SimpleAnomalyDetector.cpp.obj: CMakeFiles/anomalyDetector.dir/flags.make
CMakeFiles/anomalyDetector.dir/SimpleAnomalyDetector.cpp.obj: ../SimpleAnomalyDetector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Projects\anomalyDetector\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/anomalyDetector.dir/SimpleAnomalyDetector.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\anomalyDetector.dir\SimpleAnomalyDetector.cpp.obj -c C:\Projects\anomalyDetector\SimpleAnomalyDetector.cpp

CMakeFiles/anomalyDetector.dir/SimpleAnomalyDetector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/anomalyDetector.dir/SimpleAnomalyDetector.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Projects\anomalyDetector\SimpleAnomalyDetector.cpp > CMakeFiles\anomalyDetector.dir\SimpleAnomalyDetector.cpp.i

CMakeFiles/anomalyDetector.dir/SimpleAnomalyDetector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/anomalyDetector.dir/SimpleAnomalyDetector.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Projects\anomalyDetector\SimpleAnomalyDetector.cpp -o CMakeFiles\anomalyDetector.dir\SimpleAnomalyDetector.cpp.s

CMakeFiles/anomalyDetector.dir/timeseries.cpp.obj: CMakeFiles/anomalyDetector.dir/flags.make
CMakeFiles/anomalyDetector.dir/timeseries.cpp.obj: ../timeseries.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Projects\anomalyDetector\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/anomalyDetector.dir/timeseries.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\anomalyDetector.dir\timeseries.cpp.obj -c C:\Projects\anomalyDetector\timeseries.cpp

CMakeFiles/anomalyDetector.dir/timeseries.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/anomalyDetector.dir/timeseries.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Projects\anomalyDetector\timeseries.cpp > CMakeFiles\anomalyDetector.dir\timeseries.cpp.i

CMakeFiles/anomalyDetector.dir/timeseries.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/anomalyDetector.dir/timeseries.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Projects\anomalyDetector\timeseries.cpp -o CMakeFiles\anomalyDetector.dir\timeseries.cpp.s

CMakeFiles/anomalyDetector.dir/MainTrain.cpp.obj: CMakeFiles/anomalyDetector.dir/flags.make
CMakeFiles/anomalyDetector.dir/MainTrain.cpp.obj: ../MainTrain.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Projects\anomalyDetector\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/anomalyDetector.dir/MainTrain.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\anomalyDetector.dir\MainTrain.cpp.obj -c C:\Projects\anomalyDetector\MainTrain.cpp

CMakeFiles/anomalyDetector.dir/MainTrain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/anomalyDetector.dir/MainTrain.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Projects\anomalyDetector\MainTrain.cpp > CMakeFiles\anomalyDetector.dir\MainTrain.cpp.i

CMakeFiles/anomalyDetector.dir/MainTrain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/anomalyDetector.dir/MainTrain.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Projects\anomalyDetector\MainTrain.cpp -o CMakeFiles\anomalyDetector.dir\MainTrain.cpp.s

CMakeFiles/anomalyDetector.dir/minCircle.cpp.obj: CMakeFiles/anomalyDetector.dir/flags.make
CMakeFiles/anomalyDetector.dir/minCircle.cpp.obj: ../minCircle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Projects\anomalyDetector\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/anomalyDetector.dir/minCircle.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\anomalyDetector.dir\minCircle.cpp.obj -c C:\Projects\anomalyDetector\minCircle.cpp

CMakeFiles/anomalyDetector.dir/minCircle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/anomalyDetector.dir/minCircle.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Projects\anomalyDetector\minCircle.cpp > CMakeFiles\anomalyDetector.dir\minCircle.cpp.i

CMakeFiles/anomalyDetector.dir/minCircle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/anomalyDetector.dir/minCircle.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Projects\anomalyDetector\minCircle.cpp -o CMakeFiles\anomalyDetector.dir\minCircle.cpp.s

CMakeFiles/anomalyDetector.dir/HybridAnomalyDetector.cpp.obj: CMakeFiles/anomalyDetector.dir/flags.make
CMakeFiles/anomalyDetector.dir/HybridAnomalyDetector.cpp.obj: ../HybridAnomalyDetector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Projects\anomalyDetector\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/anomalyDetector.dir/HybridAnomalyDetector.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\anomalyDetector.dir\HybridAnomalyDetector.cpp.obj -c C:\Projects\anomalyDetector\HybridAnomalyDetector.cpp

CMakeFiles/anomalyDetector.dir/HybridAnomalyDetector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/anomalyDetector.dir/HybridAnomalyDetector.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Projects\anomalyDetector\HybridAnomalyDetector.cpp > CMakeFiles\anomalyDetector.dir\HybridAnomalyDetector.cpp.i

CMakeFiles/anomalyDetector.dir/HybridAnomalyDetector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/anomalyDetector.dir/HybridAnomalyDetector.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Projects\anomalyDetector\HybridAnomalyDetector.cpp -o CMakeFiles\anomalyDetector.dir\HybridAnomalyDetector.cpp.s

CMakeFiles/anomalyDetector.dir/CLI.cpp.obj: CMakeFiles/anomalyDetector.dir/flags.make
CMakeFiles/anomalyDetector.dir/CLI.cpp.obj: ../CLI.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Projects\anomalyDetector\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/anomalyDetector.dir/CLI.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\anomalyDetector.dir\CLI.cpp.obj -c C:\Projects\anomalyDetector\CLI.cpp

CMakeFiles/anomalyDetector.dir/CLI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/anomalyDetector.dir/CLI.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Projects\anomalyDetector\CLI.cpp > CMakeFiles\anomalyDetector.dir\CLI.cpp.i

CMakeFiles/anomalyDetector.dir/CLI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/anomalyDetector.dir/CLI.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Projects\anomalyDetector\CLI.cpp -o CMakeFiles\anomalyDetector.dir\CLI.cpp.s

CMakeFiles/anomalyDetector.dir/server.cpp.obj: CMakeFiles/anomalyDetector.dir/flags.make
CMakeFiles/anomalyDetector.dir/server.cpp.obj: ../server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Projects\anomalyDetector\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/anomalyDetector.dir/server.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\anomalyDetector.dir\server.cpp.obj -c C:\Projects\anomalyDetector\server.cpp

CMakeFiles/anomalyDetector.dir/server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/anomalyDetector.dir/server.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Projects\anomalyDetector\server.cpp > CMakeFiles\anomalyDetector.dir\server.cpp.i

CMakeFiles/anomalyDetector.dir/server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/anomalyDetector.dir/server.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Projects\anomalyDetector\server.cpp -o CMakeFiles\anomalyDetector.dir\server.cpp.s

# Object files for target anomalyDetector
anomalyDetector_OBJECTS = \
"CMakeFiles/anomalyDetector.dir/anomaly_detection_util.cpp.obj" \
"CMakeFiles/anomalyDetector.dir/SimpleAnomalyDetector.cpp.obj" \
"CMakeFiles/anomalyDetector.dir/timeseries.cpp.obj" \
"CMakeFiles/anomalyDetector.dir/MainTrain.cpp.obj" \
"CMakeFiles/anomalyDetector.dir/minCircle.cpp.obj" \
"CMakeFiles/anomalyDetector.dir/HybridAnomalyDetector.cpp.obj" \
"CMakeFiles/anomalyDetector.dir/CLI.cpp.obj" \
"CMakeFiles/anomalyDetector.dir/server.cpp.obj"

# External object files for target anomalyDetector
anomalyDetector_EXTERNAL_OBJECTS =

anomalyDetector.exe: CMakeFiles/anomalyDetector.dir/anomaly_detection_util.cpp.obj
anomalyDetector.exe: CMakeFiles/anomalyDetector.dir/SimpleAnomalyDetector.cpp.obj
anomalyDetector.exe: CMakeFiles/anomalyDetector.dir/timeseries.cpp.obj
anomalyDetector.exe: CMakeFiles/anomalyDetector.dir/MainTrain.cpp.obj
anomalyDetector.exe: CMakeFiles/anomalyDetector.dir/minCircle.cpp.obj
anomalyDetector.exe: CMakeFiles/anomalyDetector.dir/HybridAnomalyDetector.cpp.obj
anomalyDetector.exe: CMakeFiles/anomalyDetector.dir/CLI.cpp.obj
anomalyDetector.exe: CMakeFiles/anomalyDetector.dir/server.cpp.obj
anomalyDetector.exe: CMakeFiles/anomalyDetector.dir/build.make
anomalyDetector.exe: CMakeFiles/anomalyDetector.dir/linklibs.rsp
anomalyDetector.exe: CMakeFiles/anomalyDetector.dir/objects1.rsp
anomalyDetector.exe: CMakeFiles/anomalyDetector.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Projects\anomalyDetector\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable anomalyDetector.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\anomalyDetector.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/anomalyDetector.dir/build: anomalyDetector.exe

.PHONY : CMakeFiles/anomalyDetector.dir/build

CMakeFiles/anomalyDetector.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\anomalyDetector.dir\cmake_clean.cmake
.PHONY : CMakeFiles/anomalyDetector.dir/clean

CMakeFiles/anomalyDetector.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Projects\anomalyDetector C:\Projects\anomalyDetector C:\Projects\anomalyDetector\cmake-build-debug C:\Projects\anomalyDetector\cmake-build-debug C:\Projects\anomalyDetector\cmake-build-debug\CMakeFiles\anomalyDetector.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/anomalyDetector.dir/depend


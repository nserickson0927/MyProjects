# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.4

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
CMAKE_SOURCE_DIR = /mnt/nfs/netapp2/students/nserickson/CS3210_erickson/IC05

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/nfs/netapp2/students/nserickson/CS3210_erickson/IC05/build

# Include any dependencies generated for this target.
include CMakeFiles/ic05.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ic05.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ic05.dir/flags.make

CMakeFiles/ic05.dir/main.cpp.o: CMakeFiles/ic05.dir/flags.make
CMakeFiles/ic05.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/nfs/netapp2/students/nserickson/CS3210_erickson/IC05/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ic05.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ic05.dir/main.cpp.o -c /mnt/nfs/netapp2/students/nserickson/CS3210_erickson/IC05/main.cpp

CMakeFiles/ic05.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ic05.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/nfs/netapp2/students/nserickson/CS3210_erickson/IC05/main.cpp > CMakeFiles/ic05.dir/main.cpp.i

CMakeFiles/ic05.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ic05.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/nfs/netapp2/students/nserickson/CS3210_erickson/IC05/main.cpp -o CMakeFiles/ic05.dir/main.cpp.s

CMakeFiles/ic05.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/ic05.dir/main.cpp.o.requires

CMakeFiles/ic05.dir/main.cpp.o.provides: CMakeFiles/ic05.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/ic05.dir/build.make CMakeFiles/ic05.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/ic05.dir/main.cpp.o.provides

CMakeFiles/ic05.dir/main.cpp.o.provides.build: CMakeFiles/ic05.dir/main.cpp.o


CMakeFiles/ic05.dir/vector.cpp.o: CMakeFiles/ic05.dir/flags.make
CMakeFiles/ic05.dir/vector.cpp.o: ../vector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/nfs/netapp2/students/nserickson/CS3210_erickson/IC05/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ic05.dir/vector.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ic05.dir/vector.cpp.o -c /mnt/nfs/netapp2/students/nserickson/CS3210_erickson/IC05/vector.cpp

CMakeFiles/ic05.dir/vector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ic05.dir/vector.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/nfs/netapp2/students/nserickson/CS3210_erickson/IC05/vector.cpp > CMakeFiles/ic05.dir/vector.cpp.i

CMakeFiles/ic05.dir/vector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ic05.dir/vector.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/nfs/netapp2/students/nserickson/CS3210_erickson/IC05/vector.cpp -o CMakeFiles/ic05.dir/vector.cpp.s

CMakeFiles/ic05.dir/vector.cpp.o.requires:

.PHONY : CMakeFiles/ic05.dir/vector.cpp.o.requires

CMakeFiles/ic05.dir/vector.cpp.o.provides: CMakeFiles/ic05.dir/vector.cpp.o.requires
	$(MAKE) -f CMakeFiles/ic05.dir/build.make CMakeFiles/ic05.dir/vector.cpp.o.provides.build
.PHONY : CMakeFiles/ic05.dir/vector.cpp.o.provides

CMakeFiles/ic05.dir/vector.cpp.o.provides.build: CMakeFiles/ic05.dir/vector.cpp.o


# Object files for target ic05
ic05_OBJECTS = \
"CMakeFiles/ic05.dir/main.cpp.o" \
"CMakeFiles/ic05.dir/vector.cpp.o"

# External object files for target ic05
ic05_EXTERNAL_OBJECTS =

ic05: CMakeFiles/ic05.dir/main.cpp.o
ic05: CMakeFiles/ic05.dir/vector.cpp.o
ic05: CMakeFiles/ic05.dir/build.make
ic05: CMakeFiles/ic05.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/nfs/netapp2/students/nserickson/CS3210_erickson/IC05/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ic05"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ic05.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ic05.dir/build: ic05

.PHONY : CMakeFiles/ic05.dir/build

CMakeFiles/ic05.dir/requires: CMakeFiles/ic05.dir/main.cpp.o.requires
CMakeFiles/ic05.dir/requires: CMakeFiles/ic05.dir/vector.cpp.o.requires

.PHONY : CMakeFiles/ic05.dir/requires

CMakeFiles/ic05.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ic05.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ic05.dir/clean

CMakeFiles/ic05.dir/depend:
	cd /mnt/nfs/netapp2/students/nserickson/CS3210_erickson/IC05/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/nfs/netapp2/students/nserickson/CS3210_erickson/IC05 /mnt/nfs/netapp2/students/nserickson/CS3210_erickson/IC05 /mnt/nfs/netapp2/students/nserickson/CS3210_erickson/IC05/build /mnt/nfs/netapp2/students/nserickson/CS3210_erickson/IC05/build /mnt/nfs/netapp2/students/nserickson/CS3210_erickson/IC05/build/CMakeFiles/ic05.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ic05.dir/depend


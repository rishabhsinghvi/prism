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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.17.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.17.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/rishabh/desktop/prism

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/rishabh/desktop/prism/build

# Include any dependencies generated for this target.
include CMakeFiles/prism.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/prism.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/prism.dir/flags.make

CMakeFiles/prism.dir/src/prism_frame_allocator.c.o: CMakeFiles/prism.dir/flags.make
CMakeFiles/prism.dir/src/prism_frame_allocator.c.o: ../src/prism_frame_allocator.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rishabh/desktop/prism/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/prism.dir/src/prism_frame_allocator.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/prism.dir/src/prism_frame_allocator.c.o   -c /Users/rishabh/desktop/prism/src/prism_frame_allocator.c

CMakeFiles/prism.dir/src/prism_frame_allocator.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/prism.dir/src/prism_frame_allocator.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rishabh/desktop/prism/src/prism_frame_allocator.c > CMakeFiles/prism.dir/src/prism_frame_allocator.c.i

CMakeFiles/prism.dir/src/prism_frame_allocator.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/prism.dir/src/prism_frame_allocator.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rishabh/desktop/prism/src/prism_frame_allocator.c -o CMakeFiles/prism.dir/src/prism_frame_allocator.c.s

CMakeFiles/prism.dir/src/prism_vec3f.c.o: CMakeFiles/prism.dir/flags.make
CMakeFiles/prism.dir/src/prism_vec3f.c.o: ../src/prism_vec3f.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rishabh/desktop/prism/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/prism.dir/src/prism_vec3f.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/prism.dir/src/prism_vec3f.c.o   -c /Users/rishabh/desktop/prism/src/prism_vec3f.c

CMakeFiles/prism.dir/src/prism_vec3f.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/prism.dir/src/prism_vec3f.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/rishabh/desktop/prism/src/prism_vec3f.c > CMakeFiles/prism.dir/src/prism_vec3f.c.i

CMakeFiles/prism.dir/src/prism_vec3f.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/prism.dir/src/prism_vec3f.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/rishabh/desktop/prism/src/prism_vec3f.c -o CMakeFiles/prism.dir/src/prism_vec3f.c.s

# Object files for target prism
prism_OBJECTS = \
"CMakeFiles/prism.dir/src/prism_frame_allocator.c.o" \
"CMakeFiles/prism.dir/src/prism_vec3f.c.o"

# External object files for target prism
prism_EXTERNAL_OBJECTS =

libprism.a: CMakeFiles/prism.dir/src/prism_frame_allocator.c.o
libprism.a: CMakeFiles/prism.dir/src/prism_vec3f.c.o
libprism.a: CMakeFiles/prism.dir/build.make
libprism.a: CMakeFiles/prism.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/rishabh/desktop/prism/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C static library libprism.a"
	$(CMAKE_COMMAND) -P CMakeFiles/prism.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/prism.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/prism.dir/build: libprism.a

.PHONY : CMakeFiles/prism.dir/build

CMakeFiles/prism.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/prism.dir/cmake_clean.cmake
.PHONY : CMakeFiles/prism.dir/clean

CMakeFiles/prism.dir/depend:
	cd /Users/rishabh/desktop/prism/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/rishabh/desktop/prism /Users/rishabh/desktop/prism /Users/rishabh/desktop/prism/build /Users/rishabh/desktop/prism/build /Users/rishabh/desktop/prism/build/CMakeFiles/prism.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/prism.dir/depend


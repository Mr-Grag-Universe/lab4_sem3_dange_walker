# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build"

# Include any dependencies generated for this target.
include src/libs/glfw-3.3.8/tests/CMakeFiles/msaa.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/libs/glfw-3.3.8/tests/CMakeFiles/msaa.dir/compiler_depend.make

# Include the progress variables for this target.
include src/libs/glfw-3.3.8/tests/CMakeFiles/msaa.dir/progress.make

# Include the compile flags for this target's objects.
include src/libs/glfw-3.3.8/tests/CMakeFiles/msaa.dir/flags.make

src/libs/glfw-3.3.8/tests/CMakeFiles/msaa.dir/msaa.c.o: src/libs/glfw-3.3.8/tests/CMakeFiles/msaa.dir/flags.make
src/libs/glfw-3.3.8/tests/CMakeFiles/msaa.dir/msaa.c.o: /media/stepan/Windows\ 10\ Compact/Users/Stephan/Desktop/vs_code_game/src/libs/glfw-3.3.8/tests/msaa.c
src/libs/glfw-3.3.8/tests/CMakeFiles/msaa.dir/msaa.c.o: src/libs/glfw-3.3.8/tests/CMakeFiles/msaa.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/libs/glfw-3.3.8/tests/CMakeFiles/msaa.dir/msaa.c.o"
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/glfw-3.3.8/tests" && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/libs/glfw-3.3.8/tests/CMakeFiles/msaa.dir/msaa.c.o -MF CMakeFiles/msaa.dir/msaa.c.o.d -o CMakeFiles/msaa.dir/msaa.c.o -c "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/libs/glfw-3.3.8/tests/msaa.c"

src/libs/glfw-3.3.8/tests/CMakeFiles/msaa.dir/msaa.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/msaa.dir/msaa.c.i"
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/glfw-3.3.8/tests" && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/libs/glfw-3.3.8/tests/msaa.c" > CMakeFiles/msaa.dir/msaa.c.i

src/libs/glfw-3.3.8/tests/CMakeFiles/msaa.dir/msaa.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/msaa.dir/msaa.c.s"
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/glfw-3.3.8/tests" && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/libs/glfw-3.3.8/tests/msaa.c" -o CMakeFiles/msaa.dir/msaa.c.s

src/libs/glfw-3.3.8/tests/CMakeFiles/msaa.dir/__/deps/getopt.c.o: src/libs/glfw-3.3.8/tests/CMakeFiles/msaa.dir/flags.make
src/libs/glfw-3.3.8/tests/CMakeFiles/msaa.dir/__/deps/getopt.c.o: /media/stepan/Windows\ 10\ Compact/Users/Stephan/Desktop/vs_code_game/src/libs/glfw-3.3.8/deps/getopt.c
src/libs/glfw-3.3.8/tests/CMakeFiles/msaa.dir/__/deps/getopt.c.o: src/libs/glfw-3.3.8/tests/CMakeFiles/msaa.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object src/libs/glfw-3.3.8/tests/CMakeFiles/msaa.dir/__/deps/getopt.c.o"
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/glfw-3.3.8/tests" && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/libs/glfw-3.3.8/tests/CMakeFiles/msaa.dir/__/deps/getopt.c.o -MF CMakeFiles/msaa.dir/__/deps/getopt.c.o.d -o CMakeFiles/msaa.dir/__/deps/getopt.c.o -c "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/libs/glfw-3.3.8/deps/getopt.c"

src/libs/glfw-3.3.8/tests/CMakeFiles/msaa.dir/__/deps/getopt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/msaa.dir/__/deps/getopt.c.i"
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/glfw-3.3.8/tests" && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/libs/glfw-3.3.8/deps/getopt.c" > CMakeFiles/msaa.dir/__/deps/getopt.c.i

src/libs/glfw-3.3.8/tests/CMakeFiles/msaa.dir/__/deps/getopt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/msaa.dir/__/deps/getopt.c.s"
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/glfw-3.3.8/tests" && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/libs/glfw-3.3.8/deps/getopt.c" -o CMakeFiles/msaa.dir/__/deps/getopt.c.s

src/libs/glfw-3.3.8/tests/CMakeFiles/msaa.dir/__/deps/glad_gl.c.o: src/libs/glfw-3.3.8/tests/CMakeFiles/msaa.dir/flags.make
src/libs/glfw-3.3.8/tests/CMakeFiles/msaa.dir/__/deps/glad_gl.c.o: /media/stepan/Windows\ 10\ Compact/Users/Stephan/Desktop/vs_code_game/src/libs/glfw-3.3.8/deps/glad_gl.c
src/libs/glfw-3.3.8/tests/CMakeFiles/msaa.dir/__/deps/glad_gl.c.o: src/libs/glfw-3.3.8/tests/CMakeFiles/msaa.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object src/libs/glfw-3.3.8/tests/CMakeFiles/msaa.dir/__/deps/glad_gl.c.o"
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/glfw-3.3.8/tests" && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/libs/glfw-3.3.8/tests/CMakeFiles/msaa.dir/__/deps/glad_gl.c.o -MF CMakeFiles/msaa.dir/__/deps/glad_gl.c.o.d -o CMakeFiles/msaa.dir/__/deps/glad_gl.c.o -c "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/libs/glfw-3.3.8/deps/glad_gl.c"

src/libs/glfw-3.3.8/tests/CMakeFiles/msaa.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/msaa.dir/__/deps/glad_gl.c.i"
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/glfw-3.3.8/tests" && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/libs/glfw-3.3.8/deps/glad_gl.c" > CMakeFiles/msaa.dir/__/deps/glad_gl.c.i

src/libs/glfw-3.3.8/tests/CMakeFiles/msaa.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/msaa.dir/__/deps/glad_gl.c.s"
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/glfw-3.3.8/tests" && /usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/libs/glfw-3.3.8/deps/glad_gl.c" -o CMakeFiles/msaa.dir/__/deps/glad_gl.c.s

# Object files for target msaa
msaa_OBJECTS = \
"CMakeFiles/msaa.dir/msaa.c.o" \
"CMakeFiles/msaa.dir/__/deps/getopt.c.o" \
"CMakeFiles/msaa.dir/__/deps/glad_gl.c.o"

# External object files for target msaa
msaa_EXTERNAL_OBJECTS =

src/libs/glfw-3.3.8/tests/msaa: src/libs/glfw-3.3.8/tests/CMakeFiles/msaa.dir/msaa.c.o
src/libs/glfw-3.3.8/tests/msaa: src/libs/glfw-3.3.8/tests/CMakeFiles/msaa.dir/__/deps/getopt.c.o
src/libs/glfw-3.3.8/tests/msaa: src/libs/glfw-3.3.8/tests/CMakeFiles/msaa.dir/__/deps/glad_gl.c.o
src/libs/glfw-3.3.8/tests/msaa: src/libs/glfw-3.3.8/tests/CMakeFiles/msaa.dir/build.make
src/libs/glfw-3.3.8/tests/msaa: src/libs/glfw-3.3.8/src/libglfw3.a
src/libs/glfw-3.3.8/tests/msaa: /usr/lib/x86_64-linux-gnu/libm.so
src/libs/glfw-3.3.8/tests/msaa: /usr/lib/x86_64-linux-gnu/librt.a
src/libs/glfw-3.3.8/tests/msaa: /usr/lib/x86_64-linux-gnu/libm.so
src/libs/glfw-3.3.8/tests/msaa: /usr/lib/x86_64-linux-gnu/libX11.so
src/libs/glfw-3.3.8/tests/msaa: src/libs/glfw-3.3.8/tests/CMakeFiles/msaa.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable msaa"
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/glfw-3.3.8/tests" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/msaa.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/libs/glfw-3.3.8/tests/CMakeFiles/msaa.dir/build: src/libs/glfw-3.3.8/tests/msaa
.PHONY : src/libs/glfw-3.3.8/tests/CMakeFiles/msaa.dir/build

src/libs/glfw-3.3.8/tests/CMakeFiles/msaa.dir/clean:
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/glfw-3.3.8/tests" && $(CMAKE_COMMAND) -P CMakeFiles/msaa.dir/cmake_clean.cmake
.PHONY : src/libs/glfw-3.3.8/tests/CMakeFiles/msaa.dir/clean

src/libs/glfw-3.3.8/tests/CMakeFiles/msaa.dir/depend:
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game" "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/libs/glfw-3.3.8/tests" "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build" "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/glfw-3.3.8/tests" "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/glfw-3.3.8/tests/CMakeFiles/msaa.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : src/libs/glfw-3.3.8/tests/CMakeFiles/msaa.dir/depend


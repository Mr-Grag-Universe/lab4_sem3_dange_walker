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
include test/lib/googletest-main/googletest-main/googletest/CMakeFiles/gtest_main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/lib/googletest-main/googletest-main/googletest/CMakeFiles/gtest_main.dir/compiler_depend.make

# Include the progress variables for this target.
include test/lib/googletest-main/googletest-main/googletest/CMakeFiles/gtest_main.dir/progress.make

# Include the compile flags for this target's objects.
include test/lib/googletest-main/googletest-main/googletest/CMakeFiles/gtest_main.dir/flags.make

test/lib/googletest-main/googletest-main/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o: test/lib/googletest-main/googletest-main/googletest/CMakeFiles/gtest_main.dir/flags.make
test/lib/googletest-main/googletest-main/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o: /media/stepan/Windows\ 10\ Compact/Users/Stephan/Desktop/vs_code_game/test/lib/googletest-main/googletest-main/googletest/src/gtest_main.cc
test/lib/googletest-main/googletest-main/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o: test/lib/googletest-main/googletest-main/googletest/CMakeFiles/gtest_main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/lib/googletest-main/googletest-main/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o"
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/test/lib/googletest-main/googletest-main/googletest" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/lib/googletest-main/googletest-main/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o -MF CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.d -o CMakeFiles/gtest_main.dir/src/gtest_main.cc.o -c "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/test/lib/googletest-main/googletest-main/googletest/src/gtest_main.cc"

test/lib/googletest-main/googletest-main/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest_main.dir/src/gtest_main.cc.i"
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/test/lib/googletest-main/googletest-main/googletest" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/test/lib/googletest-main/googletest-main/googletest/src/gtest_main.cc" > CMakeFiles/gtest_main.dir/src/gtest_main.cc.i

test/lib/googletest-main/googletest-main/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest_main.dir/src/gtest_main.cc.s"
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/test/lib/googletest-main/googletest-main/googletest" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/test/lib/googletest-main/googletest-main/googletest/src/gtest_main.cc" -o CMakeFiles/gtest_main.dir/src/gtest_main.cc.s

# Object files for target gtest_main
gtest_main_OBJECTS = \
"CMakeFiles/gtest_main.dir/src/gtest_main.cc.o"

# External object files for target gtest_main
gtest_main_EXTERNAL_OBJECTS =

lib/libgtest_main.so.1.11.0: test/lib/googletest-main/googletest-main/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o
lib/libgtest_main.so.1.11.0: test/lib/googletest-main/googletest-main/googletest/CMakeFiles/gtest_main.dir/build.make
lib/libgtest_main.so.1.11.0: lib/libgtest.so.1.11.0
lib/libgtest_main.so.1.11.0: test/lib/googletest-main/googletest-main/googletest/CMakeFiles/gtest_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library ../../../../../lib/libgtest_main.so"
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/test/lib/googletest-main/googletest-main/googletest" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest_main.dir/link.txt --verbose=$(VERBOSE)
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/test/lib/googletest-main/googletest-main/googletest" && $(CMAKE_COMMAND) -E cmake_symlink_library ../../../../../lib/libgtest_main.so.1.11.0 ../../../../../lib/libgtest_main.so.1.11.0 ../../../../../lib/libgtest_main.so

lib/libgtest_main.so: lib/libgtest_main.so.1.11.0
	@$(CMAKE_COMMAND) -E touch_nocreate lib/libgtest_main.so

# Rule to build all files generated by this target.
test/lib/googletest-main/googletest-main/googletest/CMakeFiles/gtest_main.dir/build: lib/libgtest_main.so
.PHONY : test/lib/googletest-main/googletest-main/googletest/CMakeFiles/gtest_main.dir/build

test/lib/googletest-main/googletest-main/googletest/CMakeFiles/gtest_main.dir/clean:
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/test/lib/googletest-main/googletest-main/googletest" && $(CMAKE_COMMAND) -P CMakeFiles/gtest_main.dir/cmake_clean.cmake
.PHONY : test/lib/googletest-main/googletest-main/googletest/CMakeFiles/gtest_main.dir/clean

test/lib/googletest-main/googletest-main/googletest/CMakeFiles/gtest_main.dir/depend:
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game" "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/test/lib/googletest-main/googletest-main/googletest" "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build" "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/test/lib/googletest-main/googletest-main/googletest" "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/test/lib/googletest-main/googletest-main/googletest/CMakeFiles/gtest_main.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : test/lib/googletest-main/googletest-main/googletest/CMakeFiles/gtest_main.dir/depend

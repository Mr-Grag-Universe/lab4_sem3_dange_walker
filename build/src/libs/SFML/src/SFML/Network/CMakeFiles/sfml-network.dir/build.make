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
include src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/compiler_depend.make

# Include the progress variables for this target.
include src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/progress.make

# Include the compile flags for this target's objects.
include src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/flags.make

src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Ftp.cpp.o: src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/flags.make
src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Ftp.cpp.o: /media/stepan/Windows\ 10\ Compact/Users/Stephan/Desktop/vs_code_game/src/libs/SFML/src/SFML/Network/Ftp.cpp
src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Ftp.cpp.o: src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Ftp.cpp.o"
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/SFML/src/SFML/Network" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Ftp.cpp.o -MF CMakeFiles/sfml-network.dir/Ftp.cpp.o.d -o CMakeFiles/sfml-network.dir/Ftp.cpp.o -c "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/libs/SFML/src/SFML/Network/Ftp.cpp"

src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Ftp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-network.dir/Ftp.cpp.i"
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/SFML/src/SFML/Network" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/libs/SFML/src/SFML/Network/Ftp.cpp" > CMakeFiles/sfml-network.dir/Ftp.cpp.i

src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Ftp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-network.dir/Ftp.cpp.s"
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/SFML/src/SFML/Network" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/libs/SFML/src/SFML/Network/Ftp.cpp" -o CMakeFiles/sfml-network.dir/Ftp.cpp.s

src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Http.cpp.o: src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/flags.make
src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Http.cpp.o: /media/stepan/Windows\ 10\ Compact/Users/Stephan/Desktop/vs_code_game/src/libs/SFML/src/SFML/Network/Http.cpp
src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Http.cpp.o: src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Http.cpp.o"
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/SFML/src/SFML/Network" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Http.cpp.o -MF CMakeFiles/sfml-network.dir/Http.cpp.o.d -o CMakeFiles/sfml-network.dir/Http.cpp.o -c "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/libs/SFML/src/SFML/Network/Http.cpp"

src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Http.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-network.dir/Http.cpp.i"
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/SFML/src/SFML/Network" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/libs/SFML/src/SFML/Network/Http.cpp" > CMakeFiles/sfml-network.dir/Http.cpp.i

src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Http.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-network.dir/Http.cpp.s"
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/SFML/src/SFML/Network" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/libs/SFML/src/SFML/Network/Http.cpp" -o CMakeFiles/sfml-network.dir/Http.cpp.s

src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/IpAddress.cpp.o: src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/flags.make
src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/IpAddress.cpp.o: /media/stepan/Windows\ 10\ Compact/Users/Stephan/Desktop/vs_code_game/src/libs/SFML/src/SFML/Network/IpAddress.cpp
src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/IpAddress.cpp.o: src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/IpAddress.cpp.o"
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/SFML/src/SFML/Network" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/IpAddress.cpp.o -MF CMakeFiles/sfml-network.dir/IpAddress.cpp.o.d -o CMakeFiles/sfml-network.dir/IpAddress.cpp.o -c "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/libs/SFML/src/SFML/Network/IpAddress.cpp"

src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/IpAddress.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-network.dir/IpAddress.cpp.i"
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/SFML/src/SFML/Network" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/libs/SFML/src/SFML/Network/IpAddress.cpp" > CMakeFiles/sfml-network.dir/IpAddress.cpp.i

src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/IpAddress.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-network.dir/IpAddress.cpp.s"
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/SFML/src/SFML/Network" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/libs/SFML/src/SFML/Network/IpAddress.cpp" -o CMakeFiles/sfml-network.dir/IpAddress.cpp.s

src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Packet.cpp.o: src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/flags.make
src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Packet.cpp.o: /media/stepan/Windows\ 10\ Compact/Users/Stephan/Desktop/vs_code_game/src/libs/SFML/src/SFML/Network/Packet.cpp
src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Packet.cpp.o: src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Packet.cpp.o"
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/SFML/src/SFML/Network" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Packet.cpp.o -MF CMakeFiles/sfml-network.dir/Packet.cpp.o.d -o CMakeFiles/sfml-network.dir/Packet.cpp.o -c "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/libs/SFML/src/SFML/Network/Packet.cpp"

src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Packet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-network.dir/Packet.cpp.i"
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/SFML/src/SFML/Network" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/libs/SFML/src/SFML/Network/Packet.cpp" > CMakeFiles/sfml-network.dir/Packet.cpp.i

src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Packet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-network.dir/Packet.cpp.s"
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/SFML/src/SFML/Network" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/libs/SFML/src/SFML/Network/Packet.cpp" -o CMakeFiles/sfml-network.dir/Packet.cpp.s

src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Socket.cpp.o: src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/flags.make
src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Socket.cpp.o: /media/stepan/Windows\ 10\ Compact/Users/Stephan/Desktop/vs_code_game/src/libs/SFML/src/SFML/Network/Socket.cpp
src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Socket.cpp.o: src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Socket.cpp.o"
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/SFML/src/SFML/Network" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Socket.cpp.o -MF CMakeFiles/sfml-network.dir/Socket.cpp.o.d -o CMakeFiles/sfml-network.dir/Socket.cpp.o -c "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/libs/SFML/src/SFML/Network/Socket.cpp"

src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-network.dir/Socket.cpp.i"
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/SFML/src/SFML/Network" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/libs/SFML/src/SFML/Network/Socket.cpp" > CMakeFiles/sfml-network.dir/Socket.cpp.i

src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-network.dir/Socket.cpp.s"
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/SFML/src/SFML/Network" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/libs/SFML/src/SFML/Network/Socket.cpp" -o CMakeFiles/sfml-network.dir/Socket.cpp.s

src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/SocketSelector.cpp.o: src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/flags.make
src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/SocketSelector.cpp.o: /media/stepan/Windows\ 10\ Compact/Users/Stephan/Desktop/vs_code_game/src/libs/SFML/src/SFML/Network/SocketSelector.cpp
src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/SocketSelector.cpp.o: src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/SocketSelector.cpp.o"
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/SFML/src/SFML/Network" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/SocketSelector.cpp.o -MF CMakeFiles/sfml-network.dir/SocketSelector.cpp.o.d -o CMakeFiles/sfml-network.dir/SocketSelector.cpp.o -c "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/libs/SFML/src/SFML/Network/SocketSelector.cpp"

src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/SocketSelector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-network.dir/SocketSelector.cpp.i"
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/SFML/src/SFML/Network" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/libs/SFML/src/SFML/Network/SocketSelector.cpp" > CMakeFiles/sfml-network.dir/SocketSelector.cpp.i

src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/SocketSelector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-network.dir/SocketSelector.cpp.s"
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/SFML/src/SFML/Network" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/libs/SFML/src/SFML/Network/SocketSelector.cpp" -o CMakeFiles/sfml-network.dir/SocketSelector.cpp.s

src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/TcpListener.cpp.o: src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/flags.make
src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/TcpListener.cpp.o: /media/stepan/Windows\ 10\ Compact/Users/Stephan/Desktop/vs_code_game/src/libs/SFML/src/SFML/Network/TcpListener.cpp
src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/TcpListener.cpp.o: src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/TcpListener.cpp.o"
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/SFML/src/SFML/Network" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/TcpListener.cpp.o -MF CMakeFiles/sfml-network.dir/TcpListener.cpp.o.d -o CMakeFiles/sfml-network.dir/TcpListener.cpp.o -c "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/libs/SFML/src/SFML/Network/TcpListener.cpp"

src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/TcpListener.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-network.dir/TcpListener.cpp.i"
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/SFML/src/SFML/Network" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/libs/SFML/src/SFML/Network/TcpListener.cpp" > CMakeFiles/sfml-network.dir/TcpListener.cpp.i

src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/TcpListener.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-network.dir/TcpListener.cpp.s"
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/SFML/src/SFML/Network" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/libs/SFML/src/SFML/Network/TcpListener.cpp" -o CMakeFiles/sfml-network.dir/TcpListener.cpp.s

src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/TcpSocket.cpp.o: src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/flags.make
src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/TcpSocket.cpp.o: /media/stepan/Windows\ 10\ Compact/Users/Stephan/Desktop/vs_code_game/src/libs/SFML/src/SFML/Network/TcpSocket.cpp
src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/TcpSocket.cpp.o: src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/TcpSocket.cpp.o"
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/SFML/src/SFML/Network" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/TcpSocket.cpp.o -MF CMakeFiles/sfml-network.dir/TcpSocket.cpp.o.d -o CMakeFiles/sfml-network.dir/TcpSocket.cpp.o -c "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/libs/SFML/src/SFML/Network/TcpSocket.cpp"

src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/TcpSocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-network.dir/TcpSocket.cpp.i"
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/SFML/src/SFML/Network" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/libs/SFML/src/SFML/Network/TcpSocket.cpp" > CMakeFiles/sfml-network.dir/TcpSocket.cpp.i

src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/TcpSocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-network.dir/TcpSocket.cpp.s"
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/SFML/src/SFML/Network" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/libs/SFML/src/SFML/Network/TcpSocket.cpp" -o CMakeFiles/sfml-network.dir/TcpSocket.cpp.s

src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/UdpSocket.cpp.o: src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/flags.make
src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/UdpSocket.cpp.o: /media/stepan/Windows\ 10\ Compact/Users/Stephan/Desktop/vs_code_game/src/libs/SFML/src/SFML/Network/UdpSocket.cpp
src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/UdpSocket.cpp.o: src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/UdpSocket.cpp.o"
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/SFML/src/SFML/Network" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/UdpSocket.cpp.o -MF CMakeFiles/sfml-network.dir/UdpSocket.cpp.o.d -o CMakeFiles/sfml-network.dir/UdpSocket.cpp.o -c "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/libs/SFML/src/SFML/Network/UdpSocket.cpp"

src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/UdpSocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-network.dir/UdpSocket.cpp.i"
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/SFML/src/SFML/Network" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/libs/SFML/src/SFML/Network/UdpSocket.cpp" > CMakeFiles/sfml-network.dir/UdpSocket.cpp.i

src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/UdpSocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-network.dir/UdpSocket.cpp.s"
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/SFML/src/SFML/Network" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/libs/SFML/src/SFML/Network/UdpSocket.cpp" -o CMakeFiles/sfml-network.dir/UdpSocket.cpp.s

src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.o: src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/flags.make
src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.o: /media/stepan/Windows\ 10\ Compact/Users/Stephan/Desktop/vs_code_game/src/libs/SFML/src/SFML/Network/Unix/SocketImpl.cpp
src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.o: src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.o"
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/SFML/src/SFML/Network" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.o -MF CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.o.d -o CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.o -c "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/libs/SFML/src/SFML/Network/Unix/SocketImpl.cpp"

src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.i"
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/SFML/src/SFML/Network" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/libs/SFML/src/SFML/Network/Unix/SocketImpl.cpp" > CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.i

src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.s"
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/SFML/src/SFML/Network" && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/libs/SFML/src/SFML/Network/Unix/SocketImpl.cpp" -o CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.s

# Object files for target sfml-network
sfml__network_OBJECTS = \
"CMakeFiles/sfml-network.dir/Ftp.cpp.o" \
"CMakeFiles/sfml-network.dir/Http.cpp.o" \
"CMakeFiles/sfml-network.dir/IpAddress.cpp.o" \
"CMakeFiles/sfml-network.dir/Packet.cpp.o" \
"CMakeFiles/sfml-network.dir/Socket.cpp.o" \
"CMakeFiles/sfml-network.dir/SocketSelector.cpp.o" \
"CMakeFiles/sfml-network.dir/TcpListener.cpp.o" \
"CMakeFiles/sfml-network.dir/TcpSocket.cpp.o" \
"CMakeFiles/sfml-network.dir/UdpSocket.cpp.o" \
"CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.o"

# External object files for target sfml-network
sfml__network_EXTERNAL_OBJECTS =

src/libs/SFML/lib/libsfml-network-d.so.3.0.0: src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Ftp.cpp.o
src/libs/SFML/lib/libsfml-network-d.so.3.0.0: src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Http.cpp.o
src/libs/SFML/lib/libsfml-network-d.so.3.0.0: src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/IpAddress.cpp.o
src/libs/SFML/lib/libsfml-network-d.so.3.0.0: src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Packet.cpp.o
src/libs/SFML/lib/libsfml-network-d.so.3.0.0: src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Socket.cpp.o
src/libs/SFML/lib/libsfml-network-d.so.3.0.0: src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/SocketSelector.cpp.o
src/libs/SFML/lib/libsfml-network-d.so.3.0.0: src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/TcpListener.cpp.o
src/libs/SFML/lib/libsfml-network-d.so.3.0.0: src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/TcpSocket.cpp.o
src/libs/SFML/lib/libsfml-network-d.so.3.0.0: src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/UdpSocket.cpp.o
src/libs/SFML/lib/libsfml-network-d.so.3.0.0: src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/Unix/SocketImpl.cpp.o
src/libs/SFML/lib/libsfml-network-d.so.3.0.0: src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/build.make
src/libs/SFML/lib/libsfml-network-d.so.3.0.0: src/libs/SFML/lib/libsfml-system-d.so.3.0.0
src/libs/SFML/lib/libsfml-network-d.so.3.0.0: src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX shared library ../../../lib/libsfml-network-d.so"
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/SFML/src/SFML/Network" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sfml-network.dir/link.txt --verbose=$(VERBOSE)
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/SFML/src/SFML/Network" && $(CMAKE_COMMAND) -E cmake_symlink_library ../../../lib/libsfml-network-d.so.3.0.0 ../../../lib/libsfml-network-d.so.3.0 ../../../lib/libsfml-network-d.so

src/libs/SFML/lib/libsfml-network-d.so.3.0: src/libs/SFML/lib/libsfml-network-d.so.3.0.0
	@$(CMAKE_COMMAND) -E touch_nocreate src/libs/SFML/lib/libsfml-network-d.so.3.0

src/libs/SFML/lib/libsfml-network-d.so: src/libs/SFML/lib/libsfml-network-d.so.3.0.0
	@$(CMAKE_COMMAND) -E touch_nocreate src/libs/SFML/lib/libsfml-network-d.so

# Rule to build all files generated by this target.
src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/build: src/libs/SFML/lib/libsfml-network-d.so
.PHONY : src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/build

src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/clean:
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/SFML/src/SFML/Network" && $(CMAKE_COMMAND) -P CMakeFiles/sfml-network.dir/cmake_clean.cmake
.PHONY : src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/clean

src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/depend:
	cd "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game" "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/src/libs/SFML/src/SFML/Network" "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build" "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/SFML/src/SFML/Network" "/media/stepan/Windows 10 Compact/Users/Stephan/Desktop/vs_code_game/build/src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : src/libs/SFML/src/SFML/Network/CMakeFiles/sfml-network.dir/depend

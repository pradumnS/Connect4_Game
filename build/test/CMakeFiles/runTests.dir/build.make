# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/Connect4_Game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/Connect4_Game/build

# Include any dependencies generated for this target.
include test/CMakeFiles/runTests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/CMakeFiles/runTests.dir/compiler_depend.make

# Include the progress variables for this target.
include test/CMakeFiles/runTests.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/runTests.dir/flags.make

test/CMakeFiles/runTests.dir/maintest.cpp.o: test/CMakeFiles/runTests.dir/flags.make
test/CMakeFiles/runTests.dir/maintest.cpp.o: ../test/maintest.cpp
test/CMakeFiles/runTests.dir/maintest.cpp.o: test/CMakeFiles/runTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Connect4_Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/runTests.dir/maintest.cpp.o"
	cd /home/Connect4_Game/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/runTests.dir/maintest.cpp.o -MF CMakeFiles/runTests.dir/maintest.cpp.o.d -o CMakeFiles/runTests.dir/maintest.cpp.o -c /home/Connect4_Game/test/maintest.cpp

test/CMakeFiles/runTests.dir/maintest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runTests.dir/maintest.cpp.i"
	cd /home/Connect4_Game/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/Connect4_Game/test/maintest.cpp > CMakeFiles/runTests.dir/maintest.cpp.i

test/CMakeFiles/runTests.dir/maintest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runTests.dir/maintest.cpp.s"
	cd /home/Connect4_Game/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/Connect4_Game/test/maintest.cpp -o CMakeFiles/runTests.dir/maintest.cpp.s

test/CMakeFiles/runTests.dir/BoardTest.cpp.o: test/CMakeFiles/runTests.dir/flags.make
test/CMakeFiles/runTests.dir/BoardTest.cpp.o: ../test/BoardTest.cpp
test/CMakeFiles/runTests.dir/BoardTest.cpp.o: test/CMakeFiles/runTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Connect4_Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object test/CMakeFiles/runTests.dir/BoardTest.cpp.o"
	cd /home/Connect4_Game/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/runTests.dir/BoardTest.cpp.o -MF CMakeFiles/runTests.dir/BoardTest.cpp.o.d -o CMakeFiles/runTests.dir/BoardTest.cpp.o -c /home/Connect4_Game/test/BoardTest.cpp

test/CMakeFiles/runTests.dir/BoardTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runTests.dir/BoardTest.cpp.i"
	cd /home/Connect4_Game/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/Connect4_Game/test/BoardTest.cpp > CMakeFiles/runTests.dir/BoardTest.cpp.i

test/CMakeFiles/runTests.dir/BoardTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runTests.dir/BoardTest.cpp.s"
	cd /home/Connect4_Game/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/Connect4_Game/test/BoardTest.cpp -o CMakeFiles/runTests.dir/BoardTest.cpp.s

test/CMakeFiles/runTests.dir/FriendPlayerTest.cpp.o: test/CMakeFiles/runTests.dir/flags.make
test/CMakeFiles/runTests.dir/FriendPlayerTest.cpp.o: ../test/FriendPlayerTest.cpp
test/CMakeFiles/runTests.dir/FriendPlayerTest.cpp.o: test/CMakeFiles/runTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Connect4_Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object test/CMakeFiles/runTests.dir/FriendPlayerTest.cpp.o"
	cd /home/Connect4_Game/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/runTests.dir/FriendPlayerTest.cpp.o -MF CMakeFiles/runTests.dir/FriendPlayerTest.cpp.o.d -o CMakeFiles/runTests.dir/FriendPlayerTest.cpp.o -c /home/Connect4_Game/test/FriendPlayerTest.cpp

test/CMakeFiles/runTests.dir/FriendPlayerTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runTests.dir/FriendPlayerTest.cpp.i"
	cd /home/Connect4_Game/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/Connect4_Game/test/FriendPlayerTest.cpp > CMakeFiles/runTests.dir/FriendPlayerTest.cpp.i

test/CMakeFiles/runTests.dir/FriendPlayerTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runTests.dir/FriendPlayerTest.cpp.s"
	cd /home/Connect4_Game/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/Connect4_Game/test/FriendPlayerTest.cpp -o CMakeFiles/runTests.dir/FriendPlayerTest.cpp.s

test/CMakeFiles/runTests.dir/ComputerTest.cpp.o: test/CMakeFiles/runTests.dir/flags.make
test/CMakeFiles/runTests.dir/ComputerTest.cpp.o: ../test/ComputerTest.cpp
test/CMakeFiles/runTests.dir/ComputerTest.cpp.o: test/CMakeFiles/runTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Connect4_Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object test/CMakeFiles/runTests.dir/ComputerTest.cpp.o"
	cd /home/Connect4_Game/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/runTests.dir/ComputerTest.cpp.o -MF CMakeFiles/runTests.dir/ComputerTest.cpp.o.d -o CMakeFiles/runTests.dir/ComputerTest.cpp.o -c /home/Connect4_Game/test/ComputerTest.cpp

test/CMakeFiles/runTests.dir/ComputerTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runTests.dir/ComputerTest.cpp.i"
	cd /home/Connect4_Game/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/Connect4_Game/test/ComputerTest.cpp > CMakeFiles/runTests.dir/ComputerTest.cpp.i

test/CMakeFiles/runTests.dir/ComputerTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runTests.dir/ComputerTest.cpp.s"
	cd /home/Connect4_Game/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/Connect4_Game/test/ComputerTest.cpp -o CMakeFiles/runTests.dir/ComputerTest.cpp.s

test/CMakeFiles/runTests.dir/PlayerTest.cpp.o: test/CMakeFiles/runTests.dir/flags.make
test/CMakeFiles/runTests.dir/PlayerTest.cpp.o: ../test/PlayerTest.cpp
test/CMakeFiles/runTests.dir/PlayerTest.cpp.o: test/CMakeFiles/runTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Connect4_Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object test/CMakeFiles/runTests.dir/PlayerTest.cpp.o"
	cd /home/Connect4_Game/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/runTests.dir/PlayerTest.cpp.o -MF CMakeFiles/runTests.dir/PlayerTest.cpp.o.d -o CMakeFiles/runTests.dir/PlayerTest.cpp.o -c /home/Connect4_Game/test/PlayerTest.cpp

test/CMakeFiles/runTests.dir/PlayerTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runTests.dir/PlayerTest.cpp.i"
	cd /home/Connect4_Game/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/Connect4_Game/test/PlayerTest.cpp > CMakeFiles/runTests.dir/PlayerTest.cpp.i

test/CMakeFiles/runTests.dir/PlayerTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runTests.dir/PlayerTest.cpp.s"
	cd /home/Connect4_Game/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/Connect4_Game/test/PlayerTest.cpp -o CMakeFiles/runTests.dir/PlayerTest.cpp.s

test/CMakeFiles/runTests.dir/__/src/Board.cpp.o: test/CMakeFiles/runTests.dir/flags.make
test/CMakeFiles/runTests.dir/__/src/Board.cpp.o: ../src/Board.cpp
test/CMakeFiles/runTests.dir/__/src/Board.cpp.o: test/CMakeFiles/runTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Connect4_Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object test/CMakeFiles/runTests.dir/__/src/Board.cpp.o"
	cd /home/Connect4_Game/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/runTests.dir/__/src/Board.cpp.o -MF CMakeFiles/runTests.dir/__/src/Board.cpp.o.d -o CMakeFiles/runTests.dir/__/src/Board.cpp.o -c /home/Connect4_Game/src/Board.cpp

test/CMakeFiles/runTests.dir/__/src/Board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runTests.dir/__/src/Board.cpp.i"
	cd /home/Connect4_Game/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/Connect4_Game/src/Board.cpp > CMakeFiles/runTests.dir/__/src/Board.cpp.i

test/CMakeFiles/runTests.dir/__/src/Board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runTests.dir/__/src/Board.cpp.s"
	cd /home/Connect4_Game/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/Connect4_Game/src/Board.cpp -o CMakeFiles/runTests.dir/__/src/Board.cpp.s

test/CMakeFiles/runTests.dir/__/src/Player.cpp.o: test/CMakeFiles/runTests.dir/flags.make
test/CMakeFiles/runTests.dir/__/src/Player.cpp.o: ../src/Player.cpp
test/CMakeFiles/runTests.dir/__/src/Player.cpp.o: test/CMakeFiles/runTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Connect4_Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object test/CMakeFiles/runTests.dir/__/src/Player.cpp.o"
	cd /home/Connect4_Game/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/runTests.dir/__/src/Player.cpp.o -MF CMakeFiles/runTests.dir/__/src/Player.cpp.o.d -o CMakeFiles/runTests.dir/__/src/Player.cpp.o -c /home/Connect4_Game/src/Player.cpp

test/CMakeFiles/runTests.dir/__/src/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runTests.dir/__/src/Player.cpp.i"
	cd /home/Connect4_Game/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/Connect4_Game/src/Player.cpp > CMakeFiles/runTests.dir/__/src/Player.cpp.i

test/CMakeFiles/runTests.dir/__/src/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runTests.dir/__/src/Player.cpp.s"
	cd /home/Connect4_Game/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/Connect4_Game/src/Player.cpp -o CMakeFiles/runTests.dir/__/src/Player.cpp.s

test/CMakeFiles/runTests.dir/__/src/Computer.cpp.o: test/CMakeFiles/runTests.dir/flags.make
test/CMakeFiles/runTests.dir/__/src/Computer.cpp.o: ../src/Computer.cpp
test/CMakeFiles/runTests.dir/__/src/Computer.cpp.o: test/CMakeFiles/runTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Connect4_Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object test/CMakeFiles/runTests.dir/__/src/Computer.cpp.o"
	cd /home/Connect4_Game/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/runTests.dir/__/src/Computer.cpp.o -MF CMakeFiles/runTests.dir/__/src/Computer.cpp.o.d -o CMakeFiles/runTests.dir/__/src/Computer.cpp.o -c /home/Connect4_Game/src/Computer.cpp

test/CMakeFiles/runTests.dir/__/src/Computer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runTests.dir/__/src/Computer.cpp.i"
	cd /home/Connect4_Game/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/Connect4_Game/src/Computer.cpp > CMakeFiles/runTests.dir/__/src/Computer.cpp.i

test/CMakeFiles/runTests.dir/__/src/Computer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runTests.dir/__/src/Computer.cpp.s"
	cd /home/Connect4_Game/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/Connect4_Game/src/Computer.cpp -o CMakeFiles/runTests.dir/__/src/Computer.cpp.s

test/CMakeFiles/runTests.dir/__/src/FriendPlayer.cpp.o: test/CMakeFiles/runTests.dir/flags.make
test/CMakeFiles/runTests.dir/__/src/FriendPlayer.cpp.o: ../src/FriendPlayer.cpp
test/CMakeFiles/runTests.dir/__/src/FriendPlayer.cpp.o: test/CMakeFiles/runTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/Connect4_Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object test/CMakeFiles/runTests.dir/__/src/FriendPlayer.cpp.o"
	cd /home/Connect4_Game/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT test/CMakeFiles/runTests.dir/__/src/FriendPlayer.cpp.o -MF CMakeFiles/runTests.dir/__/src/FriendPlayer.cpp.o.d -o CMakeFiles/runTests.dir/__/src/FriendPlayer.cpp.o -c /home/Connect4_Game/src/FriendPlayer.cpp

test/CMakeFiles/runTests.dir/__/src/FriendPlayer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runTests.dir/__/src/FriendPlayer.cpp.i"
	cd /home/Connect4_Game/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/Connect4_Game/src/FriendPlayer.cpp > CMakeFiles/runTests.dir/__/src/FriendPlayer.cpp.i

test/CMakeFiles/runTests.dir/__/src/FriendPlayer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runTests.dir/__/src/FriendPlayer.cpp.s"
	cd /home/Connect4_Game/build/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/Connect4_Game/src/FriendPlayer.cpp -o CMakeFiles/runTests.dir/__/src/FriendPlayer.cpp.s

# Object files for target runTests
runTests_OBJECTS = \
"CMakeFiles/runTests.dir/maintest.cpp.o" \
"CMakeFiles/runTests.dir/BoardTest.cpp.o" \
"CMakeFiles/runTests.dir/FriendPlayerTest.cpp.o" \
"CMakeFiles/runTests.dir/ComputerTest.cpp.o" \
"CMakeFiles/runTests.dir/PlayerTest.cpp.o" \
"CMakeFiles/runTests.dir/__/src/Board.cpp.o" \
"CMakeFiles/runTests.dir/__/src/Player.cpp.o" \
"CMakeFiles/runTests.dir/__/src/Computer.cpp.o" \
"CMakeFiles/runTests.dir/__/src/FriendPlayer.cpp.o"

# External object files for target runTests
runTests_EXTERNAL_OBJECTS =

test/runTests: test/CMakeFiles/runTests.dir/maintest.cpp.o
test/runTests: test/CMakeFiles/runTests.dir/BoardTest.cpp.o
test/runTests: test/CMakeFiles/runTests.dir/FriendPlayerTest.cpp.o
test/runTests: test/CMakeFiles/runTests.dir/ComputerTest.cpp.o
test/runTests: test/CMakeFiles/runTests.dir/PlayerTest.cpp.o
test/runTests: test/CMakeFiles/runTests.dir/__/src/Board.cpp.o
test/runTests: test/CMakeFiles/runTests.dir/__/src/Player.cpp.o
test/runTests: test/CMakeFiles/runTests.dir/__/src/Computer.cpp.o
test/runTests: test/CMakeFiles/runTests.dir/__/src/FriendPlayer.cpp.o
test/runTests: test/CMakeFiles/runTests.dir/build.make
test/runTests: /usr/lib/x86_64-linux-gnu/libgtest_main.a
test/runTests: /usr/lib/x86_64-linux-gnu/libgtest.a
test/runTests: test/CMakeFiles/runTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/Connect4_Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable runTests"
	cd /home/Connect4_Game/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/runTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/runTests.dir/build: test/runTests
.PHONY : test/CMakeFiles/runTests.dir/build

test/CMakeFiles/runTests.dir/clean:
	cd /home/Connect4_Game/build/test && $(CMAKE_COMMAND) -P CMakeFiles/runTests.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/runTests.dir/clean

test/CMakeFiles/runTests.dir/depend:
	cd /home/Connect4_Game/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/Connect4_Game /home/Connect4_Game/test /home/Connect4_Game/build /home/Connect4_Game/build/test /home/Connect4_Game/build/test/CMakeFiles/runTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/runTests.dir/depend


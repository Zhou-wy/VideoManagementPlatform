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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zwy/CWorkspace/VidManPlat

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zwy/CWorkspace/VidManPlat/0build-linux

# Include any dependencies generated for this target.
include src/playFFmpeg/CMakeFiles/PlayFFmpeg.dir/depend.make

# Include the progress variables for this target.
include src/playFFmpeg/CMakeFiles/PlayFFmpeg.dir/progress.make

# Include the compile flags for this target's objects.
include src/playFFmpeg/CMakeFiles/PlayFFmpeg.dir/flags.make

src/playFFmpeg/CMakeFiles/PlayFFmpeg.dir/PlayFFmpeg_autogen/mocs_compilation.cpp.o: src/playFFmpeg/CMakeFiles/PlayFFmpeg.dir/flags.make
src/playFFmpeg/CMakeFiles/PlayFFmpeg.dir/PlayFFmpeg_autogen/mocs_compilation.cpp.o: src/playFFmpeg/PlayFFmpeg_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zwy/CWorkspace/VidManPlat/0build-linux/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/playFFmpeg/CMakeFiles/PlayFFmpeg.dir/PlayFFmpeg_autogen/mocs_compilation.cpp.o"
	cd /home/zwy/CWorkspace/VidManPlat/0build-linux/src/playFFmpeg && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PlayFFmpeg.dir/PlayFFmpeg_autogen/mocs_compilation.cpp.o -c /home/zwy/CWorkspace/VidManPlat/0build-linux/src/playFFmpeg/PlayFFmpeg_autogen/mocs_compilation.cpp

src/playFFmpeg/CMakeFiles/PlayFFmpeg.dir/PlayFFmpeg_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PlayFFmpeg.dir/PlayFFmpeg_autogen/mocs_compilation.cpp.i"
	cd /home/zwy/CWorkspace/VidManPlat/0build-linux/src/playFFmpeg && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zwy/CWorkspace/VidManPlat/0build-linux/src/playFFmpeg/PlayFFmpeg_autogen/mocs_compilation.cpp > CMakeFiles/PlayFFmpeg.dir/PlayFFmpeg_autogen/mocs_compilation.cpp.i

src/playFFmpeg/CMakeFiles/PlayFFmpeg.dir/PlayFFmpeg_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PlayFFmpeg.dir/PlayFFmpeg_autogen/mocs_compilation.cpp.s"
	cd /home/zwy/CWorkspace/VidManPlat/0build-linux/src/playFFmpeg && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zwy/CWorkspace/VidManPlat/0build-linux/src/playFFmpeg/PlayFFmpeg_autogen/mocs_compilation.cpp -o CMakeFiles/PlayFFmpeg.dir/PlayFFmpeg_autogen/mocs_compilation.cpp.s

src/playFFmpeg/CMakeFiles/PlayFFmpeg.dir/ffmpeg.cpp.o: src/playFFmpeg/CMakeFiles/PlayFFmpeg.dir/flags.make
src/playFFmpeg/CMakeFiles/PlayFFmpeg.dir/ffmpeg.cpp.o: ../src/playFFmpeg/ffmpeg.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zwy/CWorkspace/VidManPlat/0build-linux/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/playFFmpeg/CMakeFiles/PlayFFmpeg.dir/ffmpeg.cpp.o"
	cd /home/zwy/CWorkspace/VidManPlat/0build-linux/src/playFFmpeg && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PlayFFmpeg.dir/ffmpeg.cpp.o -c /home/zwy/CWorkspace/VidManPlat/src/playFFmpeg/ffmpeg.cpp

src/playFFmpeg/CMakeFiles/PlayFFmpeg.dir/ffmpeg.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PlayFFmpeg.dir/ffmpeg.cpp.i"
	cd /home/zwy/CWorkspace/VidManPlat/0build-linux/src/playFFmpeg && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zwy/CWorkspace/VidManPlat/src/playFFmpeg/ffmpeg.cpp > CMakeFiles/PlayFFmpeg.dir/ffmpeg.cpp.i

src/playFFmpeg/CMakeFiles/PlayFFmpeg.dir/ffmpeg.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PlayFFmpeg.dir/ffmpeg.cpp.s"
	cd /home/zwy/CWorkspace/VidManPlat/0build-linux/src/playFFmpeg && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zwy/CWorkspace/VidManPlat/src/playFFmpeg/ffmpeg.cpp -o CMakeFiles/PlayFFmpeg.dir/ffmpeg.cpp.s

# Object files for target PlayFFmpeg
PlayFFmpeg_OBJECTS = \
"CMakeFiles/PlayFFmpeg.dir/PlayFFmpeg_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/PlayFFmpeg.dir/ffmpeg.cpp.o"

# External object files for target PlayFFmpeg
PlayFFmpeg_EXTERNAL_OBJECTS =

../lib/libPlayFFmpeg.a: src/playFFmpeg/CMakeFiles/PlayFFmpeg.dir/PlayFFmpeg_autogen/mocs_compilation.cpp.o
../lib/libPlayFFmpeg.a: src/playFFmpeg/CMakeFiles/PlayFFmpeg.dir/ffmpeg.cpp.o
../lib/libPlayFFmpeg.a: src/playFFmpeg/CMakeFiles/PlayFFmpeg.dir/build.make
../lib/libPlayFFmpeg.a: src/playFFmpeg/CMakeFiles/PlayFFmpeg.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zwy/CWorkspace/VidManPlat/0build-linux/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library ../../../lib/libPlayFFmpeg.a"
	cd /home/zwy/CWorkspace/VidManPlat/0build-linux/src/playFFmpeg && $(CMAKE_COMMAND) -P CMakeFiles/PlayFFmpeg.dir/cmake_clean_target.cmake
	cd /home/zwy/CWorkspace/VidManPlat/0build-linux/src/playFFmpeg && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PlayFFmpeg.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/playFFmpeg/CMakeFiles/PlayFFmpeg.dir/build: ../lib/libPlayFFmpeg.a

.PHONY : src/playFFmpeg/CMakeFiles/PlayFFmpeg.dir/build

src/playFFmpeg/CMakeFiles/PlayFFmpeg.dir/clean:
	cd /home/zwy/CWorkspace/VidManPlat/0build-linux/src/playFFmpeg && $(CMAKE_COMMAND) -P CMakeFiles/PlayFFmpeg.dir/cmake_clean.cmake
.PHONY : src/playFFmpeg/CMakeFiles/PlayFFmpeg.dir/clean

src/playFFmpeg/CMakeFiles/PlayFFmpeg.dir/depend:
	cd /home/zwy/CWorkspace/VidManPlat/0build-linux && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zwy/CWorkspace/VidManPlat /home/zwy/CWorkspace/VidManPlat/src/playFFmpeg /home/zwy/CWorkspace/VidManPlat/0build-linux /home/zwy/CWorkspace/VidManPlat/0build-linux/src/playFFmpeg /home/zwy/CWorkspace/VidManPlat/0build-linux/src/playFFmpeg/CMakeFiles/PlayFFmpeg.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/playFFmpeg/CMakeFiles/PlayFFmpeg.dir/depend


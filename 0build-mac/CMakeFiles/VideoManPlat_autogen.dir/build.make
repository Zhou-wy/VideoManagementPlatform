# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/zwy/CppProject/VidManPlat

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zwy/CppProject/VidManPlat/0build-mac

# Utility rule file for VideoManPlat_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/VideoManPlat_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/VideoManPlat_autogen.dir/progress.make

CMakeFiles/VideoManPlat_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/zwy/CppProject/VidManPlat/0build-mac/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target VideoManPlat"
	/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E cmake_autogen /Users/zwy/CppProject/VidManPlat/0build-mac/CMakeFiles/VideoManPlat_autogen.dir/AutogenInfo.json Debug

VideoManPlat_autogen: CMakeFiles/VideoManPlat_autogen
VideoManPlat_autogen: CMakeFiles/VideoManPlat_autogen.dir/build.make
.PHONY : VideoManPlat_autogen

# Rule to build all files generated by this target.
CMakeFiles/VideoManPlat_autogen.dir/build: VideoManPlat_autogen
.PHONY : CMakeFiles/VideoManPlat_autogen.dir/build

CMakeFiles/VideoManPlat_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/VideoManPlat_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/VideoManPlat_autogen.dir/clean

CMakeFiles/VideoManPlat_autogen.dir/depend:
	cd /Users/zwy/CppProject/VidManPlat/0build-mac && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zwy/CppProject/VidManPlat /Users/zwy/CppProject/VidManPlat /Users/zwy/CppProject/VidManPlat/0build-mac /Users/zwy/CppProject/VidManPlat/0build-mac /Users/zwy/CppProject/VidManPlat/0build-mac/CMakeFiles/VideoManPlat_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/VideoManPlat_autogen.dir/depend


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
CMAKE_COMMAND = "C:/Program Files/JetBrains/CLion 2022.3.2/bin/cmake/win/x64/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files/JetBrains/CLion 2022.3.2/bin/cmake/win/x64/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:/Users/zwy/Desktop/VidManPlat

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:/Users/zwy/Desktop/VidManPlat/0build-windows

# Utility rule file for addVideo_autogen.

# Include any custom commands dependencies for this target.
include src/addVideoDevice/CMakeFiles/addVideo_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include src/addVideoDevice/CMakeFiles/addVideo_autogen.dir/progress.make

src/addVideoDevice/CMakeFiles/addVideo_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=C:/Users/zwy/Desktop/VidManPlat/0build-windows/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target addVideo"
	cd C:/Users/zwy/Desktop/VidManPlat/0build-windows/src/addVideoDevice && "C:/Program Files/JetBrains/CLion 2022.3.2/bin/cmake/win/x64/bin/cmake.exe" -E cmake_autogen C:/Users/zwy/Desktop/VidManPlat/0build-windows/src/addVideoDevice/CMakeFiles/addVideo_autogen.dir/AutogenInfo.json Debug

addVideo_autogen: src/addVideoDevice/CMakeFiles/addVideo_autogen
addVideo_autogen: src/addVideoDevice/CMakeFiles/addVideo_autogen.dir/build.make
.PHONY : addVideo_autogen

# Rule to build all files generated by this target.
src/addVideoDevice/CMakeFiles/addVideo_autogen.dir/build: addVideo_autogen
.PHONY : src/addVideoDevice/CMakeFiles/addVideo_autogen.dir/build

src/addVideoDevice/CMakeFiles/addVideo_autogen.dir/clean:
	cd C:/Users/zwy/Desktop/VidManPlat/0build-windows/src/addVideoDevice && $(CMAKE_COMMAND) -P CMakeFiles/addVideo_autogen.dir/cmake_clean.cmake
.PHONY : src/addVideoDevice/CMakeFiles/addVideo_autogen.dir/clean

src/addVideoDevice/CMakeFiles/addVideo_autogen.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" C:/Users/zwy/Desktop/VidManPlat C:/Users/zwy/Desktop/VidManPlat/src/addVideoDevice C:/Users/zwy/Desktop/VidManPlat/0build-windows C:/Users/zwy/Desktop/VidManPlat/0build-windows/src/addVideoDevice C:/Users/zwy/Desktop/VidManPlat/0build-windows/src/addVideoDevice/CMakeFiles/addVideo_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/addVideoDevice/CMakeFiles/addVideo_autogen.dir/depend


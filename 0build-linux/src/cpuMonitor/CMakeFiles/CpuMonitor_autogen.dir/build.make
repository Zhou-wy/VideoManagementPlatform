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

# Utility rule file for CpuMonitor_autogen.

# Include the progress variables for this target.
include src/cpuMonitor/CMakeFiles/CpuMonitor_autogen.dir/progress.make

src/cpuMonitor/CMakeFiles/CpuMonitor_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/zwy/CWorkspace/VidManPlat/0build-linux/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target CpuMonitor"
	cd /home/zwy/CWorkspace/VidManPlat/0build-linux/src/cpuMonitor && /usr/local/bin/cmake -E cmake_autogen /home/zwy/CWorkspace/VidManPlat/0build-linux/src/cpuMonitor/CMakeFiles/CpuMonitor_autogen.dir/AutogenInfo.json Debug

CpuMonitor_autogen: src/cpuMonitor/CMakeFiles/CpuMonitor_autogen
CpuMonitor_autogen: src/cpuMonitor/CMakeFiles/CpuMonitor_autogen.dir/build.make

.PHONY : CpuMonitor_autogen

# Rule to build all files generated by this target.
src/cpuMonitor/CMakeFiles/CpuMonitor_autogen.dir/build: CpuMonitor_autogen

.PHONY : src/cpuMonitor/CMakeFiles/CpuMonitor_autogen.dir/build

src/cpuMonitor/CMakeFiles/CpuMonitor_autogen.dir/clean:
	cd /home/zwy/CWorkspace/VidManPlat/0build-linux/src/cpuMonitor && $(CMAKE_COMMAND) -P CMakeFiles/CpuMonitor_autogen.dir/cmake_clean.cmake
.PHONY : src/cpuMonitor/CMakeFiles/CpuMonitor_autogen.dir/clean

src/cpuMonitor/CMakeFiles/CpuMonitor_autogen.dir/depend:
	cd /home/zwy/CWorkspace/VidManPlat/0build-linux && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zwy/CWorkspace/VidManPlat /home/zwy/CWorkspace/VidManPlat/src/cpuMonitor /home/zwy/CWorkspace/VidManPlat/0build-linux /home/zwy/CWorkspace/VidManPlat/0build-linux/src/cpuMonitor /home/zwy/CWorkspace/VidManPlat/0build-linux/src/cpuMonitor/CMakeFiles/CpuMonitor_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/cpuMonitor/CMakeFiles/CpuMonitor_autogen.dir/depend


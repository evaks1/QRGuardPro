# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/annashats/Desktop/c++/project/QRGuardPro

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/annashats/Desktop/c++/project/QRGuardPro/build

# Utility rule file for QRGuardPro_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/QRGuardPro_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/QRGuardPro_autogen.dir/progress.make

CMakeFiles/QRGuardPro_autogen: QRGuardPro_autogen/timestamp

QRGuardPro_autogen/timestamp: /opt/homebrew/share/qt/libexec/moc
QRGuardPro_autogen/timestamp: /opt/homebrew/share/qt/libexec/uic
QRGuardPro_autogen/timestamp: CMakeFiles/QRGuardPro_autogen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/annashats/Desktop/c++/project/QRGuardPro/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target QRGuardPro"
	/opt/homebrew/Cellar/cmake/3.30.3/bin/cmake -E cmake_autogen /Users/annashats/Desktop/c++/project/QRGuardPro/build/CMakeFiles/QRGuardPro_autogen.dir/AutogenInfo.json ""
	/opt/homebrew/Cellar/cmake/3.30.3/bin/cmake -E touch /Users/annashats/Desktop/c++/project/QRGuardPro/build/QRGuardPro_autogen/timestamp

QRGuardPro_autogen: CMakeFiles/QRGuardPro_autogen
QRGuardPro_autogen: QRGuardPro_autogen/timestamp
QRGuardPro_autogen: CMakeFiles/QRGuardPro_autogen.dir/build.make
.PHONY : QRGuardPro_autogen

# Rule to build all files generated by this target.
CMakeFiles/QRGuardPro_autogen.dir/build: QRGuardPro_autogen
.PHONY : CMakeFiles/QRGuardPro_autogen.dir/build

CMakeFiles/QRGuardPro_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/QRGuardPro_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/QRGuardPro_autogen.dir/clean

CMakeFiles/QRGuardPro_autogen.dir/depend:
	cd /Users/annashats/Desktop/c++/project/QRGuardPro/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/annashats/Desktop/c++/project/QRGuardPro /Users/annashats/Desktop/c++/project/QRGuardPro /Users/annashats/Desktop/c++/project/QRGuardPro/build /Users/annashats/Desktop/c++/project/QRGuardPro/build /Users/annashats/Desktop/c++/project/QRGuardPro/build/CMakeFiles/QRGuardPro_autogen.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/QRGuardPro_autogen.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.3.4\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.3.4\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\cmake-build-debug"

# Utility rule file for PLATFORMIO_UPDATE_ALL.

# Include the progress variables for this target.
include CMakeFiles/PLATFORMIO_UPDATE_ALL.dir/progress.make

CMakeFiles/PLATFORMIO_UPDATE_ALL:
	cd /d C:\Users\Biscuit\GOOGLE~1\ENSEIRB\EIRBOT\COUPE2~1\Software\Nucleo && C:\Python27\Scripts\platformio.exe -f -c clion update

PLATFORMIO_UPDATE_ALL: CMakeFiles/PLATFORMIO_UPDATE_ALL
PLATFORMIO_UPDATE_ALL: CMakeFiles/PLATFORMIO_UPDATE_ALL.dir/build.make

.PHONY : PLATFORMIO_UPDATE_ALL

# Rule to build all files generated by this target.
CMakeFiles/PLATFORMIO_UPDATE_ALL.dir/build: PLATFORMIO_UPDATE_ALL

.PHONY : CMakeFiles/PLATFORMIO_UPDATE_ALL.dir/build

CMakeFiles/PLATFORMIO_UPDATE_ALL.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\PLATFORMIO_UPDATE_ALL.dir\cmake_clean.cmake
.PHONY : CMakeFiles/PLATFORMIO_UPDATE_ALL.dir/clean

CMakeFiles/PLATFORMIO_UPDATE_ALL.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo" "C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo" "C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\cmake-build-debug" "C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\cmake-build-debug" "C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\cmake-build-debug\CMakeFiles\PLATFORMIO_UPDATE_ALL.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/PLATFORMIO_UPDATE_ALL.dir/depend


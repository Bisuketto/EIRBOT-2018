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

# Include any dependencies generated for this target.
include CMakeFiles/Eirbot2018.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Eirbot2018.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Eirbot2018.dir/flags.make

CMakeFiles/Eirbot2018.dir/src/AX12/AX12.cpp.obj: CMakeFiles/Eirbot2018.dir/flags.make
CMakeFiles/Eirbot2018.dir/src/AX12/AX12.cpp.obj: CMakeFiles/Eirbot2018.dir/includes_CXX.rsp
CMakeFiles/Eirbot2018.dir/src/AX12/AX12.cpp.obj: ../src/AX12/AX12.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Eirbot2018.dir/src/AX12/AX12.cpp.obj"
	C:\SPB_Data\.platformio\packages\toolchain-gccarmnoneeabi\bin\arm-none-eabi-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Eirbot2018.dir\src\AX12\AX12.cpp.obj -c "C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\src\AX12\AX12.cpp"

CMakeFiles/Eirbot2018.dir/src/AX12/AX12.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Eirbot2018.dir/src/AX12/AX12.cpp.i"
	C:\SPB_Data\.platformio\packages\toolchain-gccarmnoneeabi\bin\arm-none-eabi-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\src\AX12\AX12.cpp" > CMakeFiles\Eirbot2018.dir\src\AX12\AX12.cpp.i

CMakeFiles/Eirbot2018.dir/src/AX12/AX12.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Eirbot2018.dir/src/AX12/AX12.cpp.s"
	C:\SPB_Data\.platformio\packages\toolchain-gccarmnoneeabi\bin\arm-none-eabi-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\src\AX12\AX12.cpp" -o CMakeFiles\Eirbot2018.dir\src\AX12\AX12.cpp.s

CMakeFiles/Eirbot2018.dir/src/AX12/AX12.cpp.obj.requires:

.PHONY : CMakeFiles/Eirbot2018.dir/src/AX12/AX12.cpp.obj.requires

CMakeFiles/Eirbot2018.dir/src/AX12/AX12.cpp.obj.provides: CMakeFiles/Eirbot2018.dir/src/AX12/AX12.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Eirbot2018.dir\build.make CMakeFiles/Eirbot2018.dir/src/AX12/AX12.cpp.obj.provides.build
.PHONY : CMakeFiles/Eirbot2018.dir/src/AX12/AX12.cpp.obj.provides

CMakeFiles/Eirbot2018.dir/src/AX12/AX12.cpp.obj.provides.build: CMakeFiles/Eirbot2018.dir/src/AX12/AX12.cpp.obj


CMakeFiles/Eirbot2018.dir/src/AX12/Comm_AX12.cpp.obj: CMakeFiles/Eirbot2018.dir/flags.make
CMakeFiles/Eirbot2018.dir/src/AX12/Comm_AX12.cpp.obj: CMakeFiles/Eirbot2018.dir/includes_CXX.rsp
CMakeFiles/Eirbot2018.dir/src/AX12/Comm_AX12.cpp.obj: ../src/AX12/Comm_AX12.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Eirbot2018.dir/src/AX12/Comm_AX12.cpp.obj"
	C:\SPB_Data\.platformio\packages\toolchain-gccarmnoneeabi\bin\arm-none-eabi-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Eirbot2018.dir\src\AX12\Comm_AX12.cpp.obj -c "C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\src\AX12\Comm_AX12.cpp"

CMakeFiles/Eirbot2018.dir/src/AX12/Comm_AX12.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Eirbot2018.dir/src/AX12/Comm_AX12.cpp.i"
	C:\SPB_Data\.platformio\packages\toolchain-gccarmnoneeabi\bin\arm-none-eabi-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\src\AX12\Comm_AX12.cpp" > CMakeFiles\Eirbot2018.dir\src\AX12\Comm_AX12.cpp.i

CMakeFiles/Eirbot2018.dir/src/AX12/Comm_AX12.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Eirbot2018.dir/src/AX12/Comm_AX12.cpp.s"
	C:\SPB_Data\.platformio\packages\toolchain-gccarmnoneeabi\bin\arm-none-eabi-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\src\AX12\Comm_AX12.cpp" -o CMakeFiles\Eirbot2018.dir\src\AX12\Comm_AX12.cpp.s

CMakeFiles/Eirbot2018.dir/src/AX12/Comm_AX12.cpp.obj.requires:

.PHONY : CMakeFiles/Eirbot2018.dir/src/AX12/Comm_AX12.cpp.obj.requires

CMakeFiles/Eirbot2018.dir/src/AX12/Comm_AX12.cpp.obj.provides: CMakeFiles/Eirbot2018.dir/src/AX12/Comm_AX12.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Eirbot2018.dir\build.make CMakeFiles/Eirbot2018.dir/src/AX12/Comm_AX12.cpp.obj.provides.build
.PHONY : CMakeFiles/Eirbot2018.dir/src/AX12/Comm_AX12.cpp.obj.provides

CMakeFiles/Eirbot2018.dir/src/AX12/Comm_AX12.cpp.obj.provides.build: CMakeFiles/Eirbot2018.dir/src/AX12/Comm_AX12.cpp.obj


CMakeFiles/Eirbot2018.dir/src/Encoders.cpp.obj: CMakeFiles/Eirbot2018.dir/flags.make
CMakeFiles/Eirbot2018.dir/src/Encoders.cpp.obj: CMakeFiles/Eirbot2018.dir/includes_CXX.rsp
CMakeFiles/Eirbot2018.dir/src/Encoders.cpp.obj: ../src/Encoders.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Eirbot2018.dir/src/Encoders.cpp.obj"
	C:\SPB_Data\.platformio\packages\toolchain-gccarmnoneeabi\bin\arm-none-eabi-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Eirbot2018.dir\src\Encoders.cpp.obj -c "C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\src\Encoders.cpp"

CMakeFiles/Eirbot2018.dir/src/Encoders.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Eirbot2018.dir/src/Encoders.cpp.i"
	C:\SPB_Data\.platformio\packages\toolchain-gccarmnoneeabi\bin\arm-none-eabi-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\src\Encoders.cpp" > CMakeFiles\Eirbot2018.dir\src\Encoders.cpp.i

CMakeFiles/Eirbot2018.dir/src/Encoders.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Eirbot2018.dir/src/Encoders.cpp.s"
	C:\SPB_Data\.platformio\packages\toolchain-gccarmnoneeabi\bin\arm-none-eabi-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\src\Encoders.cpp" -o CMakeFiles\Eirbot2018.dir\src\Encoders.cpp.s

CMakeFiles/Eirbot2018.dir/src/Encoders.cpp.obj.requires:

.PHONY : CMakeFiles/Eirbot2018.dir/src/Encoders.cpp.obj.requires

CMakeFiles/Eirbot2018.dir/src/Encoders.cpp.obj.provides: CMakeFiles/Eirbot2018.dir/src/Encoders.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Eirbot2018.dir\build.make CMakeFiles/Eirbot2018.dir/src/Encoders.cpp.obj.provides.build
.PHONY : CMakeFiles/Eirbot2018.dir/src/Encoders.cpp.obj.provides

CMakeFiles/Eirbot2018.dir/src/Encoders.cpp.obj.provides.build: CMakeFiles/Eirbot2018.dir/src/Encoders.cpp.obj


CMakeFiles/Eirbot2018.dir/src/Launcher.cpp.obj: CMakeFiles/Eirbot2018.dir/flags.make
CMakeFiles/Eirbot2018.dir/src/Launcher.cpp.obj: CMakeFiles/Eirbot2018.dir/includes_CXX.rsp
CMakeFiles/Eirbot2018.dir/src/Launcher.cpp.obj: ../src/Launcher.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Eirbot2018.dir/src/Launcher.cpp.obj"
	C:\SPB_Data\.platformio\packages\toolchain-gccarmnoneeabi\bin\arm-none-eabi-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Eirbot2018.dir\src\Launcher.cpp.obj -c "C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\src\Launcher.cpp"

CMakeFiles/Eirbot2018.dir/src/Launcher.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Eirbot2018.dir/src/Launcher.cpp.i"
	C:\SPB_Data\.platformio\packages\toolchain-gccarmnoneeabi\bin\arm-none-eabi-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\src\Launcher.cpp" > CMakeFiles\Eirbot2018.dir\src\Launcher.cpp.i

CMakeFiles/Eirbot2018.dir/src/Launcher.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Eirbot2018.dir/src/Launcher.cpp.s"
	C:\SPB_Data\.platformio\packages\toolchain-gccarmnoneeabi\bin\arm-none-eabi-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\src\Launcher.cpp" -o CMakeFiles\Eirbot2018.dir\src\Launcher.cpp.s

CMakeFiles/Eirbot2018.dir/src/Launcher.cpp.obj.requires:

.PHONY : CMakeFiles/Eirbot2018.dir/src/Launcher.cpp.obj.requires

CMakeFiles/Eirbot2018.dir/src/Launcher.cpp.obj.provides: CMakeFiles/Eirbot2018.dir/src/Launcher.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Eirbot2018.dir\build.make CMakeFiles/Eirbot2018.dir/src/Launcher.cpp.obj.provides.build
.PHONY : CMakeFiles/Eirbot2018.dir/src/Launcher.cpp.obj.provides

CMakeFiles/Eirbot2018.dir/src/Launcher.cpp.obj.provides.build: CMakeFiles/Eirbot2018.dir/src/Launcher.cpp.obj


CMakeFiles/Eirbot2018.dir/src/Motors.cpp.obj: CMakeFiles/Eirbot2018.dir/flags.make
CMakeFiles/Eirbot2018.dir/src/Motors.cpp.obj: CMakeFiles/Eirbot2018.dir/includes_CXX.rsp
CMakeFiles/Eirbot2018.dir/src/Motors.cpp.obj: ../src/Motors.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Eirbot2018.dir/src/Motors.cpp.obj"
	C:\SPB_Data\.platformio\packages\toolchain-gccarmnoneeabi\bin\arm-none-eabi-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Eirbot2018.dir\src\Motors.cpp.obj -c "C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\src\Motors.cpp"

CMakeFiles/Eirbot2018.dir/src/Motors.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Eirbot2018.dir/src/Motors.cpp.i"
	C:\SPB_Data\.platformio\packages\toolchain-gccarmnoneeabi\bin\arm-none-eabi-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\src\Motors.cpp" > CMakeFiles\Eirbot2018.dir\src\Motors.cpp.i

CMakeFiles/Eirbot2018.dir/src/Motors.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Eirbot2018.dir/src/Motors.cpp.s"
	C:\SPB_Data\.platformio\packages\toolchain-gccarmnoneeabi\bin\arm-none-eabi-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\src\Motors.cpp" -o CMakeFiles\Eirbot2018.dir\src\Motors.cpp.s

CMakeFiles/Eirbot2018.dir/src/Motors.cpp.obj.requires:

.PHONY : CMakeFiles/Eirbot2018.dir/src/Motors.cpp.obj.requires

CMakeFiles/Eirbot2018.dir/src/Motors.cpp.obj.provides: CMakeFiles/Eirbot2018.dir/src/Motors.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Eirbot2018.dir\build.make CMakeFiles/Eirbot2018.dir/src/Motors.cpp.obj.provides.build
.PHONY : CMakeFiles/Eirbot2018.dir/src/Motors.cpp.obj.provides

CMakeFiles/Eirbot2018.dir/src/Motors.cpp.obj.provides.build: CMakeFiles/Eirbot2018.dir/src/Motors.cpp.obj


CMakeFiles/Eirbot2018.dir/src/Navigator.cpp.obj: CMakeFiles/Eirbot2018.dir/flags.make
CMakeFiles/Eirbot2018.dir/src/Navigator.cpp.obj: CMakeFiles/Eirbot2018.dir/includes_CXX.rsp
CMakeFiles/Eirbot2018.dir/src/Navigator.cpp.obj: ../src/Navigator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Eirbot2018.dir/src/Navigator.cpp.obj"
	C:\SPB_Data\.platformio\packages\toolchain-gccarmnoneeabi\bin\arm-none-eabi-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Eirbot2018.dir\src\Navigator.cpp.obj -c "C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\src\Navigator.cpp"

CMakeFiles/Eirbot2018.dir/src/Navigator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Eirbot2018.dir/src/Navigator.cpp.i"
	C:\SPB_Data\.platformio\packages\toolchain-gccarmnoneeabi\bin\arm-none-eabi-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\src\Navigator.cpp" > CMakeFiles\Eirbot2018.dir\src\Navigator.cpp.i

CMakeFiles/Eirbot2018.dir/src/Navigator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Eirbot2018.dir/src/Navigator.cpp.s"
	C:\SPB_Data\.platformio\packages\toolchain-gccarmnoneeabi\bin\arm-none-eabi-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\src\Navigator.cpp" -o CMakeFiles\Eirbot2018.dir\src\Navigator.cpp.s

CMakeFiles/Eirbot2018.dir/src/Navigator.cpp.obj.requires:

.PHONY : CMakeFiles/Eirbot2018.dir/src/Navigator.cpp.obj.requires

CMakeFiles/Eirbot2018.dir/src/Navigator.cpp.obj.provides: CMakeFiles/Eirbot2018.dir/src/Navigator.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Eirbot2018.dir\build.make CMakeFiles/Eirbot2018.dir/src/Navigator.cpp.obj.provides.build
.PHONY : CMakeFiles/Eirbot2018.dir/src/Navigator.cpp.obj.provides

CMakeFiles/Eirbot2018.dir/src/Navigator.cpp.obj.provides.build: CMakeFiles/Eirbot2018.dir/src/Navigator.cpp.obj


CMakeFiles/Eirbot2018.dir/src/Stepper.cpp.obj: CMakeFiles/Eirbot2018.dir/flags.make
CMakeFiles/Eirbot2018.dir/src/Stepper.cpp.obj: CMakeFiles/Eirbot2018.dir/includes_CXX.rsp
CMakeFiles/Eirbot2018.dir/src/Stepper.cpp.obj: ../src/Stepper.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Eirbot2018.dir/src/Stepper.cpp.obj"
	C:\SPB_Data\.platformio\packages\toolchain-gccarmnoneeabi\bin\arm-none-eabi-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Eirbot2018.dir\src\Stepper.cpp.obj -c "C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\src\Stepper.cpp"

CMakeFiles/Eirbot2018.dir/src/Stepper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Eirbot2018.dir/src/Stepper.cpp.i"
	C:\SPB_Data\.platformio\packages\toolchain-gccarmnoneeabi\bin\arm-none-eabi-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\src\Stepper.cpp" > CMakeFiles\Eirbot2018.dir\src\Stepper.cpp.i

CMakeFiles/Eirbot2018.dir/src/Stepper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Eirbot2018.dir/src/Stepper.cpp.s"
	C:\SPB_Data\.platformio\packages\toolchain-gccarmnoneeabi\bin\arm-none-eabi-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\src\Stepper.cpp" -o CMakeFiles\Eirbot2018.dir\src\Stepper.cpp.s

CMakeFiles/Eirbot2018.dir/src/Stepper.cpp.obj.requires:

.PHONY : CMakeFiles/Eirbot2018.dir/src/Stepper.cpp.obj.requires

CMakeFiles/Eirbot2018.dir/src/Stepper.cpp.obj.provides: CMakeFiles/Eirbot2018.dir/src/Stepper.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Eirbot2018.dir\build.make CMakeFiles/Eirbot2018.dir/src/Stepper.cpp.obj.provides.build
.PHONY : CMakeFiles/Eirbot2018.dir/src/Stepper.cpp.obj.provides

CMakeFiles/Eirbot2018.dir/src/Stepper.cpp.obj.provides.build: CMakeFiles/Eirbot2018.dir/src/Stepper.cpp.obj


CMakeFiles/Eirbot2018.dir/src/Telemetry.cpp.obj: CMakeFiles/Eirbot2018.dir/flags.make
CMakeFiles/Eirbot2018.dir/src/Telemetry.cpp.obj: CMakeFiles/Eirbot2018.dir/includes_CXX.rsp
CMakeFiles/Eirbot2018.dir/src/Telemetry.cpp.obj: ../src/Telemetry.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Eirbot2018.dir/src/Telemetry.cpp.obj"
	C:\SPB_Data\.platformio\packages\toolchain-gccarmnoneeabi\bin\arm-none-eabi-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Eirbot2018.dir\src\Telemetry.cpp.obj -c "C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\src\Telemetry.cpp"

CMakeFiles/Eirbot2018.dir/src/Telemetry.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Eirbot2018.dir/src/Telemetry.cpp.i"
	C:\SPB_Data\.platformio\packages\toolchain-gccarmnoneeabi\bin\arm-none-eabi-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\src\Telemetry.cpp" > CMakeFiles\Eirbot2018.dir\src\Telemetry.cpp.i

CMakeFiles/Eirbot2018.dir/src/Telemetry.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Eirbot2018.dir/src/Telemetry.cpp.s"
	C:\SPB_Data\.platformio\packages\toolchain-gccarmnoneeabi\bin\arm-none-eabi-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\src\Telemetry.cpp" -o CMakeFiles\Eirbot2018.dir\src\Telemetry.cpp.s

CMakeFiles/Eirbot2018.dir/src/Telemetry.cpp.obj.requires:

.PHONY : CMakeFiles/Eirbot2018.dir/src/Telemetry.cpp.obj.requires

CMakeFiles/Eirbot2018.dir/src/Telemetry.cpp.obj.provides: CMakeFiles/Eirbot2018.dir/src/Telemetry.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Eirbot2018.dir\build.make CMakeFiles/Eirbot2018.dir/src/Telemetry.cpp.obj.provides.build
.PHONY : CMakeFiles/Eirbot2018.dir/src/Telemetry.cpp.obj.provides

CMakeFiles/Eirbot2018.dir/src/Telemetry.cpp.obj.provides.build: CMakeFiles/Eirbot2018.dir/src/Telemetry.cpp.obj


CMakeFiles/Eirbot2018.dir/src/crc32.cpp.obj: CMakeFiles/Eirbot2018.dir/flags.make
CMakeFiles/Eirbot2018.dir/src/crc32.cpp.obj: CMakeFiles/Eirbot2018.dir/includes_CXX.rsp
CMakeFiles/Eirbot2018.dir/src/crc32.cpp.obj: ../src/crc32.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Eirbot2018.dir/src/crc32.cpp.obj"
	C:\SPB_Data\.platformio\packages\toolchain-gccarmnoneeabi\bin\arm-none-eabi-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Eirbot2018.dir\src\crc32.cpp.obj -c "C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\src\crc32.cpp"

CMakeFiles/Eirbot2018.dir/src/crc32.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Eirbot2018.dir/src/crc32.cpp.i"
	C:\SPB_Data\.platformio\packages\toolchain-gccarmnoneeabi\bin\arm-none-eabi-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\src\crc32.cpp" > CMakeFiles\Eirbot2018.dir\src\crc32.cpp.i

CMakeFiles/Eirbot2018.dir/src/crc32.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Eirbot2018.dir/src/crc32.cpp.s"
	C:\SPB_Data\.platformio\packages\toolchain-gccarmnoneeabi\bin\arm-none-eabi-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\src\crc32.cpp" -o CMakeFiles\Eirbot2018.dir\src\crc32.cpp.s

CMakeFiles/Eirbot2018.dir/src/crc32.cpp.obj.requires:

.PHONY : CMakeFiles/Eirbot2018.dir/src/crc32.cpp.obj.requires

CMakeFiles/Eirbot2018.dir/src/crc32.cpp.obj.provides: CMakeFiles/Eirbot2018.dir/src/crc32.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Eirbot2018.dir\build.make CMakeFiles/Eirbot2018.dir/src/crc32.cpp.obj.provides.build
.PHONY : CMakeFiles/Eirbot2018.dir/src/crc32.cpp.obj.provides

CMakeFiles/Eirbot2018.dir/src/crc32.cpp.obj.provides.build: CMakeFiles/Eirbot2018.dir/src/crc32.cpp.obj


CMakeFiles/Eirbot2018.dir/src/main.cpp.obj: CMakeFiles/Eirbot2018.dir/flags.make
CMakeFiles/Eirbot2018.dir/src/main.cpp.obj: CMakeFiles/Eirbot2018.dir/includes_CXX.rsp
CMakeFiles/Eirbot2018.dir/src/main.cpp.obj: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Eirbot2018.dir/src/main.cpp.obj"
	C:\SPB_Data\.platformio\packages\toolchain-gccarmnoneeabi\bin\arm-none-eabi-g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Eirbot2018.dir\src\main.cpp.obj -c "C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\src\main.cpp"

CMakeFiles/Eirbot2018.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Eirbot2018.dir/src/main.cpp.i"
	C:\SPB_Data\.platformio\packages\toolchain-gccarmnoneeabi\bin\arm-none-eabi-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\src\main.cpp" > CMakeFiles\Eirbot2018.dir\src\main.cpp.i

CMakeFiles/Eirbot2018.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Eirbot2018.dir/src/main.cpp.s"
	C:\SPB_Data\.platformio\packages\toolchain-gccarmnoneeabi\bin\arm-none-eabi-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\src\main.cpp" -o CMakeFiles\Eirbot2018.dir\src\main.cpp.s

CMakeFiles/Eirbot2018.dir/src/main.cpp.obj.requires:

.PHONY : CMakeFiles/Eirbot2018.dir/src/main.cpp.obj.requires

CMakeFiles/Eirbot2018.dir/src/main.cpp.obj.provides: CMakeFiles/Eirbot2018.dir/src/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\Eirbot2018.dir\build.make CMakeFiles/Eirbot2018.dir/src/main.cpp.obj.provides.build
.PHONY : CMakeFiles/Eirbot2018.dir/src/main.cpp.obj.provides

CMakeFiles/Eirbot2018.dir/src/main.cpp.obj.provides.build: CMakeFiles/Eirbot2018.dir/src/main.cpp.obj


# Object files for target Eirbot2018
Eirbot2018_OBJECTS = \
"CMakeFiles/Eirbot2018.dir/src/AX12/AX12.cpp.obj" \
"CMakeFiles/Eirbot2018.dir/src/AX12/Comm_AX12.cpp.obj" \
"CMakeFiles/Eirbot2018.dir/src/Encoders.cpp.obj" \
"CMakeFiles/Eirbot2018.dir/src/Launcher.cpp.obj" \
"CMakeFiles/Eirbot2018.dir/src/Motors.cpp.obj" \
"CMakeFiles/Eirbot2018.dir/src/Navigator.cpp.obj" \
"CMakeFiles/Eirbot2018.dir/src/Stepper.cpp.obj" \
"CMakeFiles/Eirbot2018.dir/src/Telemetry.cpp.obj" \
"CMakeFiles/Eirbot2018.dir/src/crc32.cpp.obj" \
"CMakeFiles/Eirbot2018.dir/src/main.cpp.obj"

# External object files for target Eirbot2018
Eirbot2018_EXTERNAL_OBJECTS =

Eirbot2018.exe: CMakeFiles/Eirbot2018.dir/src/AX12/AX12.cpp.obj
Eirbot2018.exe: CMakeFiles/Eirbot2018.dir/src/AX12/Comm_AX12.cpp.obj
Eirbot2018.exe: CMakeFiles/Eirbot2018.dir/src/Encoders.cpp.obj
Eirbot2018.exe: CMakeFiles/Eirbot2018.dir/src/Launcher.cpp.obj
Eirbot2018.exe: CMakeFiles/Eirbot2018.dir/src/Motors.cpp.obj
Eirbot2018.exe: CMakeFiles/Eirbot2018.dir/src/Navigator.cpp.obj
Eirbot2018.exe: CMakeFiles/Eirbot2018.dir/src/Stepper.cpp.obj
Eirbot2018.exe: CMakeFiles/Eirbot2018.dir/src/Telemetry.cpp.obj
Eirbot2018.exe: CMakeFiles/Eirbot2018.dir/src/crc32.cpp.obj
Eirbot2018.exe: CMakeFiles/Eirbot2018.dir/src/main.cpp.obj
Eirbot2018.exe: CMakeFiles/Eirbot2018.dir/build.make
Eirbot2018.exe: CMakeFiles/Eirbot2018.dir/linklibs.rsp
Eirbot2018.exe: CMakeFiles/Eirbot2018.dir/objects1.rsp
Eirbot2018.exe: CMakeFiles/Eirbot2018.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable Eirbot2018.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Eirbot2018.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Eirbot2018.dir/build: Eirbot2018.exe

.PHONY : CMakeFiles/Eirbot2018.dir/build

CMakeFiles/Eirbot2018.dir/requires: CMakeFiles/Eirbot2018.dir/src/AX12/AX12.cpp.obj.requires
CMakeFiles/Eirbot2018.dir/requires: CMakeFiles/Eirbot2018.dir/src/AX12/Comm_AX12.cpp.obj.requires
CMakeFiles/Eirbot2018.dir/requires: CMakeFiles/Eirbot2018.dir/src/Encoders.cpp.obj.requires
CMakeFiles/Eirbot2018.dir/requires: CMakeFiles/Eirbot2018.dir/src/Launcher.cpp.obj.requires
CMakeFiles/Eirbot2018.dir/requires: CMakeFiles/Eirbot2018.dir/src/Motors.cpp.obj.requires
CMakeFiles/Eirbot2018.dir/requires: CMakeFiles/Eirbot2018.dir/src/Navigator.cpp.obj.requires
CMakeFiles/Eirbot2018.dir/requires: CMakeFiles/Eirbot2018.dir/src/Stepper.cpp.obj.requires
CMakeFiles/Eirbot2018.dir/requires: CMakeFiles/Eirbot2018.dir/src/Telemetry.cpp.obj.requires
CMakeFiles/Eirbot2018.dir/requires: CMakeFiles/Eirbot2018.dir/src/crc32.cpp.obj.requires
CMakeFiles/Eirbot2018.dir/requires: CMakeFiles/Eirbot2018.dir/src/main.cpp.obj.requires

.PHONY : CMakeFiles/Eirbot2018.dir/requires

CMakeFiles/Eirbot2018.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Eirbot2018.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Eirbot2018.dir/clean

CMakeFiles/Eirbot2018.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo" "C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo" "C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\cmake-build-debug" "C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\cmake-build-debug" "C:\Users\Biscuit\Google Drive\ENSEIRB\EIRBOT\COUPE 2018\Software\Nucleo\cmake-build-debug\CMakeFiles\Eirbot2018.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Eirbot2018.dir/depend


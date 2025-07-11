# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/nacho/esp/projects_tf/person_detection

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nacho/esp/projects_tf/person_detection/build

# Include any dependencies generated for this target.
include esp-idf/perfmon/CMakeFiles/__idf_perfmon.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include esp-idf/perfmon/CMakeFiles/__idf_perfmon.dir/compiler_depend.make

# Include the progress variables for this target.
include esp-idf/perfmon/CMakeFiles/__idf_perfmon.dir/progress.make

# Include the compile flags for this target's objects.
include esp-idf/perfmon/CMakeFiles/__idf_perfmon.dir/flags.make

esp-idf/perfmon/CMakeFiles/__idf_perfmon.dir/xtensa_perfmon_access.c.obj: esp-idf/perfmon/CMakeFiles/__idf_perfmon.dir/flags.make
esp-idf/perfmon/CMakeFiles/__idf_perfmon.dir/xtensa_perfmon_access.c.obj: /home/nacho/esp/esp-idf/components/perfmon/xtensa_perfmon_access.c
esp-idf/perfmon/CMakeFiles/__idf_perfmon.dir/xtensa_perfmon_access.c.obj: esp-idf/perfmon/CMakeFiles/__idf_perfmon.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/nacho/esp/projects_tf/person_detection/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object esp-idf/perfmon/CMakeFiles/__idf_perfmon.dir/xtensa_perfmon_access.c.obj"
	cd /home/nacho/esp/projects_tf/person_detection/build/esp-idf/perfmon && /home/nacho/esp/idf-tools/tools/xtensa-esp-elf/esp-14.2.0_20241119/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT esp-idf/perfmon/CMakeFiles/__idf_perfmon.dir/xtensa_perfmon_access.c.obj -MF CMakeFiles/__idf_perfmon.dir/xtensa_perfmon_access.c.obj.d -o CMakeFiles/__idf_perfmon.dir/xtensa_perfmon_access.c.obj -c /home/nacho/esp/esp-idf/components/perfmon/xtensa_perfmon_access.c

esp-idf/perfmon/CMakeFiles/__idf_perfmon.dir/xtensa_perfmon_access.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/__idf_perfmon.dir/xtensa_perfmon_access.c.i"
	cd /home/nacho/esp/projects_tf/person_detection/build/esp-idf/perfmon && /home/nacho/esp/idf-tools/tools/xtensa-esp-elf/esp-14.2.0_20241119/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nacho/esp/esp-idf/components/perfmon/xtensa_perfmon_access.c > CMakeFiles/__idf_perfmon.dir/xtensa_perfmon_access.c.i

esp-idf/perfmon/CMakeFiles/__idf_perfmon.dir/xtensa_perfmon_access.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/__idf_perfmon.dir/xtensa_perfmon_access.c.s"
	cd /home/nacho/esp/projects_tf/person_detection/build/esp-idf/perfmon && /home/nacho/esp/idf-tools/tools/xtensa-esp-elf/esp-14.2.0_20241119/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nacho/esp/esp-idf/components/perfmon/xtensa_perfmon_access.c -o CMakeFiles/__idf_perfmon.dir/xtensa_perfmon_access.c.s

esp-idf/perfmon/CMakeFiles/__idf_perfmon.dir/xtensa_perfmon_apis.c.obj: esp-idf/perfmon/CMakeFiles/__idf_perfmon.dir/flags.make
esp-idf/perfmon/CMakeFiles/__idf_perfmon.dir/xtensa_perfmon_apis.c.obj: /home/nacho/esp/esp-idf/components/perfmon/xtensa_perfmon_apis.c
esp-idf/perfmon/CMakeFiles/__idf_perfmon.dir/xtensa_perfmon_apis.c.obj: esp-idf/perfmon/CMakeFiles/__idf_perfmon.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/nacho/esp/projects_tf/person_detection/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object esp-idf/perfmon/CMakeFiles/__idf_perfmon.dir/xtensa_perfmon_apis.c.obj"
	cd /home/nacho/esp/projects_tf/person_detection/build/esp-idf/perfmon && /home/nacho/esp/idf-tools/tools/xtensa-esp-elf/esp-14.2.0_20241119/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT esp-idf/perfmon/CMakeFiles/__idf_perfmon.dir/xtensa_perfmon_apis.c.obj -MF CMakeFiles/__idf_perfmon.dir/xtensa_perfmon_apis.c.obj.d -o CMakeFiles/__idf_perfmon.dir/xtensa_perfmon_apis.c.obj -c /home/nacho/esp/esp-idf/components/perfmon/xtensa_perfmon_apis.c

esp-idf/perfmon/CMakeFiles/__idf_perfmon.dir/xtensa_perfmon_apis.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/__idf_perfmon.dir/xtensa_perfmon_apis.c.i"
	cd /home/nacho/esp/projects_tf/person_detection/build/esp-idf/perfmon && /home/nacho/esp/idf-tools/tools/xtensa-esp-elf/esp-14.2.0_20241119/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nacho/esp/esp-idf/components/perfmon/xtensa_perfmon_apis.c > CMakeFiles/__idf_perfmon.dir/xtensa_perfmon_apis.c.i

esp-idf/perfmon/CMakeFiles/__idf_perfmon.dir/xtensa_perfmon_apis.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/__idf_perfmon.dir/xtensa_perfmon_apis.c.s"
	cd /home/nacho/esp/projects_tf/person_detection/build/esp-idf/perfmon && /home/nacho/esp/idf-tools/tools/xtensa-esp-elf/esp-14.2.0_20241119/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nacho/esp/esp-idf/components/perfmon/xtensa_perfmon_apis.c -o CMakeFiles/__idf_perfmon.dir/xtensa_perfmon_apis.c.s

esp-idf/perfmon/CMakeFiles/__idf_perfmon.dir/xtensa_perfmon_masks.c.obj: esp-idf/perfmon/CMakeFiles/__idf_perfmon.dir/flags.make
esp-idf/perfmon/CMakeFiles/__idf_perfmon.dir/xtensa_perfmon_masks.c.obj: /home/nacho/esp/esp-idf/components/perfmon/xtensa_perfmon_masks.c
esp-idf/perfmon/CMakeFiles/__idf_perfmon.dir/xtensa_perfmon_masks.c.obj: esp-idf/perfmon/CMakeFiles/__idf_perfmon.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/nacho/esp/projects_tf/person_detection/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object esp-idf/perfmon/CMakeFiles/__idf_perfmon.dir/xtensa_perfmon_masks.c.obj"
	cd /home/nacho/esp/projects_tf/person_detection/build/esp-idf/perfmon && /home/nacho/esp/idf-tools/tools/xtensa-esp-elf/esp-14.2.0_20241119/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT esp-idf/perfmon/CMakeFiles/__idf_perfmon.dir/xtensa_perfmon_masks.c.obj -MF CMakeFiles/__idf_perfmon.dir/xtensa_perfmon_masks.c.obj.d -o CMakeFiles/__idf_perfmon.dir/xtensa_perfmon_masks.c.obj -c /home/nacho/esp/esp-idf/components/perfmon/xtensa_perfmon_masks.c

esp-idf/perfmon/CMakeFiles/__idf_perfmon.dir/xtensa_perfmon_masks.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/__idf_perfmon.dir/xtensa_perfmon_masks.c.i"
	cd /home/nacho/esp/projects_tf/person_detection/build/esp-idf/perfmon && /home/nacho/esp/idf-tools/tools/xtensa-esp-elf/esp-14.2.0_20241119/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/nacho/esp/esp-idf/components/perfmon/xtensa_perfmon_masks.c > CMakeFiles/__idf_perfmon.dir/xtensa_perfmon_masks.c.i

esp-idf/perfmon/CMakeFiles/__idf_perfmon.dir/xtensa_perfmon_masks.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/__idf_perfmon.dir/xtensa_perfmon_masks.c.s"
	cd /home/nacho/esp/projects_tf/person_detection/build/esp-idf/perfmon && /home/nacho/esp/idf-tools/tools/xtensa-esp-elf/esp-14.2.0_20241119/xtensa-esp-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/nacho/esp/esp-idf/components/perfmon/xtensa_perfmon_masks.c -o CMakeFiles/__idf_perfmon.dir/xtensa_perfmon_masks.c.s

# Object files for target __idf_perfmon
__idf_perfmon_OBJECTS = \
"CMakeFiles/__idf_perfmon.dir/xtensa_perfmon_access.c.obj" \
"CMakeFiles/__idf_perfmon.dir/xtensa_perfmon_apis.c.obj" \
"CMakeFiles/__idf_perfmon.dir/xtensa_perfmon_masks.c.obj"

# External object files for target __idf_perfmon
__idf_perfmon_EXTERNAL_OBJECTS =

esp-idf/perfmon/libperfmon.a: esp-idf/perfmon/CMakeFiles/__idf_perfmon.dir/xtensa_perfmon_access.c.obj
esp-idf/perfmon/libperfmon.a: esp-idf/perfmon/CMakeFiles/__idf_perfmon.dir/xtensa_perfmon_apis.c.obj
esp-idf/perfmon/libperfmon.a: esp-idf/perfmon/CMakeFiles/__idf_perfmon.dir/xtensa_perfmon_masks.c.obj
esp-idf/perfmon/libperfmon.a: esp-idf/perfmon/CMakeFiles/__idf_perfmon.dir/build.make
esp-idf/perfmon/libperfmon.a: esp-idf/perfmon/CMakeFiles/__idf_perfmon.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/nacho/esp/projects_tf/person_detection/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C static library libperfmon.a"
	cd /home/nacho/esp/projects_tf/person_detection/build/esp-idf/perfmon && $(CMAKE_COMMAND) -P CMakeFiles/__idf_perfmon.dir/cmake_clean_target.cmake
	cd /home/nacho/esp/projects_tf/person_detection/build/esp-idf/perfmon && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/__idf_perfmon.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
esp-idf/perfmon/CMakeFiles/__idf_perfmon.dir/build: esp-idf/perfmon/libperfmon.a
.PHONY : esp-idf/perfmon/CMakeFiles/__idf_perfmon.dir/build

esp-idf/perfmon/CMakeFiles/__idf_perfmon.dir/clean:
	cd /home/nacho/esp/projects_tf/person_detection/build/esp-idf/perfmon && $(CMAKE_COMMAND) -P CMakeFiles/__idf_perfmon.dir/cmake_clean.cmake
.PHONY : esp-idf/perfmon/CMakeFiles/__idf_perfmon.dir/clean

esp-idf/perfmon/CMakeFiles/__idf_perfmon.dir/depend:
	cd /home/nacho/esp/projects_tf/person_detection/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nacho/esp/projects_tf/person_detection /home/nacho/esp/esp-idf/components/perfmon /home/nacho/esp/projects_tf/person_detection/build /home/nacho/esp/projects_tf/person_detection/build/esp-idf/perfmon /home/nacho/esp/projects_tf/person_detection/build/esp-idf/perfmon/CMakeFiles/__idf_perfmon.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : esp-idf/perfmon/CMakeFiles/__idf_perfmon.dir/depend


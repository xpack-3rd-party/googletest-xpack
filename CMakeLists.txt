# -----------------------------------------------------------------------------
#
# This file is part of the µOS++ distribution.
#   (https://github.com/micro-os-plus/)
# Copyright (c) 2022 Liviu Ionescu
#
# Permission to use, copy, modify, and/or distribute this software
# for any purpose is hereby granted, under the terms of the MIT license.
#
# If a copy of the license was not distributed with this file, it can
# be obtained from https://opensource.org/licenses/MIT/.
#
# -----------------------------------------------------------------------------

# This file is intended to be consumed by applications with:
#
# `add_subdirectory("xpacks/xpack-3rd-party-googletest")`
#
# The result is an interface library that can be added to the linker with:
#
# `target_link_libraries(your-target PRIVATE xpack-3rd-party::googletest)`

# -----------------------------------------------------------------------------
## Preamble ##

# https://cmake.org/cmake/help/v3.20/
cmake_minimum_required(VERSION 3.20)

project(xpack-3rd-party-googletest
  DESCRIPTION "Google Test"
)

if(COMMAND xpack_get_package_name_and_version)
  xpack_get_package_name_and_version("${CMAKE_CURRENT_SOURCE_DIR}/package.json")
  message(VERBOSE "Processing xPack ${PACKAGE_JSON_NAME}@${PACKAGE_JSON_VERSION}...")
endif()

# -----------------------------------------------------------------------------
## The project library definitions ##

add_library(xpack-3rd-party-googletest-static STATIC)

# -----------------------------------------------------------------------------
# Target settings.

#  Google Test.
target_include_directories(xpack-3rd-party-googletest-static PUBLIC
  "googletest/include"
  "googletest"
)

target_sources(xpack-3rd-party-googletest-static PRIVATE
  "googletest/src/gtest-all.cc"
)

# Google Mock.
target_sources(xpack-3rd-party-googletest-static PRIVATE
  "googlemock/src/gmock-all.cc"
)

target_include_directories(xpack-3rd-party-googletest-static PUBLIC
  "googlemock/include"
  "googlemock"
)

target_compile_definitions(xpack-3rd-party-googletest-static PRIVATE
  # None.
)

target_compile_options(xpack-3rd-party-googletest-static PUBLIC
  -Wno-padded
  -Wno-undef
  -Wno-missing-noreturn
  -Wno-switch-enum
  -Wno-switch-default
  -Wno-null-dereference

  -Wno-psabi

  # https://cmake.org/cmake/help/v3.20/variable/CMAKE_LANG_COMPILER_ID.html
  $<$<C_COMPILER_ID:GNU>:-Wno-missing-attributes>
  $<$<C_COMPILER_ID:GNU>:-Wno-aggregate-return>
  $<$<C_COMPILER_ID:GNU>:-Wno-conversion>
  $<$<C_COMPILER_ID:GNU>:-Wno-suggest-final-methods>
  $<$<C_COMPILER_ID:GNU>:-Wno-suggest-final-types>
  $<$<C_COMPILER_ID:GNU>:-Wno-sign-conversion>
  $<$<C_COMPILER_ID:GNU>:-Wno-missing-declarations>

  $<$<C_COMPILER_ID:Clang,AppleClang>:-Wno-c++98-compat>
  $<$<C_COMPILER_ID:Clang,AppleClang>:-Wno-c++98-compat-pedantic>
  $<$<C_COMPILER_ID:Clang,AppleClang>:-Wno-weak-vtables>
  $<$<C_COMPILER_ID:Clang,AppleClang>:-Wno-unused-member-function>
  $<$<C_COMPILER_ID:Clang,AppleClang>:-Wno-global-constructors>
  $<$<C_COMPILER_ID:Clang,AppleClang>:-Wno-exit-time-destructors>
  $<$<C_COMPILER_ID:Clang,AppleClang>:-Wno-covered-switch-default>
  $<$<C_COMPILER_ID:Clang,AppleClang>:-Wno-used-but-marked-unused>
  $<$<C_COMPILER_ID:Clang,AppleClang>:-Wno-extra-semi-stmt>
  $<$<C_COMPILER_ID:Clang,AppleClang>:-Wno-disabled-macro-expansion>
  $<$<C_COMPILER_ID:Clang,AppleClang>:-Wno-comma>
  $<$<C_COMPILER_ID:Clang,AppleClang>:-Wno-missing-prototypes>

  $<$<COMPILE_LANGUAGE:CXX>:-Wno-zero-as-null-pointer-constant>
  $<$<COMPILE_LANGUAGE:CXX>:-Wno-suggest-override>
  $<$<COMPILE_LANGUAGE:CXX>:-Wno-ctor-dtor-privacy>

  $<$<AND:$<COMPILE_LANGUAGE:CXX>,$<C_COMPILER_ID:GNU>>:-Wno-useless-cast>
  $<$<AND:$<COMPILE_LANGUAGE:CXX>,$<C_COMPILER_ID:GNU>>:-Wno-redundant-tags>
)

target_link_libraries(xpack-3rd-party-googletest-static PRIVATE
  # None.
)

if (COMMAND xpack_display_target_lists)
  xpack_display_target_lists(xpack-3rd-party-googletest-static)
endif()

# -----------------------------------------------------------------------------
# Aliases.

# https://cmake.org/cmake/help/v3.20/command/add_library.html#alias-libraries
add_library(xpack-3rd-party::googletest ALIAS xpack-3rd-party-googletest-static)
message(VERBOSE "> xpack-3rd-party::googletest -> xpack-3rd-party-googletest-static")

# -----------------------------------------------------------------------------

if(false)
# Note: CMake support is community-based. The maintainers do not use CMake
# internally.

cmake_minimum_required(VERSION 3.5)

if (POLICY CMP0048)
  cmake_policy(SET CMP0048 NEW)
endif (POLICY CMP0048)

if (POLICY CMP0077)
  cmake_policy(SET CMP0077 NEW)
endif (POLICY CMP0077)

project(googletest-distribution)
set(GOOGLETEST_VERSION 1.11.0)

if(NOT CYGWIN AND NOT MSYS AND NOT ${CMAKE_SYSTEM_NAME} STREQUAL QNX)
  set(CMAKE_CXX_EXTENSIONS OFF)
endif()

enable_testing()

include(CMakeDependentOption)
include(GNUInstallDirs)

#Note that googlemock target already builds googletest
option(BUILD_GMOCK "Builds the googlemock subproject" ON)
option(INSTALL_GTEST "Enable installation of googletest. (Projects embedding googletest may want to turn this OFF.)" ON)

if(BUILD_GMOCK)
  add_subdirectory( googlemock )
else()
  add_subdirectory( googletest )
endif()
endif()
